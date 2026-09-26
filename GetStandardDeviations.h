#ifndef GETSTANDARDDEVIATIONS_H
#define GETSTANDARDDEVIATIONS_H

#include <fstream>
using namespace std;
#include <vector>

//Goal:
//Get standard deviations for each year from 1927-2025 (inclusive)
//Get stdevs for every year for every decile and quartile
        bool getToData(ifstream&, int);
        array<double,10> stDevsByYearsForEachDecile(ifstream&, int);
        double getStdevOfList(vector<double>);
        void prepOutFile(ostream&, string);
        void addToFile(ostream&, array<double,10>, int year);

#endif
