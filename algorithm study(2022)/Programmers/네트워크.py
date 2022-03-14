def dfs(computers, n, item, visited):
    visited[item] = True

    for k in range(n):
        if computers[k][item] == 1 and visited[k] == False:
            dfs(computers, n, k, visited)



def solution(n, computers):
    answer = 0

    visited = [False for i in range(n)]

    for i in range(n):
        if visited[i] == False:
            dfs(computers, n, i, visited)
            answer += 1

    return answer