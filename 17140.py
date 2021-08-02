# 이차원 배열과 연산 (BOJ_17140)
"""
크기 3x3 배열 A, 인덱스 1부터 시작. 1초마다 배열에 연산 적용

R연산: 행>=열 -> 모든 행에 대해 정렬 수행
C연산  열>행 -> 모든 열에 대해 정렬 수행

행 또는 열 어떻게 정렬
1. 등장 횟수 커지는 순으로
2. 등장 횟수 같다면, 수가 커지는 순으로.
3. 배열 A에 정렬된 결과 다시 넣는다. 이 때, 수와 등장횟수 모두 넣는다. 순서는 수가 왼쪽에.
4. 다시 넣으면 행 또는 열 크기가 달라질 수 있다. 가장 큰 행 또는 열 기준에 맞춘다. 빈 곳은 0.
   (수를 정렬할 때 0은 무시. [3, 2, 0, 0]은 0 빼고 정렬
5. 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개 제외한 나머지는 버린다.

# 100초가 지나도 A[r][c] = k 가 되지 않으면 -1 출력
"""

from collections import Counter
import sys
input = sys.stdin.readline

# input이 제대로 들어갔는지는 처음에 구현하고 바로 확인
r, c, k = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(3)]

find = False
time = 0
while time <= 100:
    # *** 좌표값과 실제 리스트의 인덱스와 매칭 안되는 실수 조심
    if r <= len(maps) and c <= len(maps[0]) and maps[r-1][c-1] == k:
        print(time)
        find = True
        break

    time += 1
    max_col = 0
    next_maps = []  # next 또는 new 라는 wording

    # R연산
    if len(maps) >= len(maps[0]):
        for rows in maps:
            next_row = []

            # 행의 정수 빈도는 collections 모듈의 Counter를 사용하자.
            # Counter는 딕셔너리 형태(key, value)로 반환
            count_table = sorted(list(Counter(rows).items()), key=lambda x: (x[1], x[0]))

            for num, cnt in count_table:
                # 배열 A에 들어있는 수는 100보다 작거나 같은 자연수
                if num == 0:
                    continue
                next_row.append(num)
                next_row.append(cnt)
            max_col = max(max_col, len(next_row))
            next_maps.append(next_row)

        # 가장 긴 row 길이에 맞게 0 개수 채우기
        for rows in next_maps:
            if len(rows) < max_col:
                for _ in range(max_col - len(rows)):
                    rows.append(0)
        maps = next_maps
        continue

    # C연산
    else:
        # 2차원 list transpose - 리스트 연산이 편하다.
        maps = list(map(list, zip(*maps)))
        for rows in maps:
            next_row = []

            # 행의 정수 빈도는 collections 모듈의 Counter를 사용하자.
            count_table = sorted(list(Counter(rows).items()), key=lambda x: (x[1], x[0]))
            # 딕셔너리 key, value를 리스트 요소로 받기
            for num, cnt in count_table:
                if num == 0:
                    continue
                next_row.append(num)
                next_row.append(cnt)

            max_col = max(max_col, len(next_row))
            next_maps.append(next_row)

        # 가장 긴 row 길이에 맞게 0 개수 채우기
        for rows in next_maps:
            if len(rows) < max_col:
                for _ in range(max_col - len(rows)):
                    rows.append(0)

        # C연산 후 다시 원상태로 transpose
        maps = list(map(list, zip(*next_maps)))
        continue

if not find:
    print(-1)


### 공부할 부분 ###
# from collections import Counter
# 튜플을 어느 기준에 따라 정렬할지 (key값 주기)
# sorted(), .sort() 차이점
# zip() 이용한 transpose

