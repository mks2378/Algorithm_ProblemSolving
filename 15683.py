# 16:46

"""
0: 빈 칸
1: 우
2: 좌, 우
3: 상, 우
4: 상, 좌, 우
5: 상, 하, 좌, 우
6: 벽
#: CCTV가 감시할 수 있는 영역

사각지대: CCTV가 감시할 수 없는 영역 (= # 영역 최대로 구하고 남은 0 영역)

각 CCTV의 감시 방향에 따라 감시 영역이 달라질 수 있다.
CCTV는 CCTV 통과 가능.
"""

# import sys
# input = sys.stdin.readline
#
#
# def check_cctv_area(i, j, dir):
#     pass
#
#
#
#
# # main
# dir = [0, 1, 2, 3]  # 동, 서, 남, 북
#
# N, M = map(int, input().split())
# board = []
# cctv = []
# unseen_area = []
# cnt = 1
# for i in range(N):
#     temp = list(map(int, input().split()))
#     board.append(temp)
#     for j, element in enumerate(temp):
#         if 1<=element<=5:
#             cctv.append([i, j, element, 1])
#             if element == 1:
#                 cnt *= 4
#             elif element == 2:
#                 cnt *= 2
#             elif element == 3:
#                 cnt *= 4
#             elif element == 4:
#                 cnt *= 4
#             elif element == 5:
#                 check_cctv_area(board, 5, 1)
#
# # 1 - 4가지 /2 - 2가지 / 3 - 4가지 / 4 - 4가지 / 5 - 1가지
# for _ in range(cnt):
#     new_board = board.copy()
#     new_cctv = []
#
#     for cc in cctv:
#         cy, cx, cc_num, direction = cc
#
#         check_cctv_area(new_board, cc_num, direction)
#
#         if cc_num == 1 and direction+1<=4:
#             new_cctv.append([cy, cx, cc_num, direction+1])
#         if cc_num == 2 and direction+1<=2:
#             new_cctv.append([cy, cx, cc_num, direction+1])
#         if cc_num == 1 and direction+1<=4:
#             new_cctv.append([cy, cx, cc_num, direction+1])
#         if cc_num == 1 and direction+1<=4:
#             new_cctv.append([cy, cx, cc_num, direction+1])

# import sys
# import copy
# input = sys.stdin.readline
# INF = int(1e9)
#
# # 동 서 남 북
# dy = [0, 0, 1, -1]
# dx = [1, -1, 0, 0]
# direction = [[], [[0], [1], [2], [3]], [[0, 1], [2, 3]], [[0, 2], [2, 1], [1, 3], [3, 0]], [[3, 0, 2], [1, 3, 0], [0, 2, 1], [2, 1, 3]], [[0, 1, 2, 3]]]
#
#
# def watch(y, x, direction, tmp):
#     for d in direction:
#         ny = y
#         nx = x
#         while True:
#             ny+=dy[d]
#             nx+=dx[d]
#             if 0<=nx<M and 0<=ny<N and tmp[ny][nx]!=6:
#                 if tmp[ny][nx] == 0:
#                     tmp[ny][nx] = '#'
#             else:
#                 break
#
#
# def dfs(office, cnt):
#     global ans
#
#     tmp = copy.deepcopy(office)
#     if cnt == cctv_cnt:
#         c = 0
#         for i in tmp:
#             c+=i.count(0)
#         ans = min(ans, c)
#         print('tmp: ', tmp)
#         return
#
#     y, x, cctv = q[cnt]
#     for i in direction[cctv]:
#         watch(y, x, i, tmp)
#         dfs(tmp, cnt+1)
#         tmp = copy.deepcopy(office)
#
#
# # main
# N, M = map(int, input().split())
# board = []
# cctv_cnt = 0
# q = []
# ans = INF
# for i in range(N):
#     temp_data = list(map(int, input().split()))
#     board.append(temp_data)
#     for j in range(len(temp_data)):
#         if temp_data[j]!=0 and temp_data[j]!=6:
#             cctv_cnt+=1
#             q.append([i, j, temp_data[j]]) # CCTV의 y, x, number
#
# dfs(board, 0)
# print(ans)




"""
0: 빈 칸
1: 우
2: 좌, 우
3: 상, 우
4: 상, 좌, 우
5: 상, 하, 좌, 우
6: 벽
#: CCTV가 감시할 수 있는 영역

사각지대: CCTV가 감시할 수 없는 영역 (= # 영역 최대로 구하고 남은 0 영역)

각 CCTV의 감시 방향에 따라 감시 영역이 달라질 수 있다.
CCTV는 CCTV 통과 가능.
"""


import copy
import sys
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]
# 0:북, 1:서, 2:남, 3:동
direction = [[], [[0], [1], [2], [3]], [[1, 3], [0, 2]], [[0, 1], [1, 2], [2, 3], [3, 0]], [[0, 1, 3], [0, 1, 2], [1, 2, 3], [0, 2, 3]], [[0, 1, 2, 3]]]


def check_cctv_area(y, x, direction, tmp):
    for dir in direction:
        ny, nx = y, x
        # print('dir: ', dir)
        while True:
            ny += dy[dir]
            nx += dx[dir]
            # print('ny, nx: ', ny, nx)
            if 0<=ny<N and 0<=nx<M and tmp[ny][nx]!=6:
                if tmp[ny][nx]==0:
                    tmp[ny][nx] = '#'
            else:
                break


def dfs(cnt, board):
    global ans

    tmp = copy.deepcopy(board)
    if cnt == cctv_cnt:
        cctv_area = 0
        for row in tmp:
            cctv_area += row.count(0)
        ans = min(ans, cctv_area)
        print(board)
        return

    # print('cnt: ', cnt)
    cy, cx, cctv = cctv_info[cnt]
    for i in direction[cctv]:
        check_cctv_area(cy, cx, i, tmp)
        dfs(cnt+1, tmp)
        tmp = copy.deepcopy(board)


# main
INF = int(1e9)
ans = INF

cctv_cnt = 0
cctv_info = []

N, M = map(int, input().split())
board = []
for i in range(N):
    temp_data = list(map(int, input().split()))
    board.append(temp_data)
    for j in range(M):
        if 1<=temp_data[j]<=5:
            cctv_info.append([i, j, temp_data[j]])
            cctv_cnt+=1

dfs(0, board)
print(ans)