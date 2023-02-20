"""
    D
    C D
    B C D
    A B C D
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    count = chr(64 + n - i)
    for j in range (0, i+1):
        print(count, end=" ")
        count = chr(ord(count) + 1)
    print()