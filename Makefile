CC=g++
CXXFLAGS=-std=c++11 -c -Wall -Icanvas -Itest
LDFLAGS=
SOURCES=canvas/Canvas.cpp canvas/CanvasCommandFactory.cpp canvas/CreateCanvasCommand.cpp canvas/DrawLineCommand.cpp canvas/DrawRectangleCommand.cpp canvas/BucketFillCommand.cpp canvas/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=draw

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	\rm -f canvas/*.o canvas/*~ draw
