#include "GetStandardDeviations.h"
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <iostream>
using namespace std;

bool getToData(ifstream& readFile){
    string s;
    for (int i=1; i<=13; i++){
        getline(readFile, s);
    }
    return true;
}

array<double,10> stdevYears(ifstream& readFile, int wantedYear){
    string s;
    int year;
    double v;
    double stdev;
    array<double,10> stdevs;
    //Creates a series of vectors representing each decile for the year
        vector<double> Year1Dec;
        vector<double> Year2Dec;
        vector<double> Year3Dec;
        vector<double> Year4Dec;
        vector<double> Year5Dec;
        vector<double> Year6Dec;
        vector<double> Year7Dec;
        vector<double> Year8Dec;
        vector<double> Year9Dec;
        vector<double> Year10Dec;
    //Puts all of the previous vectors into a list, i.e. a list of vectors
        array<vector<double>,10> YearIDec;
        YearIDec[0] = Year1Dec;
        YearIDec[1] = Year2Dec;
        YearIDec[2] = Year3Dec;
        YearIDec[3] = Year4Dec;
        YearIDec[4] = Year5Dec;
        YearIDec[5] = Year6Dec;
        YearIDec[6] = Year7Dec;
        YearIDec[7] = Year8Dec;
        YearIDec[8] = Year9Dec;
        YearIDec[9] = Year10Dec;
    while(readFile.good()){
        //Gets to the desired year
        getline(readFile, s, ',');
        year = stoi(s); year = year/10000;
        while (year != wantedYear){
            getline(readFile, s);
            getline(readFile, s, ',');
            year = stoi(s); year = year/10000;
        }
        //Now, we are at the 1927 part of the code

        while (year == wantedYear){
            //Gets to 10-Dec
            for (int k=1; k<=9; k++){
                getline(readFile, s, ',');
            }
            for (int j=0; j<10; j++){
                //Gets to value
                for (int l=1; l<=3; l++){
                    getline(readFile, s, ' ');
                }
                if (j!=9){
                    getline(readFile, s, ',');
                } else {
                    getline(readFile, s);
                }
                //cout << s << endl;
                v = stod(s);
                YearIDec[j].push_back(v);
            }
            getline(readFile, s, ',');
            year = stoi(s); year = year/10000;
        }
        for (int i=0; i<10; i++){
            stdevs[i] = getStdevOfList(YearIDec[i]);
        }
        //cout << endl << "ST DEV IS " << stdev << endl;
        break;
    }
    return stdevs;
}

//The code in this function was adapted from
//code from https://www.geeksforgeeks.org/cpp/cpp-program-to-find-the-standard-deviation-of-array-elements/
double getStdevOfList(vector<double> list){
    double sum, mean, standardDeviation = 0.0;

    int size = list.size();
    //cout << endl << "SIZE IS " << size<< endl;

    // Calculate the sum of elements in the vector
    for (int i = 0; i < size; ++i) {
        sum += list[i];
    }

    // Calculate the mean
    mean = sum / size;
    //cout << endl << "MEAN IS " << mean << endl;

    // Calculate the sum of squared differences from the
    // mean
    for (int i = 0; i < size; ++i) {
        standardDeviation += pow(list[i] - mean, 2);
    }

    // Calculate the square root of the variance to get the
    // standard deviation
    //cout << endl << "RETURNING " << sqrt(standardDeviation / size) << endl;
    return sqrt(standardDeviation / size);
}

void prepOutFile(ostream& out){
    out << "Standard deviations by year for each decile" << endl << endl;
    out << "Year, Lo 10, Dec 2, Dec 3, Dec 4, Dec 5, Dec 6, Dec 7, Dec 8, Dec 9, Hi 10" << endl;
}

void addToFile(ostream& out, array<double,10> yearI, int year){
    out << year << ",   ";
    for (int i = 0; i<10; i++){
        out << yearI[i];
        if (i!=9){
            out << ",   ";
        }
    }
    out << endl;
}