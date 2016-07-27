#ifndef QTCAMER_H
#define QTCAMER_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QString>
#include <QPixmap>


namespace Ui {
class QtCamer;
}

class QtCamer : public QWidget
{
    Q_OBJECT

public:
    explicit QtCamer(QWidget *parent = 0);
    ~QtCamer();
public slots:
    void Captured();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QtCamer *ui;
    QCamera *cCamera;
    QCameraViewfinder *cViewfinder;
    QCameraImageCapture *cImgCap;



};

#endif // QTCAMER_H
