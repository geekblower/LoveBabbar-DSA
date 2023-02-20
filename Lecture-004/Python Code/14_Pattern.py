"""
    A
    B C
    D E F
    G H I J
"""

n = int(input("Enter the value of n : "))
count = 'A'
for i in range (1, n+1):
    for j in range (1, i+1):
        print(count, end=" ")
        count = chr(ord(count) + 1)
    print()