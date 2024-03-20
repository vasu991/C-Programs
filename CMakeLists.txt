cmake_minimum_required(VERSION 3.23)
project(Practice C)

set(CMAKE_C_STANDARD 99)

add_executable(Main main.c)
add_executable(Table Recursion/table.c)
add_executable(Fibonacci Recursion/fibonacci.c)
add_executable(reverseArray Recursion/reverseArray.c)
add_executable(ArrayImplement Array/ArrayImplement.c)
add_executable (LLImplement "LinkedList/Singly Linked List/ListImplementMenu.c")
add_executable(StackImplementMenu Stack/StackImplementMenu.c)
add_executable(StackImplementLL Stack/StackUsingLL.c)
add_executable(QueueArrayMENU "Queue/Queue Array/QueueImplementArrayMENU.c")
add_executable(QueueLLMENU "Queue/Queue LL/QueueImplementLLMENU.c")
add_executable(CircularQueue "Queue/Circular Queue/CircularQueueImplementMENU.c")
add_executable(ProcessorMENU "Queue/Multi Processor/ProcessorMENU.c")
add_executable(DoublyLL "LinkedList/Doubly Linked List/Doubly Linked List MENU.c")

