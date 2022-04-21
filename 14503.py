import sys;input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# main
N, M = map(int, input().split())
cy, cx, d = map(int, input().split())

visited = [[0]*M for _ in range(N)]
graph = [list(map(int, input().split())) for _ in range(N)]

visited[cy][cx] = 1
cnt = 1

while True:
    flag = False
    for _ in range(4):
        ny = cy + dy[(d+3)%4]
        nx = cx + dx[(d+3)%4]
        d = (d+3)%4

        if 0<=ny<N and 0<=nx<M and graph[ny][nx] == 0:
            if not visited[ny][nx]:
                visited[ny][nx] = 1
                cnt+=1
                cy, cx = ny, nx

                flag = True
                break
    if flag is False:
        if graph[cy-dy[d]][cx-dx[d]] == 1:
            print(cnt)
            break
        else:
            cy, cx = cy-dy[d], cx-dx[d]