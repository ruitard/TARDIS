n = int(input())
s = input().split()
hmp = dict()
res = list()
max_count = 0
for c in s:
    if c in hmp:
        hmp[c] += 1
    else:
        hmp[c] = 1
    if hmp[c] > max_count:
        max_count = hmp[c]
        res = list()
        res.append(c)
    elif hmp[c] == max_count:
        res.append(c)
print(min(res))
