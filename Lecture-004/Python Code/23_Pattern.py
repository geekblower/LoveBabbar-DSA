"""
          1
        2 2
      3 3 3
    4 4 4 4
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    for j in range (1, n-i):
        print(end="  ")
    for j in range (0, i+1):
        print(i+1, end=" ")
    print()