"""
    D 
    C C
    B B B
    A A A A
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    count = chr(64 + n - i)
    for j in range (0, i+1):
        print(count, end=" ")
    print()