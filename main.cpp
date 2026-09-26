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
    //For Portfoilios formed on size daily
    ifstream readMEFile;
    readMEFile.open("Portfolios_Formed_on_ME_Daily.csv");
    ofstream outME("StDevsForPortfoliosFormedOnSizeDaily.csv");
    prepOutFile(outME,"Portfolios_Formed_on_ME_daily");
    //For portfoilios on book-to-market daily
    ifstream readBEtoMEFile;
    readBEtoMEFile.open("Portfolios_Formed_on_BE-ME_Daily.csv");
    ofstream outBEtoMEFile("StDevsForPortfoliosFormedOnBEtoMEDaily.csv");
    prepOutFile(outBEtoMEFile, "Portfolios_Formed_on_BE-ME_Daily");

    array<double,10> yearI;

    //Get a list of a list of standard deviations for a year for each decile
    if (getToData(readMEFile, 13)){
        for(int i=1927; i<=2025; i++){
            yearI = stDevsByYearsForEachDecile(readMEFile, i);
            addToFile(outME, yearI, i);
        }
    }

    if (getToData(readBEtoMEFile, 24)){
        for(int i=1927; i<=2025; i++){
            yearI = stDevsByYearsForEachDecile(readBEtoMEFile, i);
            addToFile(outBEtoMEFile, yearI, i);
        }
    }

    //Close files
    readMEFile.close();
    outME.close();
    readBEtoMEFile.close();
    outBEtoMEFile.close();
    return 0;
}
