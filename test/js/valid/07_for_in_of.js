var obj = {a:1, b:2}, sum = 0
for (var k in obj) { sum = sum + obj[k] }
var arr = [1,2,3]
for (x of arr) { sum = sum + x }
