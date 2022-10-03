import random
import os
import sys
from pprint import pprint

def random_word(words):
   return random.choice (words)


current_directory = os.path.dirname(os.path.abspath("generator.py"))
# 👇️ change to directory containing file
os.chdir(current_directory)


C = ['A','B','C','D','T','R','L']


with open("C:\\Users\\bhj01\\OneDrive\\Документы\\GitHub\\University\\Cpp\\LabbFour\\pyGenerator\\dict.txt", 'r') as file:
    words1 = file.readlines()
    words1 = [s.strip("\n") for s in words1]


with open("C:\\Users\\bhj01\\OneDrive\\Документы\\GitHub\\University\\Cpp\\LabbFour\\pyGenerator\\rdict.txt", 'r') as file:
    words2 = file.readlines()
    words2 = [s.strip("\n") for s in words2]

with open("C:\\Users\\bhj01\\OneDrive\\Документы\\GitHub\\University\\Cpp\\LabbFour\\pyGenerator\\lrdict.txt", 'r') as file:
    words = file.readlines()
    words = [s.strip("\n") for s in words]


words.extend(words1)
words.extend(words2)
# pprint(words)


with open("C:\\Users\\bhj01\\OneDrive\\Документы\\GitHub\\University\\Cpp\\LabbFour\\pyGenerator\\forTesting.txt",'w') as file:
    for i  in range(random.randint(15,45)):
        file.write(random_word(words))
        file.write(" ")
        file.write(random_word(words))
        file.write(" ")
        file.write(str(random.randint(100,1000)))
        file.write(" ")
        file.write(str(random.randint(100,1000)))
        file.write("\n")


