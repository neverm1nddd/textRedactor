#ifndef CUSTOMPLAINTEXTEDIT_H
#define CUSTOMPLAINTEXTEDIT_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QWheelEvent>
#include <QUndoStack>
#include <QGraphicsDropShadowEffect>

class customPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit customPlainTextEdit(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event);

public slots:
    void _on_zoomIn();
    void _on_zoomOut();
    void _on_cursorPositionChanged();
    void _on_searchText(QString searchText);
    void _on_clearSelections();
    void _on_setFontBold(bool state);
    void _on_setFontItalic(bool state);
    void _on_setFontUnderline(bool state);

private:
    void moveCursorToNextPosition();
    std::vector<int> found_positions;
    int current_position_index = 0;

signals:
    void cursorPositionChanged(int line, int column);
};

#endif // CUSTOMPLAINTEXTEDIT_H
