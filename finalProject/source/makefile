ifeq ($(OS), Windows_NT)
	CXX = g++
	REM = del
else
	CXX = i686-w64-mingw32-g++
	REM = rm
endif

TARGET = program
CPPFLAGS = -std=c++1z -static -g

default: $(TARGET)
all: clean default

OBJECTS += Common/EventEngine.o Common/Graphics.o Common/Control.o Common/Border/Border.o Controls/Button.o Controls/CheckBox.o Controls/CheckList.o Controls/ComboBox.o Controls/Label.o Controls/MessageBoxPopup.o Controls/NumericBox.o Controls/Panel.o Controls/RadioBox.o Controls/TextBox.o FinalProject/Source.o

%.o: %.cpp
		$(CXX) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
		$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean: cleanObj
		$(REM) $(TARGET).exe
cleanObj:
		$(REM) $(OBJECTS)