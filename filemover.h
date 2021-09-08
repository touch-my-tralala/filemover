#ifndef FILEMOVER_H
#define FILEMOVER_H

#include <QString>
#include <QJsonArray>

class FileMover
{
public:
    FileMover(QString fileName);
    bool makeMove();
    bool registerPaths(const QString &from, const QString &to);

private:
    bool move_file(const QJsonObject& obj);
    QJsonArray read_info_file();

private:
    QString m_from_path, m_to_path;
    QString m_info_file;
};

#endif // FILEMOVER_H
