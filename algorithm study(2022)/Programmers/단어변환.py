from collections import deque

def checkWords(str1, str2):
    cnt = 0
    for s1, s2 in zip(str1, str2):
        if s1 != s2:
            cnt += 1
    if cnt == 1:
        return True
    else:
        return False


def solution(begin, target, words):
    answer = 0
    
    exists = False
    for item in words:
        if item == target:
            exists = True
    
    # No target in words
    if not exists:
        return 0
    
    # BFS
    queue = deque()
    visited = [False for item in range(len(words))]
    for idx,word in enumerate(words):
        if checkWords(word, begin) and not visited[idx]:
            if word == target:
                return 1
            
            visited[idx] = True
            queue.append([word, 1])
    
    if queue == 0:
        return 0
    
    answers = []
    
    while(queue):
        items = queue.popleft()
        current, depth = items[0], items[1]
        
        for idx,word in enumerate(words):
            if checkWords(word, current) and not visited[idx]:
                if word == target:
                    return depth+1
                
                visited[idx] = True
                queue.append([word, depth+1])
        
    answer = min(answers)
    
    return answer