#include "QuizGame.h"
#include "quiz/Quiz.h"
#include <iostream>

using namespace std;

const char CONTINUE_CHARS[] = {'t', 'T', 'y', 'Y'};

QuizGame::QuizGame(Storage storage) : storage(storage) {}


void QuizGame::start() {
	string message = this->storage.getMessage("intro");
	cout << message << endl;
	map<string, QuizType> types = this->storage.loadQuizTypes();

	for (auto& entry : types) {
		QuizType type = entry.second;
		cout << type.getId() << " - " << type.getDisplayName() << endl;
	}

	string quizName;
	cin >> quizName;

	while (!types.contains(quizName)) {
		message = this->storage.getMessage("quizNotFound");
		cout << message << endl;
		cin >> quizName;
	}
	system("cls");

	QuestionManager questionManager = QuestionManager(this->getStorage());
	Quiz quiz(*this, types[quizName], questionManager);
	quiz.start();

	message = this->storage.getMessage("nextQuizAsk");
	cout << message;

	string nextGameString;
	cin >> nextGameString;
	for (const auto &item: CONTINUE_CHARS) {
		if (nextGameString[0] == item) {
			system("cls");
			start();
		}
	}
}

const Storage &QuizGame::getStorage() const {
	return this->storage;
}