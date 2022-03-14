answer = 0

def dfs(numbers, target, idx, sum):
    global answer

    if idx == len(numbers):
        if sum == target:
            answer += 1
        return

    value = numbers[idx]

    dfs(numbers, target, idx+1, sum + value)
    dfs(numbers, target, idx+1, sum - value)



def solution(numbers, target):
    global answer

    dfs(numbers, target, 0, 0)

    return answer
