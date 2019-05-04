#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->TextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}



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
    QFile newFile(Filename);
    if(newFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream ex(&newFile);

        ex << ui->TextEdit->toPlainText();
        newFile.flush();
        newFile.close();
    }
}
