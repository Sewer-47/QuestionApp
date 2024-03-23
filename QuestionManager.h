//
// Created by Lenovo on 23.03.2024.
//

#ifndef UNTITLED_QUESTIONMANAGER_H
#define UNTITLED_QUESTIONMANAGER_H

#include <vector>
#include "Question.h"

using namespace std;

class QuestionManager {
private:
	vector<Question> questions;
	int questionIndex;

public:
	void loadDefaults(const string& questionsFile);
	bool hasNext();
	Question nextQuestion();//moze zmienic to na optional<Question>
	const vector<Question> &getQuestions() const;
};


#endif //UNTITLED_QUESTIONMANAGER_H
