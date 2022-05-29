import sys; input = sys.stdin.readline

N, K = map(int, input().split())
coins = [int(input()) for _ in range(N)]

cnt = 0
for i in range(N-1, -1, -1):
    coin = coins[i]
    while coin<=K:
        K-=coin
        cnt+=1

print(cnt)