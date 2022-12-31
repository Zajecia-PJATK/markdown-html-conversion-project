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

    const string input_md =
            "# *Art* competition for children from day care centres\n"
            "## *Comprehensive survey on the functioning of day care centres*\n"
            "### *Report on th*e presentation of gifts at the Day Care Centre Przystań\n"
            "#### ~~Report~~ on the presentation of gifts at the ZATOKA day care centre\n"
            "##### The gif*t is a sens*e of security\n"
            "###### **St**udy visit from the USA\n"
            "###### *wsedfyhiolki*jugfdsxcv\n"
            "q**wert**y";

    string with_h6_replaced = regex_replace(input_md, h6_pattern, "<h6>$1</h6>");
    string with_h5_replaced = regex_replace(with_h6_replaced, h5_pattern, "<h5>$1</h5>");
    string with_h4_replaced = regex_replace(with_h5_replaced, h4_pattern, "<h4>$1</h4>");
    string with_h3_replaced = regex_replace(with_h4_replaced, h3_pattern, "<h3>$1</h3>");
    string with_h2_replaced = regex_replace(with_h3_replaced, h2_pattern, "<h2>$1</h2>");
    string with_h1_replaced = regex_replace(with_h2_replaced, h1_pattern, "<h1>$1</h1>");

    string with_strong_replaced = regex_replace(with_h1_replaced, strong_pattern, "<strong>$1</strong>");
    string with_em_replaced = regex_replace(with_strong_replaced, em_pattern, "<em>$1</em>");
    string with_del_replaced = regex_replace(with_em_replaced, del_pattern, "<del>$1</del>");


    cout << with_del_replaced <<  endl;

    return 0;
}
