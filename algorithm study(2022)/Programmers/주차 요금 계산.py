from collections import defaultdict
import math

def calculateTime(car_dict, time, number):
    in_time = car_dict[number]
    in_time_hr = int(in_time[0:2])
    in_time_min = int(in_time[3:5])
    
    out_time = time
    out_time_hr = int(out_time[0:2])
    out_time_min = int(out_time[3:5])
    
    return (out_time_hr - in_time_hr) * 60 + (out_time_min - in_time_min)


def solution(fees, records):
    answer = []
    
    car_num = []
    car_dict = defaultdict()
    car_status = defaultdict()
    car_visited = defaultdict(lambda : False)
    answer_dict = defaultdict(lambda : 0)
    
    for items in records:
        time, number, status = items.split()
        
        if number not in car_dict.keys():
            car_dict[number] = time
            car_status[number] = False # IN
            
            if car_visited[number] == False:
                answer_dict[number] = 0
            car_visited[number] = True # Visited history
        else:
            elapsed_time = calculateTime(car_dict, time, number)
            answer_dict[number] += elapsed_time
                
            del car_dict[number]
            
            car_status[number] = True # OUT
            
    for cars, stat in car_status.items():
        if stat == False: # No record until 23:59
            elapsed_time = calculateTime(car_dict, "23:59", cars)
            answer_dict[cars] += elapsed_time
    
    answer_dict = sorted(answer_dict.items())
    
    for keys, vals in answer_dict:
        result = 0
        
        # 기본 요금
        if vals <= fees[0]:
            result = fees[1]
        else:
            over_time = vals - fees[0]
            cnt = math.ceil(over_time / fees[2])
            result = fees[1] + fees[3] * cnt
        
        answer.append(result)
    
    return answer
