#include <iostream>
#include <string>
#include <regex>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include <QObject>
#include <QFileDialog>

using namespace std;

#include "regex_replace.h"
#include "markdown2html.h"
#include "html2markdown.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    bool is_input_html = true;

    auto *load_button = new QPushButton("Load");
    auto *save_button = new QPushButton("Save");
    auto *swap_button = new QPushButton("Swap");
    auto *input_text_edit = new QTextEdit();
    auto *output_text_edit = new QTextEdit();
    auto *input_label = new QLabel("HTML");
    auto *output_label = new QLabel("MD");
    auto *live_preview_text_edit = new QTextEdit();
//*wskaźnik
    input_label->setAlignment(Qt::AlignCenter);
    output_label->setAlignment(Qt::AlignCenter);
    input_text_edit->setPlaceholderText("Start typing here");

    auto *window = new QWidget();
    auto layout = new QGridLayout(window);

    layout->addWidget(load_button, 0, 0);
    layout->addWidget(save_button, 0,5);
    layout->addWidget(swap_button, 0, 2, 1, 2);
    layout->addWidget(input_text_edit, 1, 0, 4, 3);
    layout->addWidget(output_text_edit, 1, 3, 4, 3);
    layout->addWidget(input_label, 0, 1);
    layout->addWidget(output_label, 0, 4);
    layout->addWidget(live_preview_text_edit, 5, 0, 1, 6);

    //to obsługuje zamianę guzika swap
    QObject::connect(swap_button, &QPushButton::clicked, [&is_input_html, &input_label, &output_label]() {
        is_input_html = !is_input_html;//zmienna ma się równać jej przeciwieństwu
        input_label->setText(is_input_html ? "HTML" : "MD");//inpit_label = tekst, nie zmienna waryości, settext = ustawiać tekst, -> wyciąganie
        output_label->setText(is_input_html ? "MD" : "HTML");
    });

    //obsługa pola wejściowej
    QObject::connect(input_text_edit, &QTextEdit::textChanged, [&is_input_html, &output_text_edit, &input_text_edit, &live_preview_text_edit]() {
        auto input_text = input_text_edit->toPlainText().toStdString();
        auto output_text = is_input_html ? html2markdown(input_text) : markdown2html(input_text);

         output_text_edit->setPlainText(QString::fromStdString(output_text));
         live_preview_text_edit->setText(QString::fromStdString(markdown2html(output_text)));
    });

    //obsługa guzika load
    QObject::connect(load_button, &QPushButton::clicked, [&window, &is_input_html, &input_text_edit](){
        auto fileName = QFileDialog::getOpenFileName(window, "Open File", nullptr, is_input_html ? "Source files (*.html)" : "Source files (*.md)");

        if( fileName == nullptr){
            return;
        }

        QFile file(fileName);
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream contents(&file);

        input_text_edit->setText(contents.readAll());
    });

    // obsługa guzika save
    QObject::connect(save_button, &QPushButton::clicked,[&window, &is_input_html, &output_text_edit](){
        auto fileName = QFileDialog::getSaveFileName(window, "Save File", is_input_html ? "file.md" : "file.html", is_input_html ? "Source file (*.md)" : "Source file (*.html)");

        if ( fileName == nullptr){
            return;
        }
        QFile file(fileName);
        file.open(QFile::WriteOnly | QFile::Text);

        QTextStream contents(&file);

        contents << output_text_edit->toPlainText();
        file.close();
    });

    window->show();
    return QApplication::exec();
}

