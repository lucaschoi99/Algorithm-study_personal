import math
import itertools

def isPrime(num):
    if(num == 0 or num==1):
        return False
    if(num == 2):
        return True
    
    for k in range(2,math.ceil(math.sqrt(num))+1):
        if num % k == 0:
            return False
    return True
        

def solution(numbers):
    answer = 0
    
    nums = []
    numList = []
    combNums = set([])
    size = len(numbers)
    
    # 개별 조각 추출
    for elem in numbers:
        nums.append(elem)
    
    # 가능한 조합 모두 찾기 - 완전탐색
    for k in range(1,min(size,8)+1):
        npr = itertools.permutations(nums, k)
        numList.append(list(npr))
    for elem in numList:
        for tup in elem:
            number = ''.join(tup)
            if(str(int(number)) != number):
                number = int(number)
            combNums.add(int(number))
    
    # 소수 판별
    for elem in list(combNums):
        if isPrime(elem):
            answer +=1    
    
    return answer