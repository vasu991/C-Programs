cmake_minimum_required(VERSION 3.23)
project(Practice C)

set(CMAKE_C_STANDARD 99)

add_executable(Main main.c)
add_executable(Table Recursion/table.c)
add_executable(Fibonacci Recursion/fibonacci.c)
add_executable(reverseArray Recursion/reverseArray.c)
add_executable(ArrayImplement Array/ArrayImplement.c)
add_executable (LLImplement LinkedList/ListImplementMenu.c)
add_executable(StackImplementMenu Stack/StackImplementMenu.c)
add_executable(StackImplementLL Stack/StackUsingLL.c)
add_executable(QueueImplementArrayMENU Queue/QueueImplementArrayMENU.c)
add_executable(QueueImplementLLMENU Queue/QueueImplementLLMENU.c)

