def solution(arr, brr):
    answer = 0

    # arr,brr의 누적합
    asum = 0
    bsum = 0

    for aitem, bitem in zip(arr, brr):
        asum += aitem
        bsum += bitem

        # 누적합이 같이 않으면 크기 조정, 같다면 조정 X
        if asum != bsum:
            answer += 1

    return answer