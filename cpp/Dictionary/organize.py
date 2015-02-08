f = open("Full text of  Webster's Unabridged Dictionary .txt", "r")
n = open("Dictionary.txt", "w")

import re

'''
# Unused, alternate version of code
f = f.read()
match = re.findall("([A-Z]{1,}[\n])(.*\n).*([Defn:|1].*)", f)
for m in match:
    # if (len(m[0]) > 1):
     n.write(m[0])
     n.write(m[1])
     n.write(m[2])
#for m in match:
#    n.write("word:" + m.group(1))
#    n.write("pron:" + m.group(2))
#    n.write("defn:" + m.group(3))

'''
'''
This script uses regular expressions to identify the dictionary words
    and their definitions, and organize them in a way that is easier
    for my C++ code to manipulate. Since all of the words are in caps
    I just identify lines that are entirely caps, and put 'word:' in
    front of them. The rest are 'def'.

Initially, I simply rewrote this entire thing to my new text file, but
    it took too long to build the binary tree, so I decided to only
    use a fraction of the dictionary. So I stored all of the words and
    their definitions into a table, and only rewrote them up to a
    certain point in the new file.
'''
dic = {}
words = []
for line in f:
    match = re.match("([A-Z]{1,}[\n])", line)
    if(bool(match)):
        if (len(match.group(1)) == len(line)):
           if (not (match.group(1) in dic)):
	       word = match.group(1)
               words.append(word)
               dic[word] = []
    else:
        if (len(line) > 1):
            dic[word].append(line)
f.close()

for i in range(len(words)/4):
    n.write("word:" + words[i])
    for j in dic[words[i]]:
        n.write("defn:" + j)
n.close()

#f = open("Dictionary.txt", "r")
#f = f.read()
#count = re.findall("word:.[^\W]*\n", f)
#print len(count)
