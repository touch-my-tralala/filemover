#include "filemover.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QDir>

#include <QJsonObject>

FileMover::FileMover(QString fileName)
{
    m_info_file = fileName;
}

bool FileMover::makeMove()
{
    bool ok = true;;
    auto files = read_info_file();
    for(const auto& i : qAsConst(files))
    {
        auto file = i.toObject();
        ok &= move_file(file);
    }

    return ok;
}

bool FileMover::registerPaths(const QString &from, const QString &to)
{
    QFileInfo info_from(from);
    if (info_from.exists() && info_from.isDir())
        m_from_path = from;
    else
        return false;

    QFileInfo info_to(to);
    if (info_to.exists() && info_to.isDir())
        m_to_path = to;
    else
        return false;

    return true;
}

QJsonArray FileMover::read_info_file()
{
    QFile file(m_info_file);
    if(!file.open(QIODevice::ReadOnly))
        return QJsonArray();

    QJsonDocument doc =  QJsonDocument::fromJson(file.readAll());
    file.close();

    return doc.array();
}

bool FileMover::move_file(const QJsonObject& obj)
{
    QDir dir(m_from_path);
    auto name = obj["path"].toString();
    return dir.rename(name, m_to_path + "/" + name);
}
