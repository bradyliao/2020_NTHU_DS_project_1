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


class block
{
public:
   block(string type, int initialColumn, int LRmove)
   {
      this-> type = type ;
      this-> initialColumn = initialColumn ;
      this-> LRmove = LRmove ;
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
   
   void assignBlockArray()
   {
      if (type == "T1")
      {
         bool miniBlock[4][4] = {{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "T2")
      {
         bool miniBlock[4][4] = {{0,1,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "T3")
      {
         bool miniBlock[4][4] = {{1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "T4")
      {
         bool miniBlock[4][4] = {{1,0,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "L1")
      {
         bool miniBlock[4][4] = {{1,1,0,0}, {1,0,0,0}, {1,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "L2")
      {
         bool miniBlock[4][4] = {{1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "L3")
      {
         bool miniBlock[4][4] = {{0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "L4")
      {
         bool miniBlock[4][4] = {{1,1,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0}} ;
      }
      
      if (type == "J1")
      {
         <#statements#>
      }
      
      if (type == "J2")
      {
         <#statements#>
      }
      
      if (type == "J3")
      {
         <#statements#>
      }
      
      if (type == "J4")
      {
         <#statements#>
      }
      
      if (type == "S1")
      {
         <#statements#>
      }
      
      if (type == "S2")
      {
         <#statements#>
      }
      
      if (type == "Z1")
      {
         <#statements#>
      }
      
      if (type == "Z2")
      {
         <#statements#>
      }
      
      if (type == "I1")
      {
         <#statements#>
      }
      
      if (type == "I2")
      {
         <#statements#>
      }
      
      if (type == "O")
      {
         <#statements#>
      }
      
   }
   
private:
   string type ;
   int initialColumn, LRmove ;
   bool miniBlock[4][4] ;
};



void fileInput(string fileName, int &row, int &column, queue<block> &blocksQueue){
   string currentBlockType ;
   int currentBlockInitialColumn, currentBlockLRmove ;
   
   ifstream input(fileName) ;
   
   input >> row >> column ;
   
   while(input){
      input >> currentBlockType >> currentBlockInitialColumn >> currentBlockLRmove ;
      if (currentBlockType == "End")
         break ;
      block currentInputBlock = block(currentBlockType, currentBlockInitialColumn, currentBlockLRmove) ;
      blocksQueue.push(currentInputBlock) ;
   }
}





























int main(int argc, const char * argv[]) {
   int boardRow = 0, boardColumn = 0;
   queue<block> blocksQueue ;
   
   if (argc == 2) {
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
   bool gameBoard[boardRow+1][boardColumn+1];
   
   for (int i = 0; i <= boardRow; i++)
      for (int j = 0; j <= boardColumn; j++)
         gameBoard[i][j] = false ;
      
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   return 0;
}
