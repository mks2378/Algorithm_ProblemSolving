# import sys; input = sys.stdin.readline
#
# dy = [0, 0, -1, 1]
# dx = [1, -1, 0, 0]
#
#
# # function
# def move_horse(num, y, x, d):
#     global is_exit
#
#     # idx = board[y][x][:][0].index(num)
#     idx = [k[0] for k in board[y][x]].index(num)  # 현재 말이 몇 번째 순서인지
#
#     ny, nx = y + dy[d], x + dx[d]
#     if not (0 <= ny < N and 0 <= nx < N):
#         ty = y - dy[d]
#         tx = x - dx[d]
#
#         board[y][x][idx][1] = (d + 2) % 4
#         for n, dir in board[y][x][idx+1:]:
#             if n == num:
#                 horse[n] = [n, ty, tx, (d+2)%4]
#             else:
#                 horse[n] = [n, ty, tx, dir]
#
#         board[ty][tx] += board[y][x][idx:]
#         if len(board[ty][tx])>=4:
#             is_exit = True
#             return
#
#     color = color_board[ny][nx]
#     # 인덱스로 옮길 때 올라타고 있는 말들의 위치 좌표도 같이 변경해줘야 된다.
#     if color == 0:  # 흰색
#         board[ny][nx]+=board[y][x][idx:]
#         if len(board[ny][nx])>=4:
#             is_exit = True
#             return
#
#         for n, dir in board[y][x][idx:]:
#             horse[n] = [n, ny, nx, dir]
#         board[y][x][idx:].clear()
#
#     elif color == 1:  # 빨간색
#         # board[ny][nx].append(board[y][x][idx:][::-1])
#         board[ny][nx]+=board[y][x][idx:][::-1]
#         if len(board[ny][nx])>=4:
#             is_exit = True
#             return
#
#         for n, dir in board[y][x][idx:][::-1]:
#             horse[n] = [n, ny, nx, dir]
#         board[y][x][idx:].clear()
#
#     elif color == 2:  # 파란색
#         ty = y + dy[(d+2)%4]
#         tx = x + dx[(d+2)%4]
#
#         if not (0 <= ty < N and 0 <= tx < N):
#             board[y][x][idx][1] = (d + 2) % 4
#             horse[num] = [num, y, x, (d + 2) % 4]
#
#         else:
#             if color_board[ty][tx] == 2:
#                 board[y][x][idx][1] = (d+2)%4
#                 horse[num] = [num, y, x, (d+2)%4]
#
#             else:
#                 board[y][x][idx][1] = (d+2)%4
#                 # board[ty][tx].append(board[y][x][idx:])
#                 board[ty][tx]+=board[y][x][idx:]
#                 if len(board[ny][nx])>=4:
#                     is_exit = True
#                     return
#
#                 for n, dir in board[y][x][idx:]:
#                     horse[n] = [n, ty, tx, dir]
#
#                 board[y][x][idx:].clear()
#
#
# # main
# N, K = map(int, input().split())  # 게임판 크기, 사용말 개수
# color_board = [list(map(int, input().split())) for _ in range(N)]
#
# board = [[[] for _ in range(N)] for _ in range(N)]
# horse = []
# for i in range(N):
#     tmp = list(map(lambda x: int(x)-1, input().split()))
#     horse.append([i]+tmp)
#     board[tmp[0]][tmp[1]].append([i, tmp[2]])  # 말 번호, 방향
#
# turn = 0
# is_exit = False
# while True:
#     turn += 1
#     for i, y, x, d in horse:
#         move_horse(i, y, x, d)
#
#         if is_exit:
#             break
#
#     if is_exit:
#         break
#
#     if not board or turn == 1000:
#         break
#
# if is_exit:
#     print(turn)
# else:
#     print(-1)

# 리스트 내 역순으로 만들기
# board 각 위치가 list로 구성
# list.index -> 원소가 리스트로 이루어진 리스트 내에서
# 리스트 합치기 +, append, extend 차이
# for문에 돌아가는 리스트를 for문 돌아가는 중에 바꾸면?

# horse = [[3, 4, 5], [6, 7, 8]]
# for i, [a, b, c] in enumerate(horse):
#     print(i, a, b, c)

# ls = [[0,2], [1,4], [2,6], [3,8]]
# for a, b in ls:
#     ls[a][1] = 3
#     print(ls[a][1])

# board[ny][nx]+=board[y][x][idx:]
# 배열 요소가 리스트로 구성되어 있을 때 + 연산으로 붙여야 된다.
# append로 할 시에 차원이 늘어나서 추가된다.


import sys; input = sys.stdin.readline


dy = (0, 0, -1, 1)
dx = (1, -1, 0, 0)


def move_horses():
    t = 1
    while True:
        if t>1000:
            return -1
        for i in range(K):
            y, x, d = horses[i]
            ny = y + dy[d]
            nx = x + dx[d]

            # 파란색이거나 영역 밖
            if not (0<=ny<N and 0<=nx<N) or color_board[ny][nx] == 2:
                d ^= 1
                ny = y + dy[d]
                nx = x + dx[d]

                # 아래와 같이 하면 이 때의 좌표에 대해서는 반대 방향이지만, 아래에
                # horses 리스트에 방향이 바뀌지 않고 원래 방향으로 들어가게 된다.
                # 놓치기 쉬운 부분!!
                # ny = y - dy[d]
                # nx = x - dx[d]
                if not (0<=ny<N and 0<=nx<N) or color_board[ny][nx] == 2:
                    ny = y
                    nx = x
            horses[i] = [ny, nx, d]
            if ny == y and nx == x:
                continue

            # 옮긴 뒤의 색이 하얀색
            idx = horse_board[y][x].index(i)
            for p in horse_board[y][x][idx+1:]:
                horses[p][0] = ny
                horses[p][1] = nx
            if color_board[ny][nx] == 0:
                horse_board[ny][nx] += horse_board[y][x][idx:]

            # 옮긴 뒤에 색이 빨간색
            elif color_board[ny][nx] == 1:
                horse_board[ny][nx] += horse_board[y][x][idx:][::-1]

            # 떼어나가고 남은 나머지로 업데이트 (생각할 것)
            horse_board[y][x] = horse_board[y][x][:idx]
            if len(horse_board[ny][nx])>3:
                return t

        t += 1


# MAIN
N, K = map(int, input().split())
color_board = [list(map(int, input().split())) for _ in range(N)]

horses = []
horse_board = [[[] for _ in range(N)] for _ in range(N)]
for i in range(K):
    y, x, d = map(int, input().split())
    horses.append([y-1, x-1, d-1])
    horse_board[y-1][x-1].append(i)

ans = move_horses()
print(ans)


# b = []
# a = [[1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6]]
# b += a[1][3:]  # slicing 연산은 원본 리스트에서 복사 수행
# a[1][3:].clear()  # clear는 일부분만 제거 안된다.
# print(b)
# print(a)