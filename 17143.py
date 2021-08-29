# BOJ_17143
# 20:43

"""
RXC 격자판 -> (r,c)칸 - (행,열)

1초 동안. 오른쪽 열 오른쪽 도착하면 끝.
1. 낚시왕이 오른쪽 한 칸 이동
2. 낚시왕이 있는 열에 있는 상어 중 땅에 가장 가까운 상어 잡는다.
잡으면 사라진다.
3. 상어 이동


입력으로 주어진 속도로 이동 - 칸/초
상어가 이동시 격자판 경계 넘는 경우에는 방향을 반대, 속력 유지 이동.
(결국 방향은 가던 방향 or 반대 방향)

한 칸에 두 마리 이상 있을 시, 크기가 가장 큰 한 마리 빼고 나머지 모두 사라진다.

"""

# 처음 잘못 푼 코드

# import sys
# input = sys.stdin.readline
#
# R, C, M = map(int, input().split())
# boards = [[-1 for _ in range(C)] for _ in range(R)]
#
# # 상어 위치 y,x, 속력, 이동방향, 크기
# # 1: 위, 2: 아래, 3: 오른, 4: 왼
#
# sharks = []
# for idx in range(M):
#     shark = list(map(int, input().split()))
#     shark[0], shark[1] = shark[0]-1, shark[1]-1
#     sharks.append(shark)
#     boards[shark[0]][shark[1]] = idx
#
# total = 0
# king_position = 0
# while king_position < C:
#     # 2. 낚시왕이 있는 열에 있는 상어 중 땅에 가장 가까운 상어 잡는다. 잡으면 사라진다.
#     eat = False
#     for i in range(R):
#         idx = boards[i][king_position]
#         if idx != -1 and sharks[idx] != -1 and not eat:
#             # print('idx, sharks: ', idx, sharks[idx])
#             _, _, _, _, z = sharks[idx]
#             total += z
#             boards[i][king_position] = -1
#             sharks[idx] = -1
#             eat = True
#
#     # 3. 상어 이동
#     for idx, shark in enumerate(sharks):
#         if shark == -1:
#             continue
#         else:
#             r, c, s, d, z = shark
#             print('r, c, s, d, z', r, c, s, d, z)
#
#             # 위
#             if d == 1:
#                 if r-s >= 0:
#                     r -= s
#                 else:
#                     r = s-r
#                     d = 2
#
#             # 아래
#             elif d == 2:
#                 if r+s < R:
#                     r += s
#
#                 else:
#                     r = R - (r+s-R)
#                     d = 1
#
#             # 우
#             elif d == 3:
#                 if c+s < C:
#                     c += s
#                 else:  # R - (r+s-R)
#                     c = C - (c+s-C)
#                     d = 4
#
#             # 좌
#             elif d == 4:
#                 if c-s >= 0:
#                     c -= s
#                 else:
#                     c = s-c
#                     d = 3
#                     ## 2번 이상 튕길때 고려
#
#             # update
#             print('r, c, s, d, z', r, c, s, d, z)
#             print()
#             if boards[r][c] >= 0 and sharks[boards[r][c]] != -1:
#                 ex_size = sharks[boards[r][c]][4]
#                 if z > ex_size:
#                     sharks[boards[r][c]] = -1
#                     boards[r][c] = idx
#                     sharks[idx] = [r, c, s, d, z]
#                 else:
#                     sharks[idx] = -1
#             else:
#                 boards[r][c] = idx
#                 sharks[idx] = [r, c, s, d, z]
#
#     king_position += 1
#
# print(total)

import sys
input = sys.stdin.readline

R, C, M = map(int, input().split())
# 변화량으로 통일 (단위를 통일시켜주는게 혼동을 최소화)
R -= 1
C -= 1

boards = [[0 for _ in range(C+1)] for _ in range(R+1)]
for _ in range(M):
    y, x, s, d, z = map(int, input().split())  # 받고
    boards[y-1][x-1] = (s, d, z)  # 저장할 때, index 조정 (-1)

total = 0
for column in range(C+1):
    # 가장 가까운 거리의 상어 낚시
    for idx in range(R+1):
        if boards[idx][column] != 0:
            total += boards[idx][column][2]
            boards[idx][column] = 0
            break

    # 상어 이동
    # new_boards는 기존 boards의 위치해 있는 값과도 비교가 되기 때문에 이를 방지 위해 이용
    # 2차원 맵에서 전체적인 이동을 표현할 때는 새로 맵을 만들어 표현하는게 좋다.
    new_boards = [[0 for _ in range(C+1)] for _ in range(R+1)]
    for y in range(R+1):
        for x in range(C+1):
            if boards[y][x] != 0:
                s, d, size = boards[y][x]

                # 왕복 횟수 제거 // 반복될 때는 주기를 제거하여 최소값으로 만들 것.
                if d == 1 or d == 2:
                    s %= (2 * R)
                elif d == 3 or d == 4:
                    s %= (2 * C)

                ny, nx = 0, 0

                # 아래 부분 구현이 어려웠다.
                # 상
                if d == 1:
                    if s <= y:
                        ny, nx = y - s, x
                        if ny == 0:
                            d = 2
                    elif y < s <= y + R:
                        ny, nx = s - y, x
                        d = 2
                        if ny == R:
                            d = 1
                    else:
                        ny, nx = R - (s-y-R), x

                # 하
                elif d == 2:
                    if s <= R - y:
                        ny, nx = s + y, x
                        if ny == R:
                            d = 1
                    elif R - y < s <= 2 * R - y:
                        ny, nx = R - (s - (R-y)), x
                        d = 1
                        if ny == 0:
                            d = 2
                    else:
                        ny, nx = s - (R + R - y), x

                # 우
                elif d == 3:
                    if s <= C - x:
                        ny, nx = y, x + s
                        if nx == C:
                            d = 4
                    elif C - x < s <= 2 * C - x:
                        ny, nx = y, C - (s - (C-x))
                        d = 4
                        if nx == 0:
                            d = 3
                    else:
                        ny, nx = y, s - (C + C - x)

                # 좌
                elif d == 4:
                    if s <= x:
                        ny, nx = y, x - s
                        if nx == 0:
                            d = 3
                    elif x < s <= x + C:
                        ny, nx = y, s - x
                        d = 3
                        if nx == C:
                            d = 4
                    else:
                        ny, nx = y, C - (s - x - C)

                if new_boards[ny][nx] == 0 or size > new_boards[ny][nx][2]:
                    new_boards[ny][nx] = (s, d, size)

    boards = new_boards

print(total)
