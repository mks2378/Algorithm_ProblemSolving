import sys

input = sys.stdin.readline

vectors = list()
in_values = list()

curr = 0
n = int(input())

ans = 0
pos = None

for _ in range(n):
    a, b = map(int, input().split())
    vectors.append((a, True))
    vectors.append((b, False))
    in_values.append((a, b))

vectors.sort(key=lambda x: (x[0], -x[1]))

for vec in vectors:
    if vec[1]:
        curr += 1
    else:
        curr -= 1
    if curr > ans:
        ans = curr
        pos = vec[0]

print(ans)
for i, in_val in enumerate(in_values):
    if in_val[0]<=pos and in_val[1]>=pos:
        print(i+1, end=' ')