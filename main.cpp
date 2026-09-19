#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cmath>
#include <vector>
#include <array>

#include "GetStandardDeviations.h"

int main(){
    //open file

    ifstream readFile;
    readFile.open("Portfolios_Formed_on_ME_daily 4.csv");
    ofstream out("deviations.csv");
    prepOutFile(out);
    array<double,10> yearI;
    //Get a list of a list of standard deviations for a year for each decile
    if (getToData(readFile)){
        for(int i=1927; i<=2025; i++){
            yearI = stdevYears(readFile, i);
            addToFile(out, yearI, i);
        }
    }

    


    //close files
    readFile.close();
    out.close();
    return 0;
}
