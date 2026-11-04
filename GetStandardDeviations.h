#ifndef GETSTANDARDDEVIATIONS_H
#define GETSTANDARDDEVIATIONS_H

<<<<<<< HEAD
//Goal:
//Get standard deviations for each year from 1927-2025 (inclusive)
//Get stdevs for every year for every decile and quartile
class GetStandardDeviations{
    public:
        void openData(ifstream &in);
        void closeData();
        double stdevYears();
        double stdevDeciles();
        double stdevQuartiles();
}

=======
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

>>>>>>> 69ddbb647d09bc8fb271153676f29055f48e4eb0
#endif
