//
// Created by Raymond_Lx on 2020/9/3.
//

#ifndef REXTEDITOR_FILEMANAGER_H
#define REXTEDITOR_FILEMANAGER_H

#include <QString>

#include <exception>

class FileManager {
    bool dirty;
    QString currentFilePath;
public:
    FileManager();
    ~FileManager();

    QString ReadFile(const QString &path);
    inline bool IsDirty() const{
        return dirty;
    }
    inline void SetDirty(bool v = true){
        dirty = v;
    }
    QString GetCurrentFilePath(){
        return currentFilePath;
    }
    void WriteFileAs(const QString &path, const QString &text);

class FileCannotOpenException : public std::exception{
    QString path;
public:
    explicit FileCannotOpenException(const QString &path);
    ~FileCannotOpenException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};
};



#endif //REXTEDITOR_FILEMANAGER_H
