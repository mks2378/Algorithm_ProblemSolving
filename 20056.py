"""
마법사 상어가 NxN 격자에서 파이어볼 M개 발사.
i번 파이어볼의 위치는 (ri, ci), 질량 mi, 방향은 di, 속력은 si

격자의 행과 열은 1번부터 N번까지 번호가 매겨져 있고, 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다.

마법사 상어가 모든 파이어볼에게 이동 명령.
1. 모든 파이어볼이 자신의 방향 di, 속력 si칸 이동
    - 이동 중 같은 칸에 여러 개 파이어볼이 존재 가능
2. 이동 후, 2개 이상의 파이어볼이 있는 칸에서 아래 일 발생
    - 같은 칸에 있는 파이어볼은 하나로 합쳐진다.
    - 4개의 파이어볼로 나누어진다.
    - 나누어진 파이어볼의 질량, 속력, 방향은 아래와 같다.
        - 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
        - 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
        - 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    - 질량이 0인 파이어볼은 소멸되어 없어진다.


마법사 상어가 K번 명령한 후, 남아있는 파이어볼 질량의 합 구하기.
"""


import sys; input = sys.stdin.readline

dy = (-1, -1, 0, 1, 1, 1, 0, -1)
dx = (0, 1, 1, 1, 0, -1, -1, -1)


def move():
    for _ in range(len(fire_ball)):
        y, x = fire_ball.pop(0)
        m, s, d = board[y][x].pop(0)

        ny = (y + dy[d] * s) % N
        nx = (x + dx[d] * s) % N

        board[ny][nx].append([m, s, d])


def calculate():
    for i in range(N):
        for j in range(N):
            if len(board[i][j])>=2:
                # new_m = sum(board[i][j][:][0])//5
                new_m = sum([k[0] for k in board[i][j]])//5
                if new_m == 0:
                    # del board[i][j]
                    board[i][j].clear()
                    continue

                new_s = sum([k[1] for k in board[i][j]])//len(board[i][j])
                # sum_d = sum(board[i][j][:][2])

                all_odd, all_even = 0, 0
                for k in board[i][j]:
                    if k[2]%2 == 1:
                        all_odd += 1
                    else:
                        all_even += 1

                if all_odd == len(board[i][j]) or all_even == len(board[i][j]):
                    # del board[i][j]
                    board[i][j].clear()
                    board[i][j].append([new_m, new_s, 0])
                    board[i][j].append([new_m, new_s, 2])
                    board[i][j].append([new_m, new_s, 4])
                    board[i][j].append([new_m, new_s, 6])

                else:
                    # del board[i][j]
                    board[i][j].clear()
                    board[i][j].append([new_m, new_s, 1])
                    board[i][j].append([new_m, new_s, 3])
                    board[i][j].append([new_m, new_s, 5])
                    board[i][j].append([new_m, new_s, 7])

                fire_ball.append((i, j))
                fire_ball.append((i, j))
                fire_ball.append((i, j))
                fire_ball.append((i, j))

            # 아래 두 줄 없어서 계속 틀림.
            # fireball에 대한 정보 업데이트 놓침.
            if len(board[i][j]) == 1:
                fire_ball.append((i, j))


# main
N, M, K = map(int, input().split())

fire_ball = []
board = [[[] for _ in range(N)] for _ in range(N)]
for _ in range(M):
    y, x, m, s, d = map(int, input().split())
    board[y-1][x-1].append([m, s, d])
    fire_ball.append((y-1, x-1))

for _ in range(K):
    move()
    calculate()

answer = 0
for i in range(N):
    for j in range(N):
        if board[i][j]:
            for m, _, _ in board[i][j]:
                answer += m

print(answer)


# del, remove 와 clear() 차이
# 배열 내 원소가 리스트 일 경우에, 리스트 마다의 같은 열의 원소 뽑아 더하기
# list.pop(0)

# 코드가 길 때 어떻게 디버깅 하는 것이 효과적일까??
# 짤 때부터 조금씩 구현하고 확인하면v서 구현해야되나?

# ref) https://jennnn.tistory.com/77