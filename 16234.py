from collections import deque
import sys
input = sys.stdin.readline


def bfs(i, j):
    q = deque()
    q.append([i, j])
    temp = []
    temp.append([i, j])

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<N and 0<=ny<N and visit[nx][ny] == 0:
                if L<=abs(A[nx][ny] - A[x][y])<=R:
                    visit[nx][ny] = 1
                    q.append([nx, ny])
                    temp.append([nx, ny])
    return temp

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
cnt = 0
while True:
    visit = [[0]*N for _ in range(N)]
    isTrue = False
    for i in range(N):
        for j in range(N):
            if visit[i][j] == 0:
                visit[i][j] = 1
                temp = bfs(i, j)
                if len(temp) > 1:
                    isTrue = True
                    num = sum([A[x][y] for x, y in temp]) // len(temp)
                    for x, y in temp:
                        A[x][y] = num

    if not isTrue:
        break
    cnt += 1
print(cnt)