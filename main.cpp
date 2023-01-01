#include <iostream>
#include <regex>
using namespace std;
int main() {
    const regex h1_pattern = regex(R"(#{1} (.+))");
    const regex h2_pattern = regex(R"(#{2} (.+))");
    const regex h3_pattern = regex(R"(#{3} (.+))");
    const regex h4_pattern = regex(R"(#{4} (.+))");
    const regex h5_pattern = regex(R"(#{5} (.+))");
    const regex h6_pattern = regex(R"(#{6} (.+))");

    const regex em_pattern = regex(R"(\*(.+)\*)");
    const regex del_pattern = regex(R"(~~(.+)~~)");
    const regex strong_pattern = regex(R"(\*\*(.+)\*\*)");

    const regex pre_code_pattern = regex(R"(```\n((.|\n)+)\n```)");
    const regex code_pattern = regex(R"(\`(.+)\`)");

    const regex a_title_pattern = regex(R"(\[(.+)\]\(([^\"\)]+) \"(.+)\"\))");
    const regex a_pattern = regex(R"(\[(.+)]\((.+)\))");
    const regex img_title_pattern = regex(R"(!\[(.+)\]\(([^"\)]+) "(.+)\"\))");
    const regex img_pattern = regex(R"(!\[(.+)]\((.+)\))");

    const string input_md =
            "# *Art* competition for children from day care centres\n"
            "## *Comprehensive survey on the functioning of day care centres*\n"
            "### *Report on th*e presentation of gifts at the Day Care Centre Przystań\n"
            "#### ~~Report~~ on the presentation of gifts at the ZATOKA day care centre\n"
            "##### The gif*t is a sens*e of security\n"
            "###### **St**udy visit from the USA\n"
            "###### *wsedfyhiolki*jugfdsxcv\n"
            "`cos tam cos tam`\n"
            "```\n"
            "\t\t\tO\n"
            "\t\tO\n"
            "[have a title](https://markdowntohtml.com \"Awesome Markdown Converter\")\n"
            "[inline](https://markdowntohtml.com)\n"
            "![text](http://placekitten.com/g/200/302 \"tytuł\")\n"
            "![text](http://placekitten.com/g/200/302)";


    string text = input_md;

    text = regex_replace(text, h6_pattern, "<h6>$1</h6>");
    text = regex_replace(text, h5_pattern, "<h5>$1</h5>");
    text = regex_replace(text, h4_pattern, "<h4>$1</h4>");
    text = regex_replace(text, h3_pattern, "<h3>$1</h3>");
    text = regex_replace(text, h2_pattern, "<h2>$1</h2>");
    text = regex_replace(text, h1_pattern, "<h1>$1</h1>");

    text = regex_replace(text, strong_pattern, "<strong>$1</strong>");
    text = regex_replace(text, em_pattern, "<em>$1</em>");
    text = regex_replace(text, del_pattern, "<del>$1</del>");

    text = regex_replace(text, pre_code_pattern, "<pre><code>$1</code></pre>");
    text = regex_replace(text, code_pattern, "<code>$1</code>");

    text = regex_replace(text, img_title_pattern, R"(<img src="$2" alt="$1" title="$3">)");
    text = regex_replace(text, img_pattern, R"(<img src="$2" alt="$1">)");
    text = regex_replace(text, a_title_pattern, R"(<a href="$2" title="$1">$3</a>)");
    text = regex_replace(text, a_pattern, "<a href=\"$2\">$1</a>");


    cout << text <<  endl;

    return 0;
}
