#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtWidgets>
#include <QSvgGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    renderArea = new RenderArea;
    ui->setupUi(this);
    ui->gridLayout_2->addWidget(renderArea, 0, 0, 1, 4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lengthText_textChanged(const QString &arg1)
{

    long double length = ui->lengthText->text().toDouble();
    renderArea->setLength(length);

}

void MainWindow::on_heightText_textChanged(const QString &arg1)
{
    long double height = ui->heightText->text().toDouble();
    renderArea->setHeight(height);
}

void MainWindow::on_widthText_textChanged(const QString &arg1)
{

    long double width = ui->widthText->text().toDouble();
    renderArea->setWidth(width);

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{

    RenderArea::Units units = RenderArea::Units(index);
    renderArea->setUnits(units);

}
//for the downloadSVG
void MainWindow::on_pushButton_clicked()
{

    QString path = QFileDialog::getSaveFileName(this, tr("Save SVG"), tr(".svg"));
    QSvgGenerator generator;
          generator.setFileName(path);
          generator.setSize(QSize(200, 200));
         // generator.setViewBox(QRect(0, 0, 200, 200));
          generator.setTitle(tr("SVG Generator Example Drawing"));
          generator.setDescription(tr("An SVG drawing created by the SVG Generator "
                                      "Example provided with Qt."));

          QPainter painter;
          painter.begin(&generator);
          renderArea->paint(painter);
          painter.end();

}
