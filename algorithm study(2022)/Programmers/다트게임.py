num_list = []
answer = []

def calNormal(digit, alp):
    sum = 0
    if alp == "S":
        sum += digit
    elif alp == "D":
        sum += digit*digit
    else:
        sum += digit*digit*digit

    return sum


def calSpecial(digit, alp, sp, idx):
    sum = 0
    if alp == "S":
        sum += digit
    elif alp == "D":
        sum += digit*digit
    else:
        sum += digit*digit*digit

    if sp == "*":
        sum *= 2
        if idx > 0:
            answer[idx-1] *= 2
    else:
        sum = (-1) * sum

    return sum


def solution(dartResult):
    result = ""
    score_list = []
    global answer
    global num_list

    for idx, digit in enumerate(dartResult):
        result += digit
        if digit == "*" or digit == "#" or idx == len(dartResult)-1:
            score_list.append(result)
            result = ""

    for items in score_list:
        for idx, digit in enumerate(items):
            result += digit

            if(len(result) != 1 and (digit == "*" or digit == "#")):
                num_list.append(result)
                result = ""
                continue

            if(idx < len(items)-1):
                if(items[idx+1] == "*" or items[idx+1] == "#"):
                    continue

            if (digit.isalpha() and len(items) != 3) or idx == len(items)-1:
                num_list.append(result)
                result = ""

    for idx,items in enumerate(num_list):
        alphaIndex = 1
        for index,j in enumerate(items):
            if j.isalpha():
                alphaIndex = index

        digit = int(items[0])
        alp = items[1]
        special = "_"
        if(alphaIndex == 1 and len(items) == 3):
            special = items[2]

        if(alphaIndex != 1):
            digit = int(items[0:2])
            alp = items[2]
            if(len(items) == 4):
                special = items[3]

        if(special == "_"):
            value = calNormal(digit, alp)
        else:
            value = calSpecial(digit, alp, special, idx)

        answer.append(value)

    return sum(answer)
