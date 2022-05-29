import sys; input = sys.stdin.readline

N = int(input())
roads = list(map(int, input().split()))
cities = list(map(int, input().split()))

min_val = cities[0]
ans = 0
for i in range(N-1):
    min_val = min(min_val, cities[i])
    ans += (min_val * roads[i])

print(ans)