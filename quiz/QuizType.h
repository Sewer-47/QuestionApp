#ifndef QUIZ2_QUIZTYPE_H
#define QUIZ2_QUIZTYPE_H

#include <string>

using namespace std;

class QuizType {
private:
	string id;
	string displayName;
public:
	QuizType(const string &name, const string &displayName);

	QuizType();

	const string &getId() const;

	const string &getDisplayName() const;
};


#endif //QUIZ2_QUIZTYPE_H
