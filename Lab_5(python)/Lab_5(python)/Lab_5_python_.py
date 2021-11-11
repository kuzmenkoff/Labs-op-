import math
print("Простые числа ряда Фибоначчи:")
fib1 = int(1)
fib2 = int(1)
fib_sum = fib1 + fib2
i = int(2)
print(fib1, "[", i, "]")
print(fib2, "[", i+1, "]")
print(fib_sum, "[", i+2, "]")

while fib_sum <= 100:
     fib_sum = fib1 + fib2
     fib1 = fib2
     fib2 = fib_sum
     i = i + 1
     for j in range(2,fib1):
        if (fib1 % j == 0):
            break
        if (fib1 == j + 1):
            print(fib1, "[", i, "]")