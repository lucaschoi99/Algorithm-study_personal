from collections import defaultdict

def calculateDiff(td_yr, td_m, td_d, yr, m, d):
    value = (td_yr-yr)*365 + (td_m-m)*30 + (td_d-d)

    if value > 0:
        return True
    else:
        return False


# Check difference btw two dates
# and return if expires or not
def calculateDate(today, target, expires):
    td_yr, td_m, td_d = today.split(".")
    yr, m, d = target.split(".")

    # To int
    td_yr = int(td_yr)
    td_m = int(td_m)
    td_d = int(td_d)
    yr = int(yr)
    m = int(m)
    d = int(d)

    # Expiration date calculation
    m += expires
    while(m > 12):
        yr += 1
        m -= 12
    d -= 1
    if d == 0:
        m -= 1
        d = 28
    if m == 0:
        yr -= 1
        m = 12

    # Expired
    if calculateDiff(td_yr, td_m, td_d, yr, m, d):
        return True
    else:
        return False



def solution(today, terms, privacies):
    answer = []
    
    # Parse information
    types = defaultdict(int)

    for items in terms:
        key, value = items.split(" ")
        types[key] = int(value)

    for cnt, items in enumerate(privacies):
        dates, typeinfo = items.split(" ")
        expires = int(types[typeinfo])

        # Expired
        if calculateDate(today, dates, expires):
            answer.append(cnt+1)

    return answer
