# # 15:52
#
# """
# 각 상어는 1~M이하 자연수 번호. 모든 번호 다르다.
# 1번 상어가 가장 강력하여 나머지 상어 모두 쫓아낼 수 있다.
#
# NxN 격자 M개의 칸에 상어 한마리씩 초기화. 상어가 맨 처음 보고 있는 방향은 입력으로 주어진다.
# 1. 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동
#     - 각 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 뱡향으로 이동. 그런 칸이 없으면 자신의 냄새가 있는 칸의 뱡향으로 이동 (이때 가능한 칸이 여러 개일 경우, 특정한 우선순위를 따른다. 우선순위는 상어마다 다르다.) 방금 이동한 방향이 보고 있는 방향.
#
# 2. 자신의 냄새를 칸에 뿌린다.
# 3. 냄새는 상어가 k번 이동하고 나면 사라진다.
#
# [입력]
# 0 빈칸, x는 x번 상어
#
# - N, M, k
# - board 값
# - 각 상어의 방향
# - 상어별 우선순위
# 1 위, 2 아래, 3 왼쪽, 4 오른쪽
# 1행: 위 향할 때 우선순위
# 2행: 아래 향할 때 우선순위
# 3행: 왼쪽 향할 때 우선순위
# 4행: 오른쪽 향할 때의 우선순위
# """
#
# from collections import deque
# import sys
# input = sys.stdin.readline
#
#
#
# """
# NxN 격자 M개의 칸에 상어 한마리씩 초기화. 상어가 맨 처음 보고 있는 방향은 입력으로 주어진다.
# 1. 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동
#     - 각 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 뱡향으로 이동. 그런 칸이 없으면 자신의 냄새가 있는 칸의 뱡향으로 이동 (이때 가능한 칸이 여러 개일 경우, 특정한 우선순위를 따른다. 우선순위는 상어마다 다르다.) 방금 이동한 방향이 보고 있는 방향.
#
# 2. 자신의 냄새를 칸에 뿌린다.
# """
# # 1 위, 2 아래, 3 왼쪽, 4 오른쪽
# def move_shark(y, x, dir, num):
# # priority_dirs = [[], [[위...], [아래...], [왼...], [오른...]], [...], ...]
#
#     priority_d = priority_dirs[num][dir]
#     for d in priority_d:
#         if d == 1:
#             if 0<=y-1<N:
#                 if board[y-1][x] == 0:
#                     board[y-1][x] = num
#                     board[y][x] = -K
#                 elif board[y-1][x]>num:
#                     board[y][x] = -K
#                 elif 0<board[y-1][x]<num:
#                     board[y-1][x] = num
#                     board[y][x] = -K
#                 elif board[y-1][x]<0: #  board의 각 좌표에 상어num과 냄새 존재해야 해
#                     continue
#             else:
#                 continue
#         elif d == 2:
#             if 0<=y+1<N:
#                 if board[y+1][x] == 0:
#                     board[y+1][x] = num
#                     board[y][x] = -K
#                 elif board[y+1][x]>num:
#                     board[y][x] = -K
#                 elif 0<board[y+1][x]<num:
#                     board[y+1][x] = num
#                     board[y][x] = -K
#                 elif board[y+1][x]<0:
#                     continue
#         elif d == 3:
#             if 0<=x-1<N:
#                 if board[y][x-1] == 0:
#                     board[y][x-1] = num
#                     board[y][x] = -K
#                 elif board[y][x-1]>num:
#                     board[y][x] = -K
#                 elif 0<board[y][x-1]<num:
#                     board[y][x-1] = num
#                     board[y][x] = -K
#                 elif board[y][x-1]<0:
#                     continue
#         elif d == 4:
#             if 0<=x+1<N:
#                 if board[y][x+1] == 0:
#                     board[y][x+1] = num
#                     board[y][x] = -K
#                 elif board[y][x+1]>num:
#                     board[y][x] = -K
#                 elif 0<board[y][x+1]<num:
#                     board[y][x+1] = num
#                     board[y][x] = -K
#                 elif board[y][x+1]<0:
#                     continue
#
#
#
#
# def bfs():
#     global time
#
#     q = deque()
#     for i in range(1, M+1):
#         sharks_info[i].append(i)
#         sharks_info[i].append(time)
#         q.append(sharks_info[i])  # y, x, dir, shark_num, time
#
#     while q:
#         c_y, c_x, c_dir, c_num, c_time = q.popleft()
#
#         move_shark(c_y, c_x, c_dir, c_num)
#
#
#
# # main
# sharks_info = {}
# N, M, K = map(int, input().split())
# board = []
# for i in range(N):
#     temp_data = list(int, input().split())
#     for j in range(N):
#         if 0<temp_data[j]:
#             sharks_info[temp_data[j]] = [i, j]  # y, x
#
# directions = list(map(int, input().split()))
# for m, d in enumerate(directions):
#     sharks_info[m+1].append(d)  # y, x, dir
#
# priority_dirs = [[]].append([] for _ in range(M))  # 이거 되나?
# for m in range(4*M):
#     priority_dirs[m//4+1].append(list(map(int, input().split())))
#
# bfs()
# print(time)


# import sys
# input = sys.stdin.readline
#
# # 1 위, 2 아래, 3 왼쪽, 4 오른쪽
# dy = [-1, 1, 0, 0]
# dx = [0, 0, -1, 1]
#
#
# # 모든 냄새 정보 업데이트
# def update_smell():
#     for i in range(N):
#         for j in range(N):
#             # 냄새가 남아있는 경우
#             if smell_board[i][j][1]>0:
#                 smell_board[i][j][1]-=1
#             # 상어가 존재하는 위치의 경우
#             if data[i][j]!=0:
#                 smell_board[i][j] = [data[i][j], K]
#
#
# # 상어 이동
# def move():
#     new_data = [[0]*N for _ in range(N)]
#     for y in range(N):
#         for x in range(N):
#             if data[y][x]!=0:
#                 direction = directions[data[y][x]-1]
#                 found = False
#                 # 상어의 위치인 경우
#                 for idx in priorities[data[y][x]-1][direction-1]:
#                     ny = y + dy[idx-1]
#                     nx = x + dx[idx-1]
#                     if 0<=nx<N and 0<=ny<N:
#                         # smell_info (상어 번호, 냄새 머무는 시간)
#                         if smell_board[ny][nx][1] == 0:  # 냄새가 나지 않는 곳이라면
#                             directions[data[y][x]-1] = idx
#                             # 상어 이동
#                             if new_data[ny][nx] == 0:
#                                 new_data[ny][nx] = data[y][x]
#                             else:
#                                 new_data[ny][nx] = min(data[y][x], new_data[ny][nx])
#                             found = True
#                             break
#                 if found:
#                     continue
#
#                 # 주변에 모두 냄새가 남아있다면, 자신의 냄새가 있는 곳으로 이동
#                 for idx in priorities[data[y][x]-1][direction-1]:
#                     ny = y + dy[idx-1]
#                     nx = x + dx[idx-1]
#                     if 0<=nx<N and 0<=ny<N:
#                         # 자신의 냄새가 있는 곳이라면
#                         if smell_board[ny][nx][0] == data[y][x]:
#                             # 해당 상어 방향 변경
#                             directions[data[y][x]-1] = idx
#                             # 상어 이동시키기
#                             new_data[ny][nx] = data[y][x]
#                             break
#
#     return new_data
#
# # MAIN
# N, M, K = map(int, input().split())
#
# # 처음 상어 위치
# data = []
# for _ in range(N):
#     data.append(list(map(int, input().split())))
#
# shark = [[0, 0] for _ in range(M)]
#
# # 상어의 초기 방향 설정
# directions = list(map(int, input().split()))
#
# # 사엉의 방향별 우선순위 저장 (위 아래 왼쪽 오른쪽)
# priorities = []
# for i in range(M):
#     temp = []
#     for _ in range(4):
#         temp.append(list(map(int, input().split())))
#     priorities.append(temp)
#
# # 상환판 그리기 (상어번호, 냄새 머무는 시간)
# smell_board = [[[0, 0]] * N for _ in range(N)]
#
# answer = 0
# while True:
#     # 맨 처음에 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
#     update_smell()
#     data = move()
#     answer += 1
#
#     check = True
#     for i in range(N):
#         for j in range(N):
#             if data[i][j]>1:
#                 check = False
#
#     if check:
#         print(answer)
#         break
#
#     # 1000초가 지날 때까지 끝나지 않았다면
#     if answer>=1000:
#         print(-1)
#         break


# 복기
import sys
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def update_smell():
    for i in range(N):
        for j in range(N):
            # 냄새가 남아있는 경우
            if smell_board[i][j][1]>0:
                smell_board[i][j][1]-=1
            # 상어가 있는 경우
            if board[i][j]>0:
                smell_board[i][j] = [board[i][j], K]


def move():
    new_board = [[0]*N for _ in range(N)]
    for y in range(N):
        for x in range(N):
            # 임의의 상어가 (y,x) 칸에 있을 때
            if board[y][x]!=0:
                found = False
                direction = directions[board[y][x]-1]  # 상어의 현재 향하고 있는 방향
                for d in priorities[board[y][x]-1][direction-1]:
                    ny = y + dy[d-1]
                    nx = x + dx[d-1]

                    if 0<=ny<N and 0<=nx<N:
                        if smell_board[ny][nx][1] == 0:
                            directions[board[y][x]-1] = d

                            if new_board[ny][nx] == 0:
                                new_board[ny][nx] = board[y][x]
                            else:
                                new_board[ny][nx] = min(new_board[ny][nx], board[y][x])

                            found = True
                            break
                        else:
                            continue

                if found:
                    continue

                # 인접한 칸 모두에 방향이 있을 때
                for d in priorities[board[y][x] - 1][direction - 1]:
                    ny = y + dy[d-1]
                    nx = x + dx[d-1]

                    if 0<=ny<N and 0<=nx<N:
                        if smell_board[ny][nx][0] == board[y][x]:
                            directions[board[y][x]-1] = d
                            new_board[ny][nx] = board[y][x]
                            break

    return new_board


# MAIN
N, M, K = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

directions = list(map(int, input().split()))

priorities = []
for i in range(M):
    temp = []
    for j in range(4):
        temp.append(list(map(int, input().split())))
    priorities.append(temp)

# (상어 번호, 냄새 시간)
smell_board = [[[0, 0]]*N for _ in range(N)]

answer = 0
while True:
    update_smell()
    board = move()
    answer+=1

    check = True
    for i in range(N):
        for j in range(N):
            if board[i][j]>1:
                check = False

    if check:
        break

    if answer>1000:
        answer = -1
        break

print(answer)






