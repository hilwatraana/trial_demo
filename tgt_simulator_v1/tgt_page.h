#ifndef TGT_PAGE_H
#define TGT_PAGE_H

#include <QWidget>

namespace Ui {
class tgt_page;
}

class tgt_page : public QWidget
{
    Q_OBJECT

public:
    explicit tgt_page(QWidget *parent = nullptr);
    ~tgt_page();

private slots:
    void on_save_pushButton_pressed();

    void on_clear_pushButton_pressed();

    void on_tgttype_comboBox_currentIndexChanged(int index);

private:
    Ui::tgt_page *ui;
};

#endif // TGT_PAGE_H
