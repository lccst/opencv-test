/********************************************************************************
** Form generated from reading UI file 'testopencv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOPENCV_H
#define UI_TESTOPENCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testOpenCV
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testOpenCV)
    {
        if (testOpenCV->objectName().isEmpty())
            testOpenCV->setObjectName(QStringLiteral("testOpenCV"));
        testOpenCV->resize(400, 300);
        centralWidget = new QWidget(testOpenCV);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 60, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 120, 99, 27));
        testOpenCV->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testOpenCV);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        testOpenCV->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testOpenCV);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testOpenCV->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testOpenCV);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testOpenCV->setStatusBar(statusBar);

        retranslateUi(testOpenCV);

        QMetaObject::connectSlotsByName(testOpenCV);
    } // setupUi

    void retranslateUi(QMainWindow *testOpenCV)
    {
        testOpenCV->setWindowTitle(QApplication::translate("testOpenCV", "testOpenCV", 0));
        pushButton->setText(QApplication::translate("testOpenCV", "load", 0));
        pushButton_2->setText(QApplication::translate("testOpenCV", "process", 0));
    } // retranslateUi

};

namespace Ui {
    class testOpenCV: public Ui_testOpenCV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOPENCV_H
