#include <QtWidgets/QApplication>
#include <ui.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testDomain();
    testRepo();
    testService();
    Repo repo{ "fisier.txt" };
    Service service{ repo };
    UI ui{ service };
    ui.show();
    return a.exec();
}
