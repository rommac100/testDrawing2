#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class RenderArea;
namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_lengthText_textChanged(const QString &arg1);

    void on_heightText_textChanged(const QString &arg1);

    void on_widthText_textChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
