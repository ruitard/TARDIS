n = int(input())
a = map(int, input().split())
count = 0
hash_map = set()
for i in a:
    if i-1 in hash_map:
        count += 1
    if i+1 in hash_map:
        count += 1
    hash_map.add(i)
print(count)
