EIGEN_PATH = $(shell pwd)/eigen
CXX = g++
CXXFLAGS = -I$(EIGEN_PATH) -Wall -std=c++14
calc: main.o GetStandardDeviations.o PCA.o
	$(CXX) -o calc main.o GetStandardDeviations.o PCA.o
main: main.cpp PCA.h GetStandardDeviations.h
	$(CXX) $(CXXFLAGS) -c main.cpp
GetStandardDeviations.o: GetStandardDeviations.h GetStandardDeviations.cpp
	$(CXX) $(CXXFLAGS) -c GetStandardDeviations.cpp
PCA.o: PCA.cpp PCA.h
	$(CXX) $(CXXFLAGS) -c PCA.cpp
clean:
	rm -f *.o calc