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
