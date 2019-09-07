include("${CMAKE_CURRENT_LIST_DIR}/{{cookiecutter.name|title}}Targets.cmake")

{% for dep in cookiecutter.dependencies.split() %}
find_package({{dep|title}} CONFIG REQUIRED)
{% endfor %}
