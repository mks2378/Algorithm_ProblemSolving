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
    # 임시 board를 새로 만들어서 기존 board의 값을 이용하여 각 위치에 대해서 먼지가 이동하는 것을 누적으로 축적 업데이트.
    temp_board = [[0 for _ in range(W)] for _ in range(H)]

    # 미세먼지 확산
    for i in range(H):
        for j in range(W):
            cur_y = i
            cur_x = j

            # 먼지가 존재하는 위치에 대해서 먼지 확산 연산
            if board[i][j] > 0:  # 먼지가 없는 위치, 청소기 위치 제외
                time = 0

                for k in range(4):
                    ny = cur_y + dy[k]
                    nx = cur_x + dx[k]

                    if ny < 0 or ny >= H or nx < 0 or nx >= W: continue  # board 벗어나는 위치 제외
                    if ny == cleaner[0][0] and nx == cleaner[0][1]: continue  # 청소기1 위치 제외
                    if ny == cleaner[1][0] and nx == cleaner[1][1]: continue  # 청소기2 위치 제외
                    else:
                        transfer = board[cur_y][cur_x] // 5  # 몫만 가져올시 // 연산자 이용
                        temp_board[ny][nx] += transfer  # 주변 위치로 일정량 먼지 이동
                        time += 1  # 현재 위치로부터 몇 개 방향으로 먼지가 이동했는지 카운트
                # temp_board[cur_y][cur_x] = board[cur_y][cur_x] - transfer * time // 처음에 연산된 값을 새로 대입하는 방식으로 기존의 값들이 지워지는 것을 캐치 못함.
                # 이 실수는 디버깅 통해서 찾음. board가 커도 번거로워하지 말고 디버깅해서 직접 확인해보자.
                temp_board[cur_y][cur_x] += board[cur_y][cur_x] - transfer * time

    # 공기청정기 작동  // 각 행, 열에 대해 공기청정기 위치에 따라 이동 방향에 맞게 이동시킨다.
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
            # 공기 청정기에 의해 이동하는 먼지 외에 이전에 먼지가 이동된 것을 board의 각 위치에서 값을 업데이트 해줘야하는 것을 생각하지 못함.
            else:
                board[i][j] = temp_board[i][j]

total = 0
for i in range(H):
    for j in range(W):
        if board[i][j] > 0:
            total += board[i][j]  # 총합 계산시, 청소기 위치 값까지 더해서 총합에서 -2 된 부분 실수
print(total)