//
// Created by Lenovo on 23.03.2024.
//

#ifndef UNTITLED_QUIZGAME_H
#define UNTITLED_QUIZGAME_H

#include "QuestionManager.h"

class QuizGame {
private:
	QuestionManager questionManager;
	int points;
public:
	void start();
};


#endif //UNTITLED_QUIZGAME_H
