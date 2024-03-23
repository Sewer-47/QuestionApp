//
// Created by Lenovo on 23.03.2024.
//

#include "QuizGame.h"
#include <iostream>
#include <format>

using namespace std;

static string CORRECT_ANSWER = "Gratulacje, zdobywasz 1 punkt";
static string INCORRECT_ANSWER = "Zla odpowiedz, 0 punktow";

static string QUESTIONS_FILE = "C:\\Users\\Lenovo\\CLionProjects\\untitled\\questions.json";

void QuizGame::start() {
	this->questionManager.loadDefaults(QUESTIONS_FILE);

	while (this->questionManager.hasNext()) {

		Question question = this->questionManager.nextQuestion();
		question.print();

		char answer;
		cin >> answer;

		bool correct = answer == question.getAnswer();
		string message = correct ? CORRECT_ANSWER : INCORRECT_ANSWER;

		if (correct) {
			this->points++;
		}
		cout << message << endl;
	}

	//nie wiem czemu, ale nie moge zapisac ponizszego tekstu jako stala u gory
	int questionsAmount = this->questionManager.getQuestions().size();
	cout << format("Ukonczyles test z wynikiem: {}/{}", this->points, questionsAmount);
}
