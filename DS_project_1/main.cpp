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
      if (type == "T1"){
         miniBlock[0][1] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[1][2] = 1 ;
      }
      else if (type == "T2"){
         miniBlock[0][1] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][1] = 1 ;
      }
      else if (type == "T3"){
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[0][2] = 1 ;   miniBlock[1][1] = 1 ;
      }
      else if (type == "T4"){
         miniBlock[0][0] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][0] = 1 ;
      }
      
      else if (type == "L1")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[2][0] = 1 ;
      }
      
      else if (type == "L2")
      {
         miniBlock[0][0] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[1][2] = 1 ;
      }
      
      else if (type == "L3")
      {
         miniBlock[0][1] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][0] = 1 ;   miniBlock[2][1] = 1 ;
      }
      
      else if (type == "L4")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[0][2] = 1 ;   miniBlock[1][2] = 1 ;
      }
      
      else if (type == "J1")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][1] = 1 ;
      }
      
      else if (type == "J2")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[0][2] = 1 ;   miniBlock[1][0] = 1 ;
      }
      
      else if (type == "J3")
      {
         miniBlock[0][0] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[2][0] = 1 ;   miniBlock[2][1] = 1 ;
      }
      
      else if (type == "J4")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[0][2] = 1 ;   miniBlock[1][2] = 1 ;
      }
      
      else if (type == "S1")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[1][2] = 1 ;
      }
      
      else if (type == "S2")
      {
         miniBlock[0][1] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][0] = 1 ;
      }
      
      else if (type == "Z1")
      {
         miniBlock[0][1] = 1 ;   miniBlock[1][2] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;
      }
      
      else if (type == "Z2")
      {
         miniBlock[0][0] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;   miniBlock[2][1] = 1 ;
      }
      
      else if (type == "I1")
      {
         miniBlock[0][0] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[2][0] = 1 ;   miniBlock[3][0] = 1 ;
      }
      
      else if (type == "I2")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[0][2] = 1 ;   miniBlock[0][3] = 1 ;
      }
      
      else if (type == "O")
      {
         miniBlock[0][0] = 1 ;   miniBlock[0][1] = 1 ;   miniBlock[1][0] = 1 ;   miniBlock[1][1] = 1 ;
      }
      
   }
   
private:
   string type ;
   int initialColumn, LRmove ;
   bool miniBlock[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}} ;
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
