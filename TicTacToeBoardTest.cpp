/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, notInvalidTurn)
{
	TicTacToeBoard Board;
	Piece turn = Board.toggleTurn();
	ASSERT_FALSE(turn == '?');
	ASSERT_FALSE(turn == ' ');
	ASSERT_FALSE(turn == 'X');
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard Board;
	Piece piece = Board.placePiece(1, 1);
	piece = Board.getPiece(1,1);
	ASSERT_EQ(piece, 'X');
}

TEST(TicTacToeBoardTest, getPiece_OutOfBounds)
{
	TicTacToeBoard Board;
	Piece piece = Board.getPiece(-1, 3);
	ASSERT_EQ(piece, '?');
}

TEST(TicTacToeBoardTest, getPiece_blank)
{
	TicTacToeBoard Board;
	Piece piece = Board.getPiece(2,2);
	ASSERT_EQ(piece, ' ');
}

TEST(TicTacToeBoardTest, getPiece_Xpiece)
{
	TicTacToeBoard Board;
	Piece piece = Board.placePiece(2,2);
	piece = Board.getPiece(2,2);
	ASSERT_EQ(piece, 'X');
}

TEST(TicTacToeBoardTest, getPiece_Opiece)
{
	TicTacToeBoard Board;
	Piece piece = Board.placePiece(2,2);
	Board.placePiece(1,1);
	piece = Board.getPiece(1,1);
	ASSERT_EQ(piece, 'O');
}

TEST(TicTacToeBoardTest, placeAPiece)
{
	TicTacToeBoard Board;
	Piece turn = Board.placePiece(1,1);
	ASSERT_EQ(turn, 'X');
}

TEST(TicTacToeBoardTest, placeAPiece_OutOfBounds)
{
	TicTacToeBoard Board;
	Piece piece = Board.placePiece(-1,3);
	ASSERT_EQ(piece, '?');
}

TEST(TicTacToeBoardTest, placeAPiece_FullBoard)
{
	TicTacToeBoard Board;
	for(int i=0; i< BOARDSIZE; i++) {
		for(int j=0; j< BOARDSIZE; j++) {
			Board.placePiece(i,j);
		}
	}
	Piece piece = Board.placePiece(1,1);
	ASSERT_EQ(piece, ' ');
}

TEST(TicTacToeBoardTest, placeAPiece_ExistingPiece)
{
	TicTacToeBoard Board;
	Piece piece = Board.placePiece(1,1);
	piece = Board.placePiece(1,1);
	ASSERT_FALSE(piece == ' ');
}

TEST(TicTacToeBoardTest, getWinner_FullBoard)
{
	TicTacToeBoard Board;
	for(int i=0; i< BOARDSIZE; i++) {
		for(int j=0; j< BOARDSIZE; j++) {
			Board.placePiece(i,j);
		}
	}
	Piece piece = Board.getWinner();
	ASSERT_EQ(piece, ' ');
}

TEST(TicTacToeBoardTest, getWinner_XWins)
{
	TicTacToeBoard Board;
	Board.placePiece(0,0);// X turn
	Board.placePiece(2,0);
	Board.placePiece(0,1);// X turn
	Board.placePiece(2,1);
	Board.placePiece(0,2);// X turn
	Piece piece = Board.getWinner();
	ASSERT_TRUE(piece == 'X');
}

TEST(TicTacToeBoardTest, getWinner_OWins)
{
	TicTacToeBoard Board;
	Board.placePiece(0,0);// X turn
	Board.placePiece(2,0);
	Board.placePiece(0,1);// X turn
	Board.placePiece(2,1);
	Board.placePiece(1,1);// X turn
	Board.placePiece(2,2);
	Piece piece = Board.getWinner();
	ASSERT_TRUE(piece == 'O');
}

TEST(TicTacToeBoardTest, getWinner_gameNotOver)
{
	TicTacToeBoard Board;
	Piece piece = Board.getWinner();
	ASSERT_EQ(piece, '?');
}