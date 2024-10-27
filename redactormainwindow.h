#ifndef REDACTORMAINWINDOW_H
#define REDACTORMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QResizeEvent>
#include <QFile>
#include <QByteArray>
#include <QPropertyAnimation>
#include <QTextCharFormat>

#include "_colors.h"
#include "_fonts.h"
#include "_enums.h"
#include "_size.h"

#include "custombutton.h"
#include "customplaintextedit.h"

using namespace COLORS;
using namespace FONTS;
using namespace ENUMS;
using namespace SIZE;

QT_BEGIN_NAMESPACE
namespace Ui {
class redactorMainWindow;
}
QT_END_NAMESPACE

class redactorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    redactorMainWindow(QWidget *parent = nullptr);
    ~redactorMainWindow();

protected:
    void resizeEvent(QResizeEvent *event);

public slots:
    void _on_cursorPositionChanged(int line, int column);
    void _on_showHint(QString hint);
    void _on_showSearchWindow();
    void _on_hideSearchWindow();
    void _on_pushButton_searchApply_clicked();
    void _on_animateFrameFont();

private:
    qreal getYBottomPos(QWidget *w);
    qreal getXRightPos(QWidget *w);
    void setStyleSheetToWidget();
    void loadButton();
    void createConnectWithPlainTextEdit();
    void createConnectWithButtons();
    void loadDataToComboBoxFonts();

    customButton *buttonSearch;
    customButton *buttonCloseSearchWindow;
    customButton *buttonSearchApply;

    customButton *buttonZoomIn;
    customButton *buttonZoomOut;

    customButton *buttonBack;
    customButton *buttonForward;

    customButton *buttonBold;
    customButton *buttonItalic;
    customButton *buttonUnderline;

    customPlainTextEdit *plainTextEdit;

    Ui::redactorMainWindow *ui;

signals:
    void searchText(QString searchText);
};
#endif // REDACTORMAINWINDOW_H
