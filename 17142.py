# 18:50
# from collections import deque
# from itertools import combinations as combi
# import sys
# input = sys.stdin.readline


# def bfs(y, x):
#     pass


# N, M = map(int, input().split())
# graph = []
# virus_pos = []
# for i in range(N):
#     temp = list(map(int, input().split()))
#     graph.append(temp)
#     for j in range(N):
#         if temp[j] == 2:
#             virus_pos.append([i, j])
#             temp[j] = 0
#
# viruses_combi = list(combinations(virus_pos, M))
# print(viruses_combi)

# min_time = 1000000000
# flag = True
# for viruses in viruses_combi:
#     temp_map = graph.copy()
#     for virus in viruses:
#         y, x = virus
#         temp_map[y][x] = 2
#
#     t = bfs(viruses, temp_map)
#     if flag == True:
#


from collections import deque
from itertools import combinations as combi
import sys
input = sys.stdin.readline

def bfs(virus_list):
    dist = [[-1] * N for _ in range(N)]
    dq = deque()
    for pos in virus_list:
        dq.append(pos)
        dist[pos[0]][pos[1]] = 0

    max_dist = 0
    while dq:
        y, x = dq.popleft()
        for k in range(4):
            ny = y + dy[k]
            nx = x + dx[k]

            if 0<=ny<N and 0<=nx<N and graph[ny][nx]!=1 and dist[ny][nx]==-1:
                dist[ny][nx] = dist[y][x] + 1
                if graph[ny][nx]==0:
                    max_dist = max(max_dist, dist[ny][nx])
                dq.append([ny, nx])

    a = list(sum(dist, []))
    if a.count(-1) == list(sum(graph, [])).count(1):
        ans.append(max_dist)


dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

virus_pos = []
ans = []
for i in range(N):
    for j in range(N):
        if graph[i][j] == 2:
            virus_pos.append([i, j])

for now_virus_list in combi(virus_pos, M):
    bfs(now_virus_list)

print(min(ans) if ans else -1)

# 리스트가 비어있는지 확인
# ans = []
# print(min(ans) if ans else -1)