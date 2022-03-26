"""
가장 처음에 주사위의 이동 방향은 동쪽.

  2
4 1 3
  5
  6

지도 윗면이 1, 동쪽 바라보는 방향이 3.

1. 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
2. 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
3. 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
    A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
    A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
    A = B인 경우 이동 방향에 변화는 없다.

B = 칸 (x,y)에 있는 정수일 때,
C = (x,y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수
이때 이동할 수 있는 칸에는 모두 정수 B가 있어야 한다. 여기서 점수는 B와 C를 곱한 값이다.
각 이동에서 획득하는 점수의 합을 구해보자.

"""

from collections import deque
import sys
input = sys.stdin.readline


def bfs(y, x):
    visited = [[0]*M for _ in range(N)]
    cnt = 0

    q = deque()
    q.append([y, x])
    visited[y][x] = 1  # 놓침
    cnt += 1

    while q:
        cy, cx = q.popleft()

        for k in range(4):
            ny = cy + dy[k]
            nx = cx + dx[k]

            if 0<=ny<=N-1 and 0<=nx<=M-1 and board[ny][nx] == board[y][x] and not visited[ny][nx]:
                visited[ny][nx] = 1
                q.append([ny, nx])
                cnt+=1
    return cnt

# 주사위 숫자 순서대로 코드 작성
# 값의 변화가 있으면 새로운 배열 만들어서 값의 변화 반영 (실수 쉬워)
def move_dice(dir):
    new_dice = [0]*6

    if dir == 0: # 동
        new_dice[0] = dice[0]
        new_dice[1] = dice[5]
        new_dice[2] = dice[1]
        new_dice[3] = dice[2]
        new_dice[4] = dice[4]
        new_dice[5] = dice[3]

    elif dir == 1: # 서
        new_dice[0] = dice[0]
        new_dice[1] = dice[2]
        new_dice[2] = dice[3]
        new_dice[3] = dice[5]
        new_dice[4] = dice[4]
        new_dice[5] = dice[1]
        
    elif dir == 2: # 남
        new_dice[0] = dice[5]
        new_dice[1] = dice[1]
        new_dice[2] = dice[0]
        new_dice[3] = dice[3]
        new_dice[4] = dice[2]
        new_dice[5] = dice[4]
        
    elif dir == 3: # 북
        new_dice[0] = dice[2]
        new_dice[1] = dice[1]
        new_dice[2] = dice[4]
        new_dice[3] = dice[3]
        new_dice[4] = dice[5]
        new_dice[5] = dice[0]

    return new_dice


# main
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

score = 0

N, M, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

cur_dir = 0  # 0:동, 1:서, 2:남, 3:북
cur_y, cur_x = 0, 0

# 주어진 초기값대로 작성
dice = [2, 4, 1, 3, 5, 6]

for _ in range(K):
    # 주사위 한칸 이동 & 현재 지도 위 위치
    if cur_dir == 0: # 동
        if 0<=cur_x+1<=M-1:
            cur_x+=1
            dice = move_dice(0)
        else:
            cur_x-=1
            cur_dir = 1
            dice = move_dice(1)
    elif cur_dir == 1: # 서
        if 0<=cur_x-1<=M-1:
            cur_x-=1
            dice = move_dice(1)
        else:
            cur_x+=1
            cur_dir = 0
            dice = move_dice(0)
    elif cur_dir == 2: # 남
        if 0<=cur_y+1<=N-1:
            cur_y+=1
            dice = move_dice(2)
        else:
            cur_y-=1
            cur_dir = 3
            dice = move_dice(3)
    elif cur_dir == 3: # 북
        if 0<=cur_y-1<=N-1:
            cur_y-=1
            dice = move_dice(3)
        else:
            cur_y+=1
            cur_dir = 2
            dice = move_dice(2)

    # 이동방향 결정
    # 90도 시계방향 회전
    if dice[5]>board[cur_y][cur_x]:
        if cur_dir == 0:
            cur_dir = 2
        elif cur_dir == 1:
            cur_dir = 3
        elif cur_dir == 2:
            cur_dir = 1
        elif cur_dir == 3:
            cur_dir = 0
    # 90도 반시계방향 회전
    elif dice[5]<board[cur_y][cur_x]:
        if cur_dir == 0:
            cur_dir = 3
        elif cur_dir == 1:
            cur_dir = 2
        elif cur_dir == 2:
            cur_dir = 0
        elif cur_dir == 3:
            cur_dir = 1
    else:
        pass

    cur_cnt = bfs(cur_y, cur_x)

    score += cur_cnt * board[cur_y][cur_x]

print(score)
