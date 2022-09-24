def solution(commands):
    answer = []

    tables = [["EMPTY" for col in range(50)] for row in range(50)]
    mergeInfo = list()
    
    for cmd in commands:
        infos = cmd.split(" ")
        command = infos[0]
        
        # 값 변경
        if command == "UPDATE":
            if len(infos) == 3:
                # Value1 <- Value2
                for i in range(50):
                    for j in range(50):
                        if tables[i][j] == infos[1]:
                            tables[i][j] = infos[2]
            else:
                # (r,c) <- value
                tables[int(infos[1])-1][int(infos[2])-1] = infos[3]
                print("UPDATE 4 [0][1]:", tables[0][1])
                print("UPDATE 4 [1][0]:", tables[1][0])

        # (r1, c1) <-> (r2,c2) 병합
        elif command == "MERGE":
            r1, c1, r2, c2 = int(infos[1])-1, int(infos[2])-1, int(infos[3])-1, int(infos[4])-1
            isMerged = False
            isMerged2 = False
            index = -1
            index2 = -1
                
            # 병합 관계 확인
            for idx, items in enumerate(mergeInfo):
                if list(r1,c1) in items:
                    index = idx
                    isMerged = True
                if list(r2,c2) in items:
                    index2 = idx
                    isMerged2 = True
                    

            # 값을 두 셀 모두 가지고 있을 경우
            if tables[r1][c1] != "EMPTY" and tables[r2][c2] != "EMPTY":
                tables[r2][c2] = tables[r1][c1]

            # 값을 한 셀만 가지고 있을 경우
            elif (tables[r1][c1] != "EMPTY" and tables[r2][c2] == "EMPTY") or (tables[r1][c1] == "EMPTY" and tables[r2][c2] != "EMPTY"):
                tables[r2][c2] = tables[r1][c1]
            
            # 병합 정보 동기화
            if isMerged and not isMerged2:
                mergeInfo[index].append(list(r2,c2))
            elif isMerged2:
                for row, col in mergeInfo[index2]:
                    tables[row][col] = tables[r1][c1]
                mergeInfo[index].append(mergeInfo[index2])
            else:
                # mergeInfo.append((r1))
                print()
                    
            # print("mergeInfo:", mergeInfo)
            # print("MERGE [0][1]:", tables[0][1])
            # print("MERGE [1][0]:", tables[1][0])
            
            print()

        # 병합 해제
        elif command == "UNMERGE":
            row, col = int(infos[1])-1, int(infos[2])-1
            for idx, items in enumerate(mergeInfo):
                if list(row,col) in items:
                    value = tables[row][col]
                    for itemRow, itemCol in items:
                        tables[itemRow][itemCol] = "EMPTY"
                    tables[row][col] = value
                
                del mergeInfo[idx]

        # 출력
        elif command == "PRINT":
            answer.append(tables[int(infos[1])-1][int(infos[2])-1])
        else:
            print("Exception")
        

    return answer
