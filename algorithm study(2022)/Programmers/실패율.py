from collections import defaultdict

def solution(N, stages):
    answer = []
    
    # 스테이지 도전, 완료 정보
    size = len(stages)
    attempted = defaultdict(int)
    completed = defaultdict(int)
    
    # 스테이지 도전, 완료 유저 누적
    for x in range(1,N+1):
        val = 0
        for items in stages:
            if items == x:
                val += 1
        if (val > 0):
            answer.append(val / size)
            size -= val
        else:
            answer.append(0)
    
    # 내림차순 정렬
    answer = sorted(range(len(answer)), key=lambda x : answer[x], reverse=True)
    answer = [x+1 for x in answer]
        
    return answer
