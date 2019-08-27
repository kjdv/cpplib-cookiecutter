file(GLOB sources *.c *.cc *.cpp *.h *.hh)
add_executable({{cookiecutter.name}}_test ${sources})
target_link_libraries({{cookiecutter.name}}_test {{cookiecutter.name}} GTest::GTest GTest::Main)

add_test({{cookiecutter.name}}_test {{cookiecutter.name}}_test)
