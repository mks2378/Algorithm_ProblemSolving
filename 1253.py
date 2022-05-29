import sys; input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = 0
for i in range(len(arr)):
    tmp = arr[:i] + arr[i+1:]
    left, right = 0, len(tmp)-1

    while left<right:
        total = tmp[left] + tmp[right]
        if arr[i] == total:
            ans+=1
            break
        elif arr[i]<total:
            right-=1
        elif arr[i]>total:
            left+=1
print(ans)
