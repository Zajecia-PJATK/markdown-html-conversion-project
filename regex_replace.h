//
// Created by natalia on 10.01.23.
//

#ifndef MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H
#define MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H

string regex_replace(const string& input, const regex& regex, const function<string(string const& match)>& format) {
    string tmp = input;//function typ lambdy jaki jest przyjmowany

    smatch groups;// smatch typ zmiennej w którym są wszytkie grupy regexa
    while (regex_search(tmp, groups, regex)) { //gdzie ma szukać, tablice gdzie ma wpisać wyniki, co ma szukać
        tmp = groups.prefix().str() + format(groups[0]) + groups.suffix().str(); //funkcja format ma nam zmienić znaleziony tekst
    }
    // regex_search wstawi do zmiennej groups wyniki szukanego regex w tmp, jak już coś znalazł w środku tej pętli, w tmp wstawi groups.prefix(), dla grup zero uruchomi grupę format

    return tmp;// tmp nazwa zmiennej
}
#endif //MARKDOWN_HTML_CONVERSION_PROJECT_REGEX_REPLACE_H