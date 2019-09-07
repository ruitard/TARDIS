n = int(input())
a = input().split()
pre = a[0]
count = 1
for i in a[1:]:
    if i != pre:
        count += 1
        pre = i
print(count)
