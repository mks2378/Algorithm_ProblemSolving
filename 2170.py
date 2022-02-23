import sys

input = sys.stdin.readline

N = int(input())

vec = list()
for _ in range(N):
    a, b = map(int, input().split())
    vec.append((a, b))

vec.sort()

start_pos = vec[0][0]
end_pos = vec[0][1]
del vec[0]

total = end_pos - start_pos

for v in vec:
    if v[0]<end_pos and v[1]>end_pos:
        total += v[1] - end_pos
        end_pos = v[1]

    if v[0] >= end_pos:
        total += v[1] - v[0]
        end_pos = v[1]
        start_pos = v[0]

print(total)