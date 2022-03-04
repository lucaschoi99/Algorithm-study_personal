def solution(answers):
    answer = []
    
    first = [1,2,3,4,5]
    sec = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]
    
    idx = 0
    scores = [0,0,0]
    
    for elem in answers:
        if(first[idx%5] == elem):
            scores[0] += 1;
        if(sec[idx%8] == elem):
            scores[1] += 1;
        if(third[idx%10] == elem):
            scores[2] += 1;
        idx+=1
    
    maxScore = max(scores)
    
    ansIdx = 1
    for elem in scores:
        if(elem == maxScore):
            answer.append(ansIdx)
        ansIdx +=1
    
    return answer