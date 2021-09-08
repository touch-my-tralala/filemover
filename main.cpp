#include <QString>
#include "filemover.h"
#include <process.h>

int main(int argc, char *argv[])
{
    /*QString info_file = argv[0];
    QString path_from = argv[1];
    QString path_to = argv[2];

    FileMover mover(info_file);
    if(mover.registerPaths(path_from, path_to))
       mover.makeMove();

    QString app = argv[3];*/

    // Приложение не завершается после спавна
    spawnl(P_NOWAITO, "D:/Project/qt/test_client/build/debug/client_test.exe", NULL);
}
