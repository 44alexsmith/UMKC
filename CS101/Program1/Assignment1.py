# Course: CS 101
# Assignment: Program 1
# Filename: Assignment1
# Name: Alexeo Smith
# Email: asd5b@mail.umkc.edu

# Problem:
# I am planning to host a large spaghetti dinner. A child will
# eat 4 ounces of pasta, an adult 8 ounces of pasta, and a college
# student 12 ounces of pasta. I will ask the user how many of each
# type of person will be present, and report the total amount of pasta needed.

# Algorithm:
# 1) Create variables to store the given values of ounces per person
# 2) Prompt the user for the number of adults, children and students
# 3) Multiple the user input for the adults, children and students respectively
#    by the appropriate values stored in item 1 above.
# 4) Store the result of the product in three separate variables
# 5) Add those three variables from item 4 above to get the total amount of
#    pasta needed


# Create variables to store the given values for ounces per person
oz_per_child = 4
oz_per_adult = 8
oz_per_student = 12

# Prompt the user for the number of adults attending,
# capture the input, convert it to an integer and calculate the amount
# of pasta needed for adults
print("How man adults are attending? ")
num_adults = int(input())
adult_pasta_needed = num_adults * oz_per_adult

# Prompt the user for the number of children attending,
# capture the input, convert it to an integer and calculate the amount
# of pasta needed for children    
print("How many children are attending?")
num_children = int(input())
child_pasta_needed = num_children * oz_per_child

# Prompt the user for the number of students attending,
# capture the input, convert it to an integer and calculate the amount
# of pasta needed for college students
print("How many students are attending?")
num_students = int(input())
student_pasta_needed = num_students * oz_per_student

#Compute the total pasta needed and print the result to the PC screen
total_pasta_needed = adult_pasta_needed + child_pasta_needed + student_pasta_needed
print('You will need a total of ' + str(total_pasta_needed) + ' ounces of pasta. ')
