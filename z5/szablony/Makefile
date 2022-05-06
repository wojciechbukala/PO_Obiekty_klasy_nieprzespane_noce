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

#obj/Wykonaj.o: src/Wykonaj.cpp inc/Wykonaj.hh inc/UkladRownanLiniowych.hh
#	g++ ${CXXFLAGS} -o obj/Wykonaj.o src/Wykonaj.cpp

obj/SUkladRownanLiniowych.o: src/SUkladRownanLiniowych.cpp inc/SUkladRownanLiniowych.hh inc/SWektor.hh inc/SMacierz.hh
	g++ ${CXXFLAGS} -o obj/SUkladRownanLiniowych.o src/SUkladRownanLiniowych.cpp



clean:
	rm -f obj/*.o uklad_rownan