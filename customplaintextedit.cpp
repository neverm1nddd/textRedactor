#include "customplaintextedit.h"

customPlainTextEdit::customPlainTextEdit(QWidget *parent)
    : QPlainTextEdit{parent}
{
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(_on_cursorPositionChanged()));

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(15);
    effect->setXOffset(0);
    effect->setYOffset(0);
    effect->setColor(QColor(50,50,50,120));

    this->setGraphicsEffect(effect);

    this->setStyleSheet("QPlainTextEdit { padding-left:10; padding-top:10; padding-bottom:10; padding-right:10; background-color: white; border-radius: 5px;}");

    QFont initialFont("Arial", 14);
    this->setFont(initialFont);
}

void customPlainTextEdit::wheelEvent(QWheelEvent *event)
{
    QWheelEvent *wheel = static_cast<QWheelEvent*>(event);
    if ( wheel->modifiers() == Qt::CTRL)
    {
        if (wheel->angleDelta().y() > 0)
            this->zoomIn(2);
        else
            this->zoomOut(2);

        event->accept();
    }
}

void customPlainTextEdit::_on_zoomIn()
{
    this->zoomIn(2);
}

void customPlainTextEdit::_on_zoomOut()
{
    this->zoomOut(2);
    this->setExtraSelections(QList<QTextEdit::ExtraSelection>());
}

void customPlainTextEdit::_on_cursorPositionChanged()
{
    emit cursorPositionChanged(this->textCursor().blockNumber() + 1, this->textCursor().positionInBlock() + 1);
}

void customPlainTextEdit::_on_searchText(QString searchText)
{
    QTextCursor cursor = this->textCursor();
    cursor.movePosition(QTextCursor::MoveOperation::Start);

    QList<QTextEdit::ExtraSelection> selections;
    found_positions.clear();
    while (true) {
        cursor = this->document()->find(searchText, cursor);
        if (cursor.isNull()) {
            break;
        }
        QTextEdit::ExtraSelection selection;
        selection.cursor = cursor;
        selection.format.setBackground(QColor(Qt::yellow));
        selections.append(selection);
        found_positions.push_back(cursor.position());
        cursor.movePosition(QTextCursor::MoveOperation::NextWord);
    }

    if (!selections.isEmpty()) {
        this->setExtraSelections(selections);
        moveCursorToNextPosition();
    } else {
        qDebug() << "Текст не найден";
    }
}

void customPlainTextEdit::_on_clearSelections()
{
    this->setExtraSelections(QList<QTextEdit::ExtraSelection>());
    found_positions.clear();
    current_position_index = 0;
}

void customPlainTextEdit::_on_setFontBold(bool state)
{
    QTextCursor cursor = this->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontWeight(state ? QFont::Bold : QFont::Normal);
    cursor.setCharFormat(charFormat);
    this->setCurrentCharFormat(charFormat);
}

void customPlainTextEdit::_on_setFontItalic(bool state)
{
    QTextCursor cursor = this->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontItalic(state);
    cursor.setCharFormat(charFormat);
    this->setCurrentCharFormat(charFormat);
}

void customPlainTextEdit::_on_setFontUnderline(bool state)
{
    QTextCursor cursor = this->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontUnderline(state);
    cursor.setCharFormat(charFormat);
    this->setCurrentCharFormat(charFormat);
}

void customPlainTextEdit::_on_setNewFont(QString newFontStr)
{

    QTextCursor cursor = this->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontFamily(newFontStr);
    cursor.setCharFormat(charFormat);
    this->setCurrentCharFormat(charFormat);
}

void customPlainTextEdit::moveCursorToNextPosition() {
    if (!found_positions.empty()) {
        current_position_index = (current_position_index + 1) % found_positions.size();
        QTextCursor cursor = this->textCursor();
        cursor.setPosition(found_positions[current_position_index]);
        this->setTextCursor(cursor);
    }
}
