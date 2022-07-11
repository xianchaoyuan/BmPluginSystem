include(../BmPluginSystem.pri)

TEMPLATE = lib

DLLDESTDIR = $$APP_OUT_PATH/plugins

DESTDIR = $$APP_LIBS_PATH

LIBS += -L$$DESTDIR
