#ifndef QUIZ2_STORAGE_H
#define QUIZ2_STORAGE_H

#include <string>
#include <map>
#include <queue>
#include "../question/Question.h"
#include "../quiz/QuizType.h"

using namespace std;

class Storage {
private:
	string configPath;
public:
	explicit Storage(string configPath);

	queue<Question> loadQuizQuestions(const QuizType& type);

	string getMessage(string key);

	map<string, QuizType> loadQuizTypes();
};


#endif //QUIZ2_STORAGE_H
