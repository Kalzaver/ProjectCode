#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"
// #include <iostream>
using namespace std;

#include <QJsonObject>
#include <QJsonDocument>
#include <QProcess>
#include <QFile>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_forward1, &QPushButton::clicked, this, &Widget::on_clicked_switchPage);
}

Widget::~Widget()
{
    delete ui;
}

void::Widget::on_clicked_switchPage()
{
    QString pythonScript   = "C:/qt_projects/Python_hybrid_test/textEdit.py";
    QString fileCopyScript = "C:/qt_projects/Python_hybrid_test/fileCopy.py";
    QString docxPath       = "C:/qt_projects/Python_hybrid_test/file_editing/test_2.docx";

    QProcess::startDetached("C:/Users/lukan/AppData/Local/Programs/Python/Python312/python.exe", {fileCopyScript, docxPath});

    QString jsonPath     = "C:/qt_projects/Python_hybrid_test/file_editing/data.json";

    QJsonObject breed_strings;
    breed_strings.insert("NamePutOfTheClubHere"    ,ui->lineEdit_1->text());
    breed_strings.insert("NameOfTheBreed"          ,ui->lineEdit_2->text());
    breed_strings.insert("NameOfTheDog"            ,ui->lineEdit_3->text());
    breed_strings.insert("NumberFromRKFBase"       ,ui->lineEdit_4->text());
    breed_strings.insert("PuthTheChipHere"         ,ui->lineEdit_5->text());
    breed_strings.insert("HereIsYourFather"        ,ui->lineEdit_6->text());
    breed_strings.insert("HereIsYourMother"        ,ui->lineEdit_7->text());
    breed_strings.insert("hoIsTheBreeder"          ,ui->lineEdit_8->text());
    breed_strings.insert("WhoIsTheOwner"           ,ui->lineEdit_9->text());
    breed_strings.insert("PutYourCurrentAdress",ui->lineEdit_10->text());

    QJsonDocument doc(breed_strings);
    QFile file(jsonPath);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(doc.toJson());
        file.close();
    }
    else
    {
        qDebug() << "Could not create JSON file at:" << jsonPath;
        return;
    }

    QProcess::startDetached("C:/Users/lukan/AppData/Local/Programs/Python/Python312/python.exe", {pythonScript, docxPath, jsonPath});

    MainWindow *second_page = new MainWindow();
    this->hide();
    second_page->show();
}
