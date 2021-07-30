# 주사위 굴리기 (boj_14499)

import sys

input = sys.stdin.readline

# 동, 서, 북, 남
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

# 주사위 순서: 위 동 서 북 남 바닥
dice = [0 for _ in range(6)]  # 주사위를 1차원으로 생각하는게 편했던 듯.

# 문제에서 N을 x의 범위로, M을 y의 범위로 주었는데, 반대로 해서 오류를 계속 못 찾음.
n, m, y, x, k = map(int, input().split())

# 코드 표현 암기 (짧아)
board = [list(map(int, input().split())) for _ in range(n)]
order = list(map(int, input().split()))
order = [v-1 for v in order]

# 전체 시퀀스는 1. order에 따라 주사위가 움직임. 2. board의 값과 주사위 바닥 값이 주어진 규칙에 따라 업데이트 된다.
# 이 시퀀스를 먼저 생각하는게 문제 접근 방법.
for i in range(k):
    dir = order[i]
    nx = x + dx[dir]
    ny = y + dy[dir]

    # board 좌표에 대한 예외 처리
    if not 0 <= ny < n or not 0 <= nx < m: continue  # 코드 표현 암기 (직관적)

    """
    주사위를 1차원 리스트에서 각 위치가 어디인지 가정하고 코딩.
    """
    # 동쪽 회전
    if dir == 0:
        dice[0], dice[1], dice[2], dice[5] = dice[2], dice[0], dice[5], dice[1]
    # 서쪽 회전
    elif dir == 1:
        dice[0], dice[1], dice[2], dice[5] = dice[1], dice[5], dice[0], dice[2]
    # 북쪽 회전
    elif dir == 2:
        dice[0], dice[3], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[3]
    # 남쪽 회전
    else:
        dice[0], dice[3], dice[4], dice[5] = dice[3], dice[5], dice[0], dice[4]

    if board[ny][nx] == 0:
        board[ny][nx] = dice[5]
    else:
        dice[5] = board[ny][nx]
        board[ny][nx] = 0

    """
    아래와 같이 그려놓고 인덱스로 생각해서 접근하는 것이 빠르다.
    
    #   2        [3]
    # 4 1 3  [2] [0] [1]
    #   5        [4]
    #   6        [5]
    """

    y, x = ny, nx  # 업데이트 하는 것 까먹지 말기.
    print(dice[0])

