def CheckAge(date):
    date.rstrip()
    s = date.split('.')
    days = int(s[0])
    days += int(s[1]) * 30
    days += int(s[2]) * 365
    newdays = 11 + 3 * 30 + 2022 * 365
    age = newdays - days
    if (age > 7304 and age < 21914):
        return True
    else:
        return False

def CreateFile(fname):
    print("Select mode:")
    print("1) Create new file")
    print("2) Change old file")
    print("3) Just use last one")
    n = int(input())
    if n == 1:
        fout = open(fname, 'wb')
        s = "yes"
        while (s == "yes"):
            name = input("Name: ") + "  "
            bt = name.encode()
            date = input("Date: ") + "  "
            if CheckAge(date) == False:
                print("Wrong age!")
                s = input("Continue?")
                continue
            fout.write(bt)
            bt = date.encode()
            fout.write(bt)
            num = input("Registration number: ") + "  "
            bt = num.encode()
            fout.write(bt)
            sex = input("Sex: ") + '\n'
            bt = sex.encode()
            fout.write(bt)
            s = input("Continue?")
        fout.close()
    if n == 2:
        fout = open(fname, 'ab')
        s = "yes"
        while (s == "yes"):
            name = input("Name: ") + "  "
            bt = name.encode()
            date = input("Date: ") + "  "
            if CheckAge(date) == False:
                print("Wrong age!")
                s = input("Continue?")
                continue
            fout.write(bt)
            bt = date.encode()
            fout.write(bt)
            num = input("Registration number: ") + "  "
            bt = num.encode()
            fout.write(bt)
            sex = input("Sex: ") + '\n'
            bt = sex.encode()
            fout.write(bt)
            s = input("Continue?")
        fout.close()

def CheckAge2(date):
    date.rstrip()
    s = date.split('.')
    days = int(s[0])
    days += int(s[1]) * 30
    days += int(s[2]) * 365
    newdays = 11 + 3 * 30 + 2022 * 365
    age = newdays - days
    if (age > 14609):
        return True
    else:
        return False

def Sort(fname):
    fin = open(fname, 'rb')
    fout1 = open("1.bin", 'wb')
    fout2 = open("2.bin", 'wb')
    lines = fin.readlines()
    for bt in lines:
        line = bt.decode();
        b = line.split("  ")
        date = b[1]
        if CheckAge2(date) == True:
            byt = line.encode()
            fout1.write(byt)
        else:
            byt = line.encode()
            fout2.write(byt)             
    fout1.close()
    fout2.close()
    fin.close()

def FilesOutput(fname):
    read1 = open(fname, 'rb')
    read2 = open("1.bin", 'rb')
    read3 = open("2.bin", 'rb')
    print("\nFile we've got:\n")
    for line in read1:
        print(line)
    print("\nFirst file:\n")
    for line in read2:
        print(line)
    print("\nSecond file:\n")
    for line in read3:
        print(line)
    read1.close()
    read2.close()
    read3.close()
    
fname = "File.bin"  
CreateFile(fname)
Sort(fname)
FilesOutput(fname)