# 시간복잡도: O(N*M)
#
# import sys
# input = sys.stdin.readline
#
# N, M, K = map(int, input().split())
#
# interval_vec = [0]
#
# interval_sum = 0
# for _ in range(N):
#     val = int(input())
#
#     interval_sum += val
#     interval_vec.append(interval_sum)
#
# for _ in range(M+K):
#     a, b, c = map(int, input().split())
#
#     val = interval_vec[b] - interval_vec[b-1]
#     if a == 1:
#         for i in range(b, N+1):
#             interval_vec[i] += c - val
#     else:
#         print(interval_vec[c] - interval_vec[b-1])


# Ref
# https://velog.io/@kimdukbae/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%84%B8%EA%B7%B8%EB%A8%BC%ED%8A%B8-%ED%8A%B8%EB%A6%AC-Segment-Tree

# https://chance0523.github.io/algorithm/2020/12/31/algorithm-%EA%B5%AC%EA%B0%84%ED%95%A9%EA%B5%AC%ED%95%98%EA%B8%B0/


# 시간복잡도: O(logN * M)
import sys
input = sys.stdin.readline


"""
<세그먼트 트리를 배열의 각 구간 합으로 채워주기>
start: 배열의 시작 인덱스, end: 배열의 마지막 인덱스
index: 세그먼트 트리의 인덱스 (무조건 1부터 시작)
세그먼트 트리가 1부터 시작하는 이유는 2를 곱했을 때 왼쪽 자식노드를 가리키고
2를 곱하고 1을 더하면 오른쪽 자식노드를 가리키므로 효과적이기 때문
"""
def init(start, end, node):
    if start == end:
        tree[node] = nList[start]
        return tree[node]

    mid = (start + end) // 2
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)
    return tree[node]


"""
<구간 합 구하기>
# start: 시작 인덱스, end: 마지막 인덱스
# left, right: 구간 합을 구하고자 하는 범위
"""
def interval_sum(start, end, node, left, right):
    # 범위 밖에 있는 경우
    if left > end or right < start:
        return 0
    # 범위 안에 있는 경우
    if left <= start and end <= right:
        return tree[node]
    # 그렇지 않다면 두 부분으로 나누어 합 구하기
    mid = (start + end) // 2
    # start와 end가 변하면서 구간 합인 부분을 더해준다고 생각하면 된다.
    return interval_sum(start, mid, node * 2, left, right) + interval_sum(mid + 1, end, node * 2 + 1, left, right)


"""
<특정 원소의 값을 수정하는 함수>
특정 원소를 수정하면 구간 합이 당연히 달라진다.
이 때, 해당 원소를 포함하고 있는 모든 구간 합 노드들을 갱신해주면 된다.
즉, 전체가 아닌 부분적인 노드들만 바꿔주면 된다!
start: 시작 인덱스, end: 마지막 인덱스
what : 구간 합을 수정하고자 하는 노드
value: 수정할 값
"""
def update(start, end, node, index, diff):
    # 범위 밖에 있는 경우
    if index < start or index > end:
        return
    # 범위 안에 있으면 내려가면서 다른 원소도 갱신
    tree[node] += diff
    if start == end:
        return
    mid = (start + end) // 2
    update(start, mid, node * 2, index, diff)
    update(mid + 1, end, node * 2 + 1, index, diff)


N, M, K = map(int, input().split())
nList = []
tree = [0] * (N * 4)

for _ in range(N):
    nList.append(int(input()))

init(0, N-1, 1)

for _ in range(M+K):
    a, b, c = map(int, input().split())

    if a == 1:
        # 각 노드는 구간 합을 나타내기 때문에 기존 값과의 차이 값을 더해주기 위해 차이 값을 인수로 전달
        # 값을 대입하는 방식으로 가면 빼주고 더해줘서 연산이 2번 발생
        update(0, N-1, 1, b-1, c-nList[b-1])

        # diff 구할 때 쓰여서 nList에서의 값도 update 필요 
        nList[b-1] = c  
    else:
        print(interval_sum(0, n-1, 1, b-1, c-1))
