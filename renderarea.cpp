/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "renderarea.h"

#include <QPainter>
#include <QPaintEngine>
#include <QSvgGenerator>
#include <math.h>
#include <iostream>
#include <QRectF>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Rect;
    antialiased = false;
    transformed = false;
    unitsMain = Inches;
    pen.setColor(QColor(255, 0, 0, 255));
    pen.setWidth(1);

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(600, 300);
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::setUnits(Units units)
{
    this->unitsMain = units;
    update();
}

void RenderArea::setWidth(long double Width)
{
    std::cout<<"test0"<<std::endl;
    if (unitsMain != Inches)
    {
        this->width2 = Width*89*2.54;
    }
    else
    {
    this->width2 = Width*89;
    }
    std::cout<<width2<<std::endl;
    update();
}

void RenderArea::setHeight(long double Height)
{
    std::cout<<"test1"<<std::endl;
    if (unitsMain != Inches)
    {
        this->height2= Height*89*2.54;
    }
    else
    {
    this->height2 = Height*89;
    }
    std::cout<<height2<<std::endl;
    update();
}

void RenderArea::setLength(long double Length)
{
    std::cout<<"test2"<<std::endl;
    if (unitsMain != Inches)
    {
        this->length= Length*89*2.54;
    }
    else
    {
    this->length = Length*89;
    }
    std::cout<<length<<std::endl;
    update();
}

void RenderArea::paint(QPainter &painter)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    static const QPoint points2[4] = {
      QPoint(20, 160),
      QPoint(40, 20),
        QPoint(160, 60),
        QPoint(180, 140)
    };


   int multipleVal = length+10;



    QRectF rect1(10, 10, length, width2);
    QRectF rect2(10+multipleVal, 10+multipleVal, length, height2);
    QRectF rect3(10+multipleVal*2+1, 10+multipleVal*2+1, height2, width2);
    QRectF rect4(10+multipleVal*3+1, 10+multipleVal*3+1, height2, width2);
    QRectF rect5(10+multipleVal*4+1, 10+multipleVal*4+1, length, width2);
    QRectF rect6(10+multipleVal*5+1, 10+multipleVal*5+1, length, height2);

    QPainterPath path;

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, false);

    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            if (transformed) {
                painter.translate(50, 50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50, -50);
            }

            switch (shape) {
            case Line:
                painter.drawLine(rect1.bottomLeft(), rect1.topRight());
                break;
            case Points:
                painter.drawPoints(points, 4);
                break;
            case Polyline:
                //painter.drawPolyline(points, 4);
                //painter.drawPolyLine(points2, 4);
                break;
            case Polygon:
                if (unitsMain == Inches)
                {
                painter.drawPolygon(points, 4);
                }
                else if (unitsMain == Centimeters)
                {
                painter.drawPolygon(points2, 4);
                }
                break;
            case Rect:

                path.addRect(rect1);
                path.addRect(rect2);
                path.addRect(rect3);
                path.addRect(rect4);
                path.addRect(rect5);
                path.addRect(rect6);
                painter.drawPath(path);
              //  painter.drawRect(rect2);
               // painter.drawRect(rect3);
                //painter.drawRect(rect4);
                //painter.drawRect(rect5);
                //painter.drawRect(rect6);
                /*
                else if (unitsMain == Centimeters)
                {
                    painter.drawRect(rect2);
                }*/
                break;
            case RoundedRect:
                //painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
                break;
            case Ellipse:
                //painter.drawEllipse(rect);
                break;
            case Arc:
                painter.drawArc(rect1, startAngle, arcLength);
                break;
            case Chord:
                painter.drawChord(rect1, startAngle, arcLength);
                break;
            case Pie:
                painter.drawPie(rect1, startAngle, arcLength);
                break;
            case Path:
                painter.drawPath(path);
                break;
            case Text:
                painter.drawText(rect1,
                                 Qt::AlignCenter,
                                 tr("Qt by\nThe Qt Company"));
                break;
            case Pixmap:
                painter.drawPixmap(10, 10, pixmap);
            }
            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
        painter.setPen(palette().dark().color());
        painter.setBrush(Qt::NoBrush);
    //painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}



void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter;
       painter.begin(this);
       painter.setRenderHint(QPainter::Antialiasing);
       paint(painter);
       painter.end();




}
