#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "myserver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Myserver myServerHandler;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QML_Demo/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);


    QQmlContext *context(engine.rootContext());
    context->setContextProperty("serverHandler", &myServerHandler);

    engine.load(url);




    //TCP Server
    if (!myServerHandler.listen(QHostAddress::Any, 50000))
    {
        myServerHandler.setMsg("Server cannot start!\n");
    }
    myServerHandler.setMsg("Server started\n");

    return app.exec();
}
