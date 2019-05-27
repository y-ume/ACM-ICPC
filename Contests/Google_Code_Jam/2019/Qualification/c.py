import fractions as fr
T = int(input())
for case in range(1,T+1):
    n , L = map(int , input().split())
    a = list(map(int , input().split()))
    start = 0
    b = [0]*(L+1)
    for i in range(len(a)-1):
        if a[i] != a[i+1]:
            g = fr.gcd(a[i],a[i+1])
            start = i
            b[i] = a[i]//g
            break
    for j in range(start,len(a)):
        b[j+1] = a[j]//b[j]
    for j in range(start)[::-1]:
        b[j] = a[j]//b[j+1]
    t = list(set(b))
    t.sort()
    ans = "".join(list(map(lambda x: chr(t.index(x)+65),b)))
    print("Case #{}: {}".format(case,ans))
