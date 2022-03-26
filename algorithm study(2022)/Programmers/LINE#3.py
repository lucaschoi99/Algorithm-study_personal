def solution(num_teams, remote_tasks, office_tasks, employees):
    answer = []

    isTeamRemote = [False for i in range(num_teams)]
    remoteInTeam = [[] for i in range(num_teams)]
    teamInfo = [[] for i in range(num_teams)]

    for idx, emp in enumerate(employees):
        tasks = []
        infos = emp.split()

        # 팀, 팀원 정보
        teamNumber = int(infos[0])
        teamInfo[teamNumber-1].append(idx+1)

        for j in range(1, len(infos)):
            tasks.append(infos[j])
        
        isRemote = True
        for tsk in tasks:
            if tsk not in remote_tasks:
                isRemote = False
                break
        
        if isRemote:
            isTeamRemote[teamNumber-1] = True
            remoteInTeam[teamNumber-1].append(idx+1)
    
    for idx, j in enumerate(isTeamRemote):
        if j == True:
            # 한 팀에서 모두 재택은 불가
            if len(teamInfo[idx]) == len(remoteInTeam[idx]):
                del remoteInTeam[idx][0]
    
    for ppl in remoteInTeam:
        for person in ppl:
            answer.append(person)
    
    answer.sort()

    return answer