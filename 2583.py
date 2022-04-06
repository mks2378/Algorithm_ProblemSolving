import sys
input = sys.stdin.readline

from collections import deque

"""
K개의 직사각형을 모눈종이에 그린다.
K개의 직사각형 내부 제외한 나머지 부분이 몇 개의 분리된 영역으로 나뉜다.

주어진 K개의 직사각형으로 직사각형 내부 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지 출력.
분리된 각 영역의 넓이가 얼마인지 출력. (오름차순)
"""


# params
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]


# function
def draw_rectangle(rec_info):
    for x1, y1, x2, y2 in rec_info:  # 인덱스 시, x y 바꿔 사용
        # (0, 4) (2, 6)
        for i in range(y1, y2):
            for j in range(x1, x2):
                visited[i][j] = True


def find_segments(y, x):
    q = deque()
    q.append([y, x])
    visited[y][x] = True
    area = 1

    while q:
        cy, cx = q.popleft()
        for k in range(4):
            ny = cy + dy[k]
            nx = cx + dx[k]

            if 0<=ny<M and 0<=nx<N and not visited[ny][nx]:
                visited[ny][nx] = True
                area+=1
                q.append([ny, nx])

    return area


# MAIN
M, N, K = map(int, input().split())  # M:행, N:열
visited = [[0]*N for _ in range(M)]

rectangle_info = []
for _ in range(K):
    # 왼쪽 위 x,y / 오른 아래 x,y
    rectangle_info.append(list(map(int, input().split())))

draw_rectangle(rectangle_info)

answer = []
for i in range(M):
    for j in range(N):
        if not visited[i][j]:
            answer.append(find_segments(i, j))

print(len(answer))
for e in sorted(answer):
    print(e, end=' ')