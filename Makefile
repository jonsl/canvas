CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=canvas/Canvas.cpp canvas/CanvasCommandFactory.cpp canvas/CreateCanvasCommand.cpp canvas/DrawLineCommand.cpp canvas/DrawRectangleCommand.cpp canvas/BucketFillCommand.cpp canvas/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=draw

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	\rm canvas/*.o canvas/*~ draw