#ifndef TESTOPENCV_H
#define TESTOPENCV_H

#include <QMainWindow>
#include <QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class testOpenCV;
}

class testOpenCV : public QMainWindow
{
    Q_OBJECT

public:
    explicit testOpenCV(QWidget *parent = 0);
    ~testOpenCV();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::testOpenCV *ui;
    cv::Mat image;
};

#endif // TESTOPENCV_H
