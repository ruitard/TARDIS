n = int(input())
print(n)
res = (n // 50) * 7
n = n % 50
if n >= 30:
    res += 4
    res += (res-30)//10
else:
    res += res//10

print(res)
