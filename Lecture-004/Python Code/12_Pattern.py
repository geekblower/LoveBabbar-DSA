"""
    A B C
    B C D
    C D E
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    count = chr(64+i)
    for j in range (1, n+1):
        print(count, end=" ")
        count = chr(ord(count) + 1)
    print()