#ifndef REMOUVEFILE_H
#define REMOUVEFILE_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFile>
namespace Ui {
class remouveFile;
}

class remouveFile : public QDialog
{
    Q_OBJECT

public:
    explicit remouveFile(QList<QMap<QString, QString> > &ref, QWidget *parent = nullptr);
    ~remouveFile();
public slots:
private slots:
    void on_delete10message_clicked();
    void on_deleteAllMessage_clicked();
    void on_deleteNMessage_editingFinished();
    void remouveOnFile(int NumberOfRemouve);
    void on_pushButton_clicked();

private:
    QList<QMap<QString, QString>>* listeOfMessage;
    Ui::remouveFile *ui;
};

#endif // REMOUVEFILE_H
