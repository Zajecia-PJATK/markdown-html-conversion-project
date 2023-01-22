//
// Created by natalia on 17.01.23.
//
#define CATCH_CONFIG_MAIN

#include <string>
#include <regex>

using namespace std;

#include "../regex_replace.h"
#include "../html2markdown.h"
#include "catch.hpp"

TEST_CASE("conversion html h1", "[html2markdown]") {
    REQUIRE(html2markdown("<h1>things</h1>") == "# things\n");
}

TEST_CASE("conversion html h2", "[html2markdown]") {
    REQUIRE(html2markdown("<h2>things</h2>") == "## things\n");
}

TEST_CASE("conversion html h3", "[html2markdown]") {
    REQUIRE(html2markdown("<h3>things</h3>") == "### things\n");
}

TEST_CASE("conversion html h4", "[html2markdown]") {
    REQUIRE(html2markdown("<h4>things</h4>") == "#### things\n");
}

TEST_CASE("conversion html h5", "[html2markdown]") {
    REQUIRE(html2markdown("<h5>things</h5>") == "##### things\n");
}

TEST_CASE("conversion html h6", "[html2markdown]") {
    REQUIRE(html2markdown("<h6>things</h6>") == "###### things\n");
}

TEST_CASE("conversion html strong", "[html2markdown]") {
    REQUIRE(html2markdown("<strong>things</strong>") == "**things**");
}

TEST_CASE("conversion html em", "[html2markdown]") {
    REQUIRE(html2markdown("<em>things</em>") == "*things*");
}

TEST_CASE("conversion html del", "[html2markdown]") {
    REQUIRE(html2markdown("<del>things</del>") == "~~things~~");
}

TEST_CASE("conversion html pre code", "[html2markdown]") {
        REQUIRE(html2markdown("<pre><code>things</code></pre>") == "```\\nthings\\n```");
}

TEST_CASE("conversion html code", "[html2markdown]") {
    REQUIRE(html2markdown("<code>things</code>") == "`things`");
}

TEST_CASE("conversion html img title", "[html2markdown]") {
    REQUIRE(html2markdown("<img src=\"https://placebear.com/300/300\" alt=\"alt text\">") == "![alt text\"](\"https://placebear.com/300/300)");
}

TEST_CASE("conversion html img", "[html2markdown]") {
    REQUIRE(html2markdown("") == "");
}

TEST_CASE("conversion html hr", "[html2markdown]") {
    REQUIRE(html2markdown("<hr>") == "---\n");
}

TEST_CASE("conversion html blockquote", "[html2markdown]") {
    REQUIRE(html2markdown("<blockquote>things</blockquote>") == "> things\n");
}

TEST_CASE("conversion html list ul", "[html2markdown]") {
    REQUIRE(html2markdown("") == "");
}

TEST_CASE("conversion html list ol", "[html2markdown]") {
    REQUIRE(html2markdown("") == "");
}
TEST_CASE("conversion html list blockquote", "[html2markdown]") {
    REQUIRE(html2markdown("") == "");
}


