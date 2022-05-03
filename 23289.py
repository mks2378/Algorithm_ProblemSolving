# # 어항 정리
#
# import sys; input = sys.stdin.readline
#
#
# dy = (0, 0, 1, -1)
# dx = (1, -1, 0, 0)
#
#
# def heat_blow():
#     # 온풍기가 있는 칸도 다른 온풍기에 의해 온도가 상승 가능
#     for hy, hx, dir in heater:  # heater.append([i, j, temp[j]])
#         # 5-1, 4-3, 3-5, 2-7, 1-9
#
#         """
#         여기 구현이 어렵네
#         """
#         # 방향 오른쪽
#         if dir == 1:
#             if 0<hy<R and 0<=hx+1<C:
#                 if wall_board[hy][hx] == 1 and wall_board[hy][hx+1] == 1:
#
#         # 방향 왼쪽
#         elif dir == 2:
#
#
#         # 방향 위쪽
#         elif dir == 3:
#
#
#         # 방향 아래쪽
#         elif dir == 4:
#
#
#
# # 모든 인접한 칸에 대해서, 온도가 높은 칸에서 낮은 칸으로 ⌊(두 칸의 온도의 차이)/4⌋만큼 온도가 조절
# def temp_control():
#     new_board = [[0]*C for _ in range(R)]
#
#     for cy in range(R):
#         for cx in range(C):
#             total = 0
#             for d in range(4):
#                 ny = cy + dy[d]
#                 nx = cx + dx[d]
#
#                 if 0<=ny<R and 0<=nx<C:
#                     #  t == 0, (y, x)와 (y-1, x) 사이에 벽,
#                     #  t == 1, (y, x)와 (y, x+1) 사이에 벽
#                     # wall_exist = False
#                     # for wy, wx, t in walls:
#                     #     if t == 0:
#                     #         if ny == wy-1 and nx == wx:
#                     #             wall_exist = True
#                     #             break
#                     #     elif t == 1:
#                     #         if ny == wy and nx == wx+1:
#                     #             wall_exist = True
#                     #             break
#                     #
#                     # if wall_exist:
#                     #     continue
#
#                     if wall_board[cy][cx] == 1 and wall_board[ny][nx] == 1:
#                         continue
#
#                     diff = abs(board[ny][nx] - board[cy][cx]) // 4
#                     if board[ny][nx]>board[cy][cx]:
#                         total += diff
#                     elif board[ny][nx]<board[cy][cx]:
#                         total -= diff
#
#             new_board[cy][cx] = board[cy][cx] + total
#
#     return new_board
#
#
# def side_temp_control():
#     # 0행
#     for j in range(C):
#         if board[0][j]:
#             board[0][j]-=1
#     # R-1행
#     for j in range(C):
#         if board[R-1][j]:
#             board[R-1][j]-=1
#     # 0열
#     for i in range(R):
#         if board[i][0]:
#             board[i][0]-=1
#     # C-1열
#     for i in range(R):
#         if board[i][C-1]:
#             board[i][C-1]-=1
#
#
# def check_temperature():
#     cnt = 0
#     for y, x in check_rooms:
#         if board[y][x]>=K:
#             cnt+=1
#
#     if cnt == len(check_rooms):
#         return True
#     else:
#         return False
#
#
# # main
# R, C, K = map(int, input().split())
# check_rooms = []
# heater = []
# board = [[] for _ in range(R)]
# for i in range(R):
#     temp = list(map(int, input().split()))
#     for j in range(C):
#         board[i].append(0)
#
#         if 1<=temp[j]<=4:
#             heater.append([i, j, temp[j]])
#
#         elif temp[j] == 5:
#             check_rooms.append([i, j])
#
# wall_board = [[0]*C for _ in range(R)]
# W = int(input())
# # walls = [list(map(int, input().split())) for _ in range(W)] # y, x, t
# for _ in range(W):
#     y, x, t = map(int, input().split())
#
#     #  t == 0, (y, x)와 (y-1, x) 사이에 벽,
#     #  t == 1, (y, x)와 (y, x+1) 사이에 벽
#     wall_board[y][x] = 1
#     if t == 0:
#         wall_board[y-1][x] = 1
#     elif t == 1:
#         wall_board[y][x+1] = 1
#
#
# answer = 0
# while True:
#     # 모든 온풍기에서 바람이 한 번 나옴. 벽 고려할 것
#     heat_blow()
#
#     # 모든 인접한 칸에 대해서, 온도가 높은 칸에서 낮은 칸으로 ⌊(두 칸의 온도의 차이)/4⌋만큼 온도가 조절
#     board = temp_control()
#
#     # 온도가 1 이상인 가장 바깥쪽 칸의 온도가 1씩 감소
#     side_temp_control()
#
#
#     # 초콜릿 하나 먹는다.
#     answer+=1
#
#
#     # 조사하는 칸에 대해 모든 칸이 (board[i][j] == 5) 온도 K 이상인지 검사
#     # 모든 칸이 K 이사이면 테스트 중단
#     if check_temperature():
#         break
#


# https://westmino.tistory.com/136
import sys; input = sys.stdin.readline
from collections import deque

dy = (-1, 0, 1, 0)
dx = (0, 1, 0, -1)


def check_targets():
    for y, x in targets:
        if temperature[y][x][0]<K:
            return False
    return True


def set_temperature():
    # temperature[y][x][0]: 현재 칸의 온도
    # temperature[y][x][1]: 현재 칸에 들어온 온도
    # temperature[y][x][2]: 현재 칸에서 나간 온도

    for y in range(R):
        for x in range(C):
            if temperature[y][x][0] == 0:
                continue
            for d in range(4):
                ny = y + dy[d]
                nx = x + dx[d]
                if point_validator(ny, nx, (d+2)%4, False) and temperature[y][x][0] > temperature[ny][nx][0]:
                    temperature[ny][nx][1] += (temperature[y][x][0] - temperature[ny][nx][0])//4
                    temperature[y][x][2] += (temperature[y][x][0] - temperature[ny][nx][0])//4

    for y in range(R):
        for x in range(C):
            temperature[y][x][0] += temperature[y][x][1] - temperature[y][x][2]
            temperature[y][x][1] = temperature[y][x][2] = 0

    for y in range(R):
        for x in range(C):
            if y == 0 or x == 0 or y==R-1 or x == C-1:
                if temperature[y][x][0]>0:
                    temperature[y][x][0] -= 1


def spread_heat():
    global visited_num

    for sy, sx, typ in heaters:
        visited_num += 1
        sy += dy[typ]
        sx += dx[typ]

        q = deque([(sy, sx)])
        visited[sy][sx] = visited_num

        temperature[sy][sx][0] += 5

        for amount in range(4, 0, -1):
            if not q:
                break

            # 무한정이 아니라 한 턴에 대해서만 확장해야 하기 때문
            # while q: (X) // for idx in range(q_len) (O)
            q_len = len(q)
            for idx in range(q_len):  
                y, x = q.popleft()
                
                # 가는 방향의 45도 대각
                ny = y + dy[typ] + dy[(typ-1)%4]
                nx = x + dx[typ] + dx[(typ-1)%4]
                if point_validator(ny, nx, (typ+2)%4) and not wall_board[y][x][(typ-1)%4]:
                    temperature[ny][nx][0] += amount
                    visited[ny][nx] = visited_num
                    q.append((ny, nx))
                
                # 가는 방향
                ny = y + dy[typ]
                nx = x + dx[typ]
                if point_validator(ny, nx, (typ+2)%4):
                    temperature[ny][nx][0] += amount
                    visited[ny][nx] = visited_num
                    q.append((ny, nx))

                # 가는 방향의 반대 45도 대각
                ny = y + dy[typ] + dy[(typ+1)%4]
                nx = x + dx[typ] + dx[(typ+1)%4]
                if point_validator(ny, nx, (typ+2)%4) and not wall_board[y][x][(typ+1)%4]:
                    temperature[ny][nx][0] += amount
                    visited[ny][nx] = visited_num
                    q.append((ny, nx))


def point_validator(y, x, typ, flag=True):
    if y<0 or x<0 or y>=R or x>=C:
        return False
    elif wall_board[y][x][typ]:
        return False
    elif flag and visited[y][x] == visited_num:
        return False
    return True


# main
R, C, K = map(int, input().split())
temperature = [[[0, 0, 0] for _ in range(C)] for _ in range(R)]
visited = [[0]*C for _ in range(R)]
visited_num = 0

targets = []
heaters = []
for y in range(R):
    tmp = list(map(int, input().split()))
    for x in range(C):
        if tmp[x] == 5:
            targets.append((y, x))
        elif tmp[x]>0:
            if tmp[x] == 1:
                typ = 1
            elif tmp[x] == 2:
                typ = 3
            elif tmp[x] == 3:
                typ = 0
            else:
                typ = 2
            heaters.append((y, x, typ))

W = int(input())
wall_board = [[[False]*4 for _ in range(C)] for _ in range(R)]
for _ in range(W):
    y, x, t = map(int, input().split())
    y-=1
    x-=1
    if t == 0:
        wall_board[y][x][0] = wall_board[y-1][x][2] = True
    else:
        wall_board[y][x][1] = wall_board[y][x+1][3] = True

answer = 0
while True:
    spread_heat()
    set_temperature()
    answer += 1

    if check_targets():
        print(answer)
        break

    if answer == 100:
        print(101)
        break