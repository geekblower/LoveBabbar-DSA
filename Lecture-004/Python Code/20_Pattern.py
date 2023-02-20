"""
    * * * *
    * * *
    * *
    * 
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    for j in range (1, n-i+1):
        print(end="* ")
    print()