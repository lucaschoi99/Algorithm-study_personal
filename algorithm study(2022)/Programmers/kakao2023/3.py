import math
from itertools import product
from collections import defaultdict

# 할인율 적용한 결과
def tryOne(users, emoticons, salesInfo):
    addUsers = 0
    addPrice = 0
    emoPrice = [x*y for x,y in zip(emoticons, salesInfo)]
    userInfo = defaultdict(int)

    # 기준에 따른 이모티콘 구입 전략
    for userNum, (salesNum, priceNum) in enumerate(users):
        for cnt, saleItem in enumerate(salesInfo):
            if saleItem*100 <= (100-salesNum):
                userInfo[userNum] += emoPrice[cnt]
                addPrice += emoPrice[cnt]

    for key, val in userInfo.items():
        # 이모티콘 플러스 구입 조건
        if users[key][1] <= val:
            addUsers += 1
            addPrice -= val
            
    
    return addUsers, addPrice



def solution(users, emoticons):
    answer = []

    # 이모티콘 할인율 완전탐색 (10, 20, 30, 40%)
    productValue = [0.9,0.8,0.7,0.6]
    num = len(emoticons)
    maxUser = -1
    maxRes = -1
    saleEmoticons = product(productValue, repeat=num)

    for items in list(saleEmoticons):
        salesInfo = list(items)
        addUser, result = tryOne(users, emoticons, salesInfo)
        
        # 최대 가입, 최대 수익
        if addUser > maxUser:
            maxUser = addUser
            maxRes = result
        elif addUser == maxUser:
            if result > maxRes:
                maxRes = result

    answer.append(maxUser)
    answer.append(maxRes)

    return answer
