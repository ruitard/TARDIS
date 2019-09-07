n, m = input().split()
n = int(n)
m = int(m)
a = list()
for i in range(n):
    a.append(input().split())
for j in range(m-1, -1, -1):
    for i in range(0, n):
        print(a[i][j], end=" ")
    print()
