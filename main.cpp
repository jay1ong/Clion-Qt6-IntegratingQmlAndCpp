#include <QApplication>
#include <QPushButton>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "backend.h"

int main(int argc, char *argv[]) {
    QGuiApplication  app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    // 左上角logo
    QGuiApplication::setWindowIcon(QIcon(":/logo"));

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/modules");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    QQuickWindow* window = (QQuickWindow*) engine.rootObjects().first();
    window->setScreen(QGuiApplication::screens().at(1));
//    app.primaryScreenChanged(QGuiApplication::screens().at(1));
    window->show();
    return QApplication::exec();
}
