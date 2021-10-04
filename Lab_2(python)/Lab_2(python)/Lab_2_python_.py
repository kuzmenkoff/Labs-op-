import math
print("Введите значение длины сторон первого прямоугольника")
a = float(input("a="))
if a <= 0:
    print ("Данные введены некорректно.")
    exit(0)
b = float(input("b="))
if b <= 0:
    print ("Данные введены некорректно.")
    exit(0)
print("Введите значение длины сторон второго прямоугольника")
c = float(input("c="))
if c <= 0:
    print ("Данные введены некорректно.")
    exit(0)
d = float(input("d="))
if d <= 0:
    print ("Данные введены некорректно.")
    exit(0)

Max1 = max(a,b)
Min1 = min(a,b)
Max2 = max(c,d)
Min2 = min(c,d)

if Max1 <= Max2 and Min1 <= Min2:
    print("Прямоугольник со сторонами a и b можно поместить в прямоуголник со сторонами c и d.")

if Max1 > Max2 or Min1 > Min2:
    print("Прямоугольник со сторонами a и b нельзя поместить в прямоуголник со сторонами c и d.")

   