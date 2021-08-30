#ifndef SUCCEES_H
#define SUCCEES_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
namespace Ui {
class sucees;
}

class sucees : public QDialog
{
    Q_OBJECT

public:
    explicit sucees(QWidget *parent = nullptr);
    ~sucees();

private slots:
    void on_message10_clicked();

    void on_message100_clicked();

    void on_message1000_clicked();

    void on_messagemaxint_clicked();

private:
    QSettings* settings;
    Ui::sucees *ui;
};

#endif // SUCCEES_H
