"""
    1 2 3 4 5 5 4 3 2 1
    1 2 3 4 * * 4 3 2 1
    1 2 3 * * * * 3 2 1
    1 2 * * * * * * 2 1
    1 * * * * * * * * 1
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    for j in range (i, n+1):
        print(j, end=" ")
    for j in range (1, i):
        print(end="* * ")
    for j in range (n-i+1, 0, -1):
        print(j, end=" ")
    print()