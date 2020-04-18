
TARGET	=	program
ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = i686-w64-mingw32-g++
endif
CFLAGS	= -g 

default: $(TARGET)
all: clean default

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
		$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean: cleanObj
		rm $(TARGET).exe
cleanObj:
		rm *.o