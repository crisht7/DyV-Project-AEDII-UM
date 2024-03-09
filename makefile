ejecutable.out: DivideVenceras.o Abecedario.o Main.o
	g++ DivideVenceras.o Abecedario.o Main.o -o ejecutable.out

Abecedario.o: Abecedario.cpp Abecedario.h
	g++ -c Abecedario.cpp

DivideVenceras.o: DivideVenceras.cpp DivideVenceras.h
	g++ -c DivideVenceras.cpp

Main.o: Main.cpp DivideVenceras.h Abecedario.h
	g++ -c Main.cpp

clean:
	rm -rf a.out salidaActual.out *.o