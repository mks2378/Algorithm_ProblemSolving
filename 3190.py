# 2h 30

"""
사과를 먹으면 뱀 길이가 늘어난다.
뱀이 '벽' 또는 '자기자신의 몸'과 부딪히면 게임 끝

게임 시작 시, 뱀은 맨위 맨좌측에 위치.
뱀의 길이는 1
뱀은 처음에 오른쪽을 향한다.
"""
"""
뱀이 '벽' 또는 '자기자신의 몸'과 부딪히면 게임 끝
먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킴.
만약 이동한 칸에 사과 있다면, 그 칸에 사과 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸 길이를 줄여서 꼬리가 위치한 칸을 비운다. (몸 길이 변화x)
"""
"""
사과의 위치 그리고 이동경로가 주어질 때 게임이 몇 초에 끝나는지 계산.

사과의 위치는 모두 다르며, 맨 위 맨 좌측(1행1열)에는 사과 없다.

L: 왼, R: 오른 90도 회전
X는 증가하는 순으로 주어진다.
"""

import sys
from collections import deque
input = sys.stdin.readline


N = int(input())  # 보드 크기
K = int(input())  # 사과 개수
apple_pos = [list(map(int, input().split())) for _ in range(K)]  # 사과 위치
L = int(input())  # 방향 변환 횟수
dir_change = []
previous_dir = 1  # 1: 왼오, 2: 오왼, 3: 위아래, 4: 아래위

for _ in range(L):
    temp = input().split()
    dir_change.append((int(temp[0]), temp[1]))

# 꼬리 1, 사과 2
board = [[0 for _ in range(N)] for _ in range(N)]
for i in range(K):
    y, x = apple_pos[i][0]-1, apple_pos[i][1]-1
    board[y][x] = 2

head_cy, head_cx = 0, 0
# 꼬리도 방향성을 알아야 하는 것으로 착각해서 수정하여 몸의 위치들을 기억하는 큐 이용
# 꼬리 제거하려면 맨 앞에 있는 요소를 popleft()
body = deque()
out = False
body.append((0, 0))  # *** 초기값 설정 놓침
for t in range(1, 10001):
    # *** 시간의 흐름에 따라 변환 시간별로 다르게 움직이는 것을 구현
    for k in range(L):  # L번 변환에 대한 시간을 기준으로
        change_time, dir = dir_change[k][0], dir_change[k][1]

    # 뱀이 '벽' 또는 '자기자신의 몸'과 부딪히면 게임 끝
    # 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킴.
    # 만약 이동한 칸에 사과 있다면, 그 칸에 사과 없어지고 꼬리는 움직이지 않는다.
    # 만약 이동한 칸에 사과가 없다면, 몸 길이를 줄여서 꼬리가 위치한 칸을 비운다. (몸 길이 변화x)
        # 1: 왼오, 2: 오왼, 3: 위아래, 4: 아래위
        # *** 변환 시간 중 가장 큰 값 보다 클 때 고려하지 못해서 해당값일 때 loop가 끝나는 것을 찾지못함. (dir_change[L-1][0]+1)
        if t < change_time+1 or t > dir_change[L-1][0]+1:
            # 벽 박치기 예외처리
            if previous_dir == 1:
                if head_cx+1 > N-1:
                    out = True
                    break
                ny, nx = head_cy, head_cx + 1
            elif previous_dir == 2:
                if head_cx-1 < 0:
                    out = True
                    break
                ny, nx = head_cy, head_cx - 1
            elif previous_dir == 3:
                if head_cy+1 > N-1:
                    out = True
                    break
                ny, nx = head_cy + 1, head_cx
            else:
                if head_cy-1 < 0:
                    out = True
                    break
                ny, nx = head_cy - 1, head_cx

            # *** 현재 값이 항상 업데이트 되는지 고려 (이 부분 반복 실수)
            # *** 이동하려는 위치에 대한 값에만 너무 집중
            head_cy, head_cx = ny, nx

            # 꼬리 예외처리
            if board[ny][nx] == 1:
                out = True
                break

            # 공간 0, 꼬리 1, 사과 2
            if board[ny][nx] == 0:
                body.append((ny, nx))
                board[ny][nx] = 1
                tail_y, tail_x = body.popleft()
                board[tail_y][tail_x] = 0
            elif board[ny][nx] == 2:
                body.append((ny, nx))
                board[ny][nx] = 1
            else:
                out = True
                break
            # print(ny, nx)
            # print(board)
            break
        # 1: 왼오, 2: 오왼, 3: 위아래, 4: 아래위
        elif t == change_time+1:
            if dir == 'L':
                # 벽 예외처리
                if previous_dir == 1:
                    if head_cy - 1 < 0:
                        out = True
                        break
                    ny, nx = head_cy - 1, head_cx
                    previous_dir = 4
                elif previous_dir == 2:
                    if head_cy + 1 > N-1:
                        out = True
                        break
                    ny, nx = head_cy + 1, head_cx
                    previous_dir = 3
                elif previous_dir == 3:
                    if head_cx + 1 > N-1:
                        out = True
                        break
                    ny, nx = head_cy, head_cx + 1
                    previous_dir = 1
                else:
                    if head_cx - 1 < 0:
                        out = True
                        break
                    ny, nx = head_cy, head_cx - 1
                    previous_dir = 2

                # *** 현재 값이 항상 업데이트 되는지 고려 (이 부분 반복 실수)
                # *** 이동하려는 위치에 대한 값에만 너무 집중
                head_cy, head_cx = ny, nx

                # 꼬리 예외처리
                if board[ny][nx] == 1:
                    out = True
                    break

                # 공간 0, 꼬리 1, 사과 2
                if board[ny][nx] == 0:
                    body.append((ny, nx))
                    board[ny][nx] = 1
                    tail_y, tail_x = body.popleft()
                    board[tail_y][tail_x] = 0
                elif board[ny][nx] == 2:
                    body.append((ny, nx))
                    board[ny][nx] = 1
                else:
                    out = True
                    break
            # 1: 왼오, 2: 오왼, 3: 위아래, 4: 아래위
            else:  # 'D'
                # 벽 예외처리
                if previous_dir == 1:
                    if head_cy + 1 > N-1:
                        out = True
                        break
                    ny, nx = head_cy + 1, head_cx
                    previous_dir = 3
                elif previous_dir == 2:
                    if head_cy - 1 < 0:
                        out = True
                        break
                    ny, nx = head_cy - 1, head_cx
                    previous_dir = 4
                elif previous_dir == 3:
                    if head_cx - 1 < 0:
                        out = True
                        break
                    ny, nx = head_cy, head_cx - 1
                    previous_dir = 2
                else:
                    if head_cx + 1 > N-1:
                        out = True
                        break
                    ny, nx = head_cy, head_cx + 1
                    previous_dir = 1

                # *** 현재 값이 항상 업데이트 되는지 고려 (이 부분 반복 실수)
                # *** 이동하려는 위치에 대한 값에만 너무 집중
                head_cy, head_cx = ny, nx

                # 꼬리 예외처리
                if board[ny][nx] == 1:
                    out = True
                    break

                # 공간 0, 꼬리 1, 사과 2
                if board[ny][nx] == 0:
                    body.append((ny, nx))
                    board[ny][nx] = 1
                    tail_y, tail_x = body.popleft()
                    board[tail_y][tail_x] = 0
                elif board[ny][nx] == 2:
                    body.append((ny, nx))
                    board[ny][nx] = 1
                else:
                    out = True
                    break
            # print(ny, nx)
            # print(board)
            break

        else:
            continue
    if out:
        # print(t)
        break