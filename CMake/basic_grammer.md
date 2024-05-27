#
#[[]]
cmake_minimum_required(VERSION 3.0)

add_executable(app_name, source_file_name)
add_executable(app add.c div.c main.c mult.c sub.c)
add_executable(app add.c;div.c;main.c;mult.c;sub.c)
