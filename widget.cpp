#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>


void Widget::paintEvent(QPaintEvent *event)
{
//    qDebug()<<__FUNCTION__;
//    QPainter painter(this);//创建QPainter对象
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setRenderHint(QPainter::TextAntialiasing);
//    int W = this->width();//绘图区宽度
//    int H = this->height();//绘图区高度
//    QRect rect(W/4, H/4, W/2, H/2);//中间区域矩形框
//    //设置画笔
//    QPen pen;
//    pen.setWidth(3);//线宽
//    pen.setColor(Qt::red);//划线颜色
//    pen.setStyle(Qt::SolidLine);//线的样式，比如实线，虚线等
//    pen.setCapStyle(Qt::FlatCap);//终端点样式
//    pen.setJoinStyle(Qt::BevelJoin);//线的连接点样式
//    painter.setPen(pen);
//    //设置画刷
//    QBrush brush;
////    brush.setColor(Qt::green);//画刷颜色
////    brush.setStyle(Qt::SolidPattern);//画刷填充样式
//    QPixmap texturePixmap(":image/image/actCascade.PNG");
//    brush.setStyle(Qt::TexturePattern);//画刷填充样式
//    brush.setTexture(texturePixmap);
//    painter.setBrush(brush);
//    //绘图
//    painter.drawRect(rect);

//    //辐射渐变
//    QPainter painter(this);
//    int W = this->width();
//    int H = this->height();
//    QRadialGradient radialGrad(W/2, H/2, qMax(W/8, H/8), W/2, H/2);
//    radialGrad.setColorAt(0, Qt::green);
//    radialGrad.setColorAt(1, Qt::blue);
//    radialGrad.setSpread(QGradient::ReflectSpread);
//    painter.setBrush(radialGrad);
//    //绘图
//    painter.drawRect(this->rect());

    //线性渐变
    QPainter painter(this);
    QLinearGradient linearGrad(this->rect().left(), this->rect().top(), this->rect().right(), this->rect().bottom());//左上角和右下角
    //QLinearGradient linearGrad
    linearGrad.setColorAt(0, Qt::green);
    linearGrad.setColorAt(1, Qt::blue);
    painter.setBrush(linearGrad);
    painter.drawRect(this->rect());


}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setPalette(QPalette(Qt::yellow));//设置窗口绘图区域的背景
   // qDebug()<<autoFillBackground();
    this->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}
