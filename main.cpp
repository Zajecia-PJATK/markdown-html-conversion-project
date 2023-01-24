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


int main(int argc, char *argv[]) {// główna funkcja w programie,(argc, argv)to sposób przekazywania argumentów wiersza poleceń
    QApplication a(argc, argv);// agrumenty początkowe dla progarmu, pierwszy arguemtem będzie jego nazwa,
    //QApplication to główna funkcja w tej bibliotece, jest na samym początku, bez tego nic by się nie pojawiło na ekranie
//cmake list == make, zielony trójkąt
    bool is_input_html = true; // zmienna, która trzyma w sobie tylko prawdę albo kłamstwo
//new == dynamiczne przydzielanie pamięci
    auto *load_button = new QPushButton("Load");
    auto *save_button = new QPushButton("Save");
    auto *swap_button = new QPushButton("Swap");
    auto *input_text_edit = new QTextEdit();
    auto *output_text_edit = new QTextEdit();
    auto *input_label = new QLabel("HTML");
    auto *output_label = new QLabel("MD");
    auto *live_preview_text_edit = new QTextEdit();
//*wskaźnik
//auto automatyczne określenie typu
    input_label->setAlignment(Qt::AlignCenter);//label tekst do wyświetlenia którego użytkownik nie może edytować
    output_label->setAlignment(Qt::AlignCenter);// AlignCenter wyrównanie do środka
    input_text_edit->setPlaceholderText("Start typing here"); //wyświetlanie wyszarzonego tekstu, który po wpisanie znika
    input_text_edit->setAcceptRichText(false); //gdy się ustawi fałsz, to akceptuje tylko wprowadzenie zwykłego tekstu
    //gdy, jest prawda to akceptuje wprowadzenie tekstu w bogatej postaci przez użytkownika

    auto *window = new QWidget(); //jest oknem, przyjmuje inforamcje od QApplication
    auto layout = new QGridLayout(window);
// layout = w jaki sposób będą rozłożone komponenty
// QGridlLayout = układa wszystkie komponenty w siatce, jak mają byc ułożone
// addwidget = komponent
// wiersz, kolumna, w którym się zaczyna, naile się rozciąga
    layout->addWidget(load_button, 0, 0);
    layout->addWidget(save_button, 0,5);
    layout->addWidget(swap_button, 0, 2, 1, 2);
    layout->addWidget(input_text_edit, 1, 0, 4, 3);
    layout->addWidget(output_text_edit, 1, 3, 4, 3);
    layout->addWidget(input_label, 0, 1);
    layout->addWidget(output_label, 0, 4);
    layout->addWidget(live_preview_text_edit, 5, 0, 1, 6);

    //to obsługuje zamianę guzika swap, przypisanie jakiejś logiki dla wydarzenia w wigecie, np kinkiecie guzika, jest funkcja która przyjmuje argument lambda
    QObject::connect(swap_button, &QPushButton::clicked, [&is_input_html, &input_label, &output_label]() {
        is_input_html = !is_input_html;//zmienna ma się równać jej przeciwieństwu
        input_label->setText(is_input_html ? "HTML" : "MD");//inpit_label = tekst, nie zmienna wartości, settext = ustawiać tekst, -> wyciąganie
        output_label->setText(is_input_html ? "MD" : "HTML");
    });

    //obsługa pola wejściowej
    QObject::connect(input_text_edit, &QTextEdit::textChanged, [&is_input_html, &output_text_edit, &input_text_edit, &live_preview_text_edit]() {
        auto input_text = input_text_edit->toPlainText().toStdString();//(input_text_edit)wskaźnik,(toplaintext)wyciągnie zwykły tekst, zwraca qstring, następnie zmienia go na stdstring
        auto output_text = is_input_html ? html2markdown(input_text) : markdown2html(input_text); //jeśli is_input jest prawdą to: pierwsze, jeśli fałsz to drugie

         output_text_edit->setPlainText(QString::fromStdString(output_text)); //wywołanie funkcji setplaintext, spowoduje zamianę qstringa na stdstringa
         live_preview_text_edit->setText(QString::fromStdString(markdown2html(output_text)));//settext(metoda ustawia tekst, który ma być wyświetlany przez obiekt, który jest na lewo od strzałki)
         // stetext próbuje wyświetlić html jako richtext(jeśli już był html to nic się nie zmieni, ale jeśli był mk to zmieni na html)
         //plain = ubogi
    });

    //obsługa guzika load
    QObject::connect(load_button, &QPushButton::clicked, [&window, &is_input_html, &input_text_edit](){
        auto fileName = QFileDialog::getOpenFileName(window, "Open File", nullptr, is_input_html ? "Source files (*.html)" : "Source files (*.md)");
        // QFileDialog ma w sobie funkcie QFileDialog i ona otworzy okienko do wybierania plików i zwróci pełną ścieżkę do tego pliku

        if( fileName == nullptr){
            return;
        }// jak kliknie się anuluj podczas wyszukiwania pliku to ta funkcja zwróci pustkę

        QFile file(fileName);//deklaracja zmiennej typu qfile o nazwie file(ścieżka która użytkownik podał sam)
        file.open(QFile::ReadOnly | QFile::Text);// otwiera plik w trybie tylko od odczytu jako tekst
        QTextStream contents(&file);//wyciąganie całej zawartości pliku do zmiennej contents

        input_text_edit->setText(contents.readAll());// stetext ustawia tekst w input_text_edit i odczytuje zawartości pliku i przekazuje do contents
    });

    // obsługa guzika save, lamda === funkcja anonimowa
    QObject::connect(save_button, &QPushButton::clicked,[&window, &is_input_html, &output_text_edit](){
        auto fileName = QFileDialog::getSaveFileName(window, "Save File", is_input_html ? "file.md" : "file.html", is_input_html ? "Source file (*.md)" : "Source file (*.html)");
// QFileDialog ma w sobie funkcje getSaveFileName i ona otworzy okienko do zapisu, jeśli jest prawda do pierwsze, jeśli fałsz to drugie
        if ( fileName == nullptr){
            return;
        }
        // jak kliknie się anuluj podczas zapisywania pliku to ta funkcja zwróci pustkę
        QFile file(fileName);//deklaracja zmiennej typu qfile o nazwie file(ścieżka która użytkownik podał sam)
        file.open(QFile::WriteOnly | QFile::Text);// otwiera plik do zapisu

        QTextStream contents(&file);//wyciąganie całej zawartości pliku do zmiennej contents

        contents << output_text_edit->toPlainText();// contents jest cout tylko że to jest plik, do contents ląduje to co zwróci funkcja toPlainText
        file.close();
    });

    window->show();
    return QApplication::exec(); // obsługa myszki i klawiatury, to jest główna funkcja z biblioteki QT
}

