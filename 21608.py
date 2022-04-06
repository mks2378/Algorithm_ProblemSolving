import sys
input = sys.stdin.readline


"""
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리 정한다.
2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리 정한다.

학생의 만족도 구하기
-  학생의 만족도를 구하려면 그 학생과 인접한 칸에 앉은 좋아하는 학생의 수를 구해야 한다. 그 값이 0이면 학생의 만족도는 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000이다.
"""

"""
구현 익힐 부분
- 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리 정한다.

"""


## params ##
score_1, score_2, score_3, score_4 = 0, 0, 0, 0


## function ##
def find_seat(s):
    candidates = []
    for i in range(N):
        for j in range(N):
            s_like = 0
            space = 0

            if i-1>=0:
                if board[i-1][j] == 0:
                    space+=1
                elif board[i-1][j] in s:
                    s_like+=1
            if i+1<N:
                if board[i+1][j] == 0:
                    space+=1
                elif board[i+1][j] in s:
                    s_like+=1
            if j-1>=0:
                if board[i][j-1] == 0:
                    space+=1
                elif board[i][j-1] in s:
                    s_like+=1
            if j+1<N:
                if board[i][j+1] == 0:
                    space+=1
                elif board[i][j+1] in s:
                    s_like+=1

            candidates.append([s_like, space, i, j])

    candidates.sort(key=lambda x : (x[0], x[1], -x[2], -x[3]))

    return candidates


## MAIN ##
N = int(input())

student_info = [list(map(int, input().split())) for _ in range(N**2)]

board = [[0]*N for _ in range(N)]

for s in student_info:  # [학생 번호, like1, like2, like3, like4]
    seat_candidates = find_seat(s)  # 좋아하는 학생 수, 비어있는 공간 수, y, x

    for c_info in seat_candidates[::-1]:
        if board[c_info[2]][c_info[3]] == 0:
            board[c_info[2]][c_info[3]] = s[0]
            break

student_info.sort(key=lambda x:x[0])

# 만족도 조사
for i in range(N):
    for j in range(N):
        # 그 값이 0이면 학생의 만족도는 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000
        # score_0, score_1, score_2, score_3, score_4
        temp = 0
        if i-1>=0 and (board[i-1][j] in student_info[board[i][j]-1]):
            temp+=1

        if i+1<N and (board[i+1][j] in student_info[board[i][j]-1]):
            temp+=1

        if j-1>=0 and (board[i][j-1] in student_info[board[i][j]-1]):
            temp+=1

        if j+1<N and (board[i][j+1] in student_info[board[i][j]-1]):
            temp+=1

        if temp == 1:
            score_1+=1
        elif temp == 2:
            score_1+=10
        elif temp == 3:
            score_1+=100
        elif temp == 4:
            score_1+=1000

print(score_1+score_2+score_3+score_4)
