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

const regex html_strong_pattern = regex (R"(<strong>(.+)</strong>)");
const regex html_em_pattern = regex(R"(<em>(.+)<\/em>)");
const regex html_del_pattern = regex(R"(<del>(.+)</del>)");

const regex html_pre_code_pattern = regex(R"(<pre><code>((.|\n)+)<\/code><\/pre>)");
const regex html_code_pattern = regex(R"(<code>(.+)</code>)");

const regex html_a_title_pattern = regex(R"(<a href="([^"]+)/" title="(.+)/">(.+)<\/a>)");
const regex html_a_pattern = regex(R"(<a href="(.+)\">(.+)<\/a>)");
const regex html_img_title_pattern = regex(R"(<img src="([^"]+)\" alt=\"(.+)\" title=\"(.+)\">)");
const regex html_img_pattern = regex(R"(<img src="$2" alt="$1">)");


string html2markdown(string html) {
    string markdown = html;

    markdown = regex_replace(markdown, html_h1_pattern, "# $1\n");
    markdown = regex_replace(markdown, html_h2_pattern, "## $1\n");
    markdown = regex_replace(markdown, html_h3_pattern, "### $1\n");
    markdown = regex_replace(markdown, html_h4_pattern, "#### $1\n");
    markdown = regex_replace(markdown, html_h5_pattern, "##### $1\n");
    markdown = regex_replace(markdown, html_h6_pattern, "###### $1\n");

    markdown = regex_replace(markdown, html_strong_pattern, R"(**$1**)");
    markdown = regex_replace(markdown, html_em_pattern, "*$1*");
    markdown = regex_replace(markdown, html_del_pattern, "~~$1~~");

    markdown = regex_replace(markdown, html_pre_code_pattern, R"(```\n$1\n```)");
    markdown = regex_replace(markdown, html_code_pattern, "`$1`");

    markdown = regex_replace(markdown, html_img_title_pattern, "![$2]($1 \"$3\")");
    markdown = regex_replace(markdown, html_img_pattern, "![$2]($1)");
    markdown = regex_replace(markdown, html_a_title_pattern, R"([$3]($1 "$2"))");
    markdown = regex_replace(markdown, html_a_pattern, R"([$1]($2))");//

    return markdown;
}

#endif //MARKDOWN_HTML_CONVERSION_PROJECT_HTML2MARKDOWN_H
