visited = [False for _ in range(101)]
cnt = 1

def search(idx, graph):
    
    global visited
    global cnt
    
    visited[idx] = True
    
    for items in graph[idx]:
        if visited[items] == False:
            cnt += 1
            search(items, graph)
    

def solution(n, wires):
    
    global visited
    global cnt
    
    answer = 987654321
    graph = [[] for _ in range(n+1)]
    
    for v1,v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)
    
    # 연결 한 개씩 끊으며 완전탐색
    for idx, edges in enumerate(graph):
        for nodes in edges:
            # 큰 노드와의 연결만 진행 (중복방지)
            if idx < nodes:
                
                visited[idx] = True 
                search(nodes, graph)
                
                # Initalize
                visited = [False for _ in range(101)]
                if(abs(2*cnt-n) < answer):
                    answer = abs(2*cnt-n)
                cnt = 1
        
    return answer
