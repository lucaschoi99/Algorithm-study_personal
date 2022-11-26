def solution(s, times):
    answer = []

    # 시작 날짜 데이터
    start = list(map(int, s.split(":")))
    temp = list(map(int, s.split(":")))
    ifSucceed = True

    # 저축 날짜 갱신떄마다 날짜 계산
    for item in times:
        timePassed = list(map(int, item.split(":")))
        nextDate = calculateDate(temp, timePassed)
        if checkSucceed(temp, nextDate) == False:
            ifSucceed = False
        temp = nextDate

    # 1일 1저축 성공여부
    if ifSucceed:
        answer.append(1)
    else:
        answer.append(0)
    
    # 저축 기간 계산
    timeElaspedCnt = calculateElapsed(start, temp)
    answer.append(timeElaspedCnt)

    return answer


# 기준 날짜에 지난 기간을 더한 날짜 반환
def calculateDate(start, elapsed):
    calYr = start[0]
    calMonth = start[1]
    calDay = start[2] + elapsed[0]
    calHr = start[3] + elapsed[1]
    calMin = start[4] + elapsed[2]
    calSec = start[5] + elapsed[3]

    while calSec >= 60:
        calSec -= 60
        calMin += 1
    
    while calMin >= 60:
        calMin -= 60
        calHr += 1
        
    while calHr >= 24:
        calHr -= 24
        calDay += 1

    while calDay >= 31:
        calDay -= 30
        calMonth += 1
    
    while calMonth >= 13:
        calMonth -= 12
        calYr += 1
    
    return [calYr, calMonth, calDay, calHr, calMin, calSec]
    

# 기준 날짜 바로 다음 날을 건너뛰었는지 여부 확인
def checkSucceed(start, end):
    yrGap = end[0] - start[0]
    monthGap = end[1] - start[1]
    
    # 연도가 바뀌었을 경우
    if yrGap > 0 and start[1] == 12 and end[1] == 1 and start[2] == 30 and end[2] == 1:
        return True
     
    # 달이 바뀌었을 경우
    if monthGap == 1 and start[2] == 30 and end[2] == 1:
        return True
    
    # 달이 바뀌지 않았을 경우
    if end[2] - start[2] <= 1:
        return True

    return False


# 시작 날짜와 마지막 날짜로 저축 기간 계산
def calculateElapsed(start, end):
    
    # 연도가 바뀐 경우
    if start[0] < end[0]:
        YrPassed = 360*(end[0] - start[0] - 1)
        monthPassed = 30*((12-start[1]) + (end[1]-1))
        dayPassed = (30-start[2]+1) + end[2]
        return (YrPassed + monthPassed + dayPassed)
    else:
        # 같은 연도, 달이 바뀌지 않은 경우
        if start[1] == end[1]:
            return end[2] - start[2] + 1
        # 같은 연도, 달이 바뀌었을 경우
        else:
            monthPassed = 30*(end[1] - start[1] - 1)
            dayPassed = (30-start[2]+1) + end[2]
            return (monthPassed + dayPassed)
