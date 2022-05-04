#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "mymath.hpp"
#include "envs.hpp"
#include "constants.hpp"

using namespace std;

template <typename T>
void display_vec(T msg, int n, double *v)
{
    cout << msg;
    for (int i = 0; i != n; i++)
        cout << " " << v[i];
    cout << endl;
}

int main (int argc, char *argv[])
{
    cout << "Source code directory: " << source_dir << endl;
    cout << "Version: " << _version << endl;
    cout << "Sum up to 10: " << sum(10) << endl;
    srand(time(0));
    const int DIM = 5;
    const double MAXELEMENT = 1.0;
    double v1[DIM], v2[DIM];
    double mat[DIM*DIM];
    cout << "Randomizing two vectors of dimension " << DIM << endl;
    for (int i = 0; i != DIM; i++)
        v1[i] = random() *MAXELEMENT / RAND_MAX; 
    srand(time(0));
    for (int i = 0; i != DIM; i++)
        v2[i] = random() *MAXELEMENT / RAND_MAX;
    display_vec("v1:", DIM, v1);
    display_vec("v2:", DIM, v2);
    cout << "Dot product by manual: " << dot(DIM, v1, v2) << endl;
    cout << "Dot product by BLAS: " << dot_blas(DIM, v1, v2) << endl;
    
    cout << "Serializing vector 1 and matrix of dimension " << DIM << endl;
    for (int i = 0; i != DIM*DIM; i++)
        /* mat[i] = random() *MAXELEMENT / RAND_MAX; */
        mat[i] = i; 
    for (int i = 0; i != DIM; i++)
        v1[i] = i;
    display_vec("v1:", DIM, v1);
    for (int i = 0; i != DIM; i++)
        display_vec(string("matrix row ") + to_string(i) + ":", DIM, mat+(DIM*i));
    dgemv(DIM, DIM, mat, v1, v2);
    display_vec("v1-matrix product by manual:", DIM, v2);
    dgemv_blas(DIM, DIM, mat, v1, v2);
    display_vec("v1-matrix product by BLAS:", DIM, v2);

    return 0;
}
