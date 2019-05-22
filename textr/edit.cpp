#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include <QFont>
#include <QPalette>
#include <QColorDialog>

void MainWindow::on_Font_triggered()
{
    bool yes;
    QFont font = QFontDialog::getFont(&yes,this);
    if(yes)
    {
        ui->TextEdit->setFont(font);
    }
    else return;
}

void MainWindow::on_Text_triggered()
{

}

void MainWindow::on_Background_triggered()
{
    QPalette pal(palette());
    QColor Color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (Color.isValid())
    {
    pal.setColor(QPalette::Base, Color);
    ui->TextEdit->setPalette(pal);
    }

}
