TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    hot_drink.cpp \
    hot_drink_factory.cpp \
    drink_factory.cpp

HEADERS += \
    hot_drink.h \
    hot_drink_factory.h \
    drink_factory.h
