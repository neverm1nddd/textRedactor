#include "redactormainwindow.h"
#include "ui_redactormainwindow.h"

redactorMainWindow::redactorMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::redactorMainWindow)
{
    ui->setupUi(this);

    this->setMinimumWidth(APP_MINIMUM_WIDTH);
    this->setMinimumHeight(APP_MINIMUM_HEIGHT);

    setStyleSheetToWidget();

    loadButton();
    createConnectWithButtons();

    plainTextEdit = new customPlainTextEdit(ui->frameCentral);
    createConnectWithPlainTextEdit();

    ui->frameSearch->setVisible(false);
    ui->frameFontRedactor->hide();

    loadDataToComboBoxFonts();
    createConnectWithUiWidgets();

    // QFile file1("C:/Users/User/Desktop/doc.txt"); // создаем объект класса QFile
    // QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    // if (!file1.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
    //     return; // если это сделать невозможно, то завершаем функцию
    // data = file1.readAll(); //считываем все данные с файла в объект data
    // plainTextEdit->appendPlainText(QString(data));
}

redactorMainWindow::~redactorMainWindow()
{
    delete ui;
}


void redactorMainWindow::setStyleSheetToWidget()
{

}

void redactorMainWindow::loadButton()
{
    buttonSearch = new customButton(eButtonType_search, ui->frameTitle);
    buttonCloseSearchWindow = new customButton(eButtonType_close, ui->frameSearch);
    buttonSearchApply = new customButton(eButtonType_searchApply, ui->frameSearch);

    buttonZoomIn = new customButton(eButtonType_zoomIn, ui->frameBottom);
    buttonZoomOut = new customButton(eButtonType_zoomOut, ui->frameBottom);

    buttonBack = new customButton(eButtonType_back, ui->frameBottom);
    buttonForward = new customButton(eButtobType_forward, ui->frameBottom);

    buttonBold = new customButton(eButtonType_fontBold, ui->frameFontRedactor);
    buttonItalic = new customButton(eButtonType_fontItalic, ui->frameFontRedactor);
    buttonUnderline = new customButton(eButtonType_fontUnderLine, ui->frameFontRedactor);
}

void redactorMainWindow::createConnectWithPlainTextEdit()
{
    connect(buttonZoomIn, SIGNAL(clicked(bool)), plainTextEdit, SLOT(_on_zoomIn()));
    connect(buttonZoomOut, SIGNAL(clicked(bool)), plainTextEdit, SLOT(_on_zoomOut()));
    connect(plainTextEdit, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(_on_cursorPositionChanged(int,int)));
    connect(buttonBack, SIGNAL(clicked(bool)), plainTextEdit, SLOT(undo()));
    connect(buttonForward, SIGNAL(clicked(bool)), plainTextEdit, SLOT(redo()));
    connect(this, SIGNAL(searchText(QString)), plainTextEdit, SLOT(_on_searchText(QString)));
    connect(buttonCloseSearchWindow, SIGNAL(clicked(bool)), plainTextEdit, SLOT(_on_clearSelections()));
    connect(ui->pushButton_font, SIGNAL(clicked(bool)), this, SLOT(_on_animateFrameFont()));
    connect(buttonBold, SIGNAL(setFontBold(bool)), plainTextEdit, SLOT(_on_setFontBold(bool)));
    connect(buttonItalic, SIGNAL(setFontItalic(bool)), plainTextEdit, SLOT(_on_setFontItalic(bool)));
    connect(buttonUnderline, SIGNAL(setFontUnderline(bool)), plainTextEdit, SLOT(_on_setFontUnderline(bool)));
}

void redactorMainWindow::createConnectWithButtons()
{
    connect(buttonSearch, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonZoomIn, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonZoomOut, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonBack, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonForward, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonCloseSearchWindow, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonSearchApply, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonSearchApply, SIGNAL(clicked(bool)), this, SLOT(_on_pushButton_searchApply_clicked()));
    connect(buttonSearch, SIGNAL(clicked(bool)), this, SLOT(_on_showSearchWindow()));
    connect(buttonCloseSearchWindow, SIGNAL(clicked(bool)), this, SLOT(_on_hideSearchWindow()));
    connect(buttonBold, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonItalic, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
    connect(buttonUnderline, SIGNAL(showHint(QString)), this, SLOT(_on_showHint(QString)));
}

void redactorMainWindow::createConnectWithUiWidgets()
{
    connect(ui->comboBox_fonts, SIGNAL(currentTextChanged(QString)), this, SLOT(_on_comboBoxTextChanged(QString)));
}

void redactorMainWindow::loadDataToComboBoxFonts()
{
    QFontDatabase fontDatabase;
    QStringList fontFamilies = fontDatabase.families();
    ui->comboBox_fonts->addItems(fontFamilies);
    ui->comboBox_fonts->setCurrentText("Arial");
}

void redactorMainWindow::resizeEvent(QResizeEvent *event)
{
    QSize windowSize = event->size();

    qreal windowWidth = windowSize.width();
    qreal windowHeight = windowSize.height();

    qreal topAndBottomFrameHeight = windowHeight / TOP_AND_BOTTOM_FRAME_PARTS;

    //ОСНОВНЫЕ ФРЕЙМЫ
    ui->frameTitle->setGeometry(0, 0, windowWidth, topAndBottomFrameHeight);
    ui->frameCentral->setGeometry(0, getYBottomPos(ui->frameTitle), windowWidth, windowHeight - 1.5*topAndBottomFrameHeight);
    ui->frameBottom->setGeometry(0, getYBottomPos(ui->frameCentral), windowWidth, topAndBottomFrameHeight/2 + 2);

    //ЭЛЕМЕНТЫ НА ВЕРХНЕМ ФРЕЙМЕ
    ui->pushButton_file->setGeometry(0, PUSH_BUTTON_VERTICAL_GAP, windowWidth/PUSH_BUTTON_FILE_WIDTH, ui->frameTitle->height() - PUSH_BUTTON_VERTICAL_GAP);
    ui->pushButton_font->setFixedSize(windowWidth/PUSH_BUTTON_FONT_WIDTH, ui->frameTitle->height() - PUSH_BUTTON_VERTICAL_GAP);
    ui->pushButton_font->move(ui->frameTitle->width()/2 - ui->pushButton_font->width(), PUSH_BUTTON_VERTICAL_GAP);
    ui->dividingLine_2->setGeometry(getXRightPos(ui->pushButton_font) + DIVIDING_LINES_HORIZONTAL_GAP, DIVIDING_LINES_VERTICAL_GAP, DIVIDING_LINES_WIDTH, ui->frameTitle->height() - 2*DIVIDING_LINES_VERTICAL_GAP);
    ui->pushButton_paragraph->setGeometry(getXRightPos(ui->dividingLine_2) + DIVIDING_LINES_HORIZONTAL_GAP, PUSH_BUTTON_VERTICAL_GAP, windowWidth/PUSH_BUTTON_PARAGRAPH_WIDTH, ui->frameTitle->height() - PUSH_BUTTON_VERTICAL_GAP);
    buttonSearch->move(getXRightPos(ui->frameTitle) - buttonSearch->width() - 5*PUSH_BUTTON_VERTICAL_GAP, ui->frameTitle->height()/2 - buttonSearch->height()/2);

    //ЭЛЕМЕНТЫ ЦЕНТРАЛЬНОГО ФРЕЙМА
    plainTextEdit->setGeometry(ui->frameCentral->width()/PLAIN_TEXT_EDIT_HORIZONTAL_GAP, PLAIN_TEXT_EDIT_VERTICAL_GAP, ui->frameCentral->width() - 2*ui->frameCentral->width()/PLAIN_TEXT_EDIT_HORIZONTAL_GAP, ui->frameCentral->height() - 2*PLAIN_TEXT_EDIT_VERTICAL_GAP);

    //ЭЛЕМЕНТЫ НИЖНЕГО ФРЕЙМА
    buttonZoomOut->move(ui->frameBottom->width() - buttonZoomOut->width() - PUSH_BUTTON_ZOOM_GAP, ui->frameBottom->height()/2 - buttonZoomOut->height()/2);
    buttonZoomIn->move(buttonZoomOut->x() - buttonZoomIn->width() - PUSH_BUTTON_ZOOM_GAP, ui->frameBottom->height()/2 - buttonZoomIn->height()/2);
    buttonForward->move(buttonZoomIn->x() - buttonZoomIn->width() - 3*PUSH_BUTTON_ZOOM_GAP, ui->frameBottom->height()/2 - buttonForward->height()/2);
    buttonBack->move(buttonForward->x() - buttonForward->width() - PUSH_BUTTON_ZOOM_GAP, ui->frameBottom->height()/2 - buttonZoomIn->height()/2);
    ui->labelCursorPosition->setGeometry(LABEL_CURSOR_POSITION_HORIZONTAL_GAP, 0, ui->frameBottom->width()/LABEL_CURSOR_POSITION_WIDTH, ui->frameBottom->height());
    ui->labelHint->setGeometry(ui->frameBottom->width()/2 - ui->labelHint->width()/2, 0, ui->frameBottom->width()/LABEL_HINT_WIDTH, ui->frameBottom->height());

    //ФРЕЙМ ПОИСКА ТЕКСТА И ЕГО ЭЛЕМЕНТЫ
    ui->frameSearch->setFixedSize(ui->frameCentral->width()/8, ui->frameCentral->height()/10);
    ui->frameSearch->move(ui->frameCentral->width() - ui->frameSearch->width() - FRAME_SEARCH_GAP, FRAME_SEARCH_GAP);
    buttonCloseSearchWindow->move(ui->frameSearch->width() - buttonCloseSearchWindow->width() - PUSH_BUTTON_CLOSE_SEARCH_GAP, PUSH_BUTTON_CLOSE_SEARCH_GAP);
    ui->lineEdit_search->setGeometry(LINE_EDIT_SEARCH_LEFT_GAP, ui->frameSearch->height()/2, ui->frameSearch->width() - LINE_EDIT_SEARCH_LEFT_GAP - LINE_EDIT_SEARCH_RIGHT_GAP, buttonSearchApply->height());
    buttonSearchApply->move(getXRightPos(ui->lineEdit_search) + PUSH_BUTTON_CLOSE_SEARCH_GAP, ui->lineEdit_search->y());
    ui->labelSearchWindowTitle->move(ui->frameSearch->width()/2 - ui->labelSearchWindowTitle->width()/2, PUSH_BUTTON_CLOSE_SEARCH_GAP);

    //ФРЕЙМ РЕДАКТОРА ШРИФТА И ЕГО ЭЛЕМЕНТЫ
    ui->frameFontRedactor->setFixedSize(ui->frameCentral->width()/FRAME_FONT_REDACTOR_WIDTH, ui->frameCentral->height()/FRAME_FONT_REDACTOR_HEIGHT);
    ui->frameFontRedactor->move(FRAME_FONT_REDACTOR_X_POS, ui->frameCentral->height()/2 - ui->frameFontRedactor->height()/2);
    ui->labelFontRedactorTitle->setGeometry(0, 0, ui->frameFontRedactor->width(), ui->frameFontRedactor->height()/LABEL_FRAME_FRONT_TITLE_HEIGHT);
    buttonBold->move(ui->frameFontRedactor->width()/4 - buttonBold->width()/2, 2*ui->frameFontRedactor->height()/LABEL_FRAME_FRONT_TITLE_HEIGHT - buttonBold->height()/2);
    buttonItalic->move(2*ui->frameFontRedactor->width()/4 - buttonBold->width()/2, buttonBold->y());
    buttonUnderline->move(3*ui->frameFontRedactor->width()/4 - buttonBold->width()/2, buttonBold->y());
    ui->labelFontList->setGeometry(LABEL_FONT_LIST_HORIZONTAL_GAP, 3*ui->frameFontRedactor->height()/LABEL_FRAME_FRONT_TITLE_HEIGHT - ui->labelFontList->height()/2, ui->frameFontRedactor->width()/4, LABEL_FONT_LIST_HEIGHT);
    ui->comboBox_fonts->setGeometry(getXRightPos(ui->labelFontList) + LABEL_FONT_LIST_HORIZONTAL_GAP, ui->labelFontList->y(), ui->frameFontRedactor->width() - 3*LABEL_FONT_LIST_HORIZONTAL_GAP - ui->labelFontList->width(), ui->labelFontList->height());
}

void redactorMainWindow::_on_cursorPositionChanged(int line, int column)
{
    ui->labelCursorPosition->setText(QString("Стр %1, стлб %2").arg(QString::number(line), QString::number(column)));
}

void redactorMainWindow::_on_showHint(QString hint)
{
    ui->labelHint->setText(hint);
}

void redactorMainWindow::_on_showSearchWindow()
{
    ui->frameSearch->setVisible(true);
}

void redactorMainWindow::_on_hideSearchWindow()
{
    ui->frameSearch->setVisible(false);
}

void redactorMainWindow::_on_pushButton_searchApply_clicked()
{
    if(ui->lineEdit_search->text().size() > 0)
        emit searchText(ui->lineEdit_search->text());
}

void redactorMainWindow::_on_animateFrameFont()
{
    if (ui->frameFontRedactor->isHidden()) {
        ui->frameFontRedactor->show();
        ui->frameFontRedactor->setGeometry(-FRAME_FONT_REDACTOR_X_POS - ui->frameFontRedactor->width(), ui->frameFontRedactor->y(), ui->frameFontRedactor->width(), ui->frameFontRedactor->height());
        QPropertyAnimation *animation = new QPropertyAnimation(ui->frameFontRedactor, "geometry");
        animation->setDuration(250);
        animation->setStartValue(QRect(-FRAME_FONT_REDACTOR_X_POS - ui->frameFontRedactor->width(), ui->frameFontRedactor->y(), ui->frameFontRedactor->width(), ui->frameFontRedactor->height()));
        animation->setEndValue(QRect(FRAME_FONT_REDACTOR_X_POS, ui->frameCentral->height()/2 - ui->frameFontRedactor->height()/2, ui->frameFontRedactor->width(), ui->frameFontRedactor->height()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    } else {
        QPropertyAnimation *animation = new QPropertyAnimation(ui->frameFontRedactor, "geometry");
        animation->setDuration(250);
        animation->setStartValue(QRect(FRAME_FONT_REDACTOR_X_POS, ui->frameCentral->height()/2 - ui->frameFontRedactor->height()/2, ui->frameFontRedactor->width(), ui->frameFontRedactor->height()));
        animation->setEndValue(QRect(-FRAME_FONT_REDACTOR_X_POS - ui->frameFontRedactor->width(), ui->frameFontRedactor->y(), ui->frameFontRedactor->width(), ui->frameFontRedactor->height()));
        connect(animation, &QPropertyAnimation::finished, ui->frameFontRedactor, &QFrame::hide);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void redactorMainWindow::_on_comboBoxTextChanged(QString newFontStr)
{
    QFont newFont(newFontStr);
    newFont.setBold(plainTextEdit->font().bold());
    newFont.setItalic(plainTextEdit->font().italic());
    newFont.setUnderline(plainTextEdit->font().underline());
    newFont.setPointSize(plainTextEdit->font().pointSize());

    QTextCursor cursor = plainTextEdit->textCursor();
    QTextCharFormat format;
    format.setFontFamily(newFontStr);
    cursor.setCharFormat(format);
    plainTextEdit->setTextCursor(cursor);
}

qreal redactorMainWindow::getYBottomPos(QWidget *w)
{
    return w->y() + w->height();
}

qreal redactorMainWindow::getXRightPos(QWidget *w)
{
    return w->x() + w->width();
}
