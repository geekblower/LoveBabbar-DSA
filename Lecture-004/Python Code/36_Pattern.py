"""
    1 2 3 4 5 16 17 18 19 20
    6 7 8 9 21 22 23 24
    10 11 12 25 26 27
    13 14 28 29
    15 30
"""

n = int(input("Enter the value of n : "))
count1 = 1
count2 = (int)(n*(n+1)/2) + 1
for i in range (0, n):
    for j in range (i, n):
        print(count1, end=" ")
        count1 += 1
    for j in range (i, n):
        print(count2, end=" ")
        count2 += 1
    print()