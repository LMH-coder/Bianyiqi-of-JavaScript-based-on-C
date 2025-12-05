# C(re2c + bison) JavaScript syntax parser with ASI
# deps: re2c, bison, gcc
# build: make
# test: make test
# corpus: make corpus-js DATASET_JS=/path/to/js; make corpus-vb DATASET_VB=/path/to/vb_examples

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -O2
LDFLAGS := 
RE2C    := re2c
BISON   := bison

SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
GEN_DIR := src
TEST_DIR:= test

# generated
LEX_C   := $(GEN_DIR)/lexer.c
PARSER_C:= $(GEN_DIR)/parser.c
PARSER_H:= $(GEN_DIR)/parser.h

OBJS := $(SRC_DIR)/main.o $(LEX_C:.c=.o) $(PARSER_C:.c=.o) $(SRC_DIR)/parser_driver.o

all: $(BIN_DIR)/jsparser

$(BIN_DIR)/jsparser: $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(SRC_DIR) -o $@ $(OBJS) $(LDFLAGS)

$(LEX_C): $(SRC_DIR)/lexer.re $(PARSER_H)
	$(RE2C) -o $@ --case-ranges --no-generation-date $<

$(PARSER_C) $(PARSER_H): $(SRC_DIR)/parser.y
	$(BISON) -Wall --defines=$(PARSER_H) -o $(PARSER_C) $<

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/tokens.h $(SRC_DIR)/parser.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(SRC_DIR) -c -o $@ $<

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/parser_driver.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(SRC_DIR) -c -o $@ $<

$(SRC_DIR)/parser_driver.o: $(SRC_DIR)/parser_driver.c $(INC_DIR)/parser_driver.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(SRC_DIR) -c -o $@ $<

clean:
	rm -f $(SRC_DIR)/*.o $(LEX_C) $(PARSER_C) $(PARSER_H)
	rm -f $(BIN_DIR)/jsparser

test: all
	@echo "== JS valid samples =="
	@set -e; for f in $(TEST_DIR)/js/valid/*.js; do \
	  echo "-- $$f"; ./bin/jsparser $$f >/dev/null || exit 1; \
	done
	@echo "== JS invalid samples =="
	@set -e; for f in $(TEST_DIR)/js/invalid/*.js; do \
	  echo "-- $$f"; if ./bin/jsparser $$f >/dev/null; then echo "Expected error but parsed OK"; exit 1; fi; done
	@echo "== VB files should be rejected =="
	@set -e; if [ -d $(TEST_DIR)/vb ]; then \
	  for f in $(TEST_DIR)/vb/*.vb; do \
	    echo "-- $$f"; if ./bin/jsparser $$f >/dev/null; then echo "Expected error but parsed OK"; exit 1; fi; \
	  done; \
	else echo "(no VB files under test/vb, skip)"; fi
	@echo "All tests passed."

DATASET_JS ?=
DATASET_VB ?=

corpus-js: all
	@if [ -z "$(DATASET_JS)" ]; then echo "Usage: make corpus-js DATASET_JS=/path/to/js/dataset"; exit 2; fi
	@echo "== Corpus JS ($(DATASET_JS)) =="
	@set -e; rg --glob '!node_modules' --glob '!**/*.min.js' --files $(DATASET_JS) -g '*.js' | \
	while read -r f; do \
	  ./bin/jsparser "$$f" >/dev/null || echo "Syntax error: $$f"; \
	done

corpus-vb: all
	@if [ -z "$(DATASET_VB)" ]; then echo "Usage: make corpus-vb DATASET_VB=/path/to/vb_examples"; exit 2; fi
	@echo "== Corpus VB ($(DATASET_VB)) should be rejected =="
	@set -e; rg --files $(DATASET_VB) -g '*.vb' | \
	while read -r f; do \
	  if ./bin/jsparser "$$f" >/dev/null; then echo "Unexpected OK: $$f"; exit 1; fi; \
	done; echo "VB corpus rejected as expected."
