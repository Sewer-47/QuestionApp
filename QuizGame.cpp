//
// Created by Lenovo on 23.03.2024.
//

#include "QuizGame.h"
#include <iostream>
#include <format>
#include <algorithm>

using namespace std;

char readInputChar();

static string CORRECT_ANSWER = "Gratulacje, zdobywasz 1 punkt";
static string INCORRECT_ANSWER = "Zla odpowiedz, 0 punktow";

static string NOT_ALLOWED_CHAR = "Uzyto niedozwolonego znaku, dozwolone [a-z]";
static string TO_MANY_CHARS = "Odpowiedz moze zawierac tylko jeden znak";

static string QUESTIONS_FILE = "C:\\Users\\Lenovo\\CLionProjects\\untitled\\questions.json";

void QuizGame::start() {
	this->questionManager.loadDefaults(QUESTIONS_FILE);

	while (this->questionManager.hasNext()) {

		Question question = this->questionManager.nextQuestion();
		question.print();

		char answer = readInputChar();

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


char readInputChar() {
	string input;
	while (true) {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input.length() > 1) {
			cout << TO_MANY_CHARS << endl;
			continue;
		}

		if(!isalpha(input[0])) {
			cout << NOT_ALLOWED_CHAR << endl;
			continue;
		}

		return input[0];
	}
}