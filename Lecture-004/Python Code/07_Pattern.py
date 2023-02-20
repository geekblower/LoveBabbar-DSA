"""
    1
    2 3
    3 4 5
    4 5 6 7
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    count = i
    for j in range (0, i):
        print(count, end=" ")
        count += 1
    print()