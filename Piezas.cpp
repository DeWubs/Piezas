#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  turn = X;
  board.resize(BOARD_ROWS);
  for(int g = 0; g < 3; g++){
    board[g].resize(BOARD_COLS);
  }
  for(int i = 0; i < BOARD_ROWS; i++){
    for(int j= 0; j < BOARD_COLS; j++){
      board[i][j] = Blank;
    }
  }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for(int i = 0; i < BOARD_ROWS; i++){
    for(int j= 0; j < BOARD_COLS; j++){
      board[i][j] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  if(column > (BOARD_COLS - 1) ){
      if(turn == X){
        turn = O;
        return Invalid;
      }
    else{
        turn = X;
        return Invalid;
      }
    }
    if(board[0][column] != ' '){
      return Blank;
    }
    for(int i = 2; i >= 0; i--){
      if(board[i][column] == ' '){
        if(turn == X){
          board[i][column] = X;
          turn = O;
          return X;
        }
        else{
          board[i][column] = O;
          turn = X;
          return O;
        }
      }
    }
    return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row > (BOARD_ROWS - 1) || column > (BOARD_COLS - 1) ){
    return Invalid;
  }
  if(board[row][column] == ' '){
    return Blank;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    if(board[0][0] == ' ' || board[0][1] == ' ' || board[0][2] == ' ' || board[0][3] == ' '){
      return Invalid;
    }
    int tally = 0;
    int xScore = 0;
    int oScore = 0;
    /*checking horizontally for X*/
    for (int i = 0; i < (BOARD_ROWS - 1); i++){
      for (int j = 0; j <(BOARD_COLS - 1); j++){
        if (board[i][j] == board[i][j + 1] && board[i][j] == X){
            tally++;
        }
        else{
            if (xScore < tally){
                xScore = tally;
            }
            tally = 0;
        }
    }
  }
  /*checking vertically for X*/
  for (int i = 0; i < (BOARD_ROWS - 1); i++){
    for (int j = 0; j < (BOARD_COLS - 1); j++){
      if (board[i][j] == board[i + 1][j] && board[i][j] == X){
          tally++;
      }
      else{
          if (xScore < tally){
              xScore = tally;
          }
          tally = 0;
      }
  }
}

/*checking horizontally for O*/
  for (int i = 0; i < (BOARD_ROWS - 1); i++){
    for (int j = 0; j <(BOARD_COLS - 1); j++){
      if (board[i][j] == board[i][j + 1] && board[i][j] == O){
          tally++;
      }
      else{
          if (oScore < tally){
              oScore = tally;
          }
          tally = 0;
      }
    }
  }
  /*checking vertically for O*/
  for (int i = 0; i < (BOARD_ROWS - 1); i++){
    for (int j = 0; j <(BOARD_COLS - 1); j++){
      if (board[i][j] == board[i + 1][j] && board[i][j] == O){
          tally++;
        }
      else{
        if (oScore < tally){
            oScore = tally;
        }
        tally = 0;
      }
    }
  }

  if(xScore > oScore){
    return X;
  }
  else if(oScore > xScore){
    return O;
  }
  return Blank;

}
