def GetString(str):
    words = string.split(" ")
    res = ""
    for word in words:
        first = word[0].lower()
        last = word[len(word) - 1].lower()
        if first == last:
            res += " " + word
    return res

string = input("Enter string: ")
words = GetString(str)
print("List of words: " + words)
print("Number of such words: " + str(len(words.split(" ")) - 1))

