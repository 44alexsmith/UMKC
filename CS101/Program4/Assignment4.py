## Course: CS 101
## Assignment: Program 4
## Filename: Assignment4
## Name: Alexeo Smith
## Email: asd5b@mail.umkc.edu

## Problem:
## A recent study claims that English text is still readable, with almost
## no loss of comprehension, even if the letters of a word are scrambled, as
## long as the first and last letters of each word are kept in the same position,
## along with sentence punctuation and any apostrophes in the word.
## For example, the above sentence, scrambled while keeping the first and last
## letters in place, may look like this:
## A recent sudty calmis that Ensgilh text is stlil rlbaeade, with amsolt no lsos
## of cpenoiromsehn, even if the leertts of a wrod are sacmblred, as long as the
## fsirt and lsat lrttees of ecah wrod are kpet in the smae pistooin, anlog with
## sncenete pottcuiuann and any asoherppots in the word.

##Algorithm:
##
## 1) Prompt the user for the path to a text file 
## 2) If the file path is valid open the file in read only mode
## 3) Throw an exception message if the user entered an invalid file path and prompt  
##    the user again to enter a valid file path
## 4) Use a function to read the lines in the text and split the sentences into individual words
## 5) Via a function, break the words into individual letters, slice and
##    shuffle all letters except the first and last characters
## 6) Create a function to handle newline characters, break the proceding word(s) into individual letters,
##    slice and shuffle all letters except the first and last
## 7) Create a function to handle a period at the end of a sentence. Break the proceeding word(s) into
##    individual letters slice and shuffle all letters except the first and last
## 8) Create a function to handle a comma at the end of a word. Break the proceeding  
##    word(s) into individual letters, slice and shuffle all the letters except the first and last
## 9) Call a main function to check to see if words are greater than three characters, and contain a new
##    line character, a period or a comma.  Base on what's found call the appropriate function above(i.e. 6-8)
##    to shuffle the letters appropriately
##    Print the result to the screen and suppress the default newline behavior of the  
##    print command


import random

##1) Prompt the user for the path to a text file
Switch = True
filePath = ""
while Switch == True:
 try:
## 2) If the file path is valid open the file in read only mode
    filePath = input("Enter your complete file path: ")
    print("\n")
    inputFile = open(filePath, 'r')
    Switch = False

## 3) Use a function to read the lines in the text and split the sentences into individual words
    def words_from_file(theFilePath):
      for line in open(theFilePath):
        for word in line.split(" "):
            yield word
            
## 4) Throw an exception if the user enters an invalid file path and prompt the
##    the user to enter a valid path file
 except IOError:           
    print("Please enter a valid path to a text file!")
    continue

## 5) Via a function, break the words into individual letters, slice and
##    shuffle all letters except the first and last characters
def shuffleLetters(word):
    output = list(word[1:-1])
    random.shuffle(output)
    output.append(word[-1])
    return word[0] + "".join(output)

## 6) Create a function to handle newline characters, break the proceding word(s) into individual letters,
##    slice and shuffle all letters except the first and last
def shuffleLettersWithNewLine(word):
    output = list(word[1:-3])
    random.shuffle(output)
    output.append(word[-3])
    output.append(word[-2])
    output.append(word[-1])
    return word[0] + "".join(output)

## 7) Create a function to handle a period at the end of a sentence. Break the proceding word(s) into
##    individual letters slice and shuffle all letters except the first and last
def shuffleLettersWithPeriod(word):
    output = list(word[1:-2])
    random.shuffle(output)
    output.append(word[-2])
    output.append(word[-1])
    return word[0] + "".join(output)

## 8) Create a function to handle a comma at the end of a word. Break the proceding word(s) into individual
##    letters, slice and shuffle all letters except the first and last
def shuffleLettersWithComma(word):
    output = list(word[1:-2])
    random.shuffle(output)
    output.append(word[-2])
    output.append(word[-1])
    return word[0] + "".join(output)

## 9) Call a main function to check to see if words are greater than three characters, and contain a new
##    line character, a period or a comma.  Base on what's found call the appropriate function above(i.e. 6-8)
##    to shuffle the letters appropriately
##    Print the result to the screen and suppress the default newline behavior of the  
##    print command
for word in words_from_file(filePath):
    if len(word) > 3:
        if word[-1] == "\n":
            print(shuffleLettersWithNewLine(word)+" ",end="")
        elif word[-1] == ".":
            print(shuffleLettersWithPeriod(word)+" ",end="")
        elif word[-1] == ",":
            print(shuffleLettersWithComma(word)+" ",end="")
        else:
            print(shuffleLetters(word)," " ,end="")           
    else:
        print(word +" ", end="")


    
