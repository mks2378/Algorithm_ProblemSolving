import sys; input = sys.stdin.readline

def binary_search(A, x):
    start, end = 0, N-1

    while start<=end:
        mid = (start + end) // 2
        if A[mid] == x:
            return 1
        elif A[mid] < x:
            start = mid+1
        elif A[mid] > x:
            end = mid-1
    return 0


# main
N = int(input())
A = sorted(list(map(int, input().split())))

M = int(input())
X = list(map(int, input().split()))


for x in X:
    print(binary_search(A, x))