cnt_list = [0]*26
word = input().lower()

for s in word:
    cnt_list[ord(s)-ord('a')]+=1

max_v = 0
max_one = True
max_idx = 0
for idx, c in enumerate(cnt_list):
    if c>max_v:
        max_v = c
        max_idx = idx
        max_one = True
    elif c == max_v:
        max_one = False

if max_one:
    print(chr(ord('a')+max_idx).upper())
else:
    print('?')