answer = ""
alphabets = ""

def solve(words, target):
    global answer
    global alphabets
    
    idx = words.index(target)
    answer += str(idx)
    alphabets = ""


def solution(s):
    global answer
    global alphabets
    
    words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    for alp in s:
        if alp.isdigit():
            answer += alp
            if len(alphabets) != 0:
                solve(words, alphabets)
        else:
            alphabets += alp
            if alphabets in words:
                solve(words, alphabets)
    
    return int(answer)

---------------------------------------------------------------------
(개선 풀이)
def solution(s):
    answer = s
    str_dict = {"zero": "0", "one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}
    
    for key, values in str_dict.items():
        answer = answer.replace(key, values)
    
    return int(answer)
