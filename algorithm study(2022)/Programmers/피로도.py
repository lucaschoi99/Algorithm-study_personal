import math

answer = 0

def travel(hp, visited, path, cnt):
    
    global answer
    
    if cnt > answer:
        answer = cnt
    
    for k in range(len(path)):
        
        
        # 백트래킹
        if visited[k]==False and hp >= path[k][0]:
            visited[k] = True
            travel(hp - path[k][1], visited, path, cnt+1)
            visited[k] = False
    
    
def solution(k, dungeons):
    
    global answer
    
    size = len(dungeons)
    visited = [False] * size
    
    travel(k, visited, dungeons, 0)
    
    return answer
