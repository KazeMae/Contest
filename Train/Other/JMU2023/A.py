t = int(input())
while t > 0:
    a, b, c = list(input().split())
    jz = [16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2]
    ans = 16
    t -= 1
    flag = False
    for i in jz :
        aa = int(a, i)
        bb = int(b, i)
        cc = int(c, i)
        if aa + bb == cc:
            flag = True
            ans = i
            break
    if flag :
        print(ans)
        continue
