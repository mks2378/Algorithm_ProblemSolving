# import sys
#
# input = sys.stdin.readline
#
# cnt=0
# mx=0
# vec = list()
#
# n = int(input())
# for _ in range(n):
#     a, b = map(int, input().split())
#     vec.append((a, True))
#     vec.append((b, False))
#
# vec.sort()
#
# for v in vec:
#     if v[1]:
#         cnt += 1
#     else:
#         cnt -= 1
#
#     if cnt>mx:
#         mx = cnt
#
# print(mx)


import sys
from queue import PriorityQueue

input = sys.stdin.readline

n = int(input())
vec = list()

q = PriorityQueue()

for _ in range(n):
    a, b = map(int, input().split())
    vec.append((a, b))

vec.sort()

mx = 1
for v in vec:
    q.put(v[0] + v[1])
    thrs = q.get()
    while q.qsize()+1 and (thrs < v[0] - v[1]):
        q.get()

    mx = max(mx, q.qsize())

print(mx)
