#include "simulare.h"
#include "rochie.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testDomain();
    testRepo();
    testService();
    Repo repo{ "rochie.txt" };
    Service service{ repo };
    GUI gui{ service };
    gui.show();
    return a.exec();
}
