from random import randint

n = 100000

print(1)
print(n)

for i in range(1, n + 1):
    print(1, end=" " if i != n else "\n")

for i in range(2, n + 1):
    print(1, i)