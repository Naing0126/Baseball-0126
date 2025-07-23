#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};


class Baseball {
public:
	Baseball(const string& question)
		: question(question) {
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		return { true, 3, 0 };
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
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
private:
	string question;
};