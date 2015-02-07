f = open("Full text of  Webster's Unabridged Dictionary .txt", "r")
n = open("Dictionary.txt", "w")

import re

word_count = 0

for line in f:
    match = re.match("([A-Z]{1,}[\n])", line)
    if(bool(match)):
        if (len(match.group(1)) == len(line)):
            n.write("word:" + line)
            word_count += 1
    else:
        if (len(line) > 1):
            n.write("defn:" + line)
print word_count
f.close()
n.close()

f = open("Dictionary.txt", "r")
f = f.read()
count = re.findall("word:.[^\W]*\n", f)
print len(count)
