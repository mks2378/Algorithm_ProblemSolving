# import sys; input = sys.stdin.readline
#
#
# # function
# def area_separation(y, x):
#
#
#     for d1 in range(N):
#         for d2 in range(N):
#
#
#
# def area_check():
#     pass
#
#
# # 14:45
# # main
# N = int(input())
#
# population = [list(map(int, input().split)) for _ in range(N)]
#
# min_gap = int(1e9)
# for i in range(N):
#     for j in range(N):
#         max_p, min_p = area_separation(i, j)
#         min_gap = min(min_gap, max_p-min_gap)
#
# print(min_gap)

# 게리맨더링2
import sys; input = sys.stdin.readline


def calculate(row, col, d1, d2):
    global total, answer
    first, second, third, fourth = 0, 0, 0, 0

    # 구역 1
    col1 = col+1
    for r in range(row+d1):
        if r>=row:
            col1-=1
        first+=sum(matrix[r][:col1])

    # 구역 2
    col2 = col+1
    for r in range(row+d2+1):
        if r>row:
            col2+=1
        second += sum(matrix[r][col2:])

    # 구역 3
    col3 = col - d1
    for r in range(row+d1, N):
        third += sum(matrix[r][:col3])
        if r<row+d1+d2:
            col3 += 1

    # 구역 4
    col4 = col+d2
    for r in range(row+d2+1, N):
        fourth += sum(matrix[r][col4:])
        if r<=row+d1+d2:
            col4-=1

    # 구역 5
    five = total - (first + second + third + fourth)
    answer = min(answer, max(first, second, third, fourth, five) - min(first, second, third, fourth, five))


def check(r, c, d1, d2):
    # if 0<=r+d1-1<N and 0<=r+d2-1<N and 0<=c-d1+d2-1<N:
    if 0<=c-d1 and c+d2<N and r+d1+d2<N:
        calculate(r, c, d1, d2)


# main
N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]
total = 0
for row in matrix:
    total += sum(row)
answer = int(1e9)

for r in range(N-2):
    for c in range(1, N-1):
        for d1 in range(1, N-1):
            for d2 in range(1, N-1):
                check(r, c, d1, d2)

print(answer)