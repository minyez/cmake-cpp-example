#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mymath.hpp"
#include "envs.hpp"
#include "constants.hpp"

int main (int argc, char *argv[])
{
    using namespace std;
    cout << "Source code directory: " << source_dir << endl;
    cout << "Version: " << _version << endl;
    cout << "Sum up to 10: " << sum(10) << endl;
    srand(time(0));
    const int DIM = 20;
    const double MAXELEMENT = 1.0;
    double v1[DIM], v2[DIM];
    cout << "Randomizing two vectors of dimension " << DIM << endl;
    for (int i = 0; i != DIM; i++)
        v1[i] = random() *MAXELEMENT / RAND_MAX; 
    srand(time(0));
    for (int i = 0; i != DIM; i++)
        v2[i] = random() *MAXELEMENT / RAND_MAX;
    cout << "Dot product: " << dot(DIM, v1, v2) << endl;
    
    return 0;
}
