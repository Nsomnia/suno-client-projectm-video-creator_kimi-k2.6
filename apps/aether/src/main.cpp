#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariantMap>
#include <aether/core/ApplicationContext.h>
#include <aether/core/Logger.h>
#include <aether/core/VersionInfo.h>
#include <aether/core/ConfigManager.h>
#include <aether/core/EventBus.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto* ctx = aether::core::ApplicationContext::instance();
    ctx->initialize();

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/qml"));
    engine.rootContext()->setContextProperty("AppContext", ctx);
    engine.rootContext()->setContextProperty("Config", ctx->config());
    engine.rootContext()->setContextProperty("EventBus", ctx->eventBus());
    engine.rootContext()->setContextProperty("Version", QVariantMap({
        {"version", QString(aether::core::VersionInfo::version)},
        {"commit", aether::core::VersionInfo::gitCommitHash()},
        {"buildDate", aether::core::VersionInfo::buildDate()}
    }));

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (objUrl == url && !obj)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    int result = app.exec();
    ctx->shutdown();
    return result;
}
