//
// Created by natalia on 17.01.23.
//

#include <string>
#include <regex>

using namespace std;

#include "../markdown2html.h"
#include "catch.hpp"

TEST_CASE("conversion md h1", "[markdown2html]") {
    REQUIRE(markdown2html("# things") == "<h1>things</h1>");
}

TEST_CASE("conversion md h2", "[markdown2html]") {
    REQUIRE(markdown2html("## things") == "<h2>things</h2>");
}

TEST_CASE("conversion md h3", "[markdown2html]") {
    REQUIRE(markdown2html("### things") == "<h3>things</h3>");
}

TEST_CASE("conversion md h4", "[markdown2html]") {
    REQUIRE(markdown2html("#### things") == "<h4>things</h4>");
}

TEST_CASE("conversion md h5", "[markdown2html]") {
    REQUIRE(markdown2html("##### things") == "<h5>things</h5>");
}

TEST_CASE("conversion md h6", "[markdown2html]") {
    REQUIRE(markdown2html("###### things") == "<h6>things</h6>");
}

TEST_CASE("conversion md em", "[markdown2html]") {
    REQUIRE(markdown2html("*things*") == "<em>things</em>");
}

TEST_CASE("conversion md del", "[markdown2html]") {
    REQUIRE(markdown2html("~~things~~") == "<del>things</del>");
}

TEST_CASE("conversion md strong", "[markdown2html]") {
    REQUIRE(markdown2html("**things**") == "<strong>things</strong>");
}

TEST_CASE("conversion md pre code", "[markdown2html]") {
    REQUIRE(markdown2html("```\nthings\n```") == "<pre><code>things</code></pre>");
}

TEST_CASE("conversion md code", "[markdown2html]") {
    REQUIRE(markdown2html("`things`") == "<code>things</code>");
}

TEST_CASE("conversion md a title", "[markdown2html]") {
    REQUIRE(markdown2html("[have a title](https://markdowntohtml.com \"Awesome\")") == "<a href=\"https://markdowntohtml.com\" title=\"Awesome\">have a title</a>");
}

TEST_CASE("conversion md a", "[markdown2html]") {
    REQUIRE(markdown2html("[inline](https://markdowntohtml.com)") == "<a href=\"https://markdowntohtml.com\">inline</a>");
}

TEST_CASE("conversion md hr", "[markdown2html]") {
    REQUIRE(markdown2html("---\n") == "<hr>\n");
}

TEST_CASE("conversion md img title", "[markdown2html]") {
    REQUIRE(markdown2html("![image](MyLovelyImage.png \"some title\")") == "<img src=\"image\" alt=\"MyLovelyImage.png\" title=\"some title\">");
}

TEST_CASE("conversion md img", "[markdown2html]") {
    REQUIRE(markdown2html("[image](https://placebear.com/300/300)") == "<a href=\"https://placebear.com/300/300\">image</a>");
}


TEST_CASE("conversion md list ul", "[markdown2html]") {
    REQUIRE(markdown2html("- things") == "\t<li>things</li>");
}

TEST_CASE("conversion md last list ol", "[markdown2html]") {
    REQUIRE(markdown2html("1. things\n\n") == "\t<li>things</li>\n</ol>\n");
}

TEST_CASE("conversion md blockquote", "[markdown2html]") {
    REQUIRE(markdown2html("> cos\n") == "<p>cos</p>\n");
}

TEST_CASE("conversion md last blockquote", "[markdown2html]") {
    REQUIRE(markdown2html("> things\n\n") == "<p>things</p></blockquote>");
}




