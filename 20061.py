# 모노미노도미노 2

import sys; input = sys.stdin.readline

# 행 또는 열 끝으로 이동 중에 도형이 이미 있다면 움직이는 블록 전체가 그 도형 라인보다 하나 작은 행 또는 열에 위치하게끔 해야된다.
# 처음에 하나의 블록 포인트가 더 멀리 갈 수 있다면 끝가지 가도록 잘못 구현.
def block_move(cur_block):
    final_y, final_x = 9, 9
    for bt, by, bx in cur_block:
        # 열
        ry, rx = by, bx+1
        while True:
            if board[ry][rx] == 0:
                if rx == 9:
                    break
                else:
                    rx+=1
                    continue
            else:
                rx-=1
                final_x = min(final_x, rx)
                break

        cy, cx = by+1, bx
        while True:
            if board[cy][cx] == 0:
                if cy == 9:
                    break
                else:
                    cy+=1
                    continue
            else:
                cy-=1
                final_y = min(final_y, cy)
                break

    for bt, by, bx in cur_block:
        if bt == 1:
            board[final_y][bx] = 1
            board[by][final_x] = 1
        elif bt == 2:
            board[final_y][bx] = 1
            board[by][final_x] = 1
            final_x-=1
        elif bt == 3:
            board[by][final_x] = 1
            board[final_y][bx] = 1
            final_y-=1

    # 비어있는 공간이 있다면 끝까지 이동하도록 잘못 구현한 코드 (이동 후 블록이 깨진다.)
    # for cy, cx in cur_block:
    #     # 열
    #     ry, rx = cy, cx+1
    #     while True:
    #         if board[ry][rx] == 0:
    #             if rx == 9:
    #                 board[ry][rx] = 1  # 놓침
    #                 break
    #             else:
    #                 rx+=1
    #                 continue
    #         else:
    #             rx-=1
    #             board[ry][rx] = 1
    #             break
    #
    #     # 행
    #     cy+=1
    #     while True:
    #         if board[cy][cx] == 0:
    #             if cy == 9:
    #                 board[cy][cx] = 1  # 놓침
    #                 break
    #             else:
    #                 cy+=1
    #                 continue
    #         else:
    #             cy-=1
    #             board[cy][cx] = 1
    #             break


def check_full():
    # 행: 0~3, 열: 6, 7, 8, 9
    full_line = []
    for j in range(6, 10):
        cnt = 0
        for i in range(4):
            if board[i][j] == 1:
                cnt+=1

        if cnt == 4:
            full_line.append([0, j])

    # 행:6, 7, 8, 9 열: 0~3
    for i in range(6, 10):
        cnt = 0
        for j in range(4):
            if board[i][j] == 1:
                cnt+=1

        if cnt == 4:
            full_line.append([i, 0])

    # full_line.sort()는 리턴 없어서 리턴할 때 사용 못해.
    return sorted(full_line)


def check_shallow():
    lines = []
    for j in range(4, 6):
        cnt = 0
        for i in range(4):
            if board[i][j] == 1:
                cnt+=1

        if cnt>0:  # cnt == 4 로 생각함
            lines.append([0, j])

    for i in range(4, 6):
        cnt = 0
        for j in range(4):
            if board[i][j] == 1:
                cnt+=1

        if cnt>0:  # cnt == 4 로 생각함
            lines.append([i, 0])

    # return lines.sort()
    return sorted(lines)


def erase_lines(lines):
    for r, c in lines:
        # 깊은
        if r == 0 and 6<=c<=9:
            for i in range(4):
                board[i][c] = 0

            # board[0:4][]
            for j in range(c-1, 3, -1):
                for i in range(4):
                    board[i][j+1] = board[i][j]

            for i in range(4):
                board[i][4] = 0

        # 깊은
        elif c == 0 and 6<=r<=9:
            for j in range(4):
                board[r][j] = 0

            for i in range(r-1, 3, -1):
                for j in range(4):
                    board[i+1][j] = board[i][j]

            for j in range(4):
                board[4][j] = 0

        # 얕은
        elif r == 0 and 4 <= c <= 5:
            for i in range(4):
                board[i][9] = 0

            for j in range(8, 3, -1):
                for i in range(4):
                    board[i][j + 1] = board[i][j]

            for i in range(4):
                board[i][4] = 0

        # 얕은
        elif c == 0 and 4<=r<=5:
            for j in range(4):
                board[9][j] = 0

            for i in range(8, 3, -1):
                for j in range(4):
                    board[i+1][j] = board[i][j]

            for j in range(4):
                board[4][j] = 0


# 블록을 놓을 횟수 N
N = int(input())

# t y x
blocks = []
answer = 0
for _ in range(N):
    t, y, x = map(int, input().split())
    blocks.append([t, y, x])

board = [[0]*10 for _ in range(10)]
for t, y, x in blocks:
    cur_block = []
    if t == 1:
        cur_block.append([t, y, x])
    elif t == 2:
        cur_block.append([t, y, x + 1])
        cur_block.append([t, y, x])

    elif t == 3:
        cur_block.append([t, y + 1, x])
        cur_block.append([t, y, x])

    # 주어진 블락 좌, 우로 이동
    block_move(cur_block)

    # 행, 열이 다 찼는지 확인
    full_lines = check_full()

    # 다 찼으면 해당 행, 열 지우고 빈 자리까지 앞에 있는 도형들 이동
    if full_lines:
        answer += len(full_lines)
        erase_lines(full_lines)  # 없어진 행, 열 개수 만큼 점수 추가

    # 연한 칸에 도형 있는지 확인
    shallow_lines = check_shallow()

    # 있다면, 수만큼 끝 행 또는 열을 제거
    if shallow_lines:
        # answer += len(shallow_lines)  # 문제 똑바로 안읽어서 해당 조건에서도 점수 획득하는 것으로 판단 미스
        erase_lines(shallow_lines)  # 빈 자리까지 앞에 있는 도형들 이동

num_tiles = 0
for i in range(10):
    for j in range(10):
        if board[i][j]>0:
            num_tiles+=1

print(answer)
print(num_tiles)


# board = [[1, 2, 3, 4], [5, 6, 7, 8]]
# # board[:][2:] = board[:][0:2]
# print([row[1] for row in board])
# 좀 더 쉽게 못 할까??

# 보드 한쪽 끝으로 값 미는 기능 구현 연습