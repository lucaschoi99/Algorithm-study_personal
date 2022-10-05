result = ""

# 10진수 k -> n진수
def k2n(num, n):
    res = ""
    alpha = ["A", "B", "C", "D", "E", "F"]
    
    if num == 0:
        return "0"
    while num >= 1:
        q = int(num/n)
        r = num - q*n
        num = q
        
        if r >= 10:
            r = alpha[r-10]
        res += str(r)
    return res[::-1]

# 인덱싱 로직
def convert(n,t,m,p):
    res = ""
    sol = ""
    for k in range(t*m):
        res += k2n(k,n)
        
    for k in range(t):
        idx = p + m*k - 1
        sol += res[idx]
    return sol



def solution(n, t, m, p):
    answer = ''
    global result
    
    answer = convert(n,t,m,p)
    
    return answer
