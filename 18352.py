# from collections import deque
#
# def bfs(start, cnt):
#     queue = deque()
#     queue.append((start, cnt))
#
#     while queue:
#         node, cnt = queue.popleft()
#
#         if start == node:
#             global visited
#             visited = list(False for _ in range(N+1))
#             visited[start] = True
#
#         if
#
#         for i in range(M):
#             if graph[i][0] == node:
#                 next_node = graph[i][1]
#
#                 if not visited[next_node]:
#                     visited[next_node] = True
#                     queue.append((next_node, cnt+1))
#
#
# N, M, K, X = map(int, input().split())
#
# graph = []
# for i in range(M):
#     graph.append(list(map(int, input().split())))
#
# result = []
# for s in range(1, N+1):
#     if bfs(s, 1) != -1:
#         result.append(bfs(s, 1))
#
# result.sort()
# print(result)

import sys
from collections import deque

input = sys.stdin.readline

n, m, k, x = map(int, input().split())
visited = [False] * (n+1)
visited[x] = True

edge = [[] for _ in range(n+1)]  # 노드의 개수만큼 리스트 생성
for _ in range(m):  # 모든 간선 저장
    a, b = map(int, input().split())
    edge[a].append(b)

answer = list()
q = deque()
q.append((x, 0))
while q:
    node, cnt = q.popleft()
    if cnt == k:
        answer.append(node)
    elif cnt < k:
        for next_node in edge[node]:
            if not visited[next_node]:
                visited[next_node] = True
                q.append((next_node, cnt+1))

if len(answer) == 0:
    print(-1)
else:
    answer.sort()
    for ans in answer:
        print(ans)

# 방문 처리를 함으로써 임의의 노드에 도달하는 각 count가 해당 노드까지의 최단 경로를 의미.
# 방문 처리를 하지 않게 되면, 임의의 노드에 나중에 다시 도달할 수 있으므로 최단 경로를 의미하지 못한다.