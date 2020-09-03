//
// Created by Raymond_Lx on 2020/9/3.
//

#include "FileManager.h"

#include <QFile>

FileManager::FileManager():dirty(false),currentFilePath("") {}
FileManager::~FileManager() {}

QString FileManager::ReadFile(const QString &path) {
    if(path.isEmpty()) return "";
    QFile f(path);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    if(f.isReadable()){
        auto res = f.readAll();
        f.close();
        currentFilePath = path;
        return res;
    }
    f.close();
    throw FileCannotOpenException(path);
}

void FileManager::WriteFileAs(const QString &path, const QString &text) {
    if(path.isEmpty()) return;
    QFile f(path);
    f.open(QIODevice::WriteOnly | QIODevice::Text);
    if(f.isWritable()){
        f.write(text.toUtf8());
        f.close();
        currentFilePath = path;
        SetDirty(false);
        return;
    }
    f.close();
    throw FileCannotOpenException(path);
}

FileManager::FileCannotOpenException::FileCannotOpenException(const QString &path):path(path) {}
const char * FileManager::FileCannotOpenException::what() const noexcept {
    return (QString("Can't not open file ") + path).toUtf8();
}