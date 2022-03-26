from operator import index
from re import L


def checkFormat(log, idxT, colT, lenT, idxA, colA, lenA, idxE, colE, lenE, idxM, colM, lenM):
    if len(log) > 100:
        return False
    if idxT != 0:
        return False
    if log[idxT:colT+2] != "team_name : " or (idxA - colT - 1) != lenT+2:
        return False
    if log[idxA-1:colA+2] != " application_name : " or (idxE - colA -1) != lenA+2:
        return False
    if log[idxE-1:colE+2] != " error_level : " or (idxM - colE - 1) != lenE+2:
        return False
    if log[idxM-1:colM+2] != " message : " or (len(log) - 1 -colM) != lenM+1:
        return False
    
    return True

def checkBody(log, idxT, colT, lenT, idxA, colA, lenA, idxE, colE, lenE, idxM, colM, lenM):
    teamBody = log[colT+2:idxA-1]
    appBody = log[colA+2:idxE-1]
    errorBody = log[colE+2:idxM-1]
    msgBody = log[colM+2:]

    if teamBody.isalpha() and appBody.isalpha() and errorBody.isalpha() and msgBody.isalpha():
        return True
    else:
        return False

def solution(logs):
    cnt = 0

    team = "team_name"
    app = "applicatoin_name"
    error = "error_level"
    msg = "message"

    for log in logs:
        if (team in log) and (app in log) and (error in log) and (msg in log):
            indexTeam = log.index(team)
            indexApp = log.index(app)
            IndexError = log.index(error)
            indexMsg = log.index(msg)

            infos = log.split()
            lenInfos = []
            colonInfos = []

            for idx, alpha in enumerate(log):
                if alpha == ":":
                    colonInfos.append(idx)
                
            for item in range(2,12,3):
                if item >= len(infos):
                    break
                lenInfos.append(len(infos[item]))

            # 형식에 맞는 로그
            if len(lenInfos) == 4 and len(colonInfos) == 4:
                if checkFormat(log, indexTeam, colonInfos[0], lenInfos[0], indexApp, colonInfos[1], lenInfos[1], IndexError, colonInfos[2], lenInfos[2], indexMsg, colonInfos[3], lenInfos[3]):
                    if checkBody(log, indexTeam, colonInfos[0], lenInfos[0], indexApp, colonInfos[1], lenInfos[1], IndexError, colonInfos[2], lenInfos[2], indexMsg, colonInfos[3], lenInfos[3]):
                        cnt += 1

    return len(logs) - cnt