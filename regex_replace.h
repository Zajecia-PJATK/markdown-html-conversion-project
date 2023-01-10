//
// Created by natalia on 10.01.23.
//

#ifndef MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H
#define MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H

string regex_replace(const string& input, const regex& regex, const function<string(string const& match)>& format) {
    string tmp = input;

    smatch groups;
    while (regex_search(tmp, groups, regex)) { //gdzie ma szukać, tablice gdzie ma wpisać wyniki, co ma szukać
        tmp = groups.prefix().str() + format(groups[0]) + groups.suffix().str(); //funkcja format ma nam zamieć znaleziony tekst
    }

    return tmp;
}
#endif //MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H