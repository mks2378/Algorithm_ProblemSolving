import sys
input = sys.stdin.readline

"""
격자 가운데 칸부터 토네이도의 이동 시작.
토네이도가 한 칸 이동할 때마다 모래는 다음과 같이 일정한 비율로 흩날리게 된다.

토네이도 x->y일 때
    - 비율이 있으면 비율만큼 모래가 이동하고, 계산에서 소수점 아래는 버린다.
    - alpha로 이동하는 모래의 양은 비율이 적혀있는 칸으로 이동하지 않은 남은 모래 이동.
    
    - 모레가 이미 있는 칸으로 모래가 이동하면, 모래의 양은 더해진다.
    
   
토네이도 (1,1)까지 이동한 뒤 소멸.
소멸 뒤, 격자 밖으로 나간 모래의 양 구하기.  
"""


# 모래 계산하는 함수
def recount(s_x, s_y, direction):
    global ans

    if s_y<0:
        return

    # 3. a, out_sand
    total = 0  # a 구하기 위한 변수
    for dx, dy, z in direction:
        nx = s_x + dx
        ny = s_y + dy
        if z != 0:  # 비율
            new_sand = int(sand[s_x][s_y] * z)
            total += new_sand
        else:  # a(나머지)
            new_sand = sand[s_x][s_y] - total

        if 0<=nx<N and 0<=ny<N:  # 인덱스 범위이면 값 갱신
            sand[nx][ny] += new_sand
        else:  # 범위 밖이면 ans 카운트
            ans += new_sand


# MAIN
N = int(input())
sand = [list(map(int, input().split())) for _ in range(N)]

# 2.방향별 모래 비율 위치
left = [(1, 1, 0.01), (-1, 1, 0.01), (1, 0, 0.07), (-1, 0, 0.07), (1, -1, 0.1), (-1, -1, 0.1), (2, 0, 0.02), (-2, 0, 0.02), (0, -2, 0.05), (0, -1, 0)]
right = [(x, -y, z) for x,y,z in left]
down = [(-y, x, z) for x,y,z in left]
up = [(y, x, z) for x,y,z in left]

s_x, s_y = N//2, N//2
ans = 0
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

# 1. 토네이도 회전 방향(y위치)
dict = {0: left, 1: down, 2: right, 3: up}
time = 0
for i in range(2*N-1):
    # 몫: i//4(타임+1), 나머지:i%4(방향)
    d = i%4
    if d == 0 or d == 2:  # 다음 회차(d==0) 이거나 right(d==2) 이면 한번 더
        time += 1

    for _ in range(time):
        n_x = s_x + dx[d]
        n_y = s_y + dy[d]
        recount(n_x, n_y, dict[d])  # y좌표, 방향
        s_x, s_y = n_x, n_y

print(ans)