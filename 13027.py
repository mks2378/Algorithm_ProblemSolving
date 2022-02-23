import sys

input = sys.stdin.readline

cnt = 0
n = int(input())

v = list()
for _ in range(n):
    a, b = map(int, input().split())
    v.append((a-b, a+b))

v.sort(key=lambda x:(x[1], x[0]))

t = -1e9
for pt in v:
    if pt[0] < t: continue
    cnt += 1
    t = pt[1]

print(cnt)
