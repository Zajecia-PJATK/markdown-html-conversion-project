#include <iostream>
#include <string>
#include <regex>
#include <QApplication>
#include <QPushButton>

using namespace std;

#include "regex_replace.h"
#include "markdown2html.h"
#include "html2markdown.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}

