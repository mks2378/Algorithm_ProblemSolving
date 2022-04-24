# import sys
# input = sys.stdin.readline
# from collections import deque
# from copy import deepcopy
#
# dy = [0, -1, -1, -1, 0, 1, 1, 1]
# dx = [-1, -1, 0, 1, 1, 1, 0, -1]
#
# """
# 물고기 - 8방향
# 상어 - 상하좌우
#
# - 물고기 한 칸 이동
#     - 상어칸, 물고기냄새 칸, 격자범위 밖 이동 불가
#     - 현재 이동 방향에서 45도 반시계 회전으로 우선순위 방향 설정
#     - 이동 불가인 경우 이동X
#
# - 상어 3칸 이동
#     - 현재 칸에서 상하좌우로 인접한 칸 이동 (격자 범위 내에서)
#     - 이동 중 물고기 만나면 물고기 제외 + 물고기 냄새 남는다.
#     - 상어가 물고기를 가장 많이 만나는 방법으로 이동. 여러 가지인 경우 사전 순으로 가장 앞서는 방법 이용. (상 1, 좌 2, 하 3, 우 4) 방향을 숫자로 바꾸어 작은 수가 사전 순 앞
#
# - 냄새 업데이트
#     - 두 번 전 연습에서 생긴 물고기의 냄새를 격자에서 제거
#
# - 물고기 복제
#     - 1에서의 위치와 뱡항을 그대로 갖게 된다.
# """
#
#
# def move_fish():
#     new_board = [[0]*4 for _ in range(4)]
#
#     for fish in fish_info:
#         # 5 4 3 2 1 8 7 6
#         # 초기 방향이 있는 상태에서 45도씩 방향회전
#
#
#
#
# def move_shark():
#     pass
#
#
# def smell_update():
#     pass
#
#
# def copy_fish():
#     pass
#
#
# # params
# board = [[0]*4 for _ in range(4)]
#
# ## MAIN ##
# # M: 물고기수, S: 상어의 마법 연습 횟수
# M, S = map(int, input().split())
#
# fish_info = []
# for _ in range(M):
#     temp = list(map(int, input().split()))
#     fish_info.append([temp[0]-1, temp[1]-1, temp[2]-1])
#     board[temp[0]-1][temp[1]-1] = 1
#
# shark_info = list(map(int, input().split()))
# shark_info = [shark_info[0]-1, shark_info[1]-1]
# board[shark_info[0]][shark_info[1]] = 2
#
# for _ in range(S):
#     move_fish()
#     move_shark()
#     smell_update()
#     copy_fish()


# import sys
# input = sys.stdin.readline
#
# from collections import deque
#
# # params
# dy = (0, -1, -1, -1, 0, 1, 1, 1)
# dx = (-1, -1, 0, 1, 1, 1, 0, -1)
#
# sdy = (-1, 0, 1, 0)
# sdx = (0, -1, 0, 1)
#
#
# # function
# def move_fish(arr):
#     ret = [[[] for _ in range(4)] for _ in range(4)]
#     for y in range(4):
#         for x in range(4):
#             while arr[y][x]:
#                 d = arr[y][x].pop()
#
#                 # 배울 부분
#                 # for문에서 indexing // for ~ else 구문
#                 for i in range(d, d-8, -1):  # 4 3 2 1 0 7 6 5
#                     i %= 8
#                     ny = y + dy[i]
#                     nx = x + dx[i]
#                     if 0<=ny<4 and 0<=nx<4 and (ny, nx)!=shark and not smell[ny][nx]:
#                         ret[ny][nx].append(i)
#                         break  # break문에 의해 반복이 끝나면 else절은 수행X
#                 else:
#                     ret[y][x].append(d)
#
#     return ret
#
#
# def move_shark(s):
#     y, x = s
#     # q = deque()
#     q = []
#
#     # 현재y, 현재x, 방문좌표, 방향점수, 먹을 물고기 총 갯수
#     q.append((y, x, set(), '', 0))
#     for _ in range(3):
#         for _ in range(len(q)):
#             # y, x, visited, dir_score, cnt = q.popleft()
#             y, x, visited, dir_score, cnt = q.pop(0)
#             for k in range(4):
#                 ny = y + sdy[k]
#                 nx = x + sdx[k]
#                 if 0<=ny<4 and 0<=nx<4:
#                     if (ny, nx) in visited:
#                         q.append((ny, nx, visited, dir_score+str(k+1), cnt))
#                     else:
#                         # | : 합집합(union)
#                         q.append((ny, nx, visited | {(ny, nx)}, dir_score+str(k+1), cnt+len(tmp[ny][nx])))
#
#     # q = sorted(q, key=lambda x: (x[4], -int(x[3])))
#     q.sort(key=lambda x: (x[4], -int(x[3])))
#     # y, x, visited, dir_score, cnt = q.pop()
#     y, x, visited, dir_score, cnt = q[-1]
#     for i, j in visited:
#         if tmp[i][j]:
#             tmp[i][j].clear()
#             smell[i][j] = 3
#
#     return (y, x)
#
#
# # MAIN
# M, S = map(int, input().split())
# fishes = [list(map(lambda x:int(x)-1, input().split())) for _ in range(M)]
#
# # 각 칸마다 리스트로 공백 만들기 (한 칸에 2개 이상 객체 존재 가능하므로)
# matrix = [[[] for _ in range(4)] for _ in range(4)]
# for y, x, d in fishes:
#     matrix[y][x].append(d)
#
# shark = list(map(lambda x: int(x)-1, input().split()))
# smell = [[0]*4 for _ in range(4)]
# for _ in range(S):
#     # 모든 물고기 정보 복제 tmp. 5번에서 더해준다.
#     tmp = [[k[:] for k in row] for row in matrix]  # deepcopy 가능
#
#     tmp = move_fish(tmp)
#
#     shark = move_shark(shark)
#
#     # 물고기 냄새가 있는 칸은 매 연습마다 -1씩 감소
#     for i in range(4):
#         for j in range(4):
#             if smell[i][j]:
#                 smell[i][j] -= 1
#
#     for i in range(4):
#         for j in range(4):
#             matrix[i][j] += tmp[i][j]
#
#     # matrix += tmp  # 왜 결과가 달리 나오지??
#
# answer = 0
# for i in range(4):
#     for j in range(4):
#         answer += len(matrix[i][j])
#
# print(answer)


# https://devlibrary00108.tistory.com/662
import sys; input=sys.stdin.readline

dy = (0, -1, -1, -1, 0, 1, 1, 1)
dx = (-1, -1, 0, 1, 1, 1, 0, -1)

s_dy = (0, -1, 0, 1, 0)
s_dx = (0, 0, -1, 0, 1)


def move_fish(arr):
    new_board = [[[] for _ in range(4)] for _ in range(4)]
    for y in range(4):
        for x in range(4):
            while arr[y][x]:
                d = arr[y][x].pop()
                for i in range(d, d-8, -1):
                    i%=8
                    ny, nx = y+dy[i], x+dx[i]
                    # 비교할 때 자료형 같아야 된다. shark 자료형 리스트이기 때문.
                    if [ny, nx]!=shark and 0<=ny<4 and 0<=nx<4 and not smell[ny][nx]:
                        new_board[ny][nx].append(i)
                        break
                else:
                    new_board[y][x].append(d)
    return new_board


def move_shark(s):
    y, x = s
    q = []
    # 현재 좌표, 방문좌표, 방향 점수, 총갯수
    q.append((y, x, set(), '', 0))
    for _ in range(3):
        for _ in range(len(q)):
            y, x, visited, dir_score, cnt = q.pop(0)
            for i in range(1, 5):
                ny, nx = y+s_dy[i], x+s_dx[i]
                if 0<=ny<4 and 0<=nx<4:
                    if (ny, nx) in visited:
                        q.append((ny, nx, visited, dir_score+str(i), cnt))
                    else:
                        q.append((ny, nx, visited | {(ny, nx)}, dir_score+str(i), cnt+len(tmp[ny][nx])))

    q.sort(key=lambda x: (x[4], -int(x[3])))

    y, x, visited, dir_score, cnt = q[-1]
    for i, j in visited:
        if tmp[i][j]:
            tmp[i][j].clear()
            smell[i][j] = 3
    return [y, x]


# main
M, S = map(int, input().split())
fishes = [list(map(lambda x: int(x)-1, input().split())) for _ in range(M)]

# 물고기의 identity는 중요하지 않아. 방향만 중요해. 방향 1개가 물고기 한마리 나타낸다.
matrix = [[[] for _ in range(4)] for _ in range(4)]
for y, x, d in fishes:
    matrix[y][x].append(d)

shark = list(map(lambda x: int(x)-1, input().split()))
smell = [[0]*4 for _ in range(4)]
for _ in range(S):
    # 리스트 간 이어붙히기 안된다.
    # 위는 리스트가 참조하고 있는 객체의 주소를 복사한다.
    # tmp = [[k for k in row] for row in matrix]

    # 모든 물고기 정보 복제 tmp. 5번에서 더해줌
    # 실제 값 복사
    tmp = [[k[:] for k in row] for row in matrix]

    # 모든 물고기 한칸 이동.
    # 물고기 냄새 있거나 상어 있으면 이동 불가.
    # 모든 방향에 대해 이동 불가하다면 이동불가.
    tmp = move_fish(tmp)

    # 상어 연속 3칸 이동. 상하좌우로 인접한 칸으로 이동 가능. 범위를 벗어나면 불가능한 이동.
    shark = move_shark(shark)

    # 이동 중에 상어가 물고기 있는 칸으로 이동하면 그 칸의 모든 물고기는 삭제하고 냄새를 남김. 가능한 방법 중 제외되는 물고기가 가장 많은 방법으로 남긴다.
    # 여러 가지인 경우 사전순으로 이동. 상1, 좌2, 하3, 우4. 사전순 앞서는 경우로 이동.
    # 2턴 전 냄새 사라짐.
    for i in range(4):
        for j in range(4):
            if smell[i][j]:
                smell[i][j] -= 1

    # 물고기 배열 tmp fishes에 더해줌.
    for i in range(4):
        for j in range(4):
            matrix[i][j] += tmp[i][j]
    # 조심) matrix += tmp  <-- 리스트 연결된다.

# S번 연습 모두 마쳤을 때, 격자에 있는 물고기 수 구하기
answer = 0
for i in range(4):
    for j in range(4):
        answer += len(matrix[i][j])

print(answer)