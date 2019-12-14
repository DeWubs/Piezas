/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
/*Tests for drop peice*/
TEST(PiezasTest, dropPieceReturnX)
{
  Piezas board;
	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceReturnY)
{
  Piezas board;
  board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), O);
}

TEST(PiezasTest, dropPieceReturnInval)
{
  Piezas board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceReturnBlank)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), Blank);
}

/*Tests for pieceAt*/
TEST(PiezasTest, noPiece)
{
  Piezas board;
	ASSERT_EQ(board.pieceAt(0,2), Blank);
}

TEST(PiezasTest, onePiece)
{
  Piezas board;
  board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(0,2), X);
}

TEST(PiezasTest, outOfBoundsrow)
{
  Piezas board;
	ASSERT_EQ(board.pieceAt(4,0), Invalid);
}

TEST(PiezasTest, outOfBoundsCol)
{
  Piezas board;
	ASSERT_EQ(board.pieceAt(0,4), Invalid);
}
