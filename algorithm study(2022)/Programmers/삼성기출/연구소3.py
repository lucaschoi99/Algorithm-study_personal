from copy import deepcopy
import sys
from collections import deque


def combinations(arr, n):
    result = []
    if n == 0:
        return [[]]

    for (i, num) in enumerate(arr):
        for j in combinations(arr[i+1:], n-1):
            result.append([num] + j)
    return result


def rangeCheck(x, y, sz):
    if x < 0 or x >= sz or y < 0 or y >= sz:
        return False
    return True


def tryBFS(items, maps, visited, cnt, sub, zeros):
    global answer
    q = deque()
    count, time, curr, maxTime= 0, 0, 0, 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]

    for item in items:
        if len(item) == 2:
            item.append(0)
        q.append(item)
        visited[item[0]][item[1]] = True

    # 큐가 빌 때까지 반복
    while q:
        data = q.popleft()
        x, y, t = data[0], data[1], data[2]

        if curr < t:
            curr = t
            time += 1

        # 꺼낸 원소와 인접노드 확인
        for dxx, dyy in zip(dx, dy):
            if rangeCheck(x+dxx, y+dyy, len(maps)):
                if (not visited[x+dxx][y+dyy]) and maps[x+dxx][y+dyy] == 0:
                    q.append([x+dxx, y+dyy, time+1])
                    visited[x+dxx][y+dyy] = True
                    maps[x+dxx][y+dyy] = time+1
                    count += 1

    count -= sub
    for act in items:
        maps[act[0]][act[1]] = 0
    for zero in zeros:
        r, c = zero[0], zero[1]
        if maxTime < maps[r][c]:
            maxTime = maps[r][c]

    if count == cnt:
        answer.append(maxTime)
    else:
        answer.append(sys.maxsize)


if __name__ == '__main__':
    global answer
    answer = []
    n, m = input().split()
    n, m = int(n), int(m)
    maps = [[0 for i in range(n)] for k in range(n)]
    info = []
    zeros = []
    cnt = 0

    for i in range(int(n)):
        data = list(map(int, input().split()))
        for k in range(len(data)):
            maps[i][k] = data[k]
            if data[k] == 0: # 빈칸 위치 파악
                zeros.append([i, k])
                cnt += 1
            if data[k] == 2: # 바이러스 위치 파악
                info.append([i, k])

    # 완전탐색 - 모든 조합 경우
    possibleComb = combinations(info, m)
    for items in possibleComb:
        modifiedMap = deepcopy(maps)
        modifiedInfo = []

        # 비활성 바이러스 0으로 취급
        for item in info:
            if item not in items:
                modifiedInfo.append(item)
        for item in modifiedInfo:
            x, y = item[0], item[1]
            modifiedMap[x][y] = 0

        # BFS 시도
        visited = [[False for i in range(n)] for j in range(n)]
        tryBFS(items, modifiedMap, visited, cnt, len(info)-m, zeros)

    if min(answer) != sys.maxsize:
        print(min(answer))
    else:
        print(-1)

