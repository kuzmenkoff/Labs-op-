import random

class TTime:
    def __init__(self):
        self.hh = 0
        self.mm = 0
        self.ss = 0

    def SetTime(self, h, m, s):
        self.hh = h
        self.mm = m
        self.ss = s

    def DayEndTime(self):
        TimeInSec = 0
        TimeInSec += self.ss
        TimeInSec += self.mm * 60
        TimeInSec += self.hh * 60 * 60
        while TimeInSec >= 86400:
            TimeInSec -= 86400
        return 86500 - TimeInSec

    def Check(self):
        while self.hh >= 24 or self.mm >= 60 or self.ss >= 60:
            if self.hh >= 24:
                self.hh -= 24
            if self.mm >= 60:
                self.mm -= 60
                self.hh = self.hh + 1
            if self.ss >= 60:
                self.ss -= 60
                self.mm = self.mm + 1
        while self.hh < 0 or self.mm < 0 or self.ss < 0:
            if self.hh < 0:
                self.hh += 24
            if self.mm < 0:
                self.mm += 60
                self.hh = self.hh - 1
            if self.ss < 60:
                self.ss += 60
                self.mm = self.mm - 1

    def Increase(self, h, m, s):
        self.hh += h
        self.mm += m
        self.ss += s
        self.Check()

    def Decrease(self, h, m, s):
        self.hh -= h
        self.mm -= m
        self.ss -= s
        self.Check()

class TTime12(TTime):

    def Check(self):
        while self.hh >= 12 or self.mm >= 60 or self.ss >= 60:
            if self.hh >= 12 and self.meridiem == "a.m.":
                self.hh -= 12
                self.meridiem = "p.m."
            if self.hh >= 12 and self.meridiem == "p.m.":
                self.hh -= 12
                self.meridiem = "a.m."
            if self.mm >= 60:
                self.mm -= 60
                self.hh = self.hh + 1
            if self.ss >= 60:
                self.ss -= 60
                self.mm = self.mm + 1

        while self.hh < 0 or self.mm < 0 or self.ss < 0:
            if self.hh < 0 and self.meridiem == "a.m.":
                self.hh += 12
                self.meridiem = "p.m."
            if self.hh < 0 and self.meridiem == "p.m.":
                self.hh += 12
                self.meridiem = "a.m."
            if self.mm < 0:
                self.mm += 60
                self.hh = self.hh - 1
            if self.ss < 0:
                self.ss += 60
                self.mm = self.mm - 1


    def __init__(self):
        self.hh = 0;
        self.mm = 0
        self.ss = 0
        self.meridiem = "a.m."

    def __init__(self, h, m, s):
        self.hh = h
        self.mm = m
        self.ss = s
        self.meridiem = "a.m."
        self.Check()

    def DayEndTime(self):
        TimeInSec = 0
        TimeInSec += self.ss
        TimeInSec += self.mm * 60
        TimeInSec += self.hh * 60 * 60
        if self.meridiem == "p.m.":
            TimeInSec += 12 * 60 * 60
        while TimeInSec >= 86400:
            TimeInSec -= 86400
        return 86500 - TimeInSec

    def Print12(self):
        print(str(self.hh) + ':' + str(self.mm) + ':' + str(self.ss) + ' ' + self.meridiem)

    def Print12TimeBeforeEnd(self):
        TimeInSec = self.DayEndTime()
        h = 0
        m = 0
        s = 0
        while TimeInSec >= 3600:
            h = h + 1
            TimeInSec -= 3600
        while TimeInSec >= 60:
            m = m + 1
            TimeInSec -= 60
        s = TimeInSec
        print("Time before end of the day: " + str(h) + ':' + str(m) + ':' + str(s))

class TTime24(TTime):
    def __init__(self):
        self.hh = 0;
        self.mm = 0
        self.ss = 0

    def __init__(self, h, m, s):
        self.hh = h
        self.mm = m
        self.ss = s
        self.Check()

    def Print24(self):
        print(str(self.hh) + ':' + str(self.mm) + ':' + str(self.ss))

    def Print24TimeBeforeEnd(self):
        TimeInSec = self.DayEndTime()
        h = 0
        m = 0
        s = 0
        while TimeInSec >= 3600:
            h = h + 1
            TimeInSec -= 3600
        while TimeInSec >= 60:
            m = m + 1
            TimeInSec -= 60
        s = TimeInSec
        print("Time before end of the day: " + str(h) + ':' + str(m) + ':' + str(s))

N = int(input("n = "))
M = int(input("m = "))
time12 = []
print("\nTime12:")
for i in range(N):
    h = random.randint(1, 23)
    m = random.randint(1, 60)
    s = random.randint(1, 60)
    time12.append(TTime12(h, m, s))
    print(i + 1)
    time12[i].Print12()
print("\nTime12 decreased:")
for i in range(N):
    time12[i].Decrease(0, 0, 5);
    time12[i].Print12()
    time12[i].Print12TimeBeforeEnd();

time24 = []
print("\nTime24:")
for i in range(M):
    h = random.randint(1, 23)
    m = random.randint(1, 60)
    s = random.randint(1, 60)
    time24.append(TTime24(h, m, s))
    time24[i].Print24()
print("\nTime24 increased:")
for i in range(M):
    time24[i].Increase(0, 15, 0);
    time24[i].Print24()
    time24[i].Print24TimeBeforeEnd();

smalles12time = int(86400)
smallest12timei = int(0)
smallest24time = int(86400)
smallest24timei = int(0)
for i in range(N):
    if (time12[i].DayEndTime() < smalles12time):
        smallest12time = time12[i].DayEndTime();
        smallest12timei = i
for i in range(M):
    if (time24[i].DayEndTime() < smallest24time):
        smallest24time = time24[i].DayEndTime();
        smallest24timei = i
print("\nSmallest time before end of the day:\n")
if smallest24time < smallest12time:
    time24[smallest24timei].Print24()
    time24[smallest24timei].Print24TimeBeforeEnd()
else:
    time12[smallest12timei].Print12()
    time12[smallest12timei].Print12TimeBeforeEnd()
    

    
    
