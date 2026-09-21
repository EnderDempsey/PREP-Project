#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cmath>
#include <vector>
#include <array>

#include "GetStandardDeviations.h"

int main(){
    //File handling
    ifstream readFile;
    readFile.open("Portfolios_Formed_on_ME_Daily.csv");
    ofstream out("StDevsForPortfoliosFormedOnSizeDaily.csv");
    prepOutFile(out,"Portfolios_Formed_on_ME_daily");

    array<double,10> yearI;

    //Get a list of a list of standard deviations for a year for each decile
    if (getToData(readFile)){
        for(int i=1927; i<=2025; i++){
            yearI = stDevsByYearsForEachDecile(readFile, i);
            addToFile(out, yearI, i);
        }
    }

    //Close files
    readFile.close();
    out.close();
    return 0;
}
