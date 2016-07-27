#include "qtcamer.h"
#include "ui_qtcamer.h"

QtCamer::QtCamer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtCamer)
{
    ui->setupUi(this);

    cCamera = new QCamera(this);
    cViewfinder = new QCameraViewfinder(this);

    cViewfinder->show();
    cCamera->setViewfinder(cViewfinder);
    cImgCap = new QCameraImageCapture(cCamera);
    cCamera->setCaptureMode(QCamera::CaptureStillImage);
    cCamera->start();
    //捕获完成产生信号，触发Captured（） 函数，标签2输出 “捕获成功”
    connect(cImgCap,SIGNAL(imageCaptured(int,QImage)),this,SLOT(Captured()));


}

QtCamer::~QtCamer()
{
    delete ui;
}

void QtCamer::on_pushButton_3_clicked()
{
    //截图按钮
    QString Fname="e:/Cap726.jpg";

    if(cImgCap->isReadyForCapture())
    {
        cImgCap->capture(Fname);
    }

}

void QtCamer::on_pushButton_clicked()
{
    //连接按钮

}

void QtCamer::on_pushButton_2_clicked()
{
    //关闭按钮
    //用于关闭窗口
}
void QtCamer::Captured()
{

    ui->label_2->setText("Capture Success!");

    QString Fname="e:/Cap726.jpg";

    QPixmap cQmap(Fname);

    ui->label_3->setPixmap(cQmap);



}
