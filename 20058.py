"""
파이어스톰 1번 시전 프로세스

1. 2**L * 2**L 크기의 부분 격자 나누기
2. 모든 부분 격자를 시계 방향으로 90도 회전
3. 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
인접 = 상, 하, 좌, 우

파이어스톰 Q번 시전 후 구하고자 하는 것.
1. 남아있는 얼음 A[r][c]의 합
2. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 - BFS

덩어리 파악 -> BFS
"""

from collections import deque
import sys
input = sys.stdin.readline


def bfs(y, x):
    # q = deque([x, y]) 왜 안되지?
    q = deque()
    q.append([y, x])
    ice_bulk = 1
    visited[y][x] = 1

    while q:
        cy, cx = q.popleft()

        for k in range(4):
            ny = cy + dy[k]
            nx = cx + dx[k]

            if 0<=ny<2**N and 0<=nx<2**N and board[ny][nx]>0 and not visited[ny][nx]:
                visited[ny][nx] = 1
                q.append([ny, nx])
                ice_bulk+=1

    return ice_bulk


def rot90(board, r_size, board_length):
    new_board = [[0]*(2**N) for _ in range(2**N)]

    for y in range(0, board_length, r_size):
        for x in range(0, board_length, r_size):
            for i in range(r_size):
                for j in range(r_size):
                    # print(y, x, i, j)
                    # board[j-gap][(x+gap+1)-i] = board[i][j]
                    # print(y+j, x+gap-i-1, y+i, x+j)
                    new_board[y+j][x+r_size-i-1] = board[y+i][x+j]

    board = new_board

    return board


def ice_reduce(board):
    # new_a = [[0]*(2**N) for _ in range(2**N)]

    ice_cnt=0
    melting_list = []
    for i in range(2**N):
        for j in range(2**N):
            for k in range(4):
                ny = i + dy[k]
                nx = j + dx[k]

                if 0<=ny<2**N and 0<=nx<2**N and board[ny][nx]>0:
                    ice_cnt+=1

            # 여기서 계산 바로 하면 다음 계산에 영향 줘서 좌표 따가서 나중에 계산
            if ice_cnt<3 and board[i][j]>0:
                # board[i][j]-=1
                melting_list.append([i, j])

            ice_cnt=0

    for y, x in melting_list:
        board[y][x]-=1

    return board


dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

# main
N, Q = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(2**N)]
level = list(map(int, input().split()))

board_length = 2**N

# Q번 시행
for L in level:
    # y = -2**L
    # x = -2**L
    # gap = 2**L
    # time = (2**N)//(2**L)  # 4
    #
    # new_board = [[0] * (2 ** N) for _ in range(2 ** N)]
    #
    # # 격자 시작점 구하기
    # for i in range(time):
    #     cy = y + gap * (i+1)
    #     for j in range(time):
    #         cx = x + gap * (j+1)
    #         # print('cy, cx', cy, cx)
    #         rot90(cy, cx, gap)
    r_size = 2**L
    board = rot90(board, r_size, board_length)

    # board = new_board

    board = ice_reduce(board)

# print(sum(board,[]))
total = sum(sum(board, []))
max_ice = 0
visited = [[0]*(2**N) for _ in range(2**N)]
for i in range(2**N):
    for j in range(2**N):
        if not visited[i][j] and board[i][j]>0:
            max_ice = max(max_ice, bfs(i, j))

print(total)
print(max_ice)

