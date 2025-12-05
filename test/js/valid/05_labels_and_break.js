outer:
for (var i = 0; i < 3; i++) {
  inner:
  for (var j = 0; j < 3; j++) {
    if (i + j > 3) break outer
  }
}
