from collections import deque

jstick_x = [1, -1, 0, 0]
jstick_y = [0, 0, -1, 1]

def solution(maps):
    
    answer = -1
    
    sz_row = len(maps)
    sz_col = len(maps[0])
    
    visited = [[False for i in range(sz_col)] for j in range(sz_row)]
    
    start = [0,0,1]
    queue = deque([start])
    
    visited[0][0] = True
    
    # BFS
    while queue:
        x, y, cnt = queue.popleft()
        
        if (x == sz_row-1 and y == sz_col-1):
            return cnt
        
        for k in range(4):
            curX = x + jstick_x[k]
            curY = y + jstick_y[k]
            
            # 범위 check
            if(curX < 0 or curX >= sz_row or curY < 0 or curY >= sz_col):
                continue

            if visited[curX][curY] == False and maps[curX][curY] == 1:
                value = [curX, curY, cnt+1]
                queue.append(value)
                visited[curX][curY] = True
        
    
    return answer
