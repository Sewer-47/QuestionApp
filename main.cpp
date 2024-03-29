#include "QuizGame.h"
#include <string>

int main() {
	string path = "C:\\Users\\Lenovo\\CLionProjects\\quiz2\\config.json";
	QuizGame quizGame = QuizGame(Storage(path));
	quizGame.start();
	return 0;
}
