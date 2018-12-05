#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X) {
    turn = O;
  }
  else if(turn == O) {
    turn = X;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  
  // out of bounds
  if(row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    return Invalid;
  }
  
  // count pieces on board, check if full
  int count = 0;
  for(int i=0; i< BOARDSIZE; i++) {
    for(int j=0; j< BOARDSIZE; j++) {
      if(board[i][j] == X || board[i][j] == O) {
        count ++;
      }
    }
  } 
  // board is filled
  if(count == BOARDSIZE*BOARDSIZE) {
    return Blank;
  }
  
  // there is a piece already at this location
  Piece existingPiece = getPiece(row,column);
  if(existingPiece != Blank) {
    return existingPiece;
  }
  
  // place this piece, toggle turn, return what was placed
  board[row][column] = turn;
  Piece placedTurn = turn;
  turn = toggleTurn();
  return placedTurn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    return Invalid;
  }
  else {
  Piece piece = board[row][column];
  return piece;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  // count pieces on board
  int count = 0;
  for(int i=0; i< BOARDSIZE; i++) {
    for(int j=0; j< BOARDSIZE; j++) {
      if(board[i][j] == X || board[i][j] == O) {
        count ++;
      }
    }
  } 
  // board is filled
  if(count == BOARDSIZE*BOARDSIZE) {
    return Blank;
  }
  
  // check for winner, return winner piece
  for(int i=0; i< BOARDSIZE; i++) {
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != Blank) {
      return board[i][0];
    }
  }
  for(int j=0; j< BOARDSIZE; j++) {
    if(board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != Blank) {
      return board[0][j];
    }
  }
  if(board[1][1] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != Blank) {
    return board[1][1];
  }
  if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != Blank) {
    return board[0][2];
  }
      
  // game not over;
  return Invalid;
}
