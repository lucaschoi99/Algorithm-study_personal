def solution(id_list, report, k):
    answer = []
    foward = {x : [] for x in id_list}
    backward = {x : [] for x in id_list}
    cand = []
    
    # 신고 관계 수합
    for items in report:
        v1,v2 = items.split()
        
        if v2 not in foward[v1]:
            foward[v1].append(v2)
        if v1 not in backward[v2]:
            backward[v2].append(v1)
    
    # 정지 ID
    for key,val in backward.items():
        if len(val) >= k:
            cand.append(key)
    
    # 정지 ID 신고자 수합
    for item in id_list:
        cnt = 0
        for t in cand:
            if t in foward[item]:
                cnt += 1
        answer.append(cnt)
    
    
    return answer
