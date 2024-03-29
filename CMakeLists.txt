cmake_minimum_required(VERSION 3.27)
project(quiz2)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG master
)
FetchContent_MakeAvailable(json)

add_executable(quiz2 main.cpp
        question/Question.cpp
        question/Question.h
        quiz/Quiz.cpp
        quiz/Quiz.h
        quiz/QuizType.cpp
        quiz/QuizType.h
        question/QuestionManager.cpp
        question/QuestionManager.h
        QuizGame.cpp
        QuizGame.h
        storage/Storage.cpp
        storage/Storage.h)

target_link_libraries(quiz2 PRIVATE nlohmann_json::nlohmann_json)
