n = int(input())
a = [int(i) for i in input().split()]
res = 0
for i in range(1, n):
    tmp = abs(a[i]-a[i-1])
    if tmp > res:
        res = tmp
print(res)
