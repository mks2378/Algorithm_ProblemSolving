# 어항 정리

"""
1. 물고기 수 가장 작은 어항에 물고기 한마리 넣는다. 여러 개일 경우 각각 한마리씩 넣는다.
2. 맨 왼쪽 한칸 어항을 오른쪽 어항 위에 쌓기
2. 맨 왼쪽에 쌓인 2개의 어항을 90도 회전해서 남은 어항 맨 왼쪽에 쌓기
3. 쌓인 어항이 있다면 공중 부양 후, 90도 회전 후 나머지 바닥 어항에 쌓기. 이 때, 공중 부양해서 90도 회전햇을 때 아래 변이 바닥 변보다 길면 안된다.
4. 물고기 수 차이 구하여 물고기 보내기.
5. 바닥에 일렬 나열 - 맨 왼쪽 열붜 90도 회전해서 바닥에 펴기
6. 이번에는 절반 왼쪽을 180도 회전해서 바닥 어항에 올리기
7. 다시 절만을 180도 회전해서 바닥 어항에 올리기.
8. 4번 작업 다시 수행.
9. 5번 수행.
10. '가장 많은 물고기 - 가장 적은 물고기' K 이하가 되게 하려면 어항을 몇 번 정리해야 하는지 출력
"""


import sys; input = sys.stdin.readline
from collections import deque


# 최솟값들에 대해 1 더해준다.
def engage_minimum():
    min_v = min(arr)
    for i in range(N):
        if arr[i] == min_v:
            arr[i] += 1


def make_snail():
    row, col = n, n  # n: 새로 만드는 배열의 한 변 길이
    if n**2 - N >= n:
        col-=1
    matrix = [[0] * col for _ in range(row)]
    q = deque()
    q.append((row-1, col-1, 0))
    blank_cnt = row*col - N
    start = N -1
    while q:
        y, x, d = q.popleft()
        matrix[y][x] = arr[start]
        if blank_cnt:
            matrix[y][x] = -1
        for i in range(d, d+4):
            i%=4
            ny, nx = y+delta[i][0], x+delta[i][1]
            if 0<=ny<row and 0<=nx<col and not matrix[ny][nx]:
                q.append((ny, nx, i))
                if blank_cnt:
                    blank_cnt -= 1
                else:
                    start-=1
                break
    return matrix


def spread(matrix):
    row = len(matrix)
    col = len(matrix[0])
    new_matrix = [[0]*col for _ in range(row)]
    if matrix[-1][-1] == -1:
        row -= 1
        a, b = row-1, row
        # 맨 아래 행에 x가 깔리게끔 달팽이를 말았기 때문에 맨 아래 왼쪽 끝 포인트가
        # 바로 위에 포인트와 변화량을 먼저 계산해주어야 원래대로인 x 위에 오지 않도록
        # 달팽이를 말았을 때의 변화량 계산을 하는 것과 같다.
        # 결론적으로 도형을 공중부양해서 올렸을 때 맨 아래 행보다 길지 않게끔 최대한
        # 말았을 때, 맨 아래 행 중 위에 도형이 없는 튀어나온 상자들에 대해 변화량 계산
        # 그 때 위에 도형이 있는 맨 아래 상자와 맞닿는 위에 도형이 없는 상자에 대해 계산
        if matrix[a][0]!=-1 and matrix[b][0]!=-1:
            if matrix[a][0]<matrix[b][0]:
                a, b = b, a
            move = (matrix[a][0] - matrix[b][0]) // 5
            new_matrix[a][0] -= move
            new_matrix[b][0] += move
        # 위에 도형이 없는 상자들에 대한 변화량 계산
        for x in range(col):
            if matrix[row][x] == -1:
                break
            for dx in (1, -1):
                nx = x + dx
                if 0<=nx<col and matrix[row][nx]!=-1:
                    if matrix[row][x] - matrix[row][nx] < 5:
                        continue
                    move = (matrix[row][x] - matrix[row][nx])//5
                    new_matrix[row][nx]+=move
                    new_matrix[row][x]-=move

    for y in range(row):  # matrix[-1][-1] == -1 이라면, row가 원래보다 -1 상태
        for x in range(col):
            for dy, dx in delta:
                ny, nx = y + dy, x + dx
                if 0<=ny<row and 0<=nx<col:
                    if matrix[y][x] - matrix[ny][nx]<5:
                        continue
                    move = (matrix[y][x] - matrix[ny][nx])//5
                    new_matrix[ny][nx]+=move
                    new_matrix[y][x]-=move
    if matrix[-1][-1] == -1:
        row+=1
    for i in range(row):
        for j in range(col):
            matrix[i][j]+=new_matrix[i][j]

    return matrix


# 달팽이인데 오른쪽 아래 빈칸 상태면 왼쪽 위부터 행을 순서대로 읽는다.
# 완전한 정사각형이면 왼쪽 아래부터 위로 열을 순서대로 읽는다.
def make_arr(matrix):
    row = len(matrix)
    col = len(matrix[0])
    ret = []
    if matrix[-1][-1] == -1:
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == -1:
                    continue
                ret.append(matrix[i][j])
    else:
        for j in range(col):
            for i in range(row-1, -1, -1):
                ret.append(matrix[i][j])
    return ret


# 행 4개에 분배하기. 배열 4등분 해서 뒤집은 3번째, 2번째, 뒤집은 1번째, 4번째 순
def make_four_row(arr):
    new_matrix = []
    new_matrix.append(arr[pivot*2:pivot*3][::-1])
    new_matrix.append(arr[pivot:pivot*2])
    new_matrix.append(arr[:pivot][::-1])
    new_matrix.append(arr[pivot*3:])
    return new_matrix


# main
N, K = map(int, input().split())
arr = list(map(int, input().split()))
pivot = N//4
for i in range(2, 11):
    if i**2 >=N:
        n = i
        break

delta = ((0, -1), (-1, 0), (0, 1), (1, 0))

answer = 0
while max(arr) - min(arr) > K:
    # 1. 최솟값들에 대해 1씩 넣어준다.
    engage_minimum()

    # 2. 왼쪽을 중앙으로 시작해서 달팽이.
    # N보다 큰 제곱수의 2차원 배열을 만든 후 남는 칸수만큼 오른쪽에서 offset을 준 뒤 달팽이 하며 감아 들어가면 된다.
    matrix = make_snail()

    # 3. 달팽이에서 인접한 검사 (a-b) // 5만큼 분배. 동시 분배.
    matrix = spread(matrix)

    # 4. 펼치는건 왼쪽 아래부터 위로
    arr = make_arr(matrix)

    # 5. 첫 N // 4는 뒤집어서 2행, 다음 N//4는 그대로 1행, 그 다음 N//4는 뒤집어서 0행, 마지막 N//4는 그대로 3행.
    matrix = make_four_row(arr)

    # 6. 물고기 분배 한 번 더.
    matrix = spread(matrix)

    # 7. 1열부터 펼치면 3행부터 거꾸로 올라가며 펼치면 된다.
    arr = make_arr(matrix)
    answer += 1

print(answer)
