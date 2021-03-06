#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>

class SM_ComboBox : public QComboBox
{
public:
    SM_ComboBox(int w = 210, int h = 24, QWidget *parent = 0);

protected:
    void hidePopup(void);

public:
    void init(void);
    void resizeEvent(QResizeEvent *e);
    int width;
    int height;
};

#endif // COMBOBOX_H
