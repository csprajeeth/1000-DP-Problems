# https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=728
def solve(v):
  if len(v) == 0:
    return 0
  pos = None # max pos array product ending at i
  neg = None # max neg array product ending at i
  ans = v[0]
  has_zero = False

  for i in range(0, len(v)):
    if v[i] > 0:
      pos = pos * v[i] if pos != None else v[i]
      neg = neg * v[i] if neg != None else None
    elif v[i] < 0:
      old_neg = neg
      neg = pos * v[i] if pos != None else v[i]
      pos = old_neg * v[i] if old_neg != None else None
    else:
      pos = 0
      neg = None

    if pos != None:
      ans = max(ans, pos)
  return ans

while True:
  v = []
  try:
    v = list(map(int, input().split(' ')))
    while v[-1] != -999999:
      v += list(map(int, input().split(' ')))
    print (solve(v[:-1]))
  except EOFError:
    break
