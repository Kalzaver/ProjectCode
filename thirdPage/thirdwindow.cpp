#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "fourthpage.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QProcess>
#include <QFile>

ThirdWindow::ThirdWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &ThirdWindow::on_clicked_push);
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}


void::ThirdWindow::on_clicked_push()
{
    QString pythonScript = "C:/qt_projects/Python_hybrid_test/textEdit.py";
    QString docxPath     = "C:/qt_projects/Python_hybrid_test/file_editing/test_2.docx";
    QString jsonPath     = "C:/qt_projects/Python_hybrid_test/file_editing/data.json";

    QJsonObject breed_strings;

    breed_strings.insert("SomeKindOfComments1"   ,ui->lineEdit_22->text());
    breed_strings.insert("SomeKindOfComments2"   ,ui->lineEdit_23->text());
    breed_strings.insert("SomeKindOfComments3"   ,ui->lineEdit_24->text());
    breed_strings.insert("SomeKindOfComments4"   ,ui->lineEdit_25->text());
    breed_strings.insert("SomeKindOfComments5"   ,ui->lineEdit_26->text());
    breed_strings.insert("SomeKindOfComments6"   ,ui->lineEdit_27->text());

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

    fourthPage *fourth_page = new fourthPage();
    this->hide();
    fourth_page->show();
}
