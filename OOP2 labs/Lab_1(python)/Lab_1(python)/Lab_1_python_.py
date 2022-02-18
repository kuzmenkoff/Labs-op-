# Генеруємо файл та вписуємо текст
def GenerateFile(): 
    fout = open ('file.txt', 'w')
    i = 0
    text = []
    a = input();
    text.append(a)
    while text[i] != "":
        a = input()
        text.append(a);
        i = i + 1
    for j in text:
        fout.write(j + '\n')
    fout.close()
# Зчитуємо файл, заносимо отриманий текст у масив рядків, змінюємо текст
def ReadFile(): 
    fin = open ('file.txt', 'r')
    i = 0
    text = []
    for line in fin:
        text.append(line)
        i = i + 1
    j = 0
    while j < i - 1:
        a = str(len(text[j]) - 1)
        text[j] = '(' + a + ') ' + text[j]
        j = j + 1
    fin.close()
    return text
# Генеруємо новий файл та заносимо у нього змінений текст
def GenerateNewFile(text):
    fout = open ("NEWfile.txt", 'w')
    for i in text:
        fout.write(i)
    fout.close()
# Виводимо вміст двох файлів у консоль
def FilesOutput():
    read1 = open ('file.txt', 'r')
    print("Created file:" + '\n')
    for line in read1:
        print(line)
    read1.close()
    read2 = open ('NEWfile.txt', 'r')
    print("New file:" + '\n')
    for line in read2:
        print(line)
    read2.close()

GenerateFile()
NewText = ReadFile()
GenerateNewFile(NewText)
FilesOutput()