
CC = gcc
CFLAGS = -Wall -pthread

INCLUDEPATH += \
	-I src \
	-I src/periph \
	-I src/ssd1311

DEFINES =

OBJECTS = \
	gpio.o \
	i2c.o \
	ssd1311.o \
	buttons.o \
	fpio.o \
	si.o \
	menu.o \
	fp.o \
	main.o

TARGET = morda


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDEPATH) -o $(TARGET) $(OBJECTS)

gpio.o : src/gpio.c src/periph.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/gpio.c

i2c.o : src/i2c.c src/periph.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/i2c.c

ssd1311.o : src/ssd1311.c src/ssd1311.h src/periph.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/ssd1311.c

buttons.o : src/buttons.c src/buttons.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/buttons.c

fpio.o : src/fpio.c src/buttons.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/fpio.c

si.o : src/si.c src/si.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/si.c

menu.o : src/menu.c src/menu.h
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/menu.c

fp.o : src/fp.c
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/fp.c

main.o: src/main.c
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c src/main.c


clean:
	rm -rfv *.o

distclean:
	rm -rfv *.o $(TARGET)
