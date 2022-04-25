"""
비바라기 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름 생성.

M번 구름의 이동 명령
각 이동은 방향 d와 거리 s로 구성.

1. 모든 구름이 d방향 s칸 이동
2. 각 구름에서 비 내려 각 구름 칸의 바구니에 물의 양이 1 증가
3. 구름 모두 사라짐.
4. 2에서 물이 증가한 칸(r,c) 에서 마법 시전. 이 때, 대각선 방향으로 거리 1인 칸에 물이 있는 바구니 수만큼 (r, c)에 있는 바구니 물의 양 증가.
    - 경계 내에 칸.
5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름 생성 + 물의 양 2 감소.
    - 이 때, 3에서 사라진 구름칸이 아니어야 한다.
"""

# # 19:40 ~ 20:25
# # 다 맞추는데 시간초과
# import sys; input = sys.stdin.readline
#
# dy = (0, 0, -1, -1, -1, 0, 1, 1, 1)
# dx = (0, -1, -1, 0, 1, 1, 1, 0, -1)
#
# diag_dy = (-1, -1, 1, 1)
# diag_dx = (-1, 1, -1, 1)
#
#
# def water_copy(cloud):
#     for cy, cx in cloud:
#         new_water = 0
#         for d in range(4):
#             ny = cy + diag_dy[d]
#             nx = cx + diag_dx[d]
#
#             if 0 <= ny < N and 0 <= nx < N and board[ny][nx] > 0:
#                 new_water += 1
#
#         board[cy][cx] += new_water
#
#
# def water_calculate(cloud):
#     new_cloud = []
#     for i in range(N):
#         for j in range(N):
#             if board[i][j]>=2 and [i, j] not in cloud:
#                 new_cloud.append([i, j])
#                 board[i][j]-=2
#
#     return new_cloud
#
#
# # main
# N, M = map(int, input().split())
# board = [list(map(int, input().split())) for _ in range(N)]
# move_info = [list(map(int, input().split())) for _ in range(M)]
#
# cloud = [[N-1, 0], [N-1, 1], [N-2, 0], [N-2, 1]]
# for d, s in move_info:
#     for i in range(len(cloud)):
#         cy, cx = cloud.pop(0)
#
#         ny = (cy + dy[d]*s)%N
#         nx = (cx + dx[d]*s)%N
#
#         board[ny][nx] += 1
#         cloud.append([ny, nx])
#
#     water_copy(cloud)
#
#     cloud = water_calculate(cloud)
#
# answer = 0
# for i in range(N):
#     for j in range(N):
#         answer += board[i][j]
#
# print(answer)

import sys; input = sys.stdin.readline

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
moves = [tuple(map(int, input().split())) for _ in range(M)]
delta = ((0, 0), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1))
check = ((-1, 1), (1, 1), (-1, -1), (1, -1))
clouds = [(N - 1, 0), (N - 1, 1), (N - 2, 0), (N - 2, 1)]
for d, s in moves:
    # 구름 이동
    moved_clouds = set()
    for _ in range(len(clouds)):
        y, x = clouds.pop()
        ny, nx = (y + delta[d][0]*s)%N, (x + delta[d][1]*s)%N

        # 구름에서 비 내림
        A[ny][nx] += 1
        moved_clouds.add((ny, nx))

    for y, x in moved_clouds:
        tmp = 0
        for dy, dx in check:
            ny, nx = y + dy, x + dx
            if 0<=ny<N and 0<=nx<N and A[ny][nx]:
                tmp+=1
        A[y][x]+=tmp

    for i in range(N):
        for j in range(N):
            if A[i][j]>=2 and (i, j) not in moved_clouds:
                A[i][j] -= 2
                clouds.append((i, j))

water = 0
for i in range(N):
    water += sum(A[i])

print(water)