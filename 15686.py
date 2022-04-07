# # 20:20 ~ 21:15
#
# import sys
# input = sys.stdin.readline
#
# from collections import deque
# from itertools import combinations
#
# """
# 치킨 거리: 집과 가장 가까운 치킨집 사이의 거리
# 도시의 치킨 거리: 모든 집의 치킨 거리의 합
# """
#
# # params
# min_cost = int(1e9)
#
# dy = [0, 0, -1, 1]
# dx = [1, -1, 0, 0]
#
#
# # function
# def find_min_cost(c_pos):
#     total = 0
#     over_cost = False
#     for home in homes:
#         # ([1, 2], [2, 2], [4, 4])
#         visited = [[0] * N for _ in range(N)]
#         for a, b in c_pos:
#             visited[a][b] = 2
#
#         y, x = home[:]
#
#         q = deque()
#         q.append([y, x, 0])
#         visited[y][x] = 1
#
#         while q:
#             find = False
#
#             cy, cx, cnt = q.popleft()
#
#             for k in range(4):
#                 ny = cy + dy[k]
#                 nx = cx + dx[k]
#
#                 if 0<=ny<N and 0<=nx<N:
#                     if visited[ny][nx] == 2:
#                         total += (cnt+1)
#                         find = True
#                         break
#                     elif visited[ny][nx] == 0:
#                         q.append([ny, nx, cnt + 1])
#                         visited[ny][nx] = True
#
#             if find:
#                 break
#
#             if total>=min_cost:
#                 over_cost = True
#                 break
#
#         if over_cost:
#             break
#
#     return total
#
#
# # MAIN
# # N: board 길이, M:수익 최대 치킨집 개수
# N, M = map(int, input().split())
#
# board = []
# chickens = []
# homes = []
# for i in range(N):
#     temp = list(map(int, input().split()))
#     for j in range(N):
#         if temp[j] == 2:
#             chickens.append([i, j])
#         if temp[j] == 1:
#             homes.append([i, j])
#
# candidates = list(combinations(chickens, M))
# for c in candidates:
#     min_cost = min(find_min_cost(c), min_cost)
#
# print(min_cost)


import sys
input = sys.stdin.readline
from itertools import combinations

N, M = map(int, input().split())
city = []
result = int(1e9)
house = []
chicken = []

for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(N):
        if temp[j] == 1:
            house.append([i, j])
        elif temp[j] == 2:
            chicken.append([i, j])
    city.append(temp)

for chi in combinations(chicken, M):
    temp = 0
    for h in house:
        chi_len = 999
        for j in range(M):
            chi_len = min(chi_len, abs(h[0] - chi[j][0]) + abs(h[1]-chi[j][1]))
        temp += chi_len
    result = min(result, temp)

print(result)


