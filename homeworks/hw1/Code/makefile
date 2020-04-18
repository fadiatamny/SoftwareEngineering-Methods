
TARGET	=	program
CC	= g++
CFLAGS	= -g 

default: $(TARGET)
all: clean default

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

%.o: %.cpp $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean: cleanObj
		rm $(TARGET).exe
cleanObj:
		rm *.o