n = int(input())
a = [int(i) for i in input().split()]
a.sort()
res = 10001
for i in range(1, n):
    tmp = a[i] - a[i-1]
    if tmp < res:
        res = tmp
print(res)
