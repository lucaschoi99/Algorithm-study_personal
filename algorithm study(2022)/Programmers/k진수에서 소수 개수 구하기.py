import math

def changeToTarget(number, target):
    num_list = []
    
    while(True):
        q = math.floor(number / target)
        r = number % target
        
        num_list.append(str(r))
        if q <=1:
            if q != 0:
                num_list.append(str(q))
            break
        number = q
            
    num_list.reverse()
    return ''.join(num_list)
    
    
def checkPrime(number):
    target = int(number)
    
    if target <= 1:
        return False
    
    if target == 2:
        return True
    
    for k in range(2, math.ceil(math.sqrt(target))+1):
        if target % k == 0:
            return False
    return True
    
    

def solution(n, k):
    answer = 0
    
    # k진수로 변환
    number = changeToTarget(n,k)
    
    # '0' 기준으로 split
    cand = number.split('0')
    
    for item in cand:
        # 조건 검사
        if item != '':
            if checkPrime(item):
                answer += 1  
    
    return answer
