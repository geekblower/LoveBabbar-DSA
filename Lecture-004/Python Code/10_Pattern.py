"""
    A B C D
    A B C D
    A B C D
    A B C D
"""

n = int(input("Enter the value of n : "))
for i in range (65, 65+n):
    for j in range (65, 65+n):
        print(chr(j), end=" ")
    print()