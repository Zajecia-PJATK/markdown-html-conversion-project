//
// Created by natalia on 02.01.23.
//

#ifndef MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H
#define MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H

const regex html_h1_pattern = regex(R"(<h1>(.+)<\/h1>)");
const regex html_h2_pattern = regex(R"(<h2>(.+)<\/h2>)");
const regex html_h3_pattern = regex(R"(<h3>(.+)<\/h3>)");
const regex html_h4_pattern = regex(R"(<h4>(.+)<\/h4>)");
const regex html_h5_pattern = regex(R"(<h5>(.+)<\/h5>)");
const regex html_h6_pattern = regex(R"(<h6>(.+)<\/h6>)");

string html2markdown(string html) {
    string markdown = html;

    markdown = regex_replace(markdown, html_h1_pattern, "# $1\n");
    markdown = regex_replace(markdown, html_h2_pattern, "## $1\n");
    markdown = regex_replace(markdown, html_h3_pattern, "### $1\n");
    markdown = regex_replace(markdown, html_h4_pattern, "#### $1\n");
    markdown = regex_replace(markdown, html_h5_pattern, "##### $1\n");
    markdown = regex_replace(markdown, html_h6_pattern, "###### $1\n");


    return markdown;
}

#endif //MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H
