#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int number, total;
    total = 0;
    int loopstopper;
    cout<<"Enter a positive number: ";
    cin>>number;
    loopstopper = number/2;

    for (int i = 1; i <= loopstopper; i++)
        if ((number % i) == 0)
            total += i;


    if (total == number) 
        cout<<number<<" is a perfect number."<<endl;
    else {
        cout<<number<<" is not a perfect number."<<endl;
        cout<<"Sum of factors is: "<<total;
    }
    return 0;
}