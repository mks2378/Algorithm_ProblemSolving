# import sys
# input = sys.stdin.readline
#
# from collections import deque
# from copy import deepcopy
#
#
# """
# 이동은 항상 최단거리. 상하좌우 인접 칸 이동 가능.
# 1. 손님으로 이동
#     - 현재 택시 위치에서 최단거리가 가장 짧은 고객한테 이동
#         - 여러 명이면 행, 열 순으로 짧은 승객.
#         - 택시, 승객이 같은 위치 = 최단거리 0
#     - 주행거리에 따른 연료 차감
# 2. 목적지로 이동
#     - 주행 완료 -> 주행거리에 x2 주유
#     - 연료 바닥 -> 주행 실패
#
# * 이동 도중에 연료가 바닥나서 다음 출발지나 목적지로 이동할 수 없으면 -1 출력
# * 모든 손님을 이동시킬 수 없는 경우에도 -1 출력
# """
#
#
# # params
# dy = [0, 0, 1, -1]
# dx = [1, -1, 0, 0]
#
#
# def move_to_start(g_info):
#     # 출발 y,x / 도착 y,x
#     selected_guest = None
#
#     visited = deepcopy(board)
#     q = deque()
#     y, x = taxi_pos[0], taxi_pos[1]
#
#     q.append([y, x, 0])
#     visited[y][x] = True
#
#     while q:
#         cy, cx, dist = q.popleft()
#         for k in range(4):
#             ny = y + dy[k]
#             nx = x + dx[k]
#
#             if 0<=ny<N and 0<=nx<N and not visited[ny][nx]:
#                 if [ny, nx] in g_info:
#                     pass
#             ## guest 위치 찾은 다음에 기존 guest_start_info에서 이것만 어떻게 빼지?
#             ## del 써서?
#
#                 q.append([ny, nx, dist+1])
#                 visited[ny][nx] = True
#
#     # min(selected_guest)
#
#
# def move_to_end():
#     pass
#
#
# # MAIN
# # N: 격자 길이, M: 승객 수, gas: 택시 연료
# N, M, gas = map(int, input().split())
#
# board = []
# wall_position = []
# for i in range(N):
#     temp = list(map(int, input().split()))
#     for j in range(N):
#         if temp[j] == 1:
#             wall_position.append([i, j])
#     board.append(temp)
#
# taxi_pos = list(map(int, input().split()))
# taxi_pos = [taxi_pos[0] - 1, taxi_pos[1] - 1]
#
# guest_move_info = []
# for _ in range(M):
#     temp = list(map(int, input().split()))
#     guest_move_info.append([temp[0] - 1, temp[1] - 1, temp[2] - 1, temp[3] - 1])
#
# for _ in range(M):
#     move_to_start(guest_move_info[:][:2])
#     move_to_end()
#
#     if gas<=0:
#         gas=-1
#         break
#
# print(gas)


# https://youbin-shin.github.io/posts/sp-baekjoon-19238/
import sys; input = sys.stdin.readline
from collections import deque

def FindPassenger(taxi): # 최단 경로의 손님을 찾는 함수
    q = deque()
    q.append(taxi)
    visited = [[0]*N for _ in range(N)]
    minDistance = int(1e9)
    candidate = []  # 최단 경로인 승객들을 저장할 리스트
    while q:  # BFS를 이용하여 최단 경로 탐색
        y, x = q.popleft()
        
        # 각 손님들의 도달 경로 모두 구할 필요 없기 때문
        if visited[y][x] > minDistance:
            break
        if [y, x] in passenger_start:  # 최단 경로 손님 찾기
            minDistance = visited[y][x]
            candidate.append([y, x])
        else:
            for d in range(4):
                ny, nx = y + dy[d], x + dx[d]
                if 0<=ny<N and 0<=nx<N and road[ny][nx]!=1 and visited[ny][nx]==0:
                    visited[ny][nx] = visited[y][x] + 1
                    q.append([ny, nx])

    # 가장 크거나, 짧은거 찾을 때 or 행, 열 위치 좌표 대소 비교 -> 정렬 생각.
    if candidate:
        candidate.sort()  # 최단 경로, 행, 열을 기준으로 오름차순으로 정렬
        return visited[candidate[0][0]][candidate[0][1]], candidate[0][0], candidate[0][1]
    else:  # 손님한테 갈 수 없는 경우
        return -1, -1, -1

def GoDestination(start, end):
    q = deque()
    q.append(start)
    visited = [[0]*N for _ in range(N)]
    while q:  # BFS 이용하여 최단 경로 탐색
        y, x = q.popleft()
        if [y, x] == end:
            break
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if 0<=ny<N and 0<=nx<N and road[ny][nx]!=1 and visited[ny][nx]==0:
                visited[ny][nx] = visited[y][x] + 1
                q.append([ny, nx])

    return visited[y][x], y, x


# MAIN
N, M, fuel = map(int, input().split())  # 보드 길이, 승객 수, 연료
road = [list(map(int, input().split())) for _ in range(N)]
# ty, tx = map(int, input().split())
taxi = list(map(lambda x:int(x)-1, input().split()))

passenger_start = []  # 손님들의 출발지 리스트
passenger_end = []  # 손님들의 도착지 리스트
for _ in range(M):
    sy, sx, ey, ex = map(lambda x: int(x)-1, input().split())
    passenger_start.append([sy, sx])
    passenger_end.append([ey, ex])

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

for _ in range(M):
    distance, py, px = FindPassenger(taxi)  # 최단 경로의 손님을 찾는 함수
    if distance == -1 or fuel - distance<0:  # 손님에게 못가거나 연료가 떨어지는 종료조건
        fuel = -1
        break

    fuel -= distance  # 손님한테 가는 길에 사용한 연료 계산
    idx = passenger_start.index([py, px])  # 최단 경로의 손님의 인덱스 찾기
    passenger_start[idx] = [-1, -1]  # 손님을 태웠기에 FindPassenger에서 제외되기 위해 [-1, -1]로 설정.
    distance2,  py2, px2 = GoDestination([py, px], passenger_end[idx])  # 손님의 목적지로 가는 함수
    if [py2, px2] != passenger_end[idx] or fuel-distance2<0:  # (도척지에 도달 못하거나 연료가 떨어지는 중료조건
        fuel = -1
        break

    # 손님을 도착지에 잘 데려다준 경우
    fuel += distance2  # 도착지까지 연료를 -distance 사용하고 충전이 +distance*2 이기에 최종적으로 +distance 수행
    taxi = [py2, px2]  # 택시 위치 갱신하기

print(fuel)
