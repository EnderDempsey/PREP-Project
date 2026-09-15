#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cmath>

#include "GetStandardDeviations.h"

int main(){
    //open file

    ifstream readFile;
    readFile.open("Portfolios_Formed_on_ME_daily 4.csv");

    //output standard deviations by year
    if (getToData(readFile)){
        stdevYears(readFile);
    }

    //close file
    readFile.close();
    return 0;
}
