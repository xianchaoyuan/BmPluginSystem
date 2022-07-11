
#include <QApplication>
#include <QDir>

#include <QDebug>

#include <QSettings>

#include <extensionsystem/pluginmanager.h>
#include <extensionsystem/pluginspec.h>
#include <extensionsystem/iplugin.h>

#include <utils/qtcsettings.h>

int main(int argc, char *argv[])
{

    QApplication a(argc,argv);

//    QDir::setCurrent(a.applicationDirPath());

    a.setApplicationName("BmPluginSystem");
    a.setApplicationDisplayName("BmPluginSystem");
    a.setDesktopFileName("BmPluginSystem");
    a.setApplicationVersion("0.01");
    a.setOrganizationName("BmSeven");

    using namespace ExtensionSystem;

    //settings
    Utils::QtcSettings *setting = new Utils::QtcSettings(QSettings::IniFormat, QSettings::UserScope, "BmSeven", "BmPluginSystem");

    //plugin mange
    PluginManager pluginManger;

    PluginManager::setSettings(setting);

    //plugin IID, only Plugins with this IID are loaded
    PluginManager::setPluginIID(QLatin1String("BmSeven.plugin"));

    //plugin path
    QStringList pluginPath;
    pluginPath << a.applicationDirPath()+"/plugins";
    pluginManger.setPluginPaths(pluginPath);

    //load
    pluginManger.loadPlugins();

    //shutdown when app exit
    QObject::connect(&a, &QApplication::aboutToQuit, &pluginManger, &PluginManager::shutdown);

    //coreplugin
    const QList<PluginSpec*> plugins = pluginManger.plugins();
    PluginSpec *corespec = nullptr;
    //find corespec
    for(PluginSpec* spec: plugins){
        if(spec->name() == QLatin1String("CorePlugin")){
            corespec = spec;
            break;
        }
    }

    //load coreplugin
    if(corespec){
        corespec->plugin()->remoteCommand(QStringList(), QString(), QStringList());
    }else{
        pluginManger.shutdown();

        a.quit();
        return -1;
    }

    return a.exec();
}
