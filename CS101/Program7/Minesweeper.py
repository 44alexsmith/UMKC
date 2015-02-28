'''Course: CS 101
 Assignment: Program 7
 Filename: Minesweeper.py
 Name: Alexeo Smith
 Email: asd5b@mail.umkc.edu
 Due : Nov 24th, 2013
 

Problem:
 
Implement the popular Minesweepr game in Python using classes. The outline of a Minesweeper class and methods have been provided and must be completed and
used in the actual program.

Algorithm:
1) Complete the provided Minesweeper class. The implementation must meet the specifications for each provided method 

2) Complete the placeMines() method to randomly place the mines on the grid

3) Complete the getCounts() method to get the counts for each non-mine cell on the grid and
     get the grid ready for play

4) Display the grid in the form of the Player view. In the beginning it will be all H’s, and as the player uncovers the view, update the view to reflect that

5) The display of the player view needs to include row and column numbers to make it easier to play. Rows are 1-5 from top to bottom. Columns are 1-5 from left to right

6) Prompt the player for the position (row, column) on the grid that he/she wants to explore

7) If the player hits a mine, give a message that a mine was hit and the game is over. Display the actual state of the grid (i.e. with everything uncovered, the ‘actual view’ above)

9) If the player hits a number (nonzero), just show the number in the updated player view

10) If the player hits a blank, then show the ripple effect. Specifically, if a player chooses a blank cell on the grid, consider only the row and column to which the cell belongs. Starting from the cell, move horizontally (both left and right) and vertically (both up and down) until you encounter a nonzero number or the edge of the grid, whichever comes first. If a number is encountered, it should be uncovered and then the ripple effect should stop 

11) If the player has uncovered all non-mine cells, the player has won. Print a message congratulating the player and offering to play again

12) Repeat steps 5-11 until the game is over (the player hits a mine, or all cells without mines are uncovered)

13) When the game is over (won or lost), ask the user if they want to play again; if so, continue; otherwise exit

14) Most of the above should be programmed in the main program, calling methods of the Minesweeper class to carry out
    such tasks as uncovering a cell, displaying the board, etc '''





import random


class Minesweeper(object):
  ''' Minesweeper class - Plays Minesweeper.

 It provides methods that carry out most of the needed functionality. It has the following
  data structures:
      Size: Integer. The board is a square Size x Size grid. Default value 5.
      Mines: Integer. The board contains this many bombs, randomly placed at start of game.
          Default value 3. 
      ActualBoard: A list of Size lists, each Size items long. This represents
          the current game state. Possible list contents:
              'M': This cell contains a mine (bomb).
              0-8: An integer, giving the number of mines in this cell's neighborhood.
      PlayerBoard: A list of lists, the same size as ActualBoard, containing the
          board as it will be displayed to the player. Possible contents:
              'H': This cell is hidden and can be turned over.
              0-8: This cell has this many mines in its neighborhood.
			  'X': Used if the player loses, this shows the location of a mine. 
      GameState: Has 3 possible states: "win", "loss", "playing"  (These are strings) '''
  rowColumnValuesForMines_lst = []
  neighborCells1_lst = []
  neighborCells2_lst = []
  neighborCells3_lst = []
  referenceToActualBoard_lst = []
  playerBoard_str = "  "
  actualBoard_str = "  "
  actualBoard_lst = []
  playerBoard_lst = []
  blankNeighborCells_lst = []
  GameStatus = ""
 
  
  
  #The Minesweeper class has the following methods:
  def __init__(self, SideSize = 5, Mines = 3):
        '''Initializer. Sets up boards, places mines (via call to method), counts
           bombs in neighborhod for each bomb (via call to another method).
           In: Size of one side of grid, number of mines to be placed.
           Returns: Nothing
           Interaction with user: None.
           Modifications to data structures: ActualBoard is set up, mines placed, counts
              updated. PlayerBoard set to all H. GameState set to "playing"
           Errors handled: If SideSize <= 2, a value of 2 is used. If SideSize > 15, a value of
              15 is used. If Mines is greater than the number of cells in the grid, every cell
              is given a bomb and any excess is ignored. (It's going to be a pretty short game, though.)
                If Mines < 0, a value of 0 is used. '''
        self.SideSize = SideSize
        self.Mines = Mines
        col_size = 5
        row_size = 5
        
        # initialize the player board
        #playerBoard_lst = []
        for j in range(0, row_size):
          tmp1_lst = [];
          for i in range(0, col_size):
            tmp1_lst.append("H")
          self.playerBoard_lst.append(tmp1_lst)

        col_size = len(self.playerBoard_lst);
        row_size = col_size;
        for i in range (1, col_size + 1):
          self.playerBoard_str = self.playerBoard_str + str(i) + " "
        self.playerBoard_str = self.playerBoard_str + "\n";
        for i in range (0, row_size):
          self.playerBoard_str = self.playerBoard_str + str(i+1)+ " "
          for j in range(0, col_size):
            self.playerBoard_str = self.playerBoard_str + self.playerBoard_lst[i][j] + " "
          self.playerBoard_str = self.playerBoard_str + "\n"   ##Variable playerBoard_str can be passed to the displayboard function

        #Display the playerBoard
        self.displayBoard(self.playerBoard_str)
        self.getInput()
                   
        #initialize the actual board
        #actualBoard_lst = []
        for j in range(0, row_size):
          tmp2_lst = [0]
          for i in range(0, col_size):
            tmp2_lst.append(0);
          self.actualBoard_lst.append(tmp2_lst)

        #Get the row column values for the mines(i.e. 6 numbers)
        rc_mines = self.placeMines()

        #Add the mines to the actual baord 
        self.actualBoard_lst[rc_mines[0]][rc_mines[1]] = "M"
        self.actualBoard_lst[rc_mines[2]][rc_mines[3]] = "M"
        self.actualBoard_lst[rc_mines[4]][rc_mines[5]] = "M"
        
        #Add the counts to the board
        self.getCounts()

        
        # Add the headers and print the grid
        col_size = len(self.actualBoard_lst);
        row_size = col_size;
        for i in range (1, col_size + 1):
          self.actualBoard_str = self.actualBoard_str + str(i) + " "
        self.actualBoard_str = self.actualBoard_str + "\n";
        for i in range (0, row_size):
          self.actualBoard_str = self.actualBoard_str + str(i+1)+ " "
          for j in range(0, col_size):
            self.actualBoard_str = self.actualBoard_str + str(self.actualBoard_lst[i][j]) + " "
          self.actualBoard_str = self.actualBoard_str + "\n"  #Variable actualBoard_str can be passed to the displayboard function
        

  def placeMines(self):
              '''Puts mines onto ActualBoard.
              In: None. 
              Returns: None. 
              Interaction with user: None. 
              Modifications to data structures: Reads self.Size and self.Mines to handle
                setup. Randomly selects location for self.Mines mines to be placed. Calls
                self.getCounts() to finish setting up ActualBoard.  
              Errors handled: None (input was screened in __init__()).  Note that this method 
			  must make sure that each mine is placed in a separate cell; that is, if a mine
			  is about to be placed in a cell that already has a mine in it, another cell 
			  should be picked instead. '''
    
              for i in range(6):
                self.rowColumnValuesForMines_lst.append(random.randint(0,4))
              return (self.rowColumnValuesForMines_lst)
                  
              
  def getCounts(self):
              '''For each cell in grid, counts mines in area, updates ActualBoard.
              In: None. 
              Returns: None. 
              Interaction with user: None. 
              Modifications to data structures: Each cell in ActualBoard that does not have a mine
                is filled with an integer (0 to self.Mines) specifying how many cells in that cell's
                neighborhood are mined. Algorithm:
                  All non-mined cells initialized to 0
                  For each mined cell (r,c):
                    for r-1 to r+1, c-1 to c+1:  Note: need to be sure not running off edge of grid
                       exclude mined cell, otherwise Increment that cell's count by 1
              Errors handled: None. '''

              #Initialized the necessary variables
              mine1_r = self.rowColumnValuesForMines_lst[0]
              mine1_c = self.rowColumnValuesForMines_lst[1]
              mine2_r = self.rowColumnValuesForMines_lst[2]
              mine2_c = self.rowColumnValuesForMines_lst[3]
              mine3_r = self.rowColumnValuesForMines_lst[4]
              mine3_c = self.rowColumnValuesForMines_lst[5]
              neighbors_mines1 = ()
              neighbors_mines2 = ()
              neighbors_mines3 = ()
             

              #Find the neighbors around mine 1
              for row1 in range(int(mine1_r)-1,int(mine1_r)+2):
                  for col1 in range(int(mine1_c)-1,int(mine1_c)+2):
                      if row1 >=0 and row1 < int(mine1_r)+2:
                        if col1 >=0 and col1 < int(mine1_c)+2:
                            neighbors_mines1 = (row1,col1)
                      if neighbors_mines1 != (mine1_r,mine1_c):
                         self.neighborCells1_lst.append(neighbors_mines1)
              #Remove any empty entries
              self.neighborCells1_lst = [x for x in self.neighborCells1_lst if x != ()]
            
              #Update the board with the counts around mine 1
              for i in range(len(self.neighborCells1_lst)):
                  if self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] == 0:
                    self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] = 1
                  elif self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] == 1:
                    self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] = 2
                  elif self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] == 2:
                    self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] = 3
                  elif self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] == 3:
                    self.actualBoard_lst[self.neighborCells1_lst[i][0]][self.neighborCells1_lst[i][1]] = 4

             #Find the neighbors around mine 2
              for row2 in range(int(mine2_r)-1,int(mine2_r)+2):
                  for col2 in range(int(mine2_c)-1,int(mine2_c)+2):
                      if row2 >=0 and row2 < int(mine2_r)+2:
                        if col2 >=0 and col2 < int(mine2_c)+2:
                            neighbors_mines2 = (row2,col2)
                      if neighbors_mines2 != (mine2_r,mine2_c):
                         self.neighborCells2_lst.append(neighbors_mines2)
              #Remove any empty entries
              self.neighborCells2_lst = [x for x in self.neighborCells2_lst if x != ()]

             #Update the board with the counts around mine 2
              for j in range(len(self.neighborCells2_lst)):
                  if self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] == 0:
                    self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] = 1
                  elif self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] == 1:
                    self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] = 2
                  elif self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] == 2:
                    self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] = 3
                  elif self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] == 3:
                    self.actualBoard_lst[self.neighborCells2_lst[j][0]][self.neighborCells2_lst[j][1]] = 4     

              #Find the neighbors around mine 3
              for row3 in range(int(mine3_r)-1,int(mine3_r)+2):
                  for col3 in range(int(mine3_c)-1,int(mine3_c)+2):
                      if row3 >=0 and row3 < int(mine3_r)+2:
                        if col3 >=0 and col3 < int(mine3_c)+2:
                            neighbors_mines3 = (row3,col3)
                      if neighbors_mines3 != (mine3_r,mine3_c):
                         self.neighborCells3_lst.append(neighbors_mines3)
              #Remove any empty entries
              self.neighborCells3_lst = [x for x in self.neighborCells3_lst if x != ()]

              #Update the board with the counts around mine 3
              for k in range(len(self.neighborCells3_lst)):
                  if self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] == 0:
                    self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] = 1
                  elif self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] == 1:
                    self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] = 2
                  elif self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] == 2:
                    self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] = 3
                  elif self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] == 3:
                    self.actualBoard_lst[self.neighborCells3_lst[k][0]][self.neighborCells3_lst[k][1]] = 4
                    

             
  def __findNeighbors__(self, r, c):
           ''' Added late in development. Utility function for updating boards.
            In: row & column of cell to be updated.
            Returns: List of tuples (r,c) that are adjacent to the input cell and not off the grid.
            Interaction with user: None.
            Modifications to data structures: None.
            Errors handled: None. Assumes arguments received are valid coordinates (or are at least integers.)
               If integers but off the grid, then only neighboring cells that would be on the grid are returned
               (e.g. if (-1, -1) were received, (0,0) would be included in returned data. Argument of (-5, -5)
                would return empty list.) '''      
              
  def getInput(self):
              '''Handles input from user. Prompts user to enter row col of cell to check next.
              In: None. 
              Returns: tuple (r, c) of next cell to be uncovered
              Interaction with user: Prompts user for input of row & column. (NOTE: User prompt
                    and input expects 1 to self.Size. Value returned ranges from 0 to self.Size-1 (0-based
                    rather than 1-based indexing).) Gets input from keyboard. Prompts as necessary
                    until valid data is obtained. 
              Modifications to data structures: None. 
              Errors handled:               
                  Input not numeric: Prints error message, tries again.
                  Input is numeric but cell is off grid: Prints error message, tries again.
                  Input is numeric, on grid, already uncovered: Ignored (display board, return to input)
             TODO: Add feature allowing user to enter something showing game should be ended
                early (i.e. a 'Quit' option).'''
              chosen_already = ()
              row_column_lst =[]
              r_str = ""
              c_str = ""
              
              run = True
              while run:
                try:
                  print("Type q to quit")
                  user_input_str = input("Enter row & col to check, separated by space: ")
                  if user_input_str.lower() == "q":
                    run = False
                    break
                  else:
                   user_input_str = user_input_str.split()
                   if int(user_input_str[0])<0 or int(user_input_str[0])>5:
                     print("You must type a valid cell reference")
                   elif int(user_input_str[1])<0 or int(user_input_str[1])>5:
                     print("You must type a valid cell reference") 
                   elif user_input_str[0].isdigit and user_input_str[1].isdigit:
                    row_column_lst.append([user_input_str[0],user_input_str[1]])
                    chosen_already = row_column_lst
                   
                    #Pass the row column values to the updateCell method
                    r_str = row_column_lst[0][0]
                    c_str = row_column_lst[0][1]
                    self.updateCell(r_str,c_str)
                    
                   elif chosen_already == row_column_tpl:
                     continue
                except ValueError:
                    print("Please type in a valid numeric character")
                
                
  def updateCell(self,r,c):
          '''Updates cell on PlayerBoard. If mine is uncovered, sets GameState to "loss".
            In: row & column of cell (assumed to have been checked by getInput() for validity). 
            Returns:  None. 
            Interaction with user: None. 
            Modifications to data structures:
                 If cell in ActualBoard contains a nonzero int, that cell in PlayerBoard is set to that value.
                 If cell is blank (contains 0), calls rippleEffect(r, c). After rippleEffect() returns, if
                   covered cells == number of mines, player has won. (GameState set to "win")                
            Errors handled:  None. '''
##          user_vals = r,c
##          mine_vals = ((self.rowColumnValuesForMines_lst[0],self.rowColumnValuesForMines_lst[1]),\
##                       (self.rowColumnValuesForMines_lst[2],self.rowColumnValuesForMines_lst[3],\
##                       (self.rowColumnValuesForMines_lst[3],self.rowColumnValuesForMines_lst[4]))                                                                                        )
##    
##          print(self.rowColumnValuesForMines_lst)
##          if user_vals in mine_vals:
##            self.dispayBoard(self.actualBoard)
##            print("\n")
##            print(*20 + "\n")
##            print("BOOM!")
##            print(*20 + "\n")
          

  def displayBoard(self, Board):  #Takes in string playerBoard_str or actualBoard_str
    '''Displays board onscreen. Used with
          parameter because we may want to display either ActualBoard
          or PlayerBoard, depending on situation. In:  Board to be
          displayed. Returns:  None. Interaction with user:  Board is
          printed to screen, with row & column labels (starting at 1,
          not 0). Modifications to data structures:  None. Errors
          handled:  None.'''

          #print the board that was passed in
    print(Board)
    

                
  def rippleEffect(self, r, c):
            '''Handles clearing adjacent sections of board from empty cell.
                In:  row & column of cell that was cleared. 
                Returns: None. 
                Interaction with user: None.  
                Modifications to data structures:  Verifies that cell is cleared (0 in ActualBoard). 
				If so, clears adjacent cells as well. The required version clears all cells in the row and 
				column specified; the extra-credit version clears all appropriate neighboring cells.  
                Errors handled: None.''' 
    #Initialized the necessary variables
            cell_r = self.row_column_tpl[0]
            cell_c = self.row_column_tpl[1]


            #Find blank neigher cells the user's choice
            for row in range(int(cell_r)-1,int(cell_r)+2):
              for col in range(int(cell_c)-1,int(cell_c)+2):
               if (cell_r)-1 == 0 and (cell_r)+2 == 0:
                 if (cell_c)-1 == 0 and (cell_c)+2 == 0:
                   if row >=0 and row < int(cell_r)+2:
                      if col >=0 and col < int(cell_c)+2:
                        cell_neighbors = (row,col)
                   if cell_neighbors != (row_r,col_c):
                         self.blankNeighborCells_lst.append(cell_neighbors)
            #Remove any empty entries
            self.blankNeighborCells_lst = [x for x in self.blankNeighborCells_lst if x != ()]
                    
 
        
       
      
