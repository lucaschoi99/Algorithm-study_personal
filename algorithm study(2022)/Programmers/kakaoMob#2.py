from collections import defaultdict

def solution(id_list, k):
    answer = 0
    totalCustomers = defaultdict(int)

    for names in id_list:
        visited = defaultdict(int)
        customers = names.split()

        # 하루에 여러번 방문 고객 중복제거
        customerVisited = list(set(customers))
        for customer in customerVisited:
            visited[customer] += 1

        for item, value in visited.items():
            totalCustomers[item] += value
    
    # 고객 한명당 최대 k장까지 쿠폰 가능
    for item, value in totalCustomers.items():
        if value >= k:
            answer += k
            continue
        answer += value

    return answer
