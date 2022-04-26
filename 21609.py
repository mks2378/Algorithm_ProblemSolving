# # 검은색, 무지개, 일반
#
# from collections import deque
# import sys
# input = sys.stdin.readline
#
#
# def bfs(x, y):
#     q = deque()
#     temp_q = list()
#     rainbow_cnt = 0
#
#     tx = x
#     ty = y
#
#     temp_q.append([x, y])
#     q.append([x, y])
#     main_val = board[x][y]
#
#     while q:
#         cx, cy = q.popleft()
#
#         for k in range(4):
#             nx = cx + dx[k]
#             ny = cy + dy[k]
#
#             if 0<=ny<N and 0<=nx<N and board[nx][ny]>=0 and board[nx][ny]==main_val:
#                 q.append([nx, ny])
#                 temp_q.append([nx, ny])
#
#                 if board[nx][ny]>0:
#                     board[nx][ny] = -1
#
#                     if nx<tx:
#                         tx = nx
#                         ty = ny
#                     elif nx==tx and ny<ty:
#                         ty = ny
#                 else:
#                     rainbow_cnt+=1
#
#     return temp_q
#
#
# dx = [1, -1, 0, 0]
# dy = [0, 0, 1, -1]
#
# N, M = map(int, input())
# graph = [list(map(int, input().split())) for _ in range(N)]
#
# answer = 0
# while True:
#     max_cnt = 1
#     max_group = None
#     max_rb_cnt = 0
#
#     board = graph.copy()
#     main_x, main_y = N, N
#
#     for i in range(N):
#         for j in range(N):
#             if board[i][j]>0:
#                 temp_group, temp_x, temp_y, temp_rb_cnt = bfs(i, j, board)
#                 if len(temp_group)>max_cnt:
#                     max_group = temp_group
#                     max_cnt = len(temp_group)
#                 elif len(temp_group)==max_cnt:
#                     if temp_rb_cnt>max_rb_cnt:
#                         max_group = temp_group
#                         max_cnt = len(temp_group)
#                     elif temp_rb_cnt==max_rb_cnt:
#
#
#     # 블록 그룹 존재 유무
#     if max_cnt == 1:
#         break
#
#     # 점수 계산
#     answer += (max_cnt**2)
#
#     # 중력 - 90도 반시계 - 중력
#     for y, x in max_group:
#         graph[y][x] = None
#
#     for i in range(N):
#         for j in range(N):


from collections import deque
import sys
input = sys.stdin.readline

# 인접 블록 찾기 -> 블록 크기, 무지개 크기, 블록좌표 리턴
def bfs(x, y, color):
    q = deque()
    q.append([x, y])
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    block_cnt, rainbow_cnt = 1, 0 # 블록개수, 무지개블록 개수
    blocks, rainbows = [[x, y]], []

    while q:
        cx, cy = q.popleft()
        for d in range(4):
            nx = cx + dx[d]
            ny = cy + dy[d]

            # 범위 안이면서 방문 안한 일반 블록인 경우
            if 0<=nx<N and 0<=ny<N and not visited[nx][ny] and a[nx][ny] == color:
                visited[nx][ny] = 1
                q.append([nx, ny])
                blocks.append([nx, ny])
                block_cnt += 1

            # 범위 안이면서 방문 안한 무지개 블록인 경우
            elif 0<=nx<N and 0<=ny<N and not visited[nx][ny] and a[nx][ny] == 0:
                visited[nx][ny] = 1 # 다른 컬러에서 시작할 때 방문을 못 하지 않나??
                q.append([nx, ny])
                block_cnt += 1
                rainbow_cnt += 1
                rainbows.append([nx, ny])

    # 무지개블록은 방문 다시 해제
    for x, y in rainbows:
        visited[x][y] = 0

    return [block_cnt, rainbow_cnt, blocks+rainbows]


# 블록 제거 함수
def remove(block):
    for x, y in block:
        a[x][y] = -2


# 중력 함수
def gravity(a):
    for i in range(N-2, -1, -1):  # 밑에서부터 체크
        for j in range(N):
            if a[i][j]>-1: # -1이 아니면 아래로 다운
                r = i
                while True:
                    # 다음 행이 인덱스 범위 안이면서 빈칸(-2)이면 아래로 이동
                    if 0<=r+1<N and a[r+1][j] == -2:
                        a[r+1][j] = a[r][j]
                        a[r][j] = -2
                        r += 1
                    else:
                        break


# 반시계 회전 함수
def rot90(a):
    new_a = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            new_a[N-1-j][i] = a[i][j]

    return new_a

# 시계 회전은?? 구현해볼 것


# 0. main
N, M = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(N)]

score = 0

# 1. 오토플레이 -> while {2.크기 가장 큰 블록 찾기 3.블록제거+점수더하기 4.중력 5.90회전 6.중력}
while True:
    # 2.크기 가장 큰 블록 찾기
    visited = [[0]*N for _ in range(N)]  # 방문체크
    blocks = [] # 가능한 블록 그룹들 넣을 리스트
    for i in range(N):
        for j in range(N):
            # 일반블록이면서 방문x
            if a[i][j]>0 and not visited[i][j]:
                visited[i][j] = 1  # 방문
                block_info = bfs(i, j, a[i][j])  # 인접 블록 찾기

                # block_info = [블록크기, 무지개블록 개수, 블록좌표]
                if block_info[0]>=2:
                    blocks.append(block_info)

    blocks.sort(reverse=True)

    # 3.블록제거+점수더하기
    if not blocks:
        break

    remove(blocks[0][2])
    score += blocks[0][0]**2

    # 4.중력
    gravity(a)

    # 5.90도 회전
    a = rot90(a)

    # 6. 중력
    gravity(a)

print(score)