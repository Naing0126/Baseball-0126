#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public: 
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후, Exception 이 발생해야 PASS이다.
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}