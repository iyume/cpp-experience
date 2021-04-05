while True:
    try:
        x = input()
        r = input()
    except EOFError:
        break
    r_block = [int(i) for i in r.split(' ')]
    for i in range(r_block[0], r_block[1] + 1):
        n = len(str(i))
        num_split = [j for j in str(i)]
        num_split_sum = 0
        for j in num_split:
            num_split_sum += pow(int(j), n)
        if num_split_sum * int(x) == i:
            print(i)
