#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "ui_auth.h"
#include "QFileDialog"
#include <QTextDocumentWriter>

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(About_Lab1()));
    QAction *pactOpen = new QAction("File open action", 0);
    pactOpen -> setText("Открыть");
    pactOpen -> setShortcut(QKeySequence("CTRL+O"));
    pactOpen -> setToolTip("Открытие документа");
    pactOpen -> setStatusTip("Открыть файл");
    pactOpen -> setWhatsThis("Открыть файл");
    connect(pactOpen, SIGNAL(triggered()), SLOT(SlotOpen()));
    QMenu* pmnuFile=new QMenu("&Файл");
    pmnuFile->addAction(pactOpen);
    menuBar()->addMenu(pmnuFile);
    QAction* pactSave = new QAction("File save action", 0);
    pactSave -> setText("Сохранить");
    pactSave -> setShortcut(QKeySequence("CTRL+S"));
    pactSave -> setToolTip("Сохранение документа");
    pactSave -> setStatusTip("Сохранить файл");
    pactSave -> setWhatsThis("Сохранить файл");
    connect(pactSave, SIGNAL(triggered()), SLOT(SlotSave()));
    pmnuFile->addAction(pactSave);
    menuBar()->addMenu(pmnuFile);
    QAction* pactClear = new QAction("File clear action", 0);
    pactClear -> setText("Очистить");
    pactClear -> setShortcut(QKeySequence("CTRL+Q"));
    pactClear -> setToolTip("Очистить");
    pactClear -> setStatusTip("Очистить");
    pactSave -> setWhatsThis("Очистить");
    connect(pactClear, SIGNAL(triggered()), SLOT(SlotClear()));
    pmnuFile->addAction(pactClear);
    menuBar()->addMenu(pmnuFile);
}

void MainWindow::SlotSave()
{
    QString filename = QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath());
    QTextDocumentWriter writer;
    writer.setFileName(filename);
    writer.write(ui->textEdit->document());
}

void MainWindow::SlotOpen()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", QDir::currentPath());
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    ui -> textEdit -> setPlainText(file.readAll());
}

void MainWindow::SlotClear()
{
     ui->textEdit->clear();

}



MainWindow::~MainWindow()
{
    delete ui;
}

