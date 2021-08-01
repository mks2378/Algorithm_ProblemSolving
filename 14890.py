# 경사로 (boj_14890)

# import sys
# import copy
# input = sys.stdin.readline
#
#
# def check_road_up(i, j):
#     if j-L+1 < 0:
#         return False
#
#     # N개는 N-1번 비교
#     # 해당 지점으로부터 이전의 L-1개까지 총 L개에 대해 L-1번 비교하여 확인
#     for k in range(j-L+1, j):  ##### range에서 개수 카운트하는 방법 숙지
#         if board[i][k] != board[i][k+1]:
#             return False
#     return True
#
#
# def check_road_down(i, j):
#     if not j+L <= N-1:  # j로부터 L개 (인덱스)
#         return False
#
#     # 해당 지점으로부터 이후의 L개 확인
#     for k in range(j+1, j+L):
#         if board[i][k] != board[i][k+1]:
#             return False
#     return True
#
#
# N, L = map(int, input().split())
#
# board = [list(map(int, input().split())) for _ in range(N)]
# for i in range(N):
#     board.append([board[j][i] for j in range(N)])
#
# # 왔다 갔다 해야 되는 걸로 착각. 오르막, 내리막을 구현해줘서 한 방향으로 가는 것만 해주면 돼
# # for i in range(len(board)):
# #     if not board[i] == board[i][::-1]:  ##### 리스트 전체 원소 비교
# #         board.append(board[i][::-1])  ##### 역순 바꾸기
#
# # for i in range(N):
# #     temp = [board[j][i] for j in range(N)]
# #     board.append(temp)
#     # board.append(temp.reverse()) # 이거 왜 안되는거지??? -> 실제 리스트까지 바꾸기 때문에 안돼
#     # reversed() 또는 [::-1] 를 이용할 수 있는데, [::-1] 더 빨라.
#
#
# # 가는 방향의 뒤 보다 낮아야된다.
# # 높이 차가 1
# # 낮은 칸 L개의 높이는 모두 같아야 되고, 서로 연속
#
# total_road = 0
# # 정방향
# for i in range(len(board)):
#     # 직선 길 하나씩 길이 될 수 있는지 확인
#     make_road = True
#     for j in range(N-1):
#         if board[i][j] == board[i][j+1]:
#             continue
#         else:
#             if board[i][j] + 1 == board[i][j+1] and check_road_up(i, j):
#                 continue
#             elif board[i][j] == board[i][j+1] + 1 and check_road_down(i, j):
#                 continue
#             else:
#                 make_road = False
#
#     if make_road:
#         total_road += 1
#         print(board[i])  # count 또는 구하고자 하는 결과 값을 보고 분석
#
# print(total_road)
#
# # 겹칠 때를 해결하지 못함.
"""
처음에 바로 구현하지 않고, 로직을 생각하면서 어느 부분에 어떻게 구현할지 주석으로 적어가면서 푸는게 좋을 듯.
수의 범위와 조건은 모두 쓰인다.
"""

####################################################################################################################################################

def slope(i, c):
    global ans
    cnt = 1
    for j in range(0, N-1):
        # 높이 차를 기준으로 다른 연산 적용
        d = board[i][j+1]-board[i][j] if c else board[j+1][i]-board[j][i]

        # 같은 높이
        if d == 0:
            cnt += 1

        # 오르막
        elif d == 1 and cnt >= L:
            cnt = 1  # 높은 층을 시작으로 평평한 길 카운트 다시 시작

        # 내리막
        # cnt의 마이너스라는 뜻은 이전에 내리막 경사로가 존재한다는 의미
        # 이전의 가까이 내리막 경사로가 있는지 알 수 없기 때문에 cnt값을 보고 판단
        elif d == -1 and cnt >= 0:
            cnt = -L+1  # 혹시 다음에 오르막이 있을 때, 경사로가 겹치면 안되니까

        # 겹쳐서 안되는 경우 (예외처리)
        else:
            return
    if cnt >= 0:
        ans += 1


def solve():
    # 가로 방향과 세로 방향에 대해 구분해서 순차 탐색
    for i in range(N):
        slope(i, 1)  # 가로줄
        slope(i, 0)  # 세로줄
    print(ans)


N, L = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0
solve()