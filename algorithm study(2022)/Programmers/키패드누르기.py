def checkDistance(curX, curY, targetX, targetY):
    return abs(curX - targetX) + abs(curY - targetY)


def solution(numbers, hand):
    answer = ''
    keypad = [[1,2,3], [4,5,6], [7,8,9], ["*", 0, "#"]]
    ll, rr = [3,0], [3,2]
    
    for nums in numbers:
        targetX, targetY = [[ix,iy] for ix, row in enumerate(keypad) for iy, i in enumerate(row) if i == nums][0]
        
        val_left = checkDistance(ll[0], ll[1], targetX, targetY)
        val_right = checkDistance(rr[0], rr[1], targetX, targetY)
        
        # 1,4,7은 왼손, 3,6,9는 오른손 사용
        if nums in [1,4,7]:
            ll = [targetX, targetY]
            answer += "L"
            continue
        if nums in [3,6,9]:
            rr = [targetX, targetY]
            answer += "R"
            continue
        
        # 2,5,8,0은 어느 손이 더 가까운지에 따라 판단
        if val_left < val_right:
            ll = [targetX, targetY]
            answer += "L"
        elif val_left > val_right:
            rr = [targetX, targetY]
            answer += "R"
        else:
            if hand == "left":
                ll = [targetX, targetY]
                answer += "L"
            else:
                rr = [targetX, targetY]
                answer += "R"
                    
    return answer
