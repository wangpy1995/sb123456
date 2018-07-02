
add_executable(sb main.cpp initialization/A.cpp initialization/A.h initialization/B.cpp initialization/B.h initialization/C.cpp initialization/C.h fsm/TestFSM.c fsm/TestFSM.h)

target_link_libraries(sb libgtest.a libgmock.a libgtest_main.a libgmock_main.a)