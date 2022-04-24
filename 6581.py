# HTML

"""
입력 받는 부분이 제일 까다로운 문제.
입력의 끝은 개행문자가 아닌 Ctrl+D로 끝난다는 사실을 알게됨.
"""

import sys
full_sentence = ''
for sentence in sys.stdin:
    full_sentence+=sentence

result_sentence = full_sentence.split()
# ctrl+D 입력

l = 0
for idx, word in enumerate(result_sentence):
    if word == '<br>':
        print()
        l = 0
    elif word == '<hr>':
        if l:
            print('\n'+'-'*80)
        else:
            print('-' * 80)
        l = 0
    else:
        w_l = len(word)
        if l + w_l > 80:
            l = w_l
            print()
            print(word, end='')
        else:
            l += w_l
            print(word, end='')

        if l+1>80:
            l=0
            print()
        else:
            if idx == len(result_sentence)-1:
                break
            l+=1
            print(' ', end='')