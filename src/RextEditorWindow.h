//
// Created by Raymond_Lx on 2020/9/3.
//

#ifndef REXTEDITOR_REXTEDITORWINDOW_H
#define REXTEDITOR_REXTEDITORWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>

#include "FileManager.h"

namespace Ui{
    class RextEditorWindow;
}

#define PROJECT_NAME "RextEditorWindow"

class RextEditorWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit RextEditorWindow(FileManager &fileManager, QWidget *parent = nullptr);
    ~RextEditorWindow() noexcept override;
private:
    Ui::RextEditorWindow *ui;
    FileManager &fileManager;

private:
    //slots
    void OnQuit();
    void OnOpen();
    void OnSave();
    void OnSaveAs();
    void OnTextChanged();

    //helpers
#ifdef __APPLE__
    void HideTitleBar();
#endif
    void UpdateTitle();
};


#endif //REXTEDITOR_REXTEDITORWINDOW_H
