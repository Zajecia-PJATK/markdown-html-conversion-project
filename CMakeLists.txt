cmake_minimum_required(VERSION 3.24)
project(markdown_html_conversion_project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/natalia/Qt/6.4.2/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(markdown_html_conversion_project main.cpp markdown2html.h html2markdown.h regex_replace.h)
target_link_libraries(markdown_html_conversion_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

add_subdirectory(test)
