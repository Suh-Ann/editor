#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

void MainWindow::on_Create_triggered()
{
    Filename = "";
    ui->TextEdit->setPlainText("");
}

void MainWindow::on_Open_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open file");
    if(!file.isEmpty())
    {
        Filename = file;
        QFile newFile(file);
        if(newFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream at(&newFile);
            QString text = at.readAll();
            newFile.close();
            ui->TextEdit->setPlainText(text);
        }
    }
}
void MainWindow::on_Save_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save file");
    if(!file.isEmpty())
    {
        Filename = file;
        QFile newFile(file);
        if(newFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&newFile);
            QString text = ui->TextEdit->toPlainText();
            out << text;
            newFile.flush();
            newFile.close();

        }
    }
}

void MainWindow::on_To_keep_with_changes_triggered()
{
    QFile newFile(Filename);
    if(newFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream ex(&newFile);

        ex << ui->TextEdit->toPlainText();
        newFile.flush();
        newFile.close();
    }
}
