#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double fx, N, m, a, b, tolerance;
    cout<<"Enter Number for square root ";
    cin>>N;
    if (N < 1) { 
        a = 0;
        b = 1;
    }
    else {
        a = 0;
        b = N;
    }
    tolerance = 0.001;
    fx = -1;
    while (abs(fx) > tolerance) {
        if (N > 1) {
            m = (a+b)/2;
            fx = pow(m,2) - N;
            if (fx < 0)
                a = m;
            else
                b = m;        
        }
        else {
            m = (a+b)/2;
            fx = pow(m,2) - N;
            if (fx < 0)
                a = m;
            else
                b = m;        
        }
        m = (a+b)/2;
        fx = pow(m,2) - N;
    }
    cout<<"Square root of "<<N<<" is "<<m;
    return 0;
}