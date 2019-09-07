n, l, t = input().split()
n, l, t = int(n), int(l), int(t)

p = [int(i) for i in input().split()]
sp = sorted(p)
map_set = list()
for i in p:
    map_set.append(sp.index(i))
ori = [1] * n 

for ti in range(t):
    for i in range(n-1):
        if sp[i] == sp[i+1]:
            ori[i] ^= (-1^1)
            ori[i+1] ^= (-1^1)
    if sp[0] == 0 and ori[0] == -1:
        ori[0] = 1
    if sp[n-1] == l and ori[n-1] == 1:
        ori[n-1] = -1
        
    for i in range(n):
        sp[i] += ori[i]

for i in map_set:
    print(sp[i], end=" ")
print()