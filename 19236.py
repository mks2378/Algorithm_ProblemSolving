"""
청소년 상어는 (0, 0)에 있는 물고기 먹고, 거기에 들어간다. 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다.

이후에 물고기는 번호가 작은 물고기부터 순서대로 이동.
    - 물고기는 한 칸을 이동할 수 있고, 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸
    - 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸
    - 각 물고기는 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다
    - 이동할 수 있는 칸이 없으면 이동하지 않는다.
    - 그 외의 경우에는 그 칸으로 이동.
    - 물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식으로 이동    
    
물고기의 이동이 모두 끝나면 상어가 이동한다.
    - 상어는 방향에 있는 칸으로 이동할 수 있는데, 한 번에 여러 개의 칸을 이동할 수 있다. 
    - 상어가 물고기가 있는 칸으로 이동했다면, 그 칸에 있는 물고기를 먹고, 그 물고기의 방향을 가지게 된다.
    - 이동하는 중에 지나가는 칸에 있는 물고기는 먹지 않는다.
    - 물고기가 없는 칸으로는 이동할 수 없다
    - 상어가 이동할 수 있는 칸이 없으면 공간에서 벗어나 집으로 간다. 
    
상어가 먹을 수 이쓴 물고기 번호의 합의 최댓값
"""


"""
구현 익힐 부분
- 각 물고기는 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다
"""


# import sys; input = sys.stdin.readline
# 
# 
# dy = [-1, -1, 0, 1, 1, 1, 0, -1]
# dx = [0, -1, -1, -1, 0, 1, 1, 1]
# 
# 
# # function
# def fish_move(fishes, board):
#     # for fish in fishes: # 번호, 방향, y, x
#     for i in range(16):  # 번호, 방향, y, x
#         fish = fishes[i]
#         print('fish: ', fish)
#         print('i: ', i)
#         if fish:
#             num, dir, cy, cx = fish
# 
#             for k in range(dir, dir+8):
#                 k = k%8
# 
#                 ny = cy + dy[k]
#                 nx = cx + dx[k]
# 
#                 if 0<=ny<4 and 0<=nx<4 and board[ny][nx]!=-1:
#                     temp = board[ny][nx]
#                     print('temp: ', temp)
#                     print('len(fishes): ', len(fishes))
#                     board[ny][nx] = board[cy][cx]
#                     board[cy][cx] = board[ny][nx]
# 
#                     fishes[temp-1][2] = cy
#                     fishes[temp-1][3] = cx
# 
#                     fishes[num-1][2] = ny
#                     fishes[num-1][3] = nx
# 
#                     break
# 
#         if i==15:
#             break
# 
#     return fishes, board
# 
# 
# def shark_move(shark):
#     global shark_exist
# 
# # [[0, 0], 0]  # 위치정보, 방향정보
#     cy, cx = shark[0]
#     dir = shark[1]
# 
#     i=1
#     max_num = 0
#     my, mx = 0, 0
#     while True:
#         ny = cy + dy[dir]*i
#         nx = cx + dy[dir]*i
# 
#         if 0<=ny<4 and 0<=nx<4:
#             if board[ny][nx]>max_num:
#                 my, mx = ny, nx
#                 max_num = board[ny][nx]
#             i += 1
#         else:
#             break
# 
#     if max_num == 0:
#         shark_exist = False
#     else:
#         shark[0] = [my, mx]
#         shark[1] = fish_info[max_num-1][1]
#         board[cy][cx] = 0
#         board[my][mx] = -1
#         del fish_info[max_num-1]
# 
#     return shark, max_num
# 
# 
# # MAIN
# fish_info = []
# board = [[] for _ in range(4)]
# for i in range(4):
#     temp = list(map(int, input().split()))
# 
#     for j in range(4):
#         board[i].append(temp[j*2])
# 
#         fish_info.append([temp[j*2], temp[j*2+1]-1, i, j])  # 번호, 방향, y, x
# 
# shark = [[0, 0], 0]  # 위치정보, 방향정보
# 
# fish_info.sort()
# 
# # print(board)
# # print(fish_info)
# 
# init_num = board[0][0]
# shark[1] = fish_info[init_num-1][1]
# board[0][0] = -1  # 상어
# fish_info[init_num-1].clear()
# 
# shark_exist = True
# answer = 0
# while shark:
#     # 물고기 작은 번호부터 이동
#     # board = fish_move(board)
#     fish_info, board = fish_move(fish_info, board)
# 
# 
#     # 상어 이동. 이동할 수 없으면 loop 끝
#     shark, num = shark_move(shark)
# 
#     answer+=num
# 
# print(answer)


import sys; input=sys.stdin.readline
from copy import deepcopy

dir = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]
tank = []
answer = 0

def move_fish(copy_tank, num, shark_r, shark_c):  # 모든 물고기의 이동
    for r in range(4):
        for c in range(4):
            if copy_tank[r][c][0] == num:
                while True:
                    nr = r + dir[copy_tank[r][c][1]][0]
                    nc = c + dir[copy_tank[r][c][1]][1]
                    if 0<=nr<4 and 0<=nc<4:  # 조건1: 4x4 배열 안의 범위
                        if not (nr==shark_r and nc == shark_c): # 조건2: 상어가 존재하지 않는 칸
                            copy_tank[r][c], copy_tank[nr][nc] = copy_tank[nr][nc], copy_tank[r][c]
                            return
                    copy_tank[r][c][1] = (copy_tank[r][c][1]+1)%8


def recursive(tank, shark_r, shark_c, eat):  # DFS + 재귀 통해 답 도출
    global answer
    # 깊은 복사를 안하게 되면 recursive 내 연산결과들이 이전 recursive에 반영된 채로 다음 recursive 연산이 진행되어 영향을 주기 때문.
    copy_tank = deepcopy(tank)
    eat += copy_tank[shark_r][shark_c][0]
    copy_tank[shark_r][shark_c][0] = 0
    for num in range(1, 17):
        move_fish(copy_tank, num, shark_r, shark_c)

    if answer<eat:
        answer = max(answer, eat)

    for m in range(1, 4):  # 상어가 먹을 수 있는 물고기가 있다면 다음 재귀 진행
        n_shark_r = shark_r + (dir[copy_tank[shark_r][shark_c][1]][0]*m)
        n_shark_c = shark_c + (dir[copy_tank[shark_r][shark_c][1]][1]*m)
        if 0<=n_shark_r<4 and 0<=n_shark_c<4 and copy_tank[n_shark_r][n_shark_c][0]:
            recursive(copy_tank, n_shark_r, n_shark_c, eat)


for r in range(4):
    n1, d1, n2, d2, n3, d3, n4, d4 = map(int, input().split())
    before = [[n1, d1-1], [n2, d2-1], [n3, d3-1], [n4, d4-1]]
    tank.append(before)

recursive(tank, 0, 0, 0)
print(answer)