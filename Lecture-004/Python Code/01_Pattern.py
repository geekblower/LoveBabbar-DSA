"""
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    for j in range (1, n+1):
        print(j, end=" ")
    print()