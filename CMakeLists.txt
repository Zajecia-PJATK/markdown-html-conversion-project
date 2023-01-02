cmake_minimum_required(VERSION 3.24)
project(markdown_html_conversion_project)

set(CMAKE_CXX_STANDARD 23)

add_executable(markdown_html_conversion_project main.cpp markdown2html.h html2markdown.h)
