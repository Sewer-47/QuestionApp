#include "QuestionManager.h"

QuestionManager::QuestionManager(const Storage &storage) : storage(storage) {
}

void QuestionManager::init(QuizType quizType) {
	this->questions = this->storage.loadQuizQuestions(quizType);
	this->totalPoints = 0;
}

bool QuestionManager::hasNext() {
	return !this->questions.empty();
}

Question QuestionManager::nextQuestion() {
	Question question = this->questions.front();

	//poprawniej chyba byloby w metodzie init iterowac po pytaniach
	this->totalPoints += question.getPoints();

	this->questions.pop();
	return question;
}

int QuestionManager::getTotalPoints() const {
	return this->totalPoints;
}
