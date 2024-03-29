#ifndef QUIZ2_QUESTION_H
#define QUIZ2_QUESTION_H

#include <string>

using namespace std;

class Question {
private:
	string content;
	char answer;
	int points;
public:
	Question(const string &content, char answer, int points);

	const string &getContent() const;

	char getAnswer() const;

	int getPoints() const;
};


#endif //QUIZ2_QUESTION_H
