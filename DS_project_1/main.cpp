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
   
private:
   string type ;
   int initialColumn, LRmove ;
   
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
   int boardRow = 0, boardColumn = 1;
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
   
   
   
   
   // create game board
   bool gameBoar[boardRow+1][boardColumn+1] = {true};
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   return 0;
}
