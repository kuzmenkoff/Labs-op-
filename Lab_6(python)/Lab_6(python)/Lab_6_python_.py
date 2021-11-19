
import math
def foo(x):
     for j in range(2,x):
        if (x % j == 0): 
            return 0 
        if (x == j + 1): 
            return 1

print("Введите натуральное число n:")
n = int(input("n = "))
print("Числа-близнецы в интервале от", n, "до", n * 2, ":")
i = int(n)

for i in range (i, n*2):
    if (foo(i) == 1 and foo(i+2) == 1):
            print(i, i+2)