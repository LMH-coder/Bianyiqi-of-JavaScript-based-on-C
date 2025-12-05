var a = 1
let b = 2
const c = a + b

function sum(x, y) {
  return x + y
}

if (sum(a, b) > 3) {
  a++
} else {
  b--
}

for (let i = 0; i < 3; i++) {
  sum(i, i*i)
}
