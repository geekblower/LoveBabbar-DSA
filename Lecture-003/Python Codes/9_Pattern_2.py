"""
    1 1 1 1
    2 2 2 2
    3 3 3 3
    4 4 4 4
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    for j in range (0, n):
        print(i, end=" ")
    print()