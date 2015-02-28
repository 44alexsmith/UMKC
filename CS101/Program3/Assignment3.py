## Course: CS 101
## Assignment: Program 3
## Filename: Assignment3
## Name: Alexeo Smith
## Email: asd5b@mail.umkc.edu

##Problem:
##Rock-Paper-Scissors is an ancient and well-known game, sometimes used as a sort-of-random selection method. Of course, the game isn't truly random, since an intelligent player can observe and exploit non- random behavior of their opponent. For example, if you notice that your opponent most often chooses Paper, then you can choose Scissors (which beats Paper) in an attempt to win.
##Rules of the game:
##Each player chooses a weapon: Rock, Paper, or Scissors, and reveals it to the other at the same time. The winner is determined by simple rules:
##• Rock breaks Scissors (Rock wins)
##• Scissors cuts Paper (Scissors wins)
##• Paper covers Rock (Paper wins)
##• If both players choose the same thing, it's a tie, and neither wins.


##Algorithm:
##1)	Declared global variables necessary for the program. Including a variable
##      to display instructions for the game
##
##2)	Imported the sys module to exit the program via the exit() function
##
##3)	Use a while loop and write the code to have the computer select its   
##      weapon out of r(rock), p(paper) or s(scissor)
##
##4)	(i) In the aforementioned loop prompt the user to choose their weapon or  
##      h(help) for instructions
##      (ii) Print a warning message if the player entered an invalid character and give  
##             the user the opportunity to choose again
##      (iii) If the user entered a valid input, continue playing the game 
##
##5)    Compare the user's selection with the computer's selection to
##      to see who the winner is and display the result.  Increment counters
##      for wins, losses, ties and rounds played etc
##
##6)     If the user played one or more rounds and selects q to quit, print a summary 
##       report. The report will entail a comparison of the total rounds, wins, losses and  
##       ties between the player and the computer. Then the program will exit.  
##       Else, the program will just exit 



## 1) Declare some global variables
gameChoice_str = ""
basicChoice_str = "hrpsq"
computerWins = 0
playerWins = 0
rounds = 0
ties_int = 0
validInput = ""
scount_int = 0
scount2_int = 0
rcount_int = 0
rcount2_int = 0
pcount_int = 0
pcount2_int = 0
cpuChoice = ""
increment_str = 0
choices_str = ["r","p","s"]
help_str =''' Rules of the game: 

              Both you and the computer selects a weapon: Rock,
              Paper, or Scissors, and reveals it to the other at the same time.

              The winner is determined by simple rules:
              1) Rock breaks Scissors (Rock wins) 
              2) Scissors cuts Paper (Scissors wins) 
              3) Paper covers Rock (Paper wins) 

              If you and the computer choose the same thing, it's a tie, and
              neither of you win. '''

## 2) Import random to generate random numbers and sys to exit
##    the program via the quit option
import random
import sys

## 3) Write code to have the computer randomly select  its weapon
##    out of rock, paper or scissor
while validInput != "q":
 userChoice = input("Choose your weapon! ==> ").lower()
 if userChoice == "q":
## 4) Exit the program and print a summary report if the user selects q for quit      
    if rounds > 0:
        print("That was a good game!")
        print("We played " +str(rounds)+ " " + "rounds.")
        print("You won " + str(playerWins) + " rounds," + " I won " + str(computerWins)+" times"\
              " and we tied on " + str(ties_int)+".")
        print("You used rock "+str(rcount_int)+" times, " + "scissors "+str(scount_int)+" times,"\
        + " and paper "+ str(pcount_int)+" times.")
        exit()
    else:
       print("Good bye!")
       exit()      
 elif userChoice == "h":
     print(help_str)
     continue
 elif userChoice not in basicChoice_str:
    print("You must choose either r,p,s,q or h for help")
 else: 
## 5)Compare the user's selection with the computer's selection to
##   to see who the winner is and display the result
    
    cpuChoice = choices_str[0]
    increment_str += 1
    if increment_str == len(choices_str)-1:
       increment_str = 0
        
    if rcount2_int >= 3:
         cpuChoice = "p"
    elif pcount2_int >= 3:
         cpuChoice = "s"
    elif scount2_int >= 3:
         cpuChoice = "r"

    if userChoice == "r" and cpuChoice == "s":
        print("You chose rock ")
        print("I chose scissors ")
        print("You win.")
        playerWins += 1
        rounds +=1
        rcount_int += 1
        rcount2_int += 1
    elif userChoice == "r" and cpuChoice == "p":
        print("You chose rock ")
        print("I chose paper ")
        print("I win. ")
        computerWins += 1
        rounds +=1
        rcount_int += 1
        rcount2_int += 1
    elif userChoice == "r" and cpuChoice == "r":
        print("You chose rock ")
        print("I chose rock ")
        print("Neither of us win. ")
        ties_int += 1
        rounds +=1
        rcount_int += 1
        rcount2_int += 1
    elif userChoice == "s" and cpuChoice == "r":
        print("You chose scissors ")
        print("I chose rock ")
        print("I win. ")
        computerWins += 1
        rounds +=1
        scount_int += 1
        scount2_int += 1
    elif userChoice == "s" and cpuChoice == "p":
        print("You chose scissors ")
        print("I chose paper ")
        print("You win. ")
        computerWins += 1
        rounds +=1
        scount_int += 1
        scount2_int += 1
    elif userChoice == "s" and cpuChoice == "s":
        print("You chose scissors ")
        print("I chose scissors ")
        print("Neither of us win. ")
        ties_int += 1
        rounds +=1
        scount_int += 1
        scount2_int += 1
    elif userChoice == "p" and cpuChoice == "r":
        print("You chose paper ")
        print("I chose rock ")
        print("You win. ")
        playerWins += 1
        rounds +=1
        pcount_int += 1
        pcount2_int += 1
    elif userChoice == "p" and cpuChoice == "s":
        print("You chose paper ")
        print("I chose scissors ")
        print("I win. ")
        computerWins += 1
        rounds +=1
        pcount_int += 1
        pcount2_int += 1
    elif userChoice == "p" and cpuChoice == "p":
        print("You chose paper ")
        print("I chose paper ")
        print("Neither of us win. ")
        ties_int += 1
        rounds +=1
        pcount_int += 1
        pcount2_int += 1

    if rcount2_int == 4:
        rcount2_int = 0
    elif pcount2_int == 4:
        pcount2_int = 0
    elif scount2_int == 4:
        scount2_int = 0
    random.shuffle(choices_str)
         
   
         


        
