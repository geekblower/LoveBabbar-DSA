"""
    A B C
    B C D
    C D E
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    count = chr(65 + i)
    for j in range (0, n):
        print(count, end=" ")
        count = chr(ord(count) + 1)
    print()