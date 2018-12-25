#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rxmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);    

    QQmlApplicationEngine engine;
    auto pContext = engine.rootContext();
    rxmodel rx;
    pContext->setContextProperty("rx", &rx);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
