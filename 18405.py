# BOJ 18405

import sys
from collections import deque

input = sys.stdin.readline
N, K = map(int, input().split())

graph = []
for i in range(N):
    graph.append(list(map(int, input().split())))

S, X, Y = map(int, input().split())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
data = []

for i in range(N):
    for j in range(N):
        if graph[i][j] != 0:
            data.append((graph[i][j], i, j, 0))

# queue를 sorting 하고 싶으면, list로 받아 sorting 후, deque에 넘겨준다.
data.sort()
queue = deque(data)

# True 하면 왜 틀려?? S가 너무 멀면 queue가 empty인 경우가 발생해서 popleft()에서 에러 발생.
while queue:
    virus, cur_x, cur_y, time = queue.popleft()

    if time == S:
        break

    for i in range(4):
        nx = cur_x + dx[i]
        ny = cur_y + dy[i]

        if 0<=nx<N and 0<=ny<N:
            if graph[nx][ny] == 0:
                graph[nx][ny] = virus
                queue.append((virus, nx, ny, time+1))


print(graph[X-1][Y-1])