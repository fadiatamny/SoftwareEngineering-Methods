
ifeq ($(OS), Windows_NT)
	CXX = g++
	REM = del
else
	CXX = i686-w64-mingw32-g++
	REM = rm
endif

TARGET	=	program
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
		$(REM) $(TARGET).exe
cleanObj:
		$(REM) *.o