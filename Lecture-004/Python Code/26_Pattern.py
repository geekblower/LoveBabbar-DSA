"""
          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
"""

n = int(input("Enter the value of n : "))
for i in range (1, n+1):
    for j in range (0, n-i):
        print(end="  ")
    for j in range (0, i):
        print(j+1, end=" ")
    for j in range (i-1, 0, -1):
        print(j, end=" ")
    print()