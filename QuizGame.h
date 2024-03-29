#ifndef QUIZ2_QUIZGAME_H
#define QUIZ2_QUIZGAME_H

#include "storage/Storage.h"

class QuizGame {
private:
	Storage storage;
public:
	QuizGame(Storage storage);

	void start();

	const Storage &getStorage() const;
};


#endif //QUIZ2_QUIZGAME_H
