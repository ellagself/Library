 # file: Makefile
 # author: Mangos Cameron Tucker and Ella Self
 # date: 2024-11-06
 # brief: Makefile for Library


CC = g++
TARGET = library
CFLAGS = -g -Wall -Wextra

default: $(TARGET)

$(TARGET): main.o library.o 
	$(CC) $(CFLAGS) -o $(TARGET) main.o library.o

main.o: main.cpp library.h book.h
	$(CC) $(CFLAGS) -c main.cpp

library.o: library.cpp library.h book.h
	$(CC) $(CFLAGS) -c library.cpp

clean:
	$(RM) $(TARGET) *.o *~~
