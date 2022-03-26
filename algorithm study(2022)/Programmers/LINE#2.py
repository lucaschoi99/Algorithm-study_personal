from collections import defaultdict
from curses import reset_shell_mode
import itertools

def solution(setences, n):
    answer = -1
    possible = []

    for idx, sentence in enumerate(setences):
        ddict = defaultdict(int)
        cnt = 0
        score = 0
        upperWords = 0

        for st in sentence:
            ddict[st] += 1
        
        # Spacebar 제거
        if ' ' in ddict.keys():
            del ddict[' ']

        keyList = list(ddict.keys())
        usedAlpha = []
        shift = False

        for items in keyList:
            if items not in usedAlpha:
                usedAlpha.append(items.lower())
                cnt += 1

                if items.isupper():
                    shift = True
            else: # 같은 알파벳의 대문자 check
                if items.isupper():
                    if shift == False:
                        if items.lower() in usedAlpha:
                            usedAlpha.append(items.lower())
                            shift = True
                        else:
                            usedAlpha.append(items.lower())
                            shift = True
        if shift == True:
            usedAlpha.append("shift")
            cnt += 1
        
        for item in sentence:
            if item.isupper():
                uppperWords += 1
        
        if cnt <= n:
            score = len(sentence) + upperWords
        
        usedAlpha.sort()
        usedAlpha = set(usedAlpha)
        possible.append([idx, usedAlpha, score])

    # 가능한 모든 조합 - 최대 점수 확인
    maxScore = 0
    index = [i for i in range(len(possible))]

    for k in range(1,len(possible)+1):
        resList = list(itertools.combinations(index, k))
        for items in resList:
            usedIdx = []
            resScore = 0
            for j in range(len(items)):
                usedIdx.append(items[j])
            
            # usedAlpha의 합집합
            resSet = set()
            for idx in usedIdx:
                usedSet = possible[idx][1]
                resSet = resSet.union(usedSet)
            
            if len(resSet) <= n:
                for idx in usedIdx:
                    resScore += possible[idx][2]
            
            maxScore = max(resScore, maxScore)
            
    return maxScore

