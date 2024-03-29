#include "Storage.h"
#include <fstream>
#include <utility>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

const string NEW_LINE = "\n";

Storage::Storage(string configPath) : configPath(std::move(configPath)) {

}

map<string, QuizType> Storage::loadQuizTypes() {
	map<string, QuizType> quizTypeMap;

	ifstream inputStream(this->configPath);
	json data = json::parse(inputStream);
	auto jsonQuizzesMap = data["quizzes"];
	for (auto jsonQuiz : jsonQuizzesMap) {

		QuizType type = QuizType(jsonQuiz["id"], jsonQuiz["displayName"]);
		quizTypeMap[type.getId()] = type;
	}

	return quizTypeMap;
}

queue<Question> Storage::loadQuizQuestions(const QuizType& type) {
	queue<Question> questionQueue;

	ifstream inputStream(this->configPath);
	json data = json::parse(inputStream);
	auto jsonQuizzesMap = data["quizzes"];
	auto jsonQuiz = jsonQuizzesMap[type.getId()];

	string displayName = jsonQuiz["displayName"];
	auto jsonQuestionArray = jsonQuiz["questions"];
	for (auto jsonQuestion : jsonQuestionArray) {
		int points = jsonQuestion["points"];
		string answer = jsonQuestion["answerChar"];
		char answerChar = answer[0];
		auto descriptionArray = jsonQuestion["description"];
		string description;
		for (string line : descriptionArray) {
			description += line + NEW_LINE;
		}
		Question question = Question(description, answerChar, points);
		questionQueue.push(question);
	}
	return questionQueue;
}

string Storage::getMessage(string key) {
	ifstream inputStream(this->configPath);
	json data = json::parse(inputStream);
	auto jsonMessagesMap = data["messages"];
	auto result = jsonMessagesMap[std::move(key)];
	inputStream.close();

	if (typeid(result) == typeid(string)) {
		return result;
	}

	string message;
	for (string line : result) {
		message += line + NEW_LINE;
	}
	return message;
}
