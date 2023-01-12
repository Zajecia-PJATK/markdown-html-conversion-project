#include <iostream>
#include <string>
#include <regex>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>

using namespace std;

#include "regex_replace.h"
#include "markdown2html.h"
#include "html2markdown.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *load_button = new QPushButton("Load");
    auto *save_button = new QPushButton("Save");
    auto *swap_button = new QPushButton("Swap");
    auto *input_text = new QTextEdit("left");
    auto *output_text = new QTextEdit("right");
    auto *input_label = new QLabel("HTML");
    auto *output_label = new QLabel("MD");

    input_label->setAlignment(Qt::AlignCenter);
    output_label->setAlignment(Qt::AlignCenter);

    auto *window = new QWidget();
    auto layout = new QGridLayout(window);

    layout->addWidget(load_button, 0, 0);
    layout->addWidget(save_button, 0,5);
    layout->addWidget(swap_button, 0, 2, 1, 2);
    layout->addWidget(input_text, 1, 0, 4, 3);
    layout->addWidget(output_text, 1, 3, 4, 3);
    layout->addWidget(input_label, 0, 1);
    layout->addWidget(output_label, 0, 4);

    window->show();
    return QApplication::exec();
}

