# 주사위 윷놀이

import sys; input = sys.stdin.readline


def calculate():
    global result
    # 각 플레이어의 구간, 위치 정보
    players = [[0, 0] for _ in range(5)]

    # 각 경우의 수에서 포인트의 합
    sum_points = 0

    # 1턴부터 10턴까지 실행
    for i in range(1, 11):
        now = turns[i]
        section, pos = players[now]
        if section == -1:
            return
        else:
            pos += dice[i]
            # 0번 구역일 때는 섹션이 옮겨지거나 도착하거나 이동하거나
            if section == 0:
                if 20<pos:
                    players[now] = [-1, -1]
                elif pos == 5:
                    players[now] = [1, 0]
                elif pos == 10:
                    players[now] = [3, 0]
                elif pos == 15:
                    players[now] = [2, 0]
                else:
                    players[now] = [section, pos]

            # 1번 구역일 때는 쭉 가서 8 이상 가면 도착.
            elif section == 1:
                if pos>=8:
                    players[now] = [-1, -1]

                # 4 이상이면 section3 직진 구간에서 칸수를 하나 빼준다.
                # 가로 구간은 사이 3칸, 세로 구간은 2칸이기 때문)
                elif pos>=4:
                    players[now] = [3, pos-1]
                else:
                    players[now] = [section, pos]
            elif section == 2:
                if pos>=8:
                    players[now] = [-1, -1]
                elif pos>=4:
                    players[now] = [3, pos-1]
                else:
                    players[now] = [section, pos]
            elif section == 3:
                if pos>6:
                    players[now] = [-1, -1]
                else:
                    players[now] = [section, pos]

            # 이동된 칸이 이동된 칸이 이미 말이 있던 칸이면 올바르지 않은 경우이므로 연산 중지
            # 아닐 경우, point 합산.
            ny, nx = players[now]
            if ny != -1:
                for k in range(1, 5):
                    if now == k:
                        continue
                    a, b = players[k]
                    if a == -1:
                        continue

                    # 말이 이미 있는 칸으로 이동했다면, 불가능 처리
                    if idx[a][b] == idx[ny][nx]:
                        return
                sum_points+=points[ny][nx]
    result = max(result, sum_points)


# 10턴에 대한 말들의 경우의 수 조합을 turns에 저장
def dfs(depth):
    if depth == 10:
        calculate()
        return

    # 각 턴에 1~4 중 하나의 말이 이동
    for i in range(1, 5):
        turns[depth+1] = i
        dfs(depth+1)


# main
turns = [0 for _ in range(11)]

points = [[0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40], [10, 13, 16, 19], [30, 28, 27, 26], [20, 22, 24, 25, 30, 35, 40]]

idx = [[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20], [5, 21, 22, 23], [15, 24, 25, 26], [10, 27, 28, 29, 30, 31, 20]]

# 10턴에 대한 주사위는 이미 결정. 어떤 말을 쓸 지에 대한 조합을 따져서 최대 값 구하기
dice = [0] + list(map(int, input().split()))
result = 0
dfs(0)

print(result)