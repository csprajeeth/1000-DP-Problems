# https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=436
f = [0, 1]
for i in range(2, 5010):
    f.append(f[i-1] + f[i-2])

while True:
  try:
    n = int(input())
    print ("The Fibonacci number for", n, "is", f[n])
  except EOFError:
    break

exit(0)
