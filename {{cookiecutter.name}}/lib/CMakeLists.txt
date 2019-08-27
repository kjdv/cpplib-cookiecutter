file(GLOB public_headers include/*.hh include/*.h)
file(GLOB sources *.cc *.cpp *.c *.hh *.h)

add_library({{cookiecutter.name}}
    ${public_headers}
    ${sources}
)

set_target_properties({{cookiecutter.name}} PROPERTIES PUBLIC_HEADER "${public_headers}")
target_include_directories({{cookiecutter.name}}
    PUBLIC
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
      "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>"
)

{% if cookiecutter.dependencies %}
target_link_libraries({{cookiecutter.name}}
    PUBLIC{% for dep in cookiecutter.dependencies.split() %} {{dep|title}}::{{dep}}{% endfor %}
)
{% endif %}
