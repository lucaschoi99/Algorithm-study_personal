def solution(sizes):
    
    result_x = 0
    result_y = 0
    
    for v1,v2 in sizes:
        if v2 > v1:
            tmp = v1
            v1 = v2
            v2 = tmp
        
        # 가로, 세로 중 큰 값을 한 곳에 몬다
        # 작은 값을 또다른 한 곳에 몬다
        if v1 > result_x:
            result_x = v1
        if v2 > result_y:
            result_y = v2

    return result_x * result_y
