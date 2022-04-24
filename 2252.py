"""
[위상정렬]
- 그래프 알고리즘
- '순서가 정해져 있는 작업'을 차례로 수행할 때, 순서 결정에 사용하는 알고리즘
- 방향 그래프에존재하는 각 정점들의 선행 순서를 위배하지 않으며, 모든 점점을 나열하면 된다.
- 하나의 방향 그래프는 여러 개의 위상 정렬 가능하다.



https://didu-story.tistory.com/97
https://kyungseop.tistory.com/17
cf) 그래프 행렬표현
- 인접 행렬 방식: 2차원 배열로 그래프의 연결 관계를 표현하는 방식. (node 사이 edge 가중치 정보)
ex)
#2차원 배열을 활용하여 그래프를 표현
graph = [
    [0, 7, 5],
    [7, 0 INF],
    [5, INF, 0]
    ]

print(graph)
## 결괏값 ---> [[0, 7, 5] , [7, 0, 999999], [5, 999999, 0]]

- 인접 리스트 방식: 리스트로 각 정점에 연결된 점점들을 표현. (각 노드에 연결된 노드 정보)
ex)
#row 가 3개인 2차원 리스트로 연결 리스트가 표현된다. (row수 = node 수)
graph = [[] for _ in range(3)]

#노드가 0인 연결 노드 정보 (노드, 거리)로 표현
graph[0].append((1,7))
grpah[0].append((2,5))
#노드 1
graph[1].append((0, 7))
#노드 2
graph[2].append((0,5))

print(graph)
## 결과 ---> [[(1,7), (2,5)], [(0,7)], [(0,5)]]
"""

import sys; input = sys.stdin.readline
from collections import deque

N, M = map(int, input().split())
order = [list(map(lambda x:int(x)-1, input().split())) for _ in range(M)]

graph = [[] for _ in range(N)]
indegree = [0]*N
for node1, node2 in order:
    graph[node1].append(node2)
    indegree[node2]+=1

q = deque()
for node, idg in enumerate(indegree):
    if idg == 0:
        q.append(node)

while q:
    node = q.popleft()
    for next_node in graph[node]:
        indegree[next_node]-=1

        if indegree[next_node] == 0:
            q.append(next_node)

    print(node+1, end=' ')