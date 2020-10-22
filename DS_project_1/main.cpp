//
//  main.cpp
//  DS_project_1
//
//  Created by Brady Liao on 10/12/20.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std ;



// block array data
bool blockArray[19][4][4] =
{
   {{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}}, //T1    0
   {{0,1,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}, //T2    1
   {{1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}}, //T3    2
   {{1,0,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}}, //T4    3
   {{1,1,0,0}, {1,0,0,0}, {1,0,0,0}, {0,0,0,0}}, //L1    4
   {{1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}}, //L2    5
   {{0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}}, //L3    6
   {{1,1,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0}}, //L4    7
   {{1,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}}, //J1    8
   {{1,1,1,0}, {1,0,0,0}, {0,0,0,0}, {0,0,0,0}}, //J2    9
   {{1,0,0,0}, {1,0,0,0}, {1,1,0,0}, {0,0,0,0}}, //J3    10
   {{0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}}, //J4    11
   {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}, //S1    12
   {{0,1,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}}, //S2    13
   {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, //Z1    14
   {{1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}, //Z2    15
   {{1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}}, //I1    16
   {{1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}}, //I2    17
   {{1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, //O     18
} ;


// classs for each block
class block
{
public:
   block(string type, int initialColumn, int LRmove)
   {
      this-> type = type ;
      this-> LRmove = LRmove ;
      blockTypeIndex = assignBlockTypeIndex() ;
      xCoordinate = initialColumn ;
   }
   
   /* get block type (for testing purpose)
   string getType()
   {
      return type ;
   }
   */
   
   // get the remaining left/right move of a block
   int getLRmove()
   {
      return LRmove ;
   }
   
   // use block type to assign block type index in block data array
   int assignBlockTypeIndex()
   {
      if (type == "T1")     {  initialRowOffset = -1 ;  return 0 ; }
      else if (type == "T2"){  initialRowOffset = -2 ;  return 1 ; }
      else if (type == "T3"){  initialRowOffset = -1 ;  return 2 ; }
      else if (type == "T4"){  initialRowOffset = -2 ;  return 3 ; }
      else if (type == "L1"){  initialRowOffset = -2 ;  return 4 ; }
      else if (type == "L2"){  initialRowOffset = -1 ;  return 5 ; }
      else if (type == "L3"){  initialRowOffset = -2 ;  return 6 ; }
      else if (type == "L4"){  initialRowOffset = -1 ;  return 7 ; }
      else if (type == "J1"){  initialRowOffset = -2 ;  return 8 ; }
      else if (type == "J2"){  initialRowOffset = -1 ;  return 9 ; }
      else if (type == "J3"){  initialRowOffset = -2 ;  return 10 ; }
      else if (type == "J4"){  initialRowOffset = -1 ;  return 11 ; }
      else if (type == "S1"){  initialRowOffset = -1 ;  return 12 ; }
      else if (type == "S2"){  initialRowOffset = -2 ;  return 13 ; }
      else if (type == "Z1"){  initialRowOffset = -1 ;  return 14 ; }
      else if (type == "Z2"){  initialRowOffset = -2 ;  return 15 ; }
      else if (type == "I1"){  initialRowOffset = -3 ;  return 16 ; }
      else if (type == "I2"){  initialRowOffset = 0  ;  return 17 ; }
      else if (type == "O"){   initialRowOffset = -1 ;  return 18 ; }
      else return -1 ;
   }
   
   
   // set initial y coordinate (could be extened for features)
   void setYCoordinate(int boardRow)
   {
      //yCoordinate = boardRow + initialRowOffset ;
      yCoordinate = boardRow + 1 ;
   }
   
   
   // move the block to the right one step (with checking before the move and return successful move or not)
   bool moveRight(bool **gameBoard)
   {
      bool ableToMove = true ;
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if (blockArray[blockTypeIndex][i][j] == 1)
            {
               if (gameBoard[yCoordinate+i][xCoordinate+j+1] == 1)
               {
                  ableToMove = false ;
               }
            }
         }
      }
      
      if (ableToMove)
      {
         xCoordinate++ ;
      }
      LRmove-- ;
      return ableToMove ;
   }
   
   
   // move the block to the left one step (with checking before the move and return successful move or not)
   bool moveLeft(bool **gameBoard)
   {
      bool ableToMove = true ;
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if (blockArray[blockTypeIndex][i][j] == 1)
            {
               if (gameBoard[yCoordinate+i][xCoordinate+j-1] == 1)
               {
                  ableToMove = false ;
               }
            }
         }
      }
      
      if (ableToMove)
      {
         xCoordinate-- ;
      }
      LRmove++ ;
      return ableToMove ;
   }
   
   // check if the block is able to move down one step
   bool ableToMoveDown(bool **gameBoard)
   {
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if (blockArray[blockTypeIndex][i][j] == 1)
            {
               if (gameBoard[yCoordinate+i-1][xCoordinate+j] == 1)
               {
                  return false ;
               }
            }
         }
      }
      return true ;
   }
   
   // move the block down one step
   void moveDown(bool **gameBoard)
   {
      yCoordinate-- ;
   }
   
   
   // write the block to the game board
   void writeBlockToBoard(bool **gameBoard, int boardRow, int boardColumn)
   {
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if (blockArray[blockTypeIndex][i][j] == 1)
               gameBoard[yCoordinate+i][xCoordinate+j] = blockArray[blockTypeIndex][i][j] ;
         }
      }
   }
   
   
// private data of a block
private:
   string type ;
   int LRmove, blockTypeIndex, initialRowOffset, xCoordinate, yCoordinate ;
};



// input test case data with file name argv[1]
void fileInput(string fileName, int &row, int &column, queue<block> &blocksQueue)
{
   string currentBlockType ;
   int currentBlockInitialColumn, currentBlockLRmove, inputLine = 0 ;
   
   ifstream input(fileName) ;
   
   input >> row >> column ;
   inputLine++ ;
   
   if (row > 15 || row <= 0 || column > 40 || column <= 0)
      throw invalid_argument("Row or Column of the game board is not valid.") ;
   
   while(input)
   {
      input >> currentBlockType >> currentBlockInitialColumn >> currentBlockLRmove ;
      inputLine++ ;
      if (currentBlockType == "End")
         break ;
      //initialcolumn error handleing
      if (currentBlockInitialColumn > column)
         throw invalid_argument("Invalid block initial column.") ;
      
      block currentInputBlock = block(currentBlockType, currentBlockInitialColumn, currentBlockLRmove) ;
      blocksQueue.push(currentInputBlock) ;
   }
}


// create game board 2D array with boundary (1's) around to contain actual board
bool **createGameBoard(int boardRow, int boardColumn)
{
   bool **gameBoard ;
   gameBoard = new bool*[boardRow+5] ; // 1(index 0) + 4 (4 rows above for dropping blocks)
   
   for (int row = 0; row <= boardRow+4; row++) // 4 (4 rows above for dropping blocks)
   {
      gameBoard[row] = new bool[boardColumn+5] ; // 1(index 0) + 4 (4 columns to check for the most right position)
      gameBoard[row][0] = 1 ; // 1's for left boundary
      for (int column = 1; column <= boardColumn; column++)
         gameBoard[row][column] = 0 ;
      for (int column = boardColumn + 1; column <= boardColumn + 4; column++)
         gameBoard[row][column] = 1 ; // 1's for right boundary
   }
   
   // 1's for ground (bottom boundary)
   for (int column = 0 ; column <= boardColumn+4 ; column++)
   {
      gameBoard[0][column] = 1 ;
   }
   
   return gameBoard ;
}


// remove the rows that are filled
void removeFilledRow(bool **gameBoard, int boardRow, int boardColumn)
{
   int occupied , row = boardRow;
   
   // loop for goint through board rows
   while (row > 0)
   {
      occupied = 0 ;
      for (int column = 1; column <= boardColumn; column++)
      {
         if (gameBoard[row][column] == 1)
            occupied++ ;
      }
      
      // if the row is filled
      if (occupied == boardColumn)
      {
         // move above rows down 1
         for (int i = row; i < boardRow+4; i++)
         {
            for (int j = 1; j <= boardColumn; j++)
               gameBoard[i][j] = gameBoard[i+1][j] ;
         }
         // the toppest row to be 0s
         for (int j = 1; j <= boardColumn; j++)
            gameBoard[boardRow+4][j] = 0 ;
      }
      else
         row-- ;
   }
}


// display the board in the terminal
void displayBoard(bool **gameBoard, int boardRow, int boardColumn)
{
   for (int row = boardRow; row > 0; row--)
   {
      for (int column = 1; column < boardColumn; column++)
      {
         cout << gameBoard[row][column] << " " ;
      }
      cout << gameBoard[row][boardColumn] << endl ;
   }
}


//display board with boundary 1's around in the terminal for testing purpose
void displayBoardWithBoundary(bool **gameBoard, int boardRow, int boardColumn)
{
   for (int row = boardRow+4; row >= 0; row--)
   {
      for (int column = 0; column <= boardColumn+3; column++)
      {
         cout << gameBoard[row][column] << " " ;
      }
      cout << gameBoard[row][boardColumn+4] << endl ;
   }
}


// check over upper bound (over->true, within bound->false)
bool checkOverUpperBound(bool **gameBoard, int boardRow, int boardColumn)
{
   for (int column = 1; column <= boardColumn; column++)
   {
      if (gameBoard[boardRow+1][column] == 1)
      {
         // if block is over upper bound, return true
         cout << "Game ended, you lose. Blocks over boundary." << endl ;
         return true ;
      }
   }
   //if no blocks over upper bound, return false
   return false ;
}


// output the game board to file (for final result)
void outputGameBoardToFile(bool **gameBoard, int boardRow, int boardColumn, string fileName)
{
   ofstream output ;
   output.open(fileName, ios::trunc) ;
   
   if (output.is_open())
   {
      for (int row = boardRow; row > 0; row--)
      {
         for (int column = 1; column < boardColumn; column++)
         {
            output << gameBoard[row][column] << " " ;
         }
         output << gameBoard[row][boardColumn] << endl ;
      }
      
      cout << "The result is output to the file name: " << fileName << endl ;
   }
   else
   {
      cout << "Unable to output file." << endl ;
   }
}


// delete game board 2D array to free the memory
void deleteGameBoard(bool **gameBoard, int boardRow, int boardColumn)
{
   for(int i = 0; i < boardRow+5; i++)
   {
      delete[] gameBoard[i];
   }
   //Free the array of pointers
   delete[] gameBoard;
}




// main function of the code
int main(int argc, const char * argv[]) {
   int boardRow = 0, boardColumn = 0;
   queue<block> blocksQueue ;
   
   if (argc == 2)
   {
      fileInput(argv[1], boardRow, boardColumn, blocksQueue) ;
      /*
       //test input
      cout << boardRow << ' ' << boardColumn << endl ;
      while(!blocksQueue.empty()){
         cout << blocksQueue.front().getType() << " " << blocksQueue.front().getInitialColumn() << " " << blocksQueue.front().getLRmove() << endl ;
         blocksQueue.pop() ;
      }
       */
   }
   else
   {
      return 1 ;
   }
   

   
   // create game board array
   bool **gameBoard = createGameBoard(boardRow, boardColumn) ;
   
   
   // Game Loop
   while (!blocksQueue.empty())
   {
      // set initial y coordinate (could be extended for features)
      blocksQueue.front().setYCoordinate(boardRow) ;
      
      // down move loop (1st time)
      while (blocksQueue.front().ableToMoveDown(gameBoard))
         blocksQueue.front().moveDown(gameBoard) ;
      
      // LRmove
      // right move loop
      while (blocksQueue.front().getLRmove() > 0)
         blocksQueue.front().moveRight(gameBoard) ;
      // left move loop
      while (blocksQueue.front().getLRmove() < 0)
         blocksQueue.front().moveLeft(gameBoard) ;
      
      // down move loop (2nd time)
      while (blocksQueue.front().ableToMoveDown(gameBoard))
         blocksQueue.front().moveDown(gameBoard) ;
      
      // write block to game board
      blocksQueue.front().writeBlockToBoard(gameBoard, boardRow, boardColumn) ;
      
      // remove filled rows
      removeFilledRow(gameBoard, boardRow, boardColumn) ;
      
      //check over upper bound
      if (checkOverUpperBound(gameBoard, boardRow, boardColumn))
      {
         break ;
      }
      
      // pop out the block just processed from queue
      blocksQueue.pop() ;
   }
   
   
   // display board
   displayBoard(gameBoard, boardRow, boardColumn) ;
   /* display board with boundary for testing purpose
   cout << endl ;
   displayBoardWithBoundary(gameBoard, boardRow, boardColumn) ;
   */
   
   // output result to file
   outputGameBoardToFile(gameBoard, boardRow, boardColumn, "109062272_proj1.final") ;
   
   // delete game board array
   deleteGameBoard(gameBoard, boardRow, boardColumn) ;
   
   return 0;
}
