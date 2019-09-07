n = int(input())
a = input().split()
c = dict()
for i in a:
    if i in c:
        c[i] += 1
        print(c[i], end=" ")
    else:
        c[i] = 1
        print(1, end=" ")
