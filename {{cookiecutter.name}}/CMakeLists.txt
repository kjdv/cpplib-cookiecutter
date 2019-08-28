cmake_minimum_required(VERSION 3.10)

project({{cookiecutter.name}})
set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)
find_package(GTest MODULE REQUIRED)
find_library(GMOCK_LIBRARIES gmock)
enable_testing()

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
