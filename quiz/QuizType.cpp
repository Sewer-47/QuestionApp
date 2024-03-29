#include "QuizType.h"

QuizType::QuizType(const string &name, const string &displayName) : id(name), displayName(displayName) {}

const string &QuizType::getId() const {
	return this->id;
}

const string &QuizType::getDisplayName() const {
	return this->displayName;
}

QuizType::QuizType() {}
