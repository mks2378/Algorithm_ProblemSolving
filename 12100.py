# # BOJ_12199
# # 10:22
#
# def move(m, time, block):
#     if time == 6:
#         return
#
#     global max_v
#     new_block = [[0 for _ in range(N)] for _ in range(N)]
#
#     if m == 0:  # 상
#         temp = [[0, 0] for _ in range(N)]  # [idx, prev_cal]
#         for i in range(N):
#             for j in range(N):
#                 if i == 0:
#                     new_block[i][j] = block[i][j]
#                 if block[temp[j][0]][j] != block[i][j]:
#                     temp[j][0] += 1
#                     temp[j][1] = 0
#                     new_block[temp[j][0]][j] = block[i][j]
#                 else:
#                     if temp[j][1] == 1:
#                         temp[j][0] += 1
#                         temp[j][1] = 0
#                         new_block[temp[j][0]][j] = block[i][j]
#                     else:
#                         new_block[temp[j][0]][i] += block[i][j]
#                         temp[j][0] += 1
#                         temp[j][1] = 1
#     elif m == 1:  # 하
#         temp = [[N - 1, 0] for _ in range(N)]
#         for i in range(N-1, -1, -1):
#             for j in range(N):
#                 if i == N - 1:
#                     new_block[i][j] = block[i][j]
#                 if block[temp[j][0]][j] != block[i][j]:
#                     temp[j][0] -= 1
#                     temp[j][1] = 0
#                     new_block[temp[j][0]][j] = block[i][j]
#                 else:
#                     if temp[j][1] == 1:
#                         temp[j][0] -= 1
#                         temp[j][1] = 0
#                         new_block[temp[j][0]][j] = block[i][j]
#                     else:
#                         new_block[temp[j][0]][i] += block[i][j]
#                         temp[j][0] -= 1
#                         temp[j][1] = 1
#     elif m == 2:  # 좌
#         temp = [[0, 0] for _ in range(N)]
#         for i in range(N):
#             for j in range(N):
#                 if j == 0:
#                     new_block[i][j] = block[i][j]
#                 elif block[i][temp[i][0]] == 0:
#                     new_block[i][temp[i][0]] = block[i][j]
#                     temp[i][1] = 0
#                 elif block[i][temp[i][0]] != block[i][j]:
#                     temp[i][0] += 1
#                     temp[i][1] = 0
#                     print(i)
#                     print(temp[i][0])
#                     while block[i][temp[i][0]] != 0:
#                         temp[i][0] += 1
#
#                     new_block[i][temp[i][0]] = block[i][j]
#                 else:
#                     # if temp[i][1] == 1:
#                     #     temp[i][0] += 1
#                     #     temp[i][1] = 0
#                     #     new_block[i][temp[i][0]] += block[i][j]
#                     # else:
#                     new_block[i][temp[i][0]] += block[i][j]
#                     temp[i][0] += 1
#                     temp[i][1] = 1
#         if time == 1:
#             print(block)
#             print(new_block)
#             exit()
#     else:  # 우
#         temp = [[N - 1, 0] for _ in range(N)]
#         for i in range(N):
#             for j in range(N-1, -1, -1):
#                 if j == N - 1:
#                     new_block[i][j] = block[i][j]
#                 if block[i][temp[i][0]] != block[i][j]:
#                     temp[i][0] -= 1
#                     temp[i][1] = 0
#                     new_block[i][temp[i][0]] = block[i][j]
#                 else:
#                     if temp[i][1] == 1:
#                         temp[i][0] -= 1
#                         temp[i][1] = 0
#                         new_block[i][temp[i][0]] += block[i][j]
#                     else:
#                         new_block[i][temp[i][0]] += block[i][j]
#                         temp[i][0] -= 1
#                         temp[i][1] = 1
#     for i in range(N):
#         for j in range(N):
#             max_v = max(max_v, new_block[i][j])
#
#     for t in range(4):  # 상하좌우
#         move(t, time+1, new_block)
#
#
# import sys
# input = sys.stdin.readline
# N = int(input())
# block = [list(map(int, input().split())) for _ in range(N)]
#
# dy = [-1, 1, 0, 0]
# dx = [0, 0, -1, 1]
# max_v = 0
#
# # 상하좌우 네 방향 중 하나로 쭉 이동
# # 같은 값을 갖는 두 블록이 충돌하면 하나로 더해지면서 합쳐진다.
# # 한 번의 이동에서 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
#
# for t in range(4):  # 상하좌우
#     move(t, 1, block)
#
# print(max_v)


"""
1. 숫자 블록 움직이기
    - 방향에 따라 해당 열 또는 행의 숫자 블록을 큐에 넣는다.
    - 빈 공간(0)은 넣지 않는다.
    - 블록에 있던 자리는 빈 공간(0)으로 만든다.
2. 블록 합치기 - 큐에서 블록을 꺼내고, 이를 순서대로 보드와 비교하면서 진행
    - 만약 현재 좌표 보드가 빈공간(0)이라면, 큐에 꺼낸 숫자를 그대로 보드에 놓는다.
    - 보드에 현재 좌표 위치에 숫자가 이미 놓여있다면, 큐에서 꺼낸 블록과 값이 일치하는지 비교
    - 같으면 현재 좌표의 보드 숫자를 2배, 다르면 다음 좌표에 꺼낸 숫자를 둔다.
3. 1,2 과정 반복
4. 방향을 바꿀 때마다 원래 보드를 써야 하므로, 별도의 배열을 만들어 보드를 저장.

<문제점>
블록의 값을 움직일 때, 인덱스가 가리키는 값과 비교하여 수행되는 부분을 계속 혼동하여 구현을 완벽히 못함.
"""

# sol_1
import sys, copy
input = sys.stdin.readline


def move(dir):
    # 상하좌우 순서
    if dir == 0:  # 상
        for j in range(N):
            idx = 0
            for i in range(1, N):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[idx][j] == 0:
                        board[idx][j] = temp
                    elif board[idx][j] == temp:
                        board[idx][j] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        board[idx][j] = temp
    elif dir == 1:  # 하
        for j in range(N):
            idx = N-1
            for i in range(N-2, -1, -1):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[idx][j] == 0:
                        board[idx][j] = temp
                    elif board[idx][j] == temp:
                        board[idx][j] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        board[idx][j] = temp
    elif dir == 2:  # 좌
        for i in range(N):
            idx = 0
            for j in range(1, N):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[i][idx] == 0:
                        board[i][idx] = temp
                    elif board[i][idx] == temp:
                        board[i][idx] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        board[i][idx] = temp
    else:  # 우
        for i in range(N):
            idx = N-1
            for j in range(N-2, -1, -1):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[i][idx] == 0:
                        board[i][idx] = temp
                    elif board[i][idx] == temp:
                        board[i][idx] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        board[i][idx] = temp


def dfs(cnt):
    global board, ans
    if cnt == 5:
        for i in range(N):
            ans = max(ans, max(board[i]))
        return

    temp_board = copy.deepcopy(board)
    for i in range(4):
        move(i)
        dfs(cnt + 1)
        board = copy.deepcopy(temp_board)


N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0
dfs(0)
print(ans)



