QT     += core gui widgets
CONFIG += c++19

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp

HEADERS += \
    mainwindow.hpp \
    settingsdialog.hpp

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

TRANSLATIONS += \
    PI-Roll-Example_pl_PL.ts

CONFIG += lrelease
CONFIG += embed_translations
