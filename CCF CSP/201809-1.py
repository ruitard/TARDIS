n = int(input())
prices = list(map(int, input().split()))
print((prices[0]+prices[1])//2, end=" ")
for i in range(1, n-1):
    print((prices[i-1]+prices[i]+prices[i+1])//3, end=" ")
print((prices[n-2]+prices[n-1])//2)
