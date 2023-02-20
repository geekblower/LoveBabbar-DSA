"""
    A A A
    B B B
    C C C
"""

n = int(input("Enter the value of n : "))
for i in range (65, 65+n):
    for j in range (1, n+1):
        print(chr(i), end=" ")
    print()