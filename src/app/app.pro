include(../../BmPluginSystem.pri)

QT += core gui widgets

TEMPLATE = app

TARGET = BmPluginSystem

LIBS += -L$$APP_LIBS_PATH

LIBS += \
    -lutils \
    -lextensionsystem \
    -lcoreplugin \

SOURCES += \
    main.cpp

DESTDIR = $$APP_OUT_PATH

#icon
RC_FILE += app.rc
