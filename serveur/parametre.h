#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QDialog>
#include <QMap>
#include <QFile>
#include <QStyleFactory>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QSettings>

namespace Ui {
class parametre;
}

class parametre : public QDialog
{
    Q_OBJECT

public:
    //QMap<QString,QString> settings;
    QSettings* settings;
    explicit parametre(QWidget *parent = nullptr);
    ~parametre();
public slots:
    QPalette starttheme();
private:
    Ui::parametre *ui;
private slots:
    QPalette darkmode();
    QPalette whitemode();
    void startSetings();
    void on_checkBox_3_toggled(bool checked);
    void on_checkBox_2_toggled(bool checked);
    void on_checkBox_toggled(bool checked);
    void on_comboBox_2_activated(const QString &arg1);
    void on_comboBox_3_activated(const QString &arg1);
    void on_comboBox_activated(const QString &arg1);
    void on_deletbuton_clicked();
    void on_site_clicked();
    void on_discord_clicked();
    void on_tweter_clicked();
    void on_checkboxmodecondensee_toggled(bool checked);
};

#endif // PARAMETRE_H
