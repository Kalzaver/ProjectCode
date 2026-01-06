#include "fourthpage.h"
#include "ui_fourthpage.h"

#include <QPixmap>
#include <QLabel>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QProcess>
#include <QFile>


fourthPage::fourthPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fourthPage)
{
    ui->setupUi(this);
    QPixmap pic("C:/qt_projects/Python_hybrid_test/img/JawsPuc.jpg");
    ui->label->setPixmap(pic);
    ui->label->setScaledContents(true);

    connect(ui->pushButton, &QPushButton::clicked, this, &fourthPage::on_clicked_forward);
}

fourthPage::~fourthPage()
{
    delete ui;
}

void::fourthPage::on_clicked_forward()
{
    QString pythonScript   = "C:/qt_projects/Python_hybrid_test/textEdit.py";
    QString docxPath       = "C:/qt_projects/Python_hybrid_test/file_editing/test_2.docx";
    QString jsonPath       = "C:/qt_projects/Python_hybrid_test/file_editing/data.json";

    QJsonObject breed_strings;

    breed_strings.insert("howManyTeethWereMissed"   ,ui->lineEdit->text());
    breed_strings.insert("isThereAreDoubleTeeth"    ,ui->lineEdit_2->text());

    // БЛОК ПРОВЕРКИ СОСТОЯНИЯ НАЖАТИЯ РАДИО-КНОПОК
    if (ui->radioButton->isChecked())
    {
       breed_strings.insert("000"," + ");
    }
    else
    {
       breed_strings.insert("000","   ");
    }

    if (ui->radioButton_1->isChecked())
    {
       breed_strings.insert("111"," + ");
       breed_strings.insert("010","   ");
    }
    else
    {
       breed_strings.insert("010","   ");
       breed_strings.insert("111"," + ");
    }

    if (ui->radioButton_3->isChecked())
    {
       breed_strings.insert("121"," + ");
       breed_strings.insert("020","   ");
    }
    else
    {
       breed_strings.insert("020","   ");
       breed_strings.insert("121"," + ");
    }

    if (ui->radioButton_5->isChecked())
    {
       breed_strings.insert("131"," + ");
       breed_strings.insert("030","   ");
    }
    else
    {
       breed_strings.insert("030","   ");
       breed_strings.insert("131"," + ");
    }

    if (ui->radioButton_7->isChecked())
    {
       breed_strings.insert("141"," + ");
       breed_strings.insert("040","   ");
    }
    else
    {
       breed_strings.insert("040","   ");
       breed_strings.insert("141"," + ");
    }

    if (ui->radioButton_9->isChecked())
    {
       breed_strings.insert("151"," + ");
       breed_strings.insert("050","   ");
    }
    else
    {
       breed_strings.insert("050","   ");
       breed_strings.insert("151"," + ");
    }

    if (ui->radioButton_11->isChecked())
    {
       breed_strings.insert("161"," + ");
       breed_strings.insert("060","   ");
    }
    else
    {
       breed_strings.insert("060","   ");
       breed_strings.insert("161"," + ");
    }

    if (ui->radioButton_13->isChecked())
    {
       breed_strings.insert("171"," + ");
       breed_strings.insert("070","   ");
    }
    else
    {
       breed_strings.insert("070","   ");
       breed_strings.insert("171"," + ");
    }

    if (ui->radioButton_15->isChecked())
    {
       breed_strings.insert("181"," + ");
       breed_strings.insert("080","   ");
    }
    else
    {
       breed_strings.insert("080","   ");
       breed_strings.insert("181"," + ");
    }
     // КОНЕЦ БЛОКА

    breed_strings.insert("HereYourNotes",ui->lineEdit_3->text());

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
}
