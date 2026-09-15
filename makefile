calc: main.o GetStandardDeviations.o
	g++ -o calc main.o GetStandardDeviations.o
main.o: main.cpp GetStandardDeviations.o
	g++ -c main.cpp
GetStandardDeviations.o: GetStandardDeviations.h GetStandardDeviations.cpp
	g++ -c GetStandardDeviations.cpp
clean:
	rm *.o calc