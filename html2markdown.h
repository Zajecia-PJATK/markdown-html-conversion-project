//
// Created by natalia on 02.01.23.
//

#ifndef MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H
#define MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H

const regex html_h1_pattern = regex(R"(\<h1\>([^<]+)\</h1\>)");

string html2markdown(string html) {
    string markdown = html;

    markdown = regex_replace(markdown, html_h1_pattern, "# $1\n");

    return markdown;
}

#endif //MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H
