cmake_minimum_required(VERSION 3.27)
project(untitled)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG master
)
FetchContent_MakeAvailable(json)

add_executable(untitled main.cpp
        Question.cpp
        Question.h
        QuestionManager.cpp
        QuestionManager.h
        QuizGame.cpp
        QuizGame.h)

target_link_libraries(untitled PRIVATE nlohmann_json::nlohmann_json)
