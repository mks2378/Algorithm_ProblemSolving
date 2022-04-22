# 문자열 폭발

# 시간초과
# word = input()
# remove_word = input()
#
# while remove_word in word:
#     word = word.replace(remove_word, '')
#
# if word != '':
#     print(word)
# else:
#     print("FRULA")

string = input()  # 전체 문자열
bomb = input()  # 폭발 문자열

bomb_lastChar = bomb[-1]  # 폭발 문자열의 마지막 글자
stack = []
bomb_length = len(bomb)  # 폭발 문자열의 길이

for char in string:
    stack.append(char)  # 한 글자씩 스택에 넣기
    if char == bomb_lastChar and ''.join(stack[-bomb_length:]) == bomb:
    # 현재 스택에 넣은 문자가 폭발 문자열의 맨끝 문자와 일치하고,
    # 스택에서 폭발문자열의 길이만큼 문자열을 추출했을 때, 이 문자열이 폭발문자열과 일치한다면
    # 해당 문자열을 스택에서 제거.
        del stack[-bomb_length:]

answer = ''.join(stack)

if answer == '':
    print("FRULA")
else:
    print(answer)