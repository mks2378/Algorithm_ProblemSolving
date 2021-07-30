# 미세먼지 안녕! (BOJ_17144)

import sys

input = sys.stdin.readline
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

H, W, T = map(int, input().split())
board = []
cleaner = []
for i in range(H):
    board.append(list(map(int, input().split())))
    for j in range(W):
        if board[i][j] == -1:
            cleaner.append((i, j))

cln1_y, cln1_x = cleaner[0][0], cleaner[0][1]
cln2_y, cln2_x = cleaner[1][0], cleaner[1][1]
for t in range(T):
    temp_board = [[0 for _ in range(W)] for _ in range(H)]

    # 미세먼지 확산
    for i in range(H):
        for j in range(W):
            cur_y = i
            cur_x = j

            # 먼지가 존재하는 위치에 대해서 먼지 확산 연산
            if board[i][j] > 0:
                time = 0

                for k in range(4):
                    ny = cur_y + dy[k]
                    nx = cur_x + dx[k]

                    if ny < 0 or ny >= H or nx < 0 or nx >= W: continue
                    if ny == cleaner[0][0] and nx == cleaner[0][1]: continue
                    if ny == cleaner[1][0] and nx == cleaner[1][1]: continue
                    else:
                        transfer = board[cur_y][cur_x] // 5
                        temp_board[ny][nx] += transfer
                        time += 1
                temp_board[cur_y][cur_x] += board[cur_y][cur_x] - transfer * time

    # 공기청정기 작동
    for i in range(H):
        for j in range(W):
            # cleaner_1
            if i == cln1_y and 0 <= j < W-1:
                ny = i
                nx = j + 1
                if ny == cln1_y and nx == cln1_x: continue
                else:
                    board[ny][nx] = temp_board[i][j]
            elif 0 < i <= cln1_y and j == W-1:
                ny = i-1
                nx = j
                board[ny][nx] = temp_board[i][j]
            elif i == 0 and 0 < j <= W-1:
                ny = i
                nx = j-1
                board[ny][nx] = temp_board[i][j]
            elif 0 <= i < cln1_y and j == 0:
                ny = i+1
                nx = j
                if ny == cln1_y and nx == cln1_x: continue
                else:
                    board[ny][nx] = temp_board[i][j]
            # cleaner 2
            elif i == cln2_y and 0 <= j < W-1:
                ny = i
                nx = j + 1
                if ny == cln2_y and nx == cln2_x: continue
                else:
                    board[ny][nx] = temp_board[i][j]
            elif cln2_y <= i < H-1 and j == W-1:
                ny = i+1
                nx = j
                board[ny][nx] = temp_board[i][j]
            elif i == H-1 and 0 < j <= W-1:
                ny = i
                nx = j-1
                board[ny][nx] = temp_board[i][j]
            elif cln2_y < i <= H-1 and j == 0:
                ny = i-1
                nx = j
                if ny == cln2_y and nx == cln2_x: continue
                else:
                    board[ny][nx] = temp_board[i][j]
            else:
                board[i][j] = temp_board[i][j]

total = 0
for i in range(H):
    for j in range(W):
        if board[i][j] > 0:
            total += board[i][j]
print(total)