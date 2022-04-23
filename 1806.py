# 부분합

import sys; input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))

start, end, interval_sum = 0, 0, 0
answer = N+1

while True:
    if interval_sum>=S:
        answer = min(answer, end-start)
        interval_sum-=nums[start]
        start+=1
    elif end == N:
        break
    else:
        interval_sum+=nums[end]
        end+=1

if answer == N+1:
    print(0)
else:
    print(answer)