#include "mymath.hpp"
#include <cassert>
#include <iostream>

using namespace std;

bool check(bool test_expr, const char * msg)
{
    cout << msg << " ... ";
    if (test_expr)
        cout << "pass" << endl;
    else
        cout << "fail" << endl;
    return test_expr;
}

template <typename T>
bool check_array_equal(int n, const T *a1, const T *a2, const char *msg)
{
    bool iseq = true;
    for (int i = 0; i != n; i++)
        if (a1[i] != a2[i])
        {
            iseq = false;
            break;
        }
    return check(iseq, msg);
}

int main (int argc, char *argv[])
{
    if(!check(sum(10) == 45, "Check sum up to 10"))
        return 1;
    const int DIM = 4;
    double v1[DIM] { 0, 1, 2, 3 };
    double v2[DIM] { -2, 1, -4, 3 };
    double mat[DIM*DIM] { -1, 0,  2,  3, 
                          -4, 1, -3, -2,
                          -1, 0,  4,  1,
                           0, 4, -2, -3 };
    double matdv1[DIM] = { 13, -11, 11, -9};
    if(!check(dot(DIM, v1, v2) == 2.0, "Check manual dot"))
        return 1;
    if(!check(dot_blas(DIM, v1, v2) == 2.0, "Check BLAS dot"))
        return 1;
    dgemv(DIM, DIM, mat, v1, v2);
    if(!check_array_equal(DIM, v2, matdv1, "Check manual dgemv"))
        return 1;
    dgemv_blas(DIM, DIM, mat, v1, v2);
    if(!check_array_equal(DIM, v2, matdv1, "Check BLAS dgemv"))
        return 1;
    return 0;
}
