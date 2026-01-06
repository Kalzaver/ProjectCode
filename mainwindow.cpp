#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thirdwindow.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QProcess>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_clicked_push);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void::MainWindow::on_clicked_push()
{
    QString pythonScript = "C:/qt_projects/Python_hybrid_test/textEdit.py";
    QString docxPath     = "C:/qt_projects/Python_hybrid_test/file_editing/test_2.docx";
    QString jsonPath     = "C:/qt_projects/Python_hybrid_test/file_editing/data.json";

    QJsonObject breed_strings;

    breed_strings.insert("PutWeightHere"       ,ui->lineEdit_11->text());
    breed_strings.insert("PutHieghtHere"       ,ui->lineEdit_12->text());
    breed_strings.insert("PutHere"             ,ui->lineEdit_13->text());
    breed_strings.insert("PutElbowHere"        ,ui->lineEdit_14->text());
    breed_strings.insert("PutDepthHere"        ,ui->lineEdit_15->text());
    breed_strings.insert("PutChestHere"        ,ui->lineEdit_16->text());
    breed_strings.insert("PutCircimferenceHere",ui->lineEdit_17->text());
    breed_strings.insert("PutHeadLengthHere"   ,ui->lineEdit_18->text());
    breed_strings.insert("PutMuzzleHere"       ,ui->lineEdit_19->text());
    breed_strings.insert("PutSkullHere"        ,ui->lineEdit_20->text());
    breed_strings.insert("PutfoundingHere"     ,ui->lineEdit_21->text());

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

    ThirdWindow *third_page = new ThirdWindow();
    this->hide();
    third_page->show();
}
