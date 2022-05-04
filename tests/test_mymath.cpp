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

int main (int argc, char *argv[])
{
    check(sum(10) == 45, "Check sum up to 10");
    const int DIM = 4;
    double v1[DIM] { 0, 1, 2, 3 };
    double v2[DIM] { -2, 1, -4, 3 };
    double v3[DIM*DIM] { -1, 0,  2,  3, 
                         -4, 1, -3, -2,
                         -1, 0,  4,  1,
                          0, 4, -2, -3 };
    check(dot(DIM, v1, v2) == 2.0, "Check manual dot");
    check(dot_blas(DIM, v1, v2) == 2.0, "Check BLAS dot");
    return 0;
}
