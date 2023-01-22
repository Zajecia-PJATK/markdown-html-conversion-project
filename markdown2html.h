//
// Created by natalia on 02.01.23.
//

#ifndef MARKDOWN_HTML_CONVERSION_PROJECT_MARKDOWN2HTML_H
#define MARKDOWN_HTML_CONVERSION_PROJECT_MARKDOWN2HTML_H

const regex md_h1_pattern = regex(R"(#{1} (.+))");
const regex md_h2_pattern = regex(R"(#{2} (.+))");
const regex md_h3_pattern = regex(R"(#{3} (.+))");
const regex md_h4_pattern = regex(R"(#{4} (.+))");
const regex md_h5_pattern = regex(R"(#{5} (.+))");
const regex md_h6_pattern = regex(R"(#{6} (.+))");

const regex md_em_pattern = regex(R"(\*(.+)\*)");
const regex md_del_pattern = regex(R"(~~(.+)~~)");
const regex md_strong_pattern = regex(R"(\*\*(.+)\*\*)");

const regex md_pre_code_pattern = regex(R"(```\n((.|\n)+)\n```)");
const regex md_code_pattern = regex(R"(\`(.+)\`)");

const regex md_a_title_pattern = regex(R"(\[(.+)\]\(([^\"\)]+) \"(.+)\"\))");
const regex md_a_pattern = regex(R"(\[(.+)]\((.+)\))");
const regex md_img_title_pattern = regex(R"(!\[(.+)\]\(([^"\)]+) "(.+)\"\))");
const regex md_img_pattern = regex(R"(!\[(.+)]\((.+)\))");

const regex md_hr_pattern = regex(R"(---\n)");

const regex md_first_list_ul_pattern = regex(R"(\n\n- (.+))");
const regex md_last_list_ul_pattern = regex(R"(- (.+)\n{2})");
const regex md_rest_list_ul_pattern = regex(R"(- (.+))");

const regex md_first_list_ol_pattern = regex(R"(\n{2}\d+. (.+))");
const regex md_rest_list_ol_pattern = regex(R"(\n\d+. (.+))");
const regex md_last_list_ol_pattern = regex(R"(\d+. (.+)\n{2})");

const regex md_blockquote_pattern = regex(R"(\n\n> (.+)\n\n)");
const regex md_blockquote_multiple_first_pattern = regex(R"(\n\n> (.+))");
const regex md_blockquote_multiple_last_pattern = regex(R"(> (.+)\n\n)");
const regex md_blockquote_multiple_rest_pattern = regex(R"(> (.+))");

string markdown2html(string markdown) {
    string html = markdown;
    
    html = regex_replace(html, md_h6_pattern, "<h6>$1</h6>");
    html = regex_replace(html, md_h5_pattern, "<h5>$1</h5>");
    html = regex_replace(html, md_h4_pattern, "<h4>$1</h4>");
    html = regex_replace(html, md_h3_pattern, "<h3>$1</h3>");
    html = regex_replace(html, md_h2_pattern, "<h2>$1</h2>");
    html = regex_replace(html, md_h1_pattern, "<h1>$1</h1>");

    html = regex_replace(html, md_strong_pattern, "<strong>$1</strong>");
    html = regex_replace(html, md_em_pattern, "<em>$1</em>");
    html = regex_replace(html, md_del_pattern, "<del>$1</del>");

    html = regex_replace(html, md_pre_code_pattern, "<pre><code>$1</code></pre>");
    html = regex_replace(html, md_code_pattern, "<code>$1</code>");

    html = regex_replace(html, md_img_title_pattern, R"(<img src="$1" alt="$2" title="$3">)");
    html = regex_replace(html, md_img_pattern, R"(<img src="$2" alt="$1">)");
    html = regex_replace(html, md_a_title_pattern, R"(<a href="$2" title="$3">$1</a>)");
    html = regex_replace(html, md_a_pattern, "<a href=\"$2\">$1</a>");

    html = regex_replace(html, md_hr_pattern, "<hr>\n");

    html = regex_replace(html, md_first_list_ul_pattern, "\n<ul>\n\t<li>$1</li>");
    html = regex_replace(html, md_last_list_ul_pattern, "\t<li>$1</li>\n</ul>\n");
    html = regex_replace(html, md_rest_list_ul_pattern, "\t<li>$1</li>");

    html = regex_replace(html, md_first_list_ol_pattern, "\n<ol>\n\t<li>$1</li>");
    html = regex_replace(html, md_last_list_ol_pattern, "\t<li>$1</li>\n</ol>\n");
    html = regex_replace(html, md_rest_list_ol_pattern, "\t<li>$1</li>");

    html = regex_replace(html, md_blockquote_pattern, "<blockquote>$1</blockquote>");
    html = regex_replace(html, md_blockquote_multiple_first_pattern, "<blockquote><p>$1</p>");
    html = regex_replace(html, md_blockquote_multiple_last_pattern, "<p>$1</p></blockquote>");
    html = regex_replace(html, md_blockquote_multiple_rest_pattern, "<p>$1</p>");

    
    return html;
}

#endif //MARKDOWN_HTML_CONVERSION_PROJECT_MARKDOWN2HTML_H
