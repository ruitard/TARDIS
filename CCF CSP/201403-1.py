n = int(input())
a = map(int, input().split())
count = 0
s = set()
for i in a:
    if -i in s:
        count += 1
    else:
        s.add(i)
print(count)
