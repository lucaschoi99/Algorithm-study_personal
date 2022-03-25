from collections import Counter

def solution(participant, completion):
    answer = ''
    
    answer = Counter(participant) - Counter(completion)
    
    return list(answer.keys())[0]