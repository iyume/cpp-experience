def culti_num(str):
    seq_sum_list = []
    a, b = str.split(' ')
    l = len(a)
    for i in range(l):
        for j in range(l):
            if a[i] == b[j]:
                seq_sum_list.append(i + j)
    if len(seq_sum_list):
        return min(seq_sum_list)
    else:
        return "I was angry!"

while True:
    try:
        input_str = input()
    except EOFError:
        break
    print(culti_num(input_str))