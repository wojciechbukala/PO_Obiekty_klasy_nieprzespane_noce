#
#  To sa opcje dla kompilacji
#
CXXFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/SWektor.o obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/SWektor.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/SWektor.hh inc/LZespolona.hh
	g++ ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh 
	g++ ${CXXFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/SWektor.o: src/SWektor.cpp inc/SWektor.hh inc/LZespolona.hh 
	g++ ${CXXFLAGS} -o obj/SWektor.o src/SWektor.cpp

obj/SMacierz.o:src/SMacierz.cpp inc/SMacierz.hh
	g++ ${CCXXFLAGS} -o obj/SMacierz.o src/SMacierz.cpp



clean:
	rm -f obj/*.o uklad_rownan