#include "Question.h"

Question::Question(const string &content, char answer, int points) : content(content), answer(answer), points(points) {

}

const string &Question::getContent() const {
	return this->content;
}

char Question::getAnswer() const {
	return this->answer;
}

int Question::getPoints() const {
	return this->points;
}
