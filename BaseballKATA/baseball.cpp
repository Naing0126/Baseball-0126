#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, QUESTION_CHAR_CNT, 0 };
		}

		return { false, getStrikeCnt(guessNumber), getBallCnt(guessNumber)};
	}

private:
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != QUESTION_CHAR_CNT) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		bool isDuplicated = (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[0] == guessNumber[2]);
		return isDuplicated;
	}
	int getStrikeCnt(const std::string& guessNumber)
	{
		int strikeCnt = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
			if (guessNumber[i] == question[i]) strikeCnt++;
		}
		return strikeCnt;
	}
	int getBallCnt(const std::string& guessNumber)
	{
		int ballCnt = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
			if ((question.find(guessNumber[i]) != std::string::npos)
				&& (guessNumber[i] != question[i])) {
				ballCnt++;
			}
		}
		return ballCnt;
	}
	string question;
	const int QUESTION_CHAR_CNT = 3;
};