#ifndef MOREINFORMATION_H
#define MOREINFORMATION_H

#include <QDialog>

namespace Ui {
class moreinformation;
}

class moreinformation : public QDialog
{
    Q_OBJECT

public:
    explicit moreinformation(QWidget *parent = nullptr);
    ~moreinformation();

private:
    Ui::moreinformation *ui;
};

#endif // MOREINFORMATION_H
