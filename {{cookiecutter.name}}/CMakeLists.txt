cmake_minimum_required(VERSION 3.13)

project({{cookiecutter.name}})
set(CMAKE_CXX_STANDARD 17)

enable_testing()
find_package(GTest MODULE REQUIRED)
{% if cookiecutter.dependencies %}
# dependencies:
{% for dep in cookiecutter.dependencies.split() %}
find_package({{dep|title}} CONFIG REQUIRED)
{% endfor %}
{% endif %}
add_subdirectory(lib)
add_subdirectory(test)

# install rules
install(TARGETS {{cookiecutter.name}}
        EXPORT {{cookiecutter.name|title}}Config
        ARCHIVE DESTINATION lib COMPONENT lib
        PUBLIC_HEADER DESTINATION include/{{cookiecutter.name}} COMPONENT dev
)

export(TARGETS {{cookiecutter.name}} NAMESPACE {{cookiecutter.name|title}}:: FILE ${CMAKE_CURRENT_BINARY_DIR}/{{cookiecutter.name|title}}Config.cmake)
install(EXPORT {{cookiecutter.name|title}}Config DESTINATION share/{{cookiecutter.name}} NAMESPACE {{cookiecutter.name|title}}::)
