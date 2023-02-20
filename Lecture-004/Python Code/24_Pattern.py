"""
    1 2 3 4
      2 3 4
        3 4
          4
"""

n = int(input("Enter the value of n : "))
for i in range (0, n):
    for j in range (0, i):
        print(end="  ")
    for j in range (1, n-i+1):
        print(j+i, end=" ")
    print()