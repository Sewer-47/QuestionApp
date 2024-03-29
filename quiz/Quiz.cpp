#include "Quiz.h"
#include <iostream>
#include <algorithm>
#include <format>

using namespace std;

char readInputChar(Quiz);

Quiz::Quiz(const QuizGame &quizGame, const QuizType &type, const QuestionManager &questionManager) :
quizGame(quizGame),type(type),questionManager(questionManager) {
	this->score = 0;
}

void Quiz::start() {
	Storage storage = this->quizGame.getStorage();
	this->questionManager.init(this->type);

	while (this->questionManager.hasNext()) {
		Question question = this->questionManager.nextQuestion();
		string content = vformat(question.getContent(), make_format_args(question.getPoints()));
		cout << content << endl;

		char answer = readInputChar(*this);

		bool correct = answer == question.getAnswer();
		string message = correct ? storage.getMessage("correctAnswer") : storage.getMessage("incorrectAnswer");

		if (correct) this->score += question.getPoints();

		system("cls");
		cout << message << endl;
	}

	int questionsAmount = this->questionManager.getTotalPoints();
	string rawMessage = storage.getMessage("outro");
	string message = vformat(rawMessage, make_format_args(this->score, questionsAmount));
	cout << message << endl;
}

const QuizGame Quiz::getQuizGame() const {
	return this->quizGame;
}


char readInputChar(Quiz quiz) {
	string input;
	while (true) {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input.length() > 1) {
			Storage storage = quiz.getQuizGame().getStorage();
			cout << storage.getMessage("toManyChars") << endl;
			continue;
		}

		if (!isalpha(input[0])) {
			Storage storage = quiz.getQuizGame().getStorage();
			cout << storage.getMessage("notAllowedChar") << endl;
			continue;
		}

		return input[0];
	}
}