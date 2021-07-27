# 삼성 SW 역량테스트 기출
# 연구소

# 14:21~ 15:40
# Fail

# import sys
# from collections import deque
#
# def bfs():
#     dy = [0, 0, 1, -1]
#     dx = [1, -1, 0, 0]
#
#     queue = deque(lives)
#     while queue:
#         kind, cur_y, cur_x, time = queue.popleft()
#
#         if kind == 2:
#             for i in range(4):
#                 new_y = cur_y + dy[i]
#                 new_x = cur_x + dx[i]
#
#                 if board[new_y][new_x] == 1 or 2: continue
#                 if board[new_y][new_x] == 0 or 3:
#                     board[new_y][new_x] = 2
#                     queue.append((2, new_y, new_x, time + 1))
#
# # 탈출 -> 최소시간 / 바이러스 감염 -> 'ZOMBIE' / 탈출불가, but 좀비 x -> 'CANNOT ESCAPE'
#         if kind == 3:
#             virus_meet = False
#             space_meet = False
#             for i in range(4):
#                 new_y = cur_y + dy[i]
#                 new_x = cur_x + dx[i]
#
#                 if new_y>=N or new_y<0 or new_x>=M or new_x<0:
#                     return time+1
#
#                 if board[new_y][new_x] == 1 or 3: continue
#                 if board[new_y][new_x] == 2:
#                     virus_meet = True
#                 if board[new_y][new_x] == 0:
#                     space_meet = True
#                     board[new_y][new_x] = 3
#                     queue.append((3, new_y, new_x, time+1))
#
#             if virus_meet and not space_meet:
#                 return "ZOMBIE"
#             if not virus_meet and space_meet:
#                 return "CANNOT ESCAPE"
#
#
# # 0: 빈공간 / 1: 벽 / 2: 바이러스 / 3: 삼성이
# input = sys.stdin.readline
# T = int(input())
#
# lives = []
# for _ in range(T):
#     N, M = map(int, input().split())
#
#     board = []
#     for i in range(N):
#         board.append(list(map(int, input().split())))
#         for j in range(M):
#             if board[i][j] == 2:
#                 lives.append((2, i, j, 0))
#             if board[i][j] == 3:
#                 lives.append((3, i, j, 0))
#
#     lives.sort(reverse=True)
#     print(bfs())


"""
BFS를 서로 번걸아가면서 푸는 것이 포인트.
사람이 움직이고, 바이러스를 움직이면서 탈출 여부를 판단.
사람이 맵의 끝자리에 있으면 탈출할 수 있다. (단, 그 자리가 탈추라기 직전에 바이러스에게 먹히면 안된다.)
탈출하지 못하면, 전체 맵을 탐색하면서 사람이 남아있는지를 파악한다. (맵에 3의 존재 여부 확인)
3이 존재한다면, 좀비는 되지 않았지만 탈출할 수 없는 구조이기 때문에 CANNOT ESCAPE를 출력.
"""

# solution
import sys
from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

input = sys.stdin.readline
tc = int(input())

s = deque()
v = deque()
for t in range(tc):
    N, M = map(int, input().split())

    board = []
    for i in range(N):
        board.append(list(map(int, input().split())))
        for j in range(M):
            if board[i][j] == 2:
                v.append((i, j))
            elif board[i][j] == 3:
                s.append((i, j))

    dist = [[0 for _ in range(M)] for _ in range(N)]  # 시간 기록 + 방문 체크
    escape = False
    ey, ex = None, None  # 탈출 직전 보더라인 위치

    # 사람이 먼저 움직이고, 바이러스가 그 다음에 움직이고 -> BFS 이용
    # 삼성이와 바이러스의 큐가 모두 빌 때까지
    while s or v:
        s_size = len(s)
        v_size = len(v)

        # 사람이 움직이는 BFS
        for i in range(s_size):
            y, x = s.popleft()

            # 탈출에 성공하는 경우
            # 사람이 움직이고 바이러스가 움직이기 때문에 사람에 대해서 체크할 때,
            # 이전 턴에서 바이러스가 해당 자리를 먹었는지 확인해야 한다.
            if (y == 0 or y == N-1 or x == 0 or x == M-1) and board[y][x] != 2:
                ey = y
                ex = x
                escape = True
                break

            for j in range(4):
                ny = y + dy[j]
                nx = x + dx[j]

                if 0 <= nx <M and 0 <= ny < N and dist[ny][nx] == 0 and board[ny][nx] == 0:
                    board[ny][nx] = 3
                    dist[ny][nx] = dist[y][x] + 1
                    s.append((ny, nx))

        if escape:
            break

        # 바이러스가 움직이는 BFS
        for i in range(v_size):
            y, x = v.popleft()

            for j in range(4):
                ny = y + dy[j]
                nx = x + dx[j]

                if 0 <= nx < M and 0 <= ny < N and board[ny][nx] != 1 and board[ny][nx] != 2:
                    board[ny][nx] = 2
                    dist[ny][nx] = dist[y][x] + 1
                    v.append((ny, nx))

    # 탈출했을 때
    if escape:
        print("#"+str(t), dist[ey][ex]+1)
    # 탈출하지 못했을 때
    else:
        zombie = True
        for i in range(N):
            for j in range(M):
                if board[i][j] == 3:
                    zombie = False

        if zombie:
            print("#"+str(t), "ZOMBIE")
        else:
            print("#"+str(t), "CANNOT ESCAPE")
