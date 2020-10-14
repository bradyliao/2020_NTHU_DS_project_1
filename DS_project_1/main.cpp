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

class block
{
public:
   block(string type, int initialColumn, int LRmove)
   {
      this-> type = type ;
      this-> initialColumn = initialColumn ;
      this-> LRmove = LRmove ;
      typeIndex = assignTypeIndex() ;
   }
   
   string getType()
   {
      return type ;
   }
   
   int getInitialColumn()
   {
      return initialColumn ;
   }
   
   int getLRmove()
   {
      return LRmove ;
   }
   
   int assignTypeIndex()
   {
      if (type == "T1")     {  return 0 ; }
      else if (type == "T2"){  return 1 ; }
      else if (type == "T3"){  return 2 ; }
      else if (type == "T4"){  return 3 ; }
      else if (type == "L1"){  return 4 ; }
      else if (type == "L2"){  return 5 ; }
      else if (type == "L3"){  return 6 ; }
      else if (type == "L4"){  return 7 ; }
      else if (type == "J1"){  return 8 ; }
      else if (type == "J2"){  return 9 ; }
      else if (type == "J3"){  return 10 ; }
      else if (type == "J4"){  return 11 ; }
      else if (type == "S1"){  return 12 ; }
      else if (type == "S2"){  return 13 ; }
      else if (type == "Z1"){  return 14 ; }
      else if (type == "Z2"){  return 15 ; }
      else if (type == "I1"){  return 16 ; }
      else if (type == "I2"){  return 17 ; }
      else if (type == "O"){   return 18 ; }
      else return -1 ;
   }
   
private:
   string type ;
   int initialColumn, LRmove, typeIndex, initialRowOffset ;
};



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


void removeFilledRow(bool **gameBoard, int boardRow, int boardColumn)
{
   int occupied ;
   
   // loop for goint through board rows
   for (int row = boardRow; row > 0; row--)
   {
      occupied = 0 ;
      for (int column = 1; column <= boardColumn; column++)
      {
         if (gameBoard[row][column] == true)
            occupied++ ;
      }
      
      // if the row is filled
      if (occupied == boardColumn)
      {
         // move above rows down 1
         for (int i = row; i < boardRow; i++)
         {
            for (int j = 1; j <= boardColumn; j++)
               gameBoard[i][j] = gameBoard[i+1][j] ;
         }
         // the toppest row to be 0s
         for (int j = 1; j <= boardColumn; j++)
            gameBoard[boardColumn][j] = 0 ;
      }
   }
}



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



/* display board with boundary 1's around for testing
void displayBoard(bool **gameBoard, int boardRow, int boardColumn)
{
   for (int row = boardRow; row >= 0; row--)
   {
      for (int column = 0; column <= boardColumn+3; column++)
      {
         cout << gameBoard[row][column] << " " ;
      }
      cout << gameBoard[row][boardColumn+4] << endl ;
   }
}
*/
















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
   

   
   // create game board
   /*
   bool gameBoard[boardRow+1][boardColumn+1];
   for (int i = 0; i <= boardRow; i++)
      for (int j = 0; j <= boardColumn; j++)
         gameBoard[i][j] = 0 ;
   */
   
   bool **gameBoard ;
   gameBoard = new bool*[boardRow+1] ;
   
   
   
   
   for (int row = 0; row <= boardRow; row++)
   {
      gameBoard[row] = new bool[boardColumn+5] ; // 1(index 0) + 4 (4 columns to check for the most right position)
      gameBoard[row][0] = 1 ; // 1's for left boundary
      for (int column = 1; column <= boardColumn; column++)
         gameBoard[row][column] = 0 ;
      for (int column = boardColumn + 1; column <= boardColumn + 4; column++)
         gameBoard[row][column] = 1 ;
   }
   
   // 1's for ground
   for (int column = 0 ; column <= boardColumn+4 ; column++)
   {
      gameBoard[0][column] = 1 ;
   }
   
   
   
   // Game Loop
   while (!blocksQueue.empty())
   {
      
      // down move
      
      
      
      // LRmove
      
      
      
      
      
      
      // remove filled rows
      removeFilledRow(gameBoard, boardRow, boardColumn) ;
      
      //check over boundary
      
      // pop out the block just processed
      blocksQueue.pop() ;
   }
   
   
   // display board
   displayBoard(gameBoard, boardRow, boardColumn) ;
   
   
   return 0;
}
