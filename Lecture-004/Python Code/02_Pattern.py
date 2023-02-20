"""
    4 3 2 1
    4 3 2 1
    4 3 2 1
    4 3 2 1
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    j = n
    while j>0:
        print(j, end=" ")
        j -= 1
    print()