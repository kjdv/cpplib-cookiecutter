file(GLOB sources *.c *.cc *.cpp *.h *.hh)

add_executable({{cookiecutter.name}}_test ${sources})
target_link_libraries({{cookiecutter.name}}_test {{cookiecutter.name}} ${GMOCK_LIBRARIES} GTest::GTest GTest::Main)

gtest_discover_tests({{cookiecutter.name}}_test)
