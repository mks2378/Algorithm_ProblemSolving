# BOJ_16235

"""
NxN 크기의 땅. (r,c) == (y,x)
가장 처음에 양분은 모든 칸에 5만큼 존재.

M개의 나무를 구매하여 땅에 심는다.
1x1 크기의 칸에 여러 개의 나무가 심어져 있을 수 있다.

봄 - 나무가 자신의 나이만큼 양분 먹고, 나이가 1 증가.
#     하나의 칸에 여러 개의 나무가 존재하면 나이가 어린 나무부터 먹는다.
#     만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹지 못하는 나무는 즉시 죽는다.
#
#     여름 - 봄에 죽은 나무가 양분으로 변한다. 각가의 죽은 나무마다 나이를 2로 나눈 값이 나무에 잇던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
#
#     가을 - 나이가 5의 배수 나무 번식. 인접 8개의 칸에 나이가 1인 나무 생긴다. 땅 외에 나무 생기지 않는다.
#
#     겨울 - 입력으로 주어진 A[r][c] 양분이 추가된다.
"""

# import sys
# input = sys.stdin.readline
#
# N, M, K = map(int, input().split())
# foods = [[5 for _ in range(N)] for _ in range(N)]
# A = [list(map(int, input().split())) for _ in range(N)]
#
# trees = []
# for k in range(M):
#     y, x, age = map(int, input().split())
#     trees.append((y-1, x-1, age))
#
# dy = [0, 0, 1, -1, 1, 1, -1, -1]
# dx = [1, -1, 0, 0, 1, -1, 1, -1]
#
# year = 1
# while year <= K:
#     # 봄
#     trees = sorted(trees, key=lambda x: x[2])
#     updated_trees = []
#     dead_trees = []
#     for tree in trees:
#         y, x, age = tree
#         if foods[y][x] >= age:
#             foods[y][x] -= age
#             age += 1
#             updated_trees.append((y, x, age))
#         else:
#             food = age // 2
#             dead_trees.append((y, x, food))
#     trees = updated_trees
#
#     # 여름
#     for dead_tree in dead_trees:
#         y, x, food = dead_tree
#         foods[y][x] += food
#
#     # 가을
#     new_trees = []
#     for tree in trees:
#         y, x, age = tree
#
#         if age % 5 == 0:
#             for i in range(8):
#                 ny = y + dy[i]
#                 nx = x + dx[i]
#
#                 if 0 <= ny < N and 0 <= nx < N:
#                     new_trees.append((ny, nx, 1))
#
#     trees.extend(new_trees)
#
#     # 겨울
#     for i in range(N):
#         for j in range(N):
#             foods[i][j] += A[i][j]
#
#     year += 1
#
# print(len(trees))

# 비효율적인 코드 - 연도를 거듭할 때마다 정렬해야 하기 때문에 시간이 오래 걸린다.
# 이런 문제는 처음부터 순서를 고려하여 정렬된 상태로 저장하는 방식으로 접근 필요

###########################################################################

# 코드 개선
# deque 이용하여 나이가 어린 나무는 앞쪽에 오도록 appendleft() 이용
# 양분이 없어 죽는 나무는 pop() 이용

import sys
from collections import deque
input = sys.stdin.readline

dy = [0, 0, 1, -1, 1, 1, -1, -1]
dx = [1, -1, 0, 0, 1, -1, 1, -1]

ans = 0
N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
trees = [[deque() for _ in range(N)] for _ in range(N)]
nutrients = [[5 for _ in range(N)] for _ in range(N)]
for _ in range(M):
    y, x, n = map(int, input().split())
    trees[y-1][x-1].append(n)
    ans += 1

year = 1
while year <= K:
    # 봄, 여름
    for i in range(N):
        for j in range(N):
            for k in range(len(trees[i][j])):
                if nutrients[i][j] >= trees[i][j][k]:
                    nutrients[i][j] -= trees[i][j][k]
                    trees[i][j][k] += 1
                else:
                    while k < len(trees[i][j]):
                        nutrients[i][j] += (trees[i][j].pop()//2)
                        ans -= 1
                    break

    for i in range(N):
        for j in range(N):
            for k in range(len(trees[i][j])):
                if trees[i][j][k] % 5 == 0:
                    for t in range(8):
                        ny = i + dy[t]
                        nx = j + dx[t]

                        if 0 <= ny < N and 0 <= nx < N:
                            trees[ny][nx].appendleft(1)
                            ans += 1
            nutrients[i][j] += A[i][j]

    year += 1

print(ans)