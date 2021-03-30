def culti_num(str):
    drink_list = [int(i) for i in str.split(' ')]
    max_sat = 1
    sat_multi = 1
    for i in range(len(drink_list)):
        if drink_list[i] <= 20:
            for j in range(int((20 - drink_list[i]) / 2)):
                sat_multi *= 2
        drink_list[i] *= sat_multi
        if drink_list[i] > max_sat:
            max_sat = drink_list[i]
        sat_multi = 1
    return max_sat

while True:
    try:
        input_n = input()
        input_str = input()
    except EOFError:
        break
    print(culti_num(input_str))