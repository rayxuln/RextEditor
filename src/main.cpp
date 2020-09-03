#include "RextEditorWindow.h"

#include <QApplication>

#include "RextEditorWindow.h"
#include "FileManager.h"

int main(int arcc, char **arcv) {
    QApplication app(arcc, arcv);
    FileManager fileManager;
    RextEditorWindow window(fileManager);
    window.show();
    return app.exec();
}
