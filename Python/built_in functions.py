### built-in functions summarization ###

# append(): 덧붙인다는 뜻으로 괄호() 안에 값을 입력하면 새로운 요소를 array 맨 끝에 객체로 추가
nums = [1, 2, 3]
nums.append(4)
print(nums)
nums.append([5, 6])
print(nums)  # 리스트가 하나의 객체로 추가되었음
print()

# extend(): append와 비슷하나 **인자로 iterable 자료형만 올 수 있다.**
# '+' 보다 효율적
nums = [1, 2, 3]
nums.extend([4, 5])
print(nums)  # iterable 자료형의 요소를 각각 추가 할 수 있다.
print()

# '+': 리스트 이어붙이기
a = ['abc', 333]
b = [1, 2, 3]
print(a+b)
print()

# '*': 곱하는 수 만큼 리스트 반복생성
a = [1, 2, 3]
b = a * 3
print(b)
print()

# insert(i, x): array의 원하는 위치 i앞에 추가할 값 x를 삽입할 수 있다.
nums = [1, 2, 3]
nums.insert(0, [10, 20])  # 0번째 (맨앞에) 추가
print(nums)
nums.insert(-1, 100)
print(nums)
nums.insert(len(nums), 100)  # 맨 끝에 추가하고 싶다면 맨끝 인덱스+1
print(nums)
print()

# count(원소): 원소의 갯수 반환
nums = [1, 2, 3, 4, 5, 1, 2, 1, 3]
print(nums.count(1))
print()

# index(원소): 원소의 위치를 반환
nums = [1, 2, 3, 4, 5, 1, 2, 1, 3]
print(nums.index(1))  # 단 중복이 있다면 가장 앞에 있는 원소의 인덱스 반환
print()

# reverse(): 리스트의 요소를 역순으로 정렬
nums = [1, 2, 3, 4, 5, 1, 2, 1, 3]
nums.reverse()  # 리턴값이 없다
print(nums)
print()

# remove(): 리스트에서 나오는 첫번째 특정 요소를 삭제
# 만약 요소가 리스트에 존재하지 않는다면 에러 반환
ex = [0, 1, 2, 3, 1, 3, 4, 5, 6]
ex.remove(1)
print(ex)
# ex.remove(7)  # 에러 발생
print()

# pop(): 리스트에서 맨 마지막 요소를 출력하면서 그 요소를 리스트에서 삭제
ex = [0, 1, 2, 3, 4]
print(ex.pop())
print(ex)
print()

# del(리스트 범위 or 리스트 특정 요소)
c = [1, 2, 3, 4, 5, 6]
del(c[1])
print(c)
del(c[1:4])
print(c)
print()

# copy(): 리스트 복사
a = [1, 2, 3]
b = a.copy()  # 깊은 복사
print(id(a))
print(id(b))  # 주사값이 다른 것을 알 수 있다.
print()

"""
[개념정리] 깊은 복사 vs 얕은 복사
깊은 복사: 말 그대로 복사를 해서 각각 독립적인 리스트가 되는 것.
얕은 복사: 복사는 했지만 기존의 것을 대입한 것과 같아 실제로 같은 리스트를 가르키는 것.

"""

# clear(): 리스트에 저장된 모든 값 삭제
a = [1, 2, 3]
a.clear()
print(a)
print()

##############################################################################

# split(): string to list. 특정문자를 기준으로 split
# 아무것도 없을 때는 공백 기준으로 split
time_str = "10:34:17"
time_str = time_str.split(':')
print(time_str)
print()

# strip(): 인자로 전달된 문자를 왼쪽과 오른쪽에서 제거
# 전달 인자 없을 시, 문자열에서 양끝 공백 제거
text = ' Water boils at 100 degrees '
print('['+text+']')  # [ Water boils at 100 degrees ]
print('[' + text.strip() + ']')  # [Water boils at 100 degrees]
print()

# 리스트 empty 여부
list1 = []
list2 = [1, 2, 3]
if not list1:
    print('list1 is empty')
if list2:
    print('list2 is not empty')
print()

# 리스트에 특정 아이템 존재 여부 확인
list1 = []
list2 = [1, 2, 3]
item = 1
if item not in list1:
    print('list1 has no item')
if item in list2:
    print('list2 has item')
print()

# 2차원 리스트 -> 1차원 리스트
list1 = [[1, 10], [2, 22], [3, 19], [4, 7]]
list2 = []
for element in list1:
    list2 += element
print(list2)

list3 = sum(list1, [])
print(list3)
print()

# join(): 리스트의 문자열들을 합치는 역할
time_list = ['10', '34', '17']
time_list = "".join(time_list)
print(time_list)

time_list = ['10', '34', '17']
time_list = " ".join(time_list)  # 특정 문자열 넣어주기
print(time_list)
print()

# 문자열에서 문자 하나씩 가져올 때
for ch in 'abcde':
    print(ch)
print()

# list comprehension: 리스트를 쉽게 한줄로 만들 수 있는 python 문법
# ex1 - 원소 제곱
meter_list = [3, 7, 9, 10]
meter_square_list = [i*i for i in meter_list]
print(meter_square_list)

# ex2 - 홀수에 대해서만 원소 제곱
meter_list = [3, 7, 9, 10]
meter_square_list = [i*i for i in meter_list if i%2 == 1]
print(meter_square_list)

# ex3 - 구구단
result = [x * y for x in range(1, 10) for y in range(1, 10)]
print(result)

# ex4 - 짝수 구구단
result = [x * y for x in range(1, 10) if x%2 == 0 for y in range(1, 10)]
print(result)
print()

# if-else one-line
x = 3
result = x if x > 3 else x-1
print(result)
print()

##### sort vs sorted #####
# sort
num_list = [4, 2, 7, 5, 3]
num_list.sort()  # .sort()는 리턴값이 없다. 기존의 리스트를 정렬
print(num_list)
num_list.sort(reverse=True)
print(num_list)

# sorted
num_list = [4, 2, 7, 5, 3]
print(sorted(num_list))  # 정렬된 새로운 리스트 반환. 원형을 변형시키지 않는다.
print(sorted(num_list, reverse=True))
print(num_list)
print()

# 특정 요소 기준 정렬 - key에 정렬 기준 위치를 lambda 함수를 이용해서 표현
# ex1)
student_tuples = [
    ('john', 'A', 15),
    ('jane', 'B', 12),
    ('dave', 'B', 10),
]
print(sorted(student_tuples, key=lambda x: x[2]))  # 요소의 3번째 인자를 기준으로 정렬

# # ex2)
a = [(1, 2), (0, 1), (5, 1), (5, 2), (3, 0)]
b = sorted(a, key=lambda x: x[0])
print(b)
c = sorted(a, key=lambda x: x[1])
print(c)
d = sorted(a, key=lambda x: (x[0], -x[1]))
print(d)

# ex3)
tuple_list = [('좋은하루', 0),
              ('niceday', 1),
              ('좋은하루', 5),
              ('good_morning', 3),
              ('niceday', 5)
              ]
print(sorted(tuple_list, key=lambda x: (-x[1], x[0])))
# 2번째 인자에 대해서는 내림차순 후에 1번째 인자에 대해서는 오름차순
print()

##### 딕셔너리를 key 또는 value 기준으로 정렬 #####
# key 기준으로 정렬 (오름차순) - item()에 대해 조건 없으면 딕셔너리의 키 기준으로 정렬
my_dict = {'c': 3, 'a': 1, 'b': 2, 'e': 1, 'd': 2}
sorted_dict = sorted(my_dict.items())
print(sorted_dict)

# key 기준으로 역정렬 (내림차순)
sorted_dict = sorted(my_dict.items(), reverse=True)
print(sorted_dict)

# value를 기준으로 정렬 (오름차순)
sorted_dict = sorted(my_dict.items(), key=lambda x: x[1])
print(sorted_dict)

# value를 기준으로 정렬 (내림차순)
sorted_dict = sorted(my_dict.items(), key=lambda x: x[1], reverse=True)
print(sorted_dict)
sorted_dict = sorted(my_dict.items(), key=lambda x: -x[1])
print(sorted_dict)
print()

# lambda
# 인자 1개, 아웃풋 1개
g = lambda x: x**2
print(g(2))

# 인자 2개, 아웃풋 1개
f = lambda x, y: x+y
print(f(2, 3))

# 함수 바로 호출
func = (lambda x: x+10)(10)
print(func)
print()

# map(적용시킬 함수, 적용시킬 값들): 적용시킬 값들 요소들에 함수를 하나씩 적용
a = [1, 2, 3, 4]
b = [17, 12, 11, 10]
print(list(map(lambda x, y: x+y, a, b)))
print()

# filter(): 처리되는 각각의 요소에 대해 boolean 값을 반환
# True 반환하면 그 요소는 남게 되고, False 반환하면 그 요소는 제거된다.
foo = [2, 18, 9, 22, 17, 24, 8, 12, 27]
print(list(filter(lambda x: x%3 == 0, foo)))  # 자곤 만족 시키는 요소만 남아
print()

# reduce(): function을 사용하여 iterable을 하나씩 이용하여 하나의 값으로 줄인다.
from functools import reduce
print(reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]))
# == sum(sum(sum(sum(1,2),3),4),5)
print()

############################################################################

# zip(): 두개 이상의 iterable 객체를 인자로 받아 각 객체가 담고 있는 원소를 튜플의 형태로
# 차례로 접근할 수 있는 반복자(iterator)를 반환
numbers = [1, 2, 3]
letters = ['A', 'B', 'C']
for pair in zip(numbers, letters):
    print(pair)

# iterator 반환으로 list화 시켜주어야 한다.
print(list(zip(numbers, letters)))

# 3개 이상 가능
for element in zip('12345', 'ABCDE', 'abcde'):
    print(element)

# 응용 - 딕셔너리 변환
keys = [1, 2, 3]
values = ['A', 'B', 'C']
print(dict(zip(keys, values)))

# zip 주의사항: 인자의 길이가 다를 때는 가장 짧은 지라를 기준으로 튜플이 생성되고, 나머지는 버린다.
number = ['1', '2', '3']
letter = ['a']
print(list(zip(number, letter)))
print()

# unzip: 튜플, 리스트 등으로 구성 되어 있는 데이터를 같은 위치의 요소별로 해체.
numbers = [1, 2, 3]
letters = ['A', 'B', 'C']
pairs = [[1, 'a'], [2, 'b'], [3, 'c']]  # pairs = [(1, 'a'), (2, 'b'), (3, 'c')]
nums, chs = zip(*pairs)
print(nums, chs)

# 응용 - matrix transpose
list1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
result = list(zip(*list1))
print(result)