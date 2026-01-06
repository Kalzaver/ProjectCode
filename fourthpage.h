#ifndef FOURTHPAGE_H
#define FOURTHPAGE_H

#include <QMainWindow>

namespace Ui {
class fourthPage;
}

class fourthPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit fourthPage(QWidget *parent = nullptr);
    ~fourthPage();

private slots:
    void on_clicked_forward();

private:
    Ui::fourthPage *ui;
};

#endif // FOURTHPAGE_H
