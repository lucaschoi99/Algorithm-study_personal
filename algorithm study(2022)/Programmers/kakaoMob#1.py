from collections import defaultdict

def solution(flowers):
    answer = 0
    flowerInfos = defaultdict(bool)
    
    # start부터 end 사이의 날짜 단순체크
    for start, end in flowers:
        for i in range(start, end):
            flowerInfos[i] = True

    # 체크 되어있는 날짜가 곧 한 종류 이상의 꽃이 피어있는 기간
    return len(flowerInfos)
