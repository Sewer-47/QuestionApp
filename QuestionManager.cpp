//
// Created by Lenovo on 23.03.2024.
//

#include "QuestionManager.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;

void QuestionManager::loadDefaults(const string& questionsFile) {
	ifstream f(questionsFile);
	json data = json::parse(f);
	auto jsonQuestionArray = data["questions"];
	for (auto jsonQuestion : jsonQuestionArray) {
		auto descriptionArray = jsonQuestion["description"];
		string description;
		for (string line : descriptionArray) {
			description += line + "\n";
		}
		char answerChar = ((string) jsonQuestion["answerChar"])[0];

		Question question = Question(description, answerChar);
		this->questions.push_back(question);
	}
}

bool QuestionManager::hasNext() {
	return this->questionIndex < this->questions.size();
}

Question QuestionManager::nextQuestion() {
	Question question = this->questions[this->questionIndex];
	this->questionIndex++;
	return question;
}


const vector<Question> &QuestionManager::getQuestions() const {
	return this->questions;
}