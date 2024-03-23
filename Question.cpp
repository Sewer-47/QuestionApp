//
// Created by Lenovo on 23.03.2024.
//

#include "Question.h"
#include <iostream>

Question::Question(const string &content, char answer) {
	this->content = content;
	this->answer = answer;
}

void Question::print() {
	cout << this->getContent() << endl;
}

const string &Question::getContent() const {
	return this->content;
}

char Question::getAnswer() const {
	return this->answer;
}