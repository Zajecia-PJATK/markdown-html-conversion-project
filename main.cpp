#include <iostream>
#include <string>
#include <regex>

using namespace std;

#include "markdown2html.h"
#include "html2markdown.h"

int main() {

//    const string input_md =
//            "# *Art* competition for children from day care centres\n"
//            "## *Comprehensive survey on the functioning of day care centres*\n"
//            "### *Report on th*e presentation of gifts at the Day Care Centre Przystań\n"
//            "#### ~~Report~~ on the presentation of gifts at the ZATOKA day care centre\n"
//            "##### The gif*t is a sens*e of security\n"
//            "###### **St**udy visit from the USA\n"
//            "###### *wsedfyhiolki*jugfdsxcv\n"
//            "`cos tam cos tam`\n"
//            "```\n"
//            "\t\t\tO\n"
//            "\t\tO\n"
//            "[have a title](https://markdowntohtml.com \"Awesome Markdown Converter\")\n"
//            "[inline](https://markdowntohtml.com)\n"
//            "![text](http://placekitten.com/g/200/302 \"tytuł\")\n"
//            "![text](http://placekitten.com/g/200/302)\n"
//            "---\n"
//            "\n"
//            "- pierwszy argument\n"
//            "- drugi argument\n"
//            "- trzeci argument\n"
//            "- czwarty argument\n"
//            "- piaty argument\n"
//            "\n"
//            "\n"
//            "\n"
//            "1. pierwszy argument\n"
//            "2. drugi argument\n"
//            "3. trzeci argument\n"
//            "4. czwarty argument\n"
//            "5. piąty argument\n"
//            "\n"
//            "\n"
//            "\n"
//            "> Dorothy followed her through many of the beautiful rooms in her castle.\n"
//            "\n"
//            "\n"
//            "\n"
//            "\n"
//            "> Dorothy followed her through many of the beautiful rooms in her castle.\n"
//            "> The Witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.\n"
//            "\n"
//            "";
//    cout << markdown2html(input_md) <<  endl;
    string html =
            "<h1>treść</h1>\n";
    cout << html2markdown(html) << endl;



    return 0;
}
