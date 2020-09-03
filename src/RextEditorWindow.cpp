//
// Created by Raymond_Lx on 2020/9/3.
//

#include "RextEditorWindow.h"

#include "ui_RextEditorWindow.h"

#include <QFileDialog>
#include <QDebug>

RextEditorWindow::RextEditorWindow(FileManager &fileManager, QWidget *parent):fileManager(fileManager), QMainWindow(parent),ui(new Ui::RextEditorWindow) {
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &RextEditorWindow::OnQuit);
    connect(ui->actionOpen, &QAction::triggered, this, &RextEditorWindow::OnOpen);
    connect(ui->actionSave, &QAction::triggered, this, &RextEditorWindow::OnSave);
    connect(ui->actionSave_As, &QAction::triggered, this, &RextEditorWindow::OnSaveAs);

    connect(ui->textEdit, &QTextEdit::textChanged, this, &RextEditorWindow::OnTextChanged);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);
#ifdef __APPLE__
    HideTitleBar();
#endif
    statusBar()->hide();


}

RextEditorWindow::~RextEditorWindow() noexcept {
    delete ui;
}

void RextEditorWindow::OnQuit() {
    qApp->exit();
}
void RextEditorWindow::OnOpen() {
    auto path = QFileDialog::getOpenFileName(this, tr("Get your text file!"));
    try {
        ui->textEdit->setText(fileManager.ReadFile(path));
    } catch (FileManager::FileCannotOpenException &e) {
        qDebug()<<e.what();
    }
    fileManager.SetDirty(false);
    UpdateTitle();
}
void RextEditorWindow::OnSave() {
    if(fileManager.GetCurrentFilePath().isEmpty()) OnSaveAs();
    if(fileManager.IsDirty())
        try {
            fileManager.WriteFileAs(fileManager.GetCurrentFilePath(), ui->textEdit->toPlainText());
        }catch (FileManager::FileCannotOpenException &e) {
            qDebug() << e.what();
        }
    UpdateTitle();
}
void RextEditorWindow::OnSaveAs() {
    auto path = QFileDialog::getSaveFileName(this, tr("Choose your text file!"));
    try {
        fileManager.WriteFileAs(path, ui->textEdit->toPlainText());
    }catch (FileManager::FileCannotOpenException &e) {
        qDebug() << e.what();
    }
    UpdateTitle();
}
void RextEditorWindow::OnTextChanged() {
    fileManager.SetDirty();
    UpdateTitle();
}

void RextEditorWindow::UpdateTitle() {
    QString newTitile = PROJECT_NAME;
    if(!fileManager.GetCurrentFilePath().isEmpty())
        newTitile += tr(" - ") + fileManager.GetCurrentFilePath();
    if(fileManager.IsDirty())
        newTitile += '*';
    setWindowTitle(newTitile);
}

