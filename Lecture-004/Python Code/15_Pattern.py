"""
    A
    B C
    C D E
    D E F G
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    count = chr(64+i)
    for j in range (0, i):
        print(count, end=" ")
        count = chr(ord(count) + 1)
    print()