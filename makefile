# Abecedario.cpp, que incluye a Abecedario.h \
DivideVenceras.cpp, que incluye a DivideVenceras.h, que incluye Abecedario.h \
main.cpp, que incluye DivideVenceras.h

CC=g++
CFLAGS=
LDFLAGS=
SOURCES=Abecedario.cpp DivideVenceras.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=divideVenceras

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)