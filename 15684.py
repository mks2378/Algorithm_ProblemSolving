# 사다리 조작

"""
N개 세로선
M개 사용 가능 가로선 수
H개 가로선을 놓을 수 있는 위치

게임은 각각의 세로선마다 진행. 가장 위에서부터 아래 방향으로 이동.
가로선 만나면 옆으로 이동. 이동한 세로선에서 아래 방향으로 이동.

사다리에 가로선 추가하여 게임 결과 조작.
i번 세로선의 결과가 i번이 나오도록 조작.
이때 추가해야 하는 가로선 개수의 최솟값
"""

import sys
input = sys.stdin.readline


# 사다리에 가로선 놓는 함수
def dfs(start, cnt):
    global res
    if cnt == min_cnt:
        if check():
            res = cnt
        return
    for i in range(start, H):
        for j in range(N-1):
            # ij 위치에 사다리가 있지 않고, 전후로도 사다리가 없으면
            if not ladder[i][j-1] + ladder[i][j] + ladder[i][j+1]:
                # 사다리 놓기
                ladder[i][j] = 1
                dfs(i, cnt+1)
                # 함수 재귀 끝나면 사다리 다시 빼기 (원상복구)
                ladder[i][j] = 0


# 사다리 가로선 추가 후, 모든 세로선이 자기 번호로 내려오는 지 확인하는 함수
def check():
    # h행 n열, 1열부터 시작
    for j in range(N):
        tmp = j
        for i in range(H):
            if ladder[i][tmp]: # 이어져 있으면 오른쪽으로 한칸의 열 이동
                tmp += 1
            elif ladder[i][tmp-1]: # 왼쪽 방향이 이어져 있는지 확인
                tmp -= 1 # 왼쪽 열로 이동

        # 모든 행을 거친 뒤 자기 원래 번호(j)로 돌아오지 않으면 False
        if tmp!=j:
            return False

    # 모든 열이 사다리를 타고 자기 열 번호로 돌아온다면 True 반환
    return True



# 세로선 개수, 가로선 개수, 가로선 놓을 수 있는 위치 개수
N, M, H = map(int, input().split())
ladder = [[0]*N for _ in range(H)]
for i in range(M):
    a, b = map(int, input().split())
    ladder[a-1][b-1] = 1

res = 10000
for min_cnt in range(4):
    dfs(0, 0)
    if res != 10000:
        print(res)
        break
else:
    print(-1)

