import sys; input = sys.stdin.readline

zero = 0
one = 0

S = input()

if S[0] == '0':
    zero+=1
else:
    one+=1

state = S[0]
for idx in range(1, len(S)):
    if state!=S[idx]:
        state = S[idx]
        if S[idx] == '0':
            zero+=1
        elif S[idx] == '1':
            one+=1

print(min(zero, one))