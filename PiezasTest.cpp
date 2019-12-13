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
	ASSERT_EQ(board.dropPiece(0), Y);
}

TEST(PiezasTest, dropPieceReturnInval)
{
  Piezas board;
	ASSERT_EQ(board.dropPiece(4), X);
}

TEST(PiezasTest, dropPieceReturnBlank)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), Blank);
}
