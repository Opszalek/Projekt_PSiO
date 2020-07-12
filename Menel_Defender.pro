TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "D:\Aplikacje\SFML\SFML-2.5.1\include"
SOURCES += \
        TextureManager.cpp \
        box.cpp \
        bullet.cpp \
        character.cpp \
        enemy.cpp \
        game.cpp \
        main.cpp \
        weapons.cpp
LIBS += -L"D:\Aplikacje\SFML\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    TextureManager.h \
    box.h \
    bullet.h \
    character.h \
    enemy.h \
    game.h \
    weapons.h
