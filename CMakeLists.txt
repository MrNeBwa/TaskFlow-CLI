cmake_minimum_required(VERSION 3.14)
project(TaskFlowCLI VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# Зависимость для парсинга аргументов командной строки
FetchContent_Declare(
  cli11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(cli11)

# Зависимость для логирования и форматирования текста
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.1
)
FetchContent_MakeAvailable(fmt)

# Зависимость для сериализации/экспорта в JSON
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

# Основной исполняемый файл
add_executable(taskflow 
    src/main.cpp
)

target_include_directories(taskflow PRIVATE include)

target_link_libraries(taskflow PRIVATE 
    CLI11::CLI11 
    fmt::fmt 
    nlohmann_json::nlohmann_json
)
