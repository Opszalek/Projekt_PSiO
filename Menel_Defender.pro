TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "D:\Aplikacje\SFML\SFML-2.5.1\include"
SOURCES += \
        TextureManager.cpp \
        bullet.cpp \
        character.cpp \
        main.cpp
LIBS += -L"D:\Aplikacje\SFML\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    TextureManager.h \
    bullet.h \
    character.h
