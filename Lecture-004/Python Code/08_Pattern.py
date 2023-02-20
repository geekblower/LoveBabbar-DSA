"""
    1
    2 1
    3 2 1
    4 3 2 1
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    count = i
    for j in range (0, i):
        print(count, end=" ")
        count -= 1
    print()