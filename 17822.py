import sys; input = sys.stdin.readline
from collections import deque

dy = (0, 0, -1, 1)
dx = (1, -1, 0, 0)

# main
N, M, T = map(int, input().split())  # N개 원판, 각 원판에 M개 원소, T번 회전
circles = [deque([[] for _ in range(M)]) for _ in range(N)]

for i in range(N):
    nums = list(map(int, input().split()))
    for j in range(M):
        circles[i][j].append(nums[j])

cmds = [list(map(int, input().split())) for _ in range(T)]

for x, d, k in cmds:  # x의 배수 원판, d방향, k칸 회전
    # 원판 회전
    if d == 1: # 반시계
        k*=(-1)

    c = x-1
    while c<N:  # c<=N
        circles[c].rotate(k)
        c+=x

    # 후처리 연산
    same = False
    visited = [[0]*M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            deleted = False
            if circles[i][j] and not visited[i][j]:
                # q = deque([i, j])
                q = deque()
                q.append([i, j])  # 이거 한 번에 선언 못하려나
                visited[i][j] = 1
                while q:
                    cy, cx = q.popleft()
                    for d in range(4):
                        # N이 1~N이면 %4가 안먹힐듯. 인덱스 0을 사용해서.
                        ny = cy + dy[d]
                        nx = (cx + dx[d])%M  # 리스트 length가 동적으로 변할 수 있기 때문.
                        if 0<=ny<N and 0<=nx<M and not visited[ny][nx]:
                            # print(circles[ny][nx])
                            if circles[ny][nx] and circles[i][j] == circles[ny][nx]:
                                deleted = True
                                circles[ny][nx].clear()
                                q.append([ny, nx])
                                visited[ny][nx] = 1

                if deleted:
                    circles[i][j].clear()
                    same = True

    # 인접하면서 같은 수가 없을 때.
    # 1~N개 원판에 대해 평균 구한다. 이 때, 값이 없는 것들은 카운트에서 제외
    if not same:
        total = 0
        cnt = 0
        for i in range(N):
            for j in range(M):
                if circles[i][j]:
                    total += circles[i][j][0]
                    cnt+=1

        # 나누는 수가 0일 때 조심해야 돼
        if cnt == 0:
            avg = 0
        else:
            avg = total/cnt

        for i in range(N):
            for j in range(M):
                if circles[i][j]:
                    if circles[i][j][0]>avg:
                        circles[i][j][0] -= 1
                    elif circles[i][j][0]<avg:  # 조건 잘 볼 것.
                        circles[i][j][0] += 1

answer = 0
for i in range(N):
    for j in range(M):
        if circles[i][j]:
            answer+=circles[i][j][0]

print(answer)