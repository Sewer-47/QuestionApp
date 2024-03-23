//
// Created by Lenovo on 23.03.2024.
//

#ifndef UNTITLED_QUESTION_H
#define UNTITLED_QUESTION_H

#include <string>

using namespace std;

class Question {
private:
	string content;
	char answer;

public:
	Question(const string &content, char answer);

	void print();

	const string &getContent() const;

	char getAnswer() const;
};


#endif //UNTITLED_QUESTION_H
