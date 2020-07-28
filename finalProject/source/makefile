ifeq ($(OS), Windows_NT)
	CXX = g++
	REM = del
else
	CXX = i686-w64-mingw32-g++
	REM = rm
endif

TARGET = program
CPPFLAGS = -g 

default: $(TARGET)
all: clean default

OBJECTS += Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Controls/Label.o Common/Border/Border.o Common/Control.o Controls/Button.o

%.o: %.cpp
		$(CXX) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
		$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean: cleanObj
		$(REM) $(TARGET).exe
cleanObj:
		$(REM) $(OBJECTS)