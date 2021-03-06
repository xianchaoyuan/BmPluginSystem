#include "coreplugin.h"

#include <QLabel>
#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QStatusBar>

#include <coreplugin/dialogs/ioptionspage.h>
#include <coreplugin/dialogs/settingsdialog.h>
#include <extensionsystem/pluginmanager.h>

#include <coreplugin/fancypage.h>

#include "systemsettings.h"
#include "fancytabwidget/fancybutton.h"

#include "homepage.h"

using namespace Core;
using namespace FancyTabWidgetUtils;

bool CorePlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments);
    *errorString = "CorePlugin::initialize failed!";

    QMainWindow *mwin = new QMainWindow;
    mwin->setWindowTitle("BmSeven Core Plugin");

    QAction *actSetting = new QAction("setting");
    actSetting->setIcon(QIcon(":/icon/image/options.png"));
    connect(actSetting, &QAction::triggered, this, &CorePlugin::settingsDialog);

    QToolBar *mainToolbar = new QToolBar("ToolBar",mwin);
    mainToolbar->addAction(actSetting);

    mwin->addToolBar(Qt::TopToolBarArea, mainToolbar);

//    m_fancyTabWidgt = new FancyTabWidget();
//    mwin->setCentralWidget(m_fancyTabWidgt);
//    mwin->setMinimumSize(800,600);

//    //status bar
//    QWidget *statusBarLeftWidget = new QWidget(mwin);
//    QHBoxLayout *statusBarLeftWidgetLayout = new QHBoxLayout(statusBarLeftWidget);
//    statusBarLeftWidgetLayout->setMargin(0);
//    statusBarLeftWidget->setLayout(statusBarLeftWidgetLayout);
//    QToolButton *btnToggleSelectBar = new QToolButton;
//    btnToggleSelectBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
//    btnToggleSelectBar->setIcon(QIcon(":/icon/image/toggle_left_on.png"));
//    btnToggleSelectBar->setIconSize(QSize(16,16));
//    btnToggleSelectBar->setCheckable(true);
//    btnToggleSelectBar->setChecked(true);
//    btnToggleSelectBar->setStyleSheet("QToolButton\
//    {\
//        border:none;\
//        background:transparent;\
//    }\
//    QToolButton:checked\
//    {\
//        border:none;\
//        background-color:rgb(21,21,21);\
//    }\
//    QToolButton:hover\
//    {\
//      border:1px solid #757575;\
//      background-color:rgb(121,121,121);\
//    }\
//    \
//    QToolButton:pressed\
//    {\
//      border:none;\
//      background-color:rgb(151,151,151);\
//    }\
//    \
//   ");
//    statusBarLeftWidgetLayout->addWidget(btnToggleSelectBar);
//    m_fancyTabWidgt->statusBar()->insertWidget(0,statusBarLeftWidget);
//    m_fancyTabWidgt->statusBar()->setStyleSheet("QStatusBar{color:#606162;background-color:#404142;}");
//    connect(btnToggleSelectBar,&QToolButton::toggled,[=](bool checked){
////       if(checked)
//       {
//           m_fancyTabWidgt->setSelectionWidgetVisible(checked);
//       }
//    });

//    FancyButton *btn = new FancyButton(m_fancyTabWidgt);
//    btn->setIcon(QIcon(":/icon/image/options.png"));
//    btn->setIconSize(QSize(48,32));
//    connect(btn,&FancyButton::clicked,actSetting,&QAction::triggered);

//    m_fancyTabWidgt->insertCornerWidget(0, btn);

//    m_mainWindow.reset(mwin);

//    //system settings
//    new SystemSettings();

//    //home page load
//    ExtensionSystem::PluginManager::addObject(new HomePage());

    return true;
}

int CorePlugin::m_tabIndex = 0;

void CorePlugin::extensionsInitialized()
{
//   QList<QObject*> pagesObject = ExtensionSystem::PluginManager::allObjects();

//   for(QObject* objPage:pagesObject){
//       FancyPage *page = qobject_cast<FancyPage*>(objPage);

//       if(!page->pageWidget()){
//           continue;
//       }

//       qDebug()<<" pages to add:"<<page->pageBtnName();

//       m_fancyTabWidgt->insertTab(m_tabIndex, page->pageWidget(),page->pageBtnIcon(), page->pageBtnName());
//       m_fancyTabWidgt->setTabEnabled(m_tabIndex,true);

//       m_tabIndex++;

//       //remove from plugin pool
//       connect(this, &IPlugin::destroyed, this, [=]{
//           ExtensionSystem::PluginManager::removeObject(objPage);
//       });
//   }

//   //init page

//   m_fancyTabWidgt->setCurrentIndex(0);

}

QObject *CorePlugin::remoteCommand(const QStringList &, const QString &, const QStringList &)
{
    m_mainWindow->show();

    return nullptr;
}

void CorePlugin::settingsDialog()
{
    SettingsDialog *settingDialog = new SettingsDialog;

    settingDialog->exec();

}

