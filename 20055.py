# # 컨베이어 벨트 위의 로봇
#
# import sys; input = sys.stdin.readline
# from copy import deepcopy
#
#
# # function
# def move_belt(start_idx):
#     # new_belt_robot = deepcopy(belt_robot)  # 2차원 배열 복사 직접 구현?!
#     new_belt_robot = [0] * (2*N)
#
#     if start+N-1 < 2*N:
#         for i in range(0, 2*N):
#             if start<=i<=start+N-1 and not belt_robot[i] and belt_power[i]!=0:
#                 if i == start:
#                     new_belt_robot[i] = 1
#                 elif i == start+N-1:
#                     new_belt_robot[i] = 0
#                 else:
#                     new_belt_robot[i] = belt_robot[i-1]
#                 belt_power[i]-=1
#             else:
#                 new_belt_robot[i] = 0
#     else:
#         for i in range(0, 2*N):
#             if (start<=i<2*N or 0<=i<(start+N-1) % N) and not belt_robot[i] and belt_power[i]!=0:
#                 if i == start:
#                     new_belt_robot[i] = 1
#                 elif i == start+N-1:
#                     new_belt_robot[i] = 0
#                 else:
#                     new_belt_robot[i] = belt_robot[i-1]
#                 belt_power[i]-=1
#             else:
#                 new_belt_robot[i] = 0
#
#     return new_belt_robot
#
#
# def check_durability():
#     num_k = 0
#     for i in range(2*N):
#         if belt_power[i] == 0:
#             num_k += 1
#
#     if num_k>=K:
#         return True
#     else:
#         return False
#
#
# # main
# N, K = map(int, input().split())
#
# belt_power = list(map(int, input().split()))  # 내구성
# belt_robot = [0]*(2*N)  # 0 or 1
#
# cnt = 0
# start = 2*N-1
# while True:
#     cnt+=1
#
#     start = start%(2*N)
#     belt_robot = move_belt(start)
#
#     if check_durability():
#         break
#
#     start -= 1
#
# print(cnt)


import sys; input = sys.stdin.readline
from collections import deque

N, K = map(int, input().split())
belt = deque(list(map(int, input().split())))  # 내구도
robot = deque([0]*N)  # 해당 위치에 로봇 유무
answer = 0

while True:
    robot.rotate(1)
    belt.rotate(1)
    robot[-1] = 0

    for i in range(N-2, -1, -1):
        if robot[i] and not robot[i+1] and belt[i+1]:
            belt[i+1] -= 1
            robot[i+1] = 1
            robot[i] = 0
    robot[-1] = 0

    if not robot[0] and belt[0]>0:
        robot[0] = 1
        belt[0] -= 1

    answer += 1
    if belt.count(0)>=K:
        break

print(answer)
        
        
"""
deque.rotate(1)
1: deque 내에서 오른쪽으로 1칸씩 이동
-1: deque 내에서 왼쪽으로 1칸씩 이동
"""