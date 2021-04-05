while True:
    try:
        s = input()
    except EOFError:
        break
    for i in range(len(s) - 2):
        if len(s) <= 2:
            print(s)
            break
        if s[i] == s[i+1] == s[i+2]:
            for j in range(i, len(s)):
                if s[j] == s[j+1]:
                    print("+1")
                    continue
                else:
                    s.replace(s[i:i+j], str(j-i) + s[i])
        print(s)