# https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1010
def solve(a, b):
  m = len(a)
  n = len(b)
  if n == 0 or m == 0:
    return 0

  dp = []
  for i in range (0, n):
    dp.append([0] * m)

  if a[0] == b[0]:
    dp[0][0] = 1

  for i in range(1, m):
    dp[0][i] = dp[0][i-1]
    if a[i] == b[0]:
      dp[0][i] += 1

  for i in range(1, n):
    for j in range(1, m):
      dp[i][j] = dp[i][j-1]
      if a[j] == b[i]:
        dp[i][j] += dp[i-1][j-1]

  return dp[n-1][m-1]

t = int(input())

for i in range(0, t):
  a = str(input())
  b = str(input())
  ans = str(solve(a, b))
  print(ans)

exit(0)
