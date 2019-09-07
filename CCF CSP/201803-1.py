n = input().split()
pre = '1'
grade = 0
score = 0
for i in n:
    if i is '0':
        break
    elif i is '1':
        grade += 1
        pre = '1'
    elif i is '2' and pre is '1':
        score = 2
        grade += 2
        pre = '2'
    elif i is '2' and pre is '2':
        score += 2
        grade += score
print(grade)
    

