#ifndef QUIZ2_QUIZ_H
#define QUIZ2_QUIZ_H


#include "../question/QuestionManager.h"
#include "QuizType.h"
#include "../QuizGame.h"

class Quiz {
private:
	QuizGame quizGame;
	QuizType type;
	QuestionManager questionManager;
	int score;
public:
	Quiz(const QuizGame &quizGame, const QuizType &type, const QuestionManager &questionManager);

	void start();

	const QuizGame getQuizGame() const;
};


#endif //QUIZ2_QUIZ_H
