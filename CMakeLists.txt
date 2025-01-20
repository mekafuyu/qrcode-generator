cmake_minimum_required(VERSION 3.22)
project(QRCodeGen)

file(GLOB src_files "src/*.cpp")

add_executable(${PROJECT_NAME} ${src_files})

target_include_directories(${PROJECT_NAME}
    PUBLIC include
)
