/********************************************************************************
** Form generated from reading UI file 'redactormainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDACTORMAINWINDOW_H
#define UI_REDACTORMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_redactorMainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frameTitle;
    QPushButton *pushButton_file;
    QPushButton *pushButton_font;
    QFrame *dividingLine_2;
    QPushButton *pushButton_paragraph;
    QFrame *frameCentral;
    QFrame *frameSearch;
    QLineEdit *lineEdit_search;
    QLabel *labelSearchWindowTitle;
    QFrame *frameFontRedactor;
    QLabel *labelFontRedactorTitle;
    QComboBox *comboBox_fonts;
    QLabel *labelFontList;
    QFrame *frameBottom;
    QLabel *labelCursorPosition;
    QLabel *labelHint;

    void setupUi(QMainWindow *redactorMainWindow)
    {
        if (redactorMainWindow->objectName().isEmpty())
            redactorMainWindow->setObjectName("redactorMainWindow");
        redactorMainWindow->resize(800, 600);
        centralwidget = new QWidget(redactorMainWindow);
        centralwidget->setObjectName("centralwidget");
        frameTitle = new QFrame(centralwidget);
        frameTitle->setObjectName("frameTitle");
        frameTitle->setGeometry(QRect(10, 40, 621, 31));
        frameTitle->setStyleSheet(QString::fromUtf8("background-color: #687a91;"));
        frameTitle->setFrameShape(QFrame::Shape::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_file = new QPushButton(frameTitle);
        pushButton_file->setObjectName("pushButton_file");
        pushButton_file->setGeometry(QRect(0, 0, 80, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font.setPointSize(13);
        font.setBold(false);
        pushButton_file->setFont(font);
        pushButton_file->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #687a91;\n"
"	border: none;\n"
"	color: white;\n"
"	border-top-right-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #d4dae2;\n"
"	border: none;\n"
"	color: #687a91;\n"
"	border-top-right-radius: 5px;\n"
"}"));
        pushButton_font = new QPushButton(frameTitle);
        pushButton_font->setObjectName("pushButton_font");
        pushButton_font->setGeometry(QRect(130, 0, 80, 24));
        pushButton_font->setFont(font);
        pushButton_font->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_font->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #687a91;\n"
"	border: none;\n"
"	color: white;\n"
"	border-top-right-radius: 0px;\n"
"	border-top-left-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #d4dae2;\n"
"	border: none;\n"
"	color: #687a91;\n"
"	border-top-right-radius: 5px;\n"
"	border-top-left-radius: 5px;\n"
"}"));
        dividingLine_2 = new QFrame(frameTitle);
        dividingLine_2->setObjectName("dividingLine_2");
        dividingLine_2->setGeometry(QRect(220, 10, 16, 16));
        dividingLine_2->setStyleSheet(QString::fromUtf8("color:  #d4dae2;\n"
"background-color: #d4dae2;\n"
""));
        dividingLine_2->setFrameShape(QFrame::Shape::StyledPanel);
        dividingLine_2->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_paragraph = new QPushButton(frameTitle);
        pushButton_paragraph->setObjectName("pushButton_paragraph");
        pushButton_paragraph->setGeometry(QRect(260, 0, 80, 24));
        pushButton_paragraph->setFont(font);
        pushButton_paragraph->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_paragraph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #687a91;\n"
"	border: none;\n"
"	color: white;\n"
"	border-top-right-radius: 0px;\n"
"	border-top-left-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #d4dae2;\n"
"	border: none;\n"
"	color: #687a91;\n"
"	border-top-right-radius: 5px;\n"
"	border-top-left-radius: 5px;\n"
"}"));
        frameCentral = new QFrame(centralwidget);
        frameCentral->setObjectName("frameCentral");
        frameCentral->setGeometry(QRect(20, 90, 611, 351));
        frameCentral->setStyleSheet(QString::fromUtf8("background-color: #d4dae2"));
        frameCentral->setFrameShape(QFrame::Shape::StyledPanel);
        frameCentral->setFrameShadow(QFrame::Shadow::Raised);
        frameSearch = new QFrame(frameCentral);
        frameSearch->setObjectName("frameSearch");
        frameSearch->setGeometry(QRect(480, 10, 120, 80));
        frameSearch->setStyleSheet(QString::fromUtf8("background-color: rgba(104, 122, 145, 100);\n"
"border-radius: 5px;"));
        frameSearch->setFrameShape(QFrame::Shape::StyledPanel);
        frameSearch->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_search = new QLineEdit(frameSearch);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(0, 40, 113, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font1.setPointSize(10);
        font1.setBold(false);
        lineEdit_search->setFont(font1);
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border-radius: 0px;\n"
"border-bottom: 1px solid white;"));
        lineEdit_search->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelSearchWindowTitle = new QLabel(frameSearch);
        labelSearchWindowTitle->setObjectName("labelSearchWindowTitle");
        labelSearchWindowTitle->setGeometry(QRect(10, 10, 101, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font2.setPointSize(12);
        font2.setUnderline(true);
        labelSearchWindowTitle->setFont(font2);
        labelSearchWindowTitle->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border-radius: 0px;"));
        labelSearchWindowTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frameFontRedactor = new QFrame(frameCentral);
        frameFontRedactor->setObjectName("frameFontRedactor");
        frameFontRedactor->setGeometry(QRect(0, 30, 201, 131));
        frameFontRedactor->setStyleSheet(QString::fromUtf8("background-color: rgba(104, 122, 145, 100);\n"
"border-radius: 5px;"));
        frameFontRedactor->setFrameShape(QFrame::Shape::StyledPanel);
        frameFontRedactor->setFrameShadow(QFrame::Shadow::Raised);
        labelFontRedactorTitle = new QLabel(frameFontRedactor);
        labelFontRedactorTitle->setObjectName("labelFontRedactorTitle");
        labelFontRedactorTitle->setGeometry(QRect(10, 10, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(false);
        labelFontRedactorTitle->setFont(font3);
        labelFontRedactorTitle->setStyleSheet(QString::fromUtf8("/*background-color: #687a91;*/\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #687a91, stop: 1 transparent);\n"
"color: white;\n"
"border-radius: 0px;\n"
"border-top-right-radius: 5px;\n"
"border-top-left-radius: 5px;"));
        labelFontRedactorTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox_fonts = new QComboBox(frameFontRedactor);
        comboBox_fonts->setObjectName("comboBox_fonts");
        comboBox_fonts->setGeometry(QRect(10, 50, 131, 24));
        QFont font4;
        font4.setBold(false);
        comboBox_fonts->setFont(font4);
        comboBox_fonts->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"                border: 1px solid white;\n"
"                border-radius: 4px;\n"
"                padding: 5px;\n"
"                background-color: transparent;\n"
"                color: white;\n"
"                font-size: 15px;\n"
"            }\n"
"            QComboBox::drop-down {\n"
"                border: 0px;\n"
"                width: 20px;\n"
"                height: 20px;\n"
"            }\n"
"            QComboBox::down-arrow {\n"
"                image: url(:/icons/downArrow.png);\n"
"                width: 10px;\n"
"                height: 10px;\n"
"            }\n"
"            QComboBox QAbstractItemView {\n"
"                border: 1px solid #ccc;\n"
"                border-radius: 4px;\n"
"                background-color: #fff;\n"
"                color: #333;\n"
"                font-size: 15px;\n"
"                selection-background-color: #e0e0e0;\n"
"            }"));
        labelFontList = new QLabel(frameFontRedactor);
        labelFontList->setObjectName("labelFontList");
        labelFontList->setGeometry(QRect(120, 60, 71, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font5.setPointSize(11);
        font5.setBold(true);
        labelFontList->setFont(font5);
        labelFontList->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
""));
        labelFontList->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        frameBottom = new QFrame(centralwidget);
        frameBottom->setObjectName("frameBottom");
        frameBottom->setGeometry(QRect(59, 460, 261, 80));
        frameBottom->setStyleSheet(QString::fromUtf8("background-color:  #687a91;"));
        frameBottom->setFrameShape(QFrame::Shape::StyledPanel);
        frameBottom->setFrameShadow(QFrame::Shadow::Raised);
        labelCursorPosition = new QLabel(frameBottom);
        labelCursorPosition->setObjectName("labelCursorPosition");
        labelCursorPosition->setGeometry(QRect(10, 40, 81, 16));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font6.setPointSize(10);
        font6.setBold(true);
        labelCursorPosition->setFont(font6);
        labelCursorPosition->setStyleSheet(QString::fromUtf8("color: white;"));
        labelHint = new QLabel(frameBottom);
        labelHint->setObjectName("labelHint");
        labelHint->setGeometry(QRect(150, 40, 81, 16));
        labelHint->setFont(font6);
        labelHint->setStyleSheet(QString::fromUtf8("color: white;"));
        labelHint->setAlignment(Qt::AlignmentFlag::AlignCenter);
        redactorMainWindow->setCentralWidget(centralwidget);

        retranslateUi(redactorMainWindow);

        QMetaObject::connectSlotsByName(redactorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *redactorMainWindow)
    {
        redactorMainWindow->setWindowTitle(QCoreApplication::translate("redactorMainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        pushButton_file->setText(QCoreApplication::translate("redactorMainWindow", "\320\244\320\220\320\231\320\233", nullptr));
        pushButton_font->setText(QCoreApplication::translate("redactorMainWindow", "\320\250\320\240\320\230\320\244\320\242", nullptr));
        pushButton_paragraph->setText(QCoreApplication::translate("redactorMainWindow", "\320\220\320\221\320\227\320\220\320\246", nullptr));
        labelSearchWindowTitle->setText(QCoreApplication::translate("redactorMainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        labelFontRedactorTitle->setText(QCoreApplication::translate("redactorMainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\210\321\200\320\270\321\204\321\202\320\260", nullptr));
        labelFontList->setText(QCoreApplication::translate("redactorMainWindow", "\320\250\321\200\320\270\321\204\321\202:", nullptr));
        labelCursorPosition->setText(QCoreApplication::translate("redactorMainWindow", "\320\241\321\202\321\200 1, \321\201\321\202\320\273\320\261 1", nullptr));
        labelHint->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class redactorMainWindow: public Ui_redactorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDACTORMAINWINDOW_H
