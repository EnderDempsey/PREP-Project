#include "GetStandardDeviations.h"
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

bool getToData(ifstream& readFile){
    string s;
    for (int i=1; i<=13; i++){
        getline(readFile, s);
    }
    return true;
}

double stdevYears(ifstream& readFile){
    string s;
    int year;
    double v;
    double stdev;
    vector<double> list;
    while(readFile.good()){
        getline(readFile, s, ',');
        year = stoi(s); year = year/10000;
        while (year == 1926){
            getline(readFile, s);
            getline(readFile, s, ',');
            year = stoi(s); year = year/10000;
        }
        //getline(readFile, s, ',');
            while (year == 1927){
                for (int i=1; i<=10; i++){
                    getline(readFile, s, ',');
                }
                for (int i=1; i<=3; i++){
                    getline(readFile, s, ' ');
                }
                getline(readFile, s, ',');
                cout << s << endl;
                v = stod(s);
                cout << v << endl;
                list.push_back(v);
                getline(readFile, s);
                getline(readFile, s, ',');
                cout << s << endl;
                year = stoi(s); year = year/10000;
                cout << year << endl;
            }
        stdev = getStdevOfList(list);
        for (int i=0; i<list.size(); i++){
            cout << endl;
            cout << list[i] << ", ";
        }
        cout << endl;
        cout << list.size();
        cout << stdev << endl;
        break;
    }
    return stdev;
}

//The code in this function was adapted from
//code from https://www.geeksforgeeks.org/cpp/cpp-program-to-find-the-standard-deviation-of-array-elements/
double getStdevOfList(vector<double> list){
    double sum, mean, standardDeviation = 0.0;

    int size = list.size();

    // Calculate the sum of elements in the vector
    for (int i = 0; i < size; ++i) {
        sum += list[i];
    }

    // Calculate the mean
    mean = sum / size;

    // Calculate the sum of squared differences from the
    // mean
    for (int i = 0; i < size; ++i) {
        standardDeviation += pow(list[i] - mean, 2);
    }

    // Calculate the square root of the variance to get the
    // standard deviation
    return sqrt(standardDeviation / size);
}