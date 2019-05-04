#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

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

    void on_Create_triggered();

    void on_Open_triggered();

    void on_Save_triggered();

    void on_Font_triggered();

    void on_Text_triggered();

    void on_To_keep_with_changes_triggered();

    void on_Background_triggered();

private:
    Ui::MainWindow *ui;
    QString Filename;
};

#endif // MAINWINDOW_H
