#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

#include "_enums.h"

using namespace ENUMS;

class customButton : public QPushButton
{
    Q_OBJECT
public:
    explicit customButton(int bType_, QWidget *parent = nullptr);
    void setActive();
    bool isActive();

protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int bType;
    bool active;

signals:
    void showHint(QString hint);
    void setFontBold(bool state);
    void setFontItalic(bool state);
    void setFontUnderline(bool state);
};

#endif // CUSTOMBUTTON_H
