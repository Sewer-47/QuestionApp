#ifndef QUIZ2_QUESTIONMANAGER_H
#define QUIZ2_QUESTIONMANAGER_H

#include <queue>
#include "../quiz/QuizType.h"
#include "Question.h"
#include "../storage/Storage.h"

using namespace std;

class QuestionManager {
private:
	Storage storage;
	queue<Question> questions;
	int totalPoints;

public:
	QuestionManager(const Storage &storage);

	void init(QuizType quizType);

	bool hasNext();

	Question nextQuestion();

	int getTotalPoints() const;
};


#endif //QUIZ2_QUESTIONMANAGER_H
