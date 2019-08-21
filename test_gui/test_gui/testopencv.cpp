#include "testopencv.h"
#include "ui_testopencv.h"


testOpenCV::testOpenCV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testOpenCV)
{
    ui->setupUi(this);
}

testOpenCV::~testOpenCV()
{
    delete ui;
}

void testOpenCV::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                    tr("open images"), ".",
                    tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
    image = cv::imread(fileName.toStdString());
    cv::imshow("new image", image);
}

void testOpenCV::on_pushButton_2_clicked()
{
    cv::flip(image, image, 1);
    cv::imshow("fipped", image);
}
