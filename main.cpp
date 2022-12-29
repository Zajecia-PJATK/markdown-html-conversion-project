#include <iostream>
#include <regex>
using namespace std;
int main() {
    const regex h1_pattern = regex("#{1} (.+)");
    const regex h2_pattern = regex("#{2} (.+)");
    const regex h3_pattern = regex("#{3} (.+)");
    const regex h4_pattern = regex("#{4} (.+)");
    const regex h5_pattern = regex("#{5} (.+)");
    const regex h6_pattern = regex("#{6} (.+)");

    const string input_md =
            "# Art competition for children from day care centres\n"
            "## Comprehensive survey on the functioning of day care centres\n"
            "### Report on the presentation of gifts at the Day Care Centre Przystań\n"
            "#### Report on the presentation of gifts at the ZATOKA day care centre\n"
            "##### The gift is a sense of security\n"
            "###### Study visit from the USA\n"
            "###### wsedfyhiolkijugfdsxcv\n";

    string with_h6_replaced = regex_replace(input_md, h6_pattern, "<h6>$1</h6>");
    string with_h5_replaced = regex_replace(with_h6_replaced, h5_pattern, "<h5>$1</h5>");
    string with_h4_replaced = regex_replace(with_h5_replaced, h4_pattern, "<h4>$1</h4>");
    string with_h3_replaced = regex_replace(with_h4_replaced, h3_pattern, "<h3>$1</h3>");
    string with_h2_replaced = regex_replace(with_h3_replaced, h2_pattern, "<h2>$1</h2>");
    string with_h1_replaced = regex_replace(with_h2_replaced, h1_pattern, "<h1>$1</h1>");

    cout << with_h1_replaced <<  endl;

    return 0;
}
