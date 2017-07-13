
CONFIG -= qt

INCLUDEPATH += \
	src \

SOURCES += \
    src/buttons.c \
    src/fp.c \
    src/gpio.c \
    src/i2c.c \
    src/main.c \
    src/menu.c \
    src/si.c \
    src/ssd1311.c \
    src/fpio.c

HEADERS += \
    src/buttons.h \
    src/menu.h \
    src/periph.h \
    src/si.h \
    src/ssd1311.h

DISTFILES += \
	Makefile \
	.gitignore


