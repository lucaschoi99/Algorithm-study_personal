answer = []
visited = [False] * 20000

def dfs(tickets, start, ans):
    for idx, item in enumerate(tickets):
        if (not visited[idx]) and item[0] == start:            
            visited[idx] = True
            ans.append(idx)
            
            dfs(tickets, item[1], ans)
            
            visited[idx] = False
            ans.pop()
            
    current = sorted(ans)
    compare = [item for item in range(len(tickets))]
    
    if current == compare:
        candidate = []
        candidate.append("ICN")
        
        for idx in ans:
            item = tickets[idx][1]
            candidate.append(item)
        answer.append(candidate)
        return
    
    if len(ans) > len(tickets) and (False in visited):
        return
            
    

def solution(tickets):
    global answer
    
    dfs(tickets, "ICN", [])

    answer.sort()
    
    return answer[0]