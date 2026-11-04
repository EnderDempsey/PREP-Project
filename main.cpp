#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <Eigen/Dense>
using namespace Eigen;

#include "GetStandardDeviations.h"
#include "PCA.h"

int main(){
    /* Not running since we now have the data values.
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
    */
    //Matrix<double,10,10> matrixME = make10x10("ME");
    //Matrix<double,10,10> matrixBEtoME = make10x10("BEtoME");
    Matrix<double, 10, 10> matrixME; //Data from Correlation Matrix preformed on size.
    matrixME << 0.288353666, 0.259109793, 0.230822464, 0.223351817, 0.213908052, 0.210724957, 0.209446601, 0.191653374, 0.190864091, 0.144123307,
0.259109793, 0.261591265, 0.239376584, 0.233052039, 0.22697681, 0.219187493, 0.21683693, 0.204906689, 0.203158204, 0.161728253,
0.230822464, 0.239376584, 0.22427616, 0.218247883, 0.215336498, 0.208311637, 0.205890173, 0.197030723, 0.195717282, 0.160392187,
0.223351817, 0.233052039, 0.218247883, 0.216030273, 0.212510104, 0.204243434, 0.202791855, 0.194775108, 0.193767496, 0.160437846,
0.213908052, 0.22697681, 0.215336498, 0.212510104, 0.214241967, 0.206094053, 0.204383825, 0.199030911, 0.198666954, 0.169171745,
0.210724957, 0.219187493, 0.208311637, 0.204243434, 0.206094053, 0.203679688, 0.20163116, 0.196567436, 0.197273449, 0.169198687,
0.209446601, 0.21683693, 0.205890173, 0.202791855, 0.204383825, 0.20163116, 0.203225854, 0.197677405, 0.199679205, 0.172379721,
0.191653374, 0.204906689, 0.197030723, 0.194775108, 0.199030911, 0.196567436, 0.197677405, 0.197841849, 0.199876565, 0.177780571,
0.190864091, 0.203158204, 0.195717282, 0.193767496, 0.198666954, 0.197273449, 0.199679205, 0.199876565, 0.206327161, 0.185111376,
0.144123307, 0.161728253, 0.160392187, 0.160437846, 0.169171745, 0.169198687, 0.172379721, 0.177780571, 0.185111376, 0.182112103;

    Matrix<double, 10,10> matrixBEtoME;
    matrixBEtoME << 0.177065897, 0.166235867, 0.166137916, 0.178197062, 0.17004136, 0.158294074, 0.151498974, 0.14785119, 0.141237935, 0.12634063,
0.166235867, 0.176234057, 0.168629667, 0.186470235, 0.17636228, 0.166420416, 0.165590438, 0.161661589, 0.158398407, 0.14735794,
0.166137916, 0.168629667, 0.170833243, 0.181932986, 0.174191062, 0.164408812, 0.162983062, 0.159218439, 0.154899374, 0.141974696,
0.178197062, 0.186470235, 0.181932986, 0.211817765, 0.197202532, 0.190609243, 0.190191755, 0.185932499, 0.181358203, 0.171534787,
0.17004136, 0.17636228, 0.174191062, 0.197202532, 0.197977173, 0.186390227, 0.187523076, 0.184008142, 0.180844067, 0.169587953,
0.158294074, 0.166420416, 0.164408812, 0.190609243, 0.186390227, 0.192271374, 0.191050482, 0.190845335, 0.188106514, 0.179752425,
0.151498974, 0.165590438, 0.162983062, 0.190191755, 0.187523076, 0.191050482, 0.204900456, 0.201304785, 0.20084208, 0.196528968,
0.14785119, 0.161661589, 0.159218439, 0.185932499, 0.184008142, 0.190845335, 0.201304785, 0.211895532, 0.209763269, 0.207168546,
0.141237935, 0.158398407, 0.154899374, 0.181358203, 0.180844067, 0.188106514, 0.20084208, 0.209763269, 0.218770441, 0.218681626,
0.12634063, 0.14735794, 0.141974696, 0.171534787, 0.169587953, 0.179752425, 0.196528968, 0.207168546, 0.218681626, 0.238436321;

    //PCA for Covariance Matrix for ME
    SelfAdjointEigenSolver<Matrix<double,10,10>> solver (matrixME);
    double max_eigenvalueME = solver.eigenvalues()(9);
    Matrix<double,10,1> corrEigenVectorME = solver.eigenvectors().col(9);
    cout << "Max Eigenvalue: " << max_eigenvalueME << endl;
    cout << "Corresponding Eigenvector: " << endl << corrEigenVectorME << endl;

    //PCA for Covariance Matrix for BE to ME
    SelfAdjointEigenSolver<Matrix<double,10,10>> solver2 (matrixBEtoME);
    double max_eigenvalueBEtoME = solver2.eigenvalues()(9);
    Matrix<double,10,1> corrEigenVectorBEtoME = solver2.eigenvectors().col(9);
    cout << "Max Eigenvalue: " << max_eigenvalueBEtoME << endl;
    cout << "Corresponding Eigenvector: " << endl << corrEigenVectorBEtoME << endl;

    return 0;
}
