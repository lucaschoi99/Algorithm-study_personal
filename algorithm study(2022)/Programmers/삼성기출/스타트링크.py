from itertools import combinations, permutations

def teamScore(info, teamMembers):
    tryTeam = list(permutations(teamMembers, 2))
    sumScore = 0

    for p1, p2 in tryTeam:
        sumScore += info[p1-1][p2-1]

    return sumScore


def diffScore(score1, score2):
    return abs(score1 - score2)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    answer = []
    size = int(input())
    info = [[0 for i in range(size)] for k in range(size)]
    for k in range(size):
        data = list(map(int, input().split()))
        for j in range(len(data)):
            element = data[j]
            info[k][j] = element

    ppl = [i for i in range(1,size+1)]
    teams = list(combinations(ppl,int(size/2)))
    for k in range(int(len(teams)/2)):
        team1 = teams[k]
        team2 = teams[len(teams)-1-k]
        value = diffScore(teamScore(info, team1), teamScore(info, team2))
        answer.append(value)

    print(min(answer))
