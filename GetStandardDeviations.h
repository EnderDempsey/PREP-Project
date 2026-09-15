#ifndef GETSTANDARDDEVIATIONS_H
#define GETSTANDARDDEVIATIONS_H

#include <fstream>
using namespace std;
#include <vector>

//Goal:
//Get standard deviations for each year from 1927-2025 (inclusive)
//Get stdevs for every year for every decile and quartile
        bool getToData(ifstream&);
        double stdevYears(ifstream&);
        double stdevDeciles(ifstream&);
        double stdevQuartiles(ifstream&);
        double getStdevOfList(vector<double>);

#endif
