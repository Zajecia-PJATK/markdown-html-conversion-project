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

TEST_CASE("conversion h1", "[html2markdown]") {
    REQUIRE(html2markdown("<h1>things</h1>") == "# things\n");
}

TEST_CASE("conversion h2", "[html2markdown]") {
    REQUIRE(html2markdown("<h2>things</h2>") == "## things\n");
}

TEST_CASE("conversion h3", "[html2markdown]") {
    REQUIRE(html2markdown("<h3>things</h3>") == "### things\n");
}

TEST_CASE("conversion h4", "[html2markdown]") {
    REQUIRE(html2markdown("<h4>things</h4>") == "#### things\n");
}

TEST_CASE("conversion h5", "[html2markdown]") {
    REQUIRE(html2markdown("<h5>things</h5>") == "##### things\n");
}

TEST_CASE("conversion h6", "[html2markdown]") {
    REQUIRE(html2markdown("<h6>things</h6>") == "###### things\n");
}

TEST_CASE("conversion strong", "[html2markdown]") {
    REQUIRE(html2markdown("<strong>things</strong>") == "**things**");
}

TEST_CASE("conversion em", "[html2markdown]") {
    REQUIRE(html2markdown("<em>things</em>") == "*things*");
}

TEST_CASE("conversion del", "[html2markdown]") {
    REQUIRE(html2markdown("<del>things</del>") == "~~things~~");
}

TEST_CASE("conversion pre code", "[html2markdown]") {
        REQUIRE(html2markdown("<pre><code>things</code></pre>") == "```\\nthings\\n```");
}

TEST_CASE("conversion code", "[html2markdown]") {
    REQUIRE(html2markdown("<code>things</code>") == "`things`");
}

TEST_CASE("conversion img title", "[html2markdown]") {
    REQUIRE(html2markdown("<a href=\"things\" title=\"things\">things<\\/a>)") == "![things](things \"things\")");
}

TEST_CASE("conversion hr", "[html2markdown]") {
    REQUIRE(html2markdown("<hr>") == "---\n");
}

TEST_CASE("conversion blockquote", "[html2markdown]") {
    REQUIRE(html2markdown("<blockquote>things</blockquote>") == "> things\n");
}

TEST_CASE("conversion first list ul", "[html2markdown]") {
    REQUIRE(html2markdown("<ul>\\s*<li>things<\\/li>\\s*") == "\n\n- things\n");
}
