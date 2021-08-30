#ifndef REMOUVEFILE_H
#define REMOUVEFILE_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
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

private:
    QList<QMap<QString, QString>>* listeOfMessage;
    Ui::remouveFile *ui;
};

#endif // REMOUVEFILE_H
