#include <iostream>
#include <regex>
using namespace std;
int main() {
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


    cout << with_h5_replaced <<  endl;

    return 0;
}
