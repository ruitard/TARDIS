n, k = input().split()
n = int(n)
k = int(k)
#a = [int(i) for i in input().split()]
a = map(int, input().split())
count = 0
sum = 0
for i in a:
    sum += i
    if sum >= k:
        count += 1
        sum = 0
if sum > 0:
    count += 1
print(count)
