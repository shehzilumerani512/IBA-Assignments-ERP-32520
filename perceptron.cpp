#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int count = 1;
    double prediction, weight, x, bias, learningRate, error;
    int fx;
    prediction = 0.00;
    x = 5;
    fx = 2*pow(x,2) - 4;
    error = fx - prediction;
    learningRate = 0.01;
    weight = 0.0;
    bias = 0.0;
    cout<<"Step 0: prediction = "<<fixed<<setprecision(2)<<prediction<<", error = "<<error<<endl;

    while (count < 1000) {
        prediction = (((weight * x) + bias));
        error = fx - prediction;
        weight += (learningRate * error * x);
        bias += (learningRate * error);
        if (count % 100 == 0)
            cout<<"Step "<<count<<": prediction = "<<fixed<<setprecision(2)<<prediction<<", error = "<<fixed<<setprecision(2)<<error<<endl;
        count += 1;
    }

    cout<<"Final Prediction at x = "<<x<<": "<<fixed<<setprecision(2)<<prediction<<endl;
    cout<<"Target Value: "<<fx<<endl;
    cout<<"Final weight = "<<fixed<<setprecision(2)<<weight<< ", bias = "<<fixed<<setprecision(2)<<bias<<endl<<endl;

    return 0;
}