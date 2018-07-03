include_directories(${PROJECT_SOURCE_DIR}/main/io ${PROJECT_SOURCE_DIR}/main)

#add_executable(sb main.c io/test_read.h initialization/A.cpp initialization/A.h initialization/B.cpp initialization/B.h initialization/C.cpp initialization/C.h fsm/TestFSM.c fsm/TestFSM.h io/test_read.h)

add_executable(sb main.c io/test_read.h io/test_read.h)

target_link_libraries(sb libgtest.a libgmock.a libgtest_main.a libgmock_main.a)