n = int(input())
a = [int(i) for i in input().split()]
if n == 1 or n == 2:
    print(0)
else:
    count = 0
    for i in range(1, n-1):
        if a[i] > a[i-1] and a[i] > a[i+1]:
            count += 1
        elif a[i] < a[i-1] and a[i] < a[i+1]:
            count += 1
    print(count)
