# 톱니바퀴 (boj_14891)
# 19:54 ~ 21:15
"""
회전시킬 톱니바퀴, 회전시킬 방향 결정
회전할 때, 맞닿은 극에 따라 옆 톱니바퀴 회전 할 수도 있고, 안할 수도 있다.
맞닿은 극이 다르면, 반대시계 방향
맞닿은 극이 같으면, 회전 안한다. (단, 안움직였다면 그 뒤에 톱니바퀴들도 움직이지 않는다.)

톱니바퀴 초기 상태와 톱니바퀴 회전 방법 주어졌을 때, 최종 톱니바퀴 상태 구하기
"""

# 각 톱니바퀴는 12시 방향부터 시계 방향순서대로 주어진다. N극은 0, S극은 1
# 회전 횟수 K
# 다음 K개 줄에는 회전시킨 톱니바퀴 번호, 회전방향(1: 시계방향, -1: 반시계방향) 주어진다.
# 각 톱니바퀴 12시 방향이 N극이면 0점
# 각 톱니바퀴 12시 방향이 S극이면 1,2,3,4순서대로 1, 2, 4, 8점

from collections import deque
import sys
input = sys.stdin.readline

tire1 = deque(list(map(int, input().strip())))
tire2 = deque(list(map(int, input().strip())))
tire3 = deque(list(map(int, input().strip())))
tire4 = deque(list(map(int, input().strip())))

K = int(input())
order = [list(map(int, input().split())) for _ in range(K)]

for k in range(K):
    # order로부터 주어진 회전시킬 톱니바퀴, 회전방향을 기준으로 4개 톱니바퀴 업데이트
    # 1번의 [2], 2번의 [6] 비교
    # 2번의 [2], 3번의 [6] 비교
    # 3번의 [2], 4번의 [6] 비교

    t1, t2, t3, t4 = 0, 0, 0, 0  # 1 시계, -1, 반시계, 0 그대로
    tire = order[k][0]
    if tire == 1:
        t1 = order[k][1]

        if tire1[2] != tire2[6]:
            t2 = -1 if t1 == 1 else 1
        if tire2[2] != tire3[6] and t2 != 0:
            t3 = -1 if t2 == 1 else 1
        if tire3[2] != tire4[6] and t3 != 0:
            t4 = -1 if t3 == 1 else 1

    elif tire == 2:
        t2 = order[k][1]

        if tire1[2] != tire2[6]:
            t1 = -1 if t2 == 1 else 1
        if tire2[2] != tire3[6]:
            t3 = -1 if t2 == 1 else 1
        if tire3[2] != tire4[6] and t3 != 0:
            t4 = -1 if t3 == 1 else 1

    elif tire == 3:
        t3 = order[k][1]

        if tire3[2] != tire4[6]:
            t4 = -1 if t3 == 1 else 1
        if tire3[6] != tire2[2]:
            t2 = -1 if t3 == 1 else 1
        if tire2[6] != tire1[2] and t2 != 0:
            t1 = -1 if t2 == 1 else 1

    else:
        t4 = order[k][1]

        if tire4[6] != tire3[2]:
            t3 = -1 if t4 == 1 else 1
        if tire3[6] != tire2[2] and t3 != 0:
            t2 = -1 if t3 == 1 else 1
        if tire2[6] != tire1[2] and t2 != 0:
            t1 = -1 if t2 == 1 else 1

    # 바퀴 업데이트
    if t1 == 1:
        temp = tire1.pop()
        tire1.appendleft(temp)
    elif t1 == -1:
        temp = tire1.popleft()
        tire1.append(temp)
    if t2 == 1:
        temp = tire2.pop()
        tire2.appendleft(temp)
    elif t2 == -1:
        temp = tire2.popleft()
        tire2.append(temp)
    if t3 == 1:
        temp = tire3.pop()
        tire3.appendleft(temp)
    elif t3 == -1:
        temp = tire3.popleft()
        tire3.append(temp)
    if t4 == 1:
        temp = tire4.pop()
        tire4.appendleft(temp)
    elif t4 == -1:
        temp = tire4.popleft()
        tire4.append(temp)

# 각 톱니바퀴 12시 방향이 S극이면 1,2,3,4순서대로 1, 2, 4, 8점
# total은 각 tire에서 0번째 값을 현재 위치 값이 N인지 S인지 보고 기준에 따라 더해서 출력
total = 0
total += 1 if tire1[0] == 1 else 0
total += 2 if tire2[0] == 1 else 0
total += 4 if tire3[0] == 1 else 0
total += 8 if tire4[0] == 1 else 0

print(total)
