from collections import defaultdict

def getAlphabet(first, last, info):
    # 점수 높은 유형으로 판단
    if info[first] > info[last]:
        return first
    elif info[last] > info[first]:
        return last
    else:
        # 점수 같을 경우 사전순 판단
        if ord(first) - ord(last) > 0:
            return last
        else:
            return first

def solution(survey, choices):
    answer = ''
    score = [3,2,1,0,1,2,3]
    my_dict = defaultdict(int)
    score_index = [['R', 'T'], ['C', 'F'],['J', 'M'],['A', 'N']]
    
    for idx, items in enumerate(survey):
        first, last = items[0], items[1]
        choice = score[choices[idx]-1]
        
        # 점수 가산
        if choices[idx] <= 3:
            my_dict[first] += choice
        elif choices[idx] >= 5:
            my_dict[last] += choice
    
    # 합친 점수로 결과 판단
    for i in range(4):
        alpha = getAlphabet(score_index[i][0], score_index[i][1] , my_dict)
        answer += alpha
    
    return answer
