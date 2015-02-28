## Course: CS 101
## Assignment: Program 2
## Filename: Assignment2
## Name: Alexeo Smith
## Email: asd5b@mail.umkc.edu

# Problem:
## In the casino game of Lucky Sevens, the player rolls a pair of dice. If the dice add up to 7, the player
##wins $4; otherwise the player loses $1. Suppose a casino tries to entice the gullible by pointing out in
##its ads that there are several ways to win: (1, 6), (2, 5), etc. A little mathematical analysis makes it clear
##that there aren't enough ways to win to make it worthwhile; over the long run, the player is doomed.
##But most people's eyes glaze over at the first mention of mathematics, let alone probabilities. So your
##task is to write a program demonstrating the futility of playing this game.
##Your program should take as input the total amount the player wants to put into the pot (which should
##be a whole number > 0). It will then play the game until the pot is empty, at which point it will print
##how many rounds it took to bankrupt the player, and the highest amount the pot ever reached. 

## Algorithm:
 
## 1) Import random so random numbers can be generated. Create two variables to store the random
##     numbers for the dice
##    
## 2) Prompt the user for the starting pot amount and store the value
##
## 3) Ask the user if the want a detailed report and store the value
##
## 4) Create a function to see if the user entered an integer value greater than    
##    zero.  If the user entered an invalid value, warn the user again to enter 
##    an integer value greater than zero.  A function is best here because this code will
##    be needed again
##
## 5) Create a function to play the game as long as the pot value is greater than zero.
##      Execute the logic in the given assignment above and use a while loop and 
##     multiple list variables to store the results. A function is best here because this  
##    code will be needed again
##
## 6) When the pot reaches zero, either print a detailed report and a summary or just   
##    a summary. The max pot amount will be displayed in the summary.
##    The verdict will be base on the value stored in number 3 above.
##    Use a For loop to iterate through the list and print the   
##    values for the detailed report
##
## 7) Ask the user if they want to play again and call the appropriate functions (i.e. 
##    number 4 and 5 above to play the game again if necessary. 
##   Else exit the program
 


# Import random so random numbers could be generated
import random


## Prompt user for the starting pot amount
beginningPotAmount = int(input("What's the staring pot amount? "))
detailedReport = input("Do you want a detaled report? Y/N ")
report = detailedReport.lower()                    

## Create a function to see if the user entered an integer value greater than zero
def getUserInput(userResponse): 
   inputValue = userResponse
   while inputValue < 1:
      print("Sorry, you must enter an interger value greater than zero")
      inputValue = int(input("What's the staring pot amount? "))
      continue
   return inputValue

## Create a function to play the game as long as the pot value is greater than zero
def playGame(money, reportValue):
   pot = money
   initialPotAmount = money
   reportType = reportValue
   firstRoll = 0
   rounds = 0
   dispenseAmount = 0
   ## Create empty list variables to store multiple values
   storeDie1Result = []
   storeDie2Result = []              
   storeSum = []
   storePotAmount = []
   storePayout = []
   

   ## Store the results into the list variables 
   while pot > 0:
     die1 = random.randint(1,6)
     die2 = random.randint(1,6)
     total = die1 + die2
     if total == 7:
          pot += 4
          dispenseAmount = 4
     else:
          pot -= 1
          dispenseAmount = -1
     payout = dispenseAmount     
     storeDie1Result.append(die1)
     storeDie2Result.append(die2)
     storeSum.append(total)
     storePotAmount.append(pot)
     storePayout.append(dispenseAmount)
     rounds += 1
     continue

  ## When the pot reaches zero, report how many rounds was needed to bankrupt
  ## the user and  display the maximum pot amount reached
   highestPotEntry = max(storePotAmount)

   ## Print a detailed report
   if reportType == "y" or reportType == "yes":
      for value in range(rounds):
         print("Roll: " + str(storeDie1Result[value]) + " " + str(storeDie2Result[value])+ " " + "Total: " + str(storeSum[value]) \
               + " Payout: " + str(storePayout[value]) + " " + "Pot: " +  str(storePotAmount[value]))       
     
   ## Print a summary report
   print("You went broke in " + str(rounds) + " rounds, with a maximum pot of " + str(highestPotEntry)+".")
   
## Call the function to start the game and pass the pot and report values
playGame(getUserInput(beginningPotAmount), report)

## See if the user wants to play the game again
playAgain = input("Do you want to play again? Y/N ")
nextGame = playAgain.lower()
while (nextGame != "n" and nextGame != "no"):
## If yes, prompt user for the new starting pot amount
   beginningPotAmount = int(input("What's the staring pot amount? "))
   detailedReport = input("Do you want a detaled report? Y/N ")
   report = detailedReport.lower()

   ## Play the game again
   playGame(getUserInput(beginningPotAmount), report)
   playAgain = input("Do you want to play again? Y/N ")
   nextGame = playAgain.lower()

   ## Exit the program if the user doesn't want to play again
   if nextGame == "n" or nextGame == "no":
      break
   
## Print a goodby message   
print("Thanks for playing.  Have a good day!")  
   
   
   
                     

