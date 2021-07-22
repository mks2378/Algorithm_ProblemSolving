import sys
from collections import deque

# positions for obstacles
# 조합 구하기
def get_combinations():
    combi = []

    for i in range(len(space)):
        for j in range(i+1, len(space)):
            for k in range(j+1, len(space)):
                combi.append([i, j, k])

    return combi

# teacher moving
def bfs():
    obstacles = get_combinations()

    # 장애물이 있을 수 있는 모든 경우의 수에 대해 서치
    for obs in obstacles:
        success = True
        queue = deque(teacher)  # list to queue

        # graph 값을 바꾸면 새로운 장애물 위치마다 graph 초기화가 어려우므로 visited 이용
        # 장애물, 선생님, 학생에 대해 visited 초기화 
        obs1 = space[obs[0]]
        obs2 = space[obs[1]]
        obs3 = space[obs[2]]

        visited = [[False for _ in range(N)] for _ in range(N)]
        visited[obs1[0]][obs1[1]] = True
        visited[obs2[0]][obs2[1]] = True
        visited[obs3[0]][obs3[1]] = True

        for t in teacher:
            visited[t[0]][t[1]] = True
        for s in student:
            visited[s[0]][s[1]] = True

        # teacher가 이동할 수 있는 모든 위치에 대해서 주변 확인
        while queue:
            cur_x, cur_y, cur_dx, cur_dy = queue.popleft()

            nx = cur_x + cur_dx
            ny = cur_y + cur_dy

            # 위치에 대한 예외 처리 (map에서 항상)
            if 0<=nx<N and 0<=ny<N:
                # student일 때
                if graph[nx][ny] == 'S':
                    # 성공 여부를 false로 바꾸고 현재 obstacle 위치에 대해서 서치 중지 
                    success = False   
                    break

                # obstacles일 때
                if nx == obs1[0] and ny == obs1[1]: continue
                if nx == obs2[0] and ny == obs2[1]: continue
                if nx == obs3[0] and ny == obs3[1]: continue

                # teacher 일 때
                if visited[nx][ny]:
                    continue
                # empty space 일 때
                else:
                    queue.append((nx, ny, cur_dx, cur_dy))

        # student를 한 번도 만나지 않았다면, success는 True 유지 -> 성공 
        if success:
            return True


input = sys.stdin.readline
N = int(input())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

graph = []
space = []
student = []
teacher = []
for i in range(N):
    graph.append(list(input().split()))
    for j in range(N):
        if graph[i][j] == 'X':
            space.append((i, j))
        if graph[i][j] == 'S':
            student.append((i, j))

        # 처음 시작할 때 4 가지 방향이 같이 주어져서 queue에 삽입
        # queue에서 나올 때 같은 방향으로 계속 이동 위해
        if graph[i][j] == 'T':
            for k in range(4):
                teacher.append((i, j, dx[k], dy[k]))

if bfs():
    print('YES')
else:
    print('NO')
