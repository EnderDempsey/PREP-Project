#ifndef GETSTANDARDDEVIATIONS_H
#define GETSTANDARDDEVIATIONS_H

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

#endif
