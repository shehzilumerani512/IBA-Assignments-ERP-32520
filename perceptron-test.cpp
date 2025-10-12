#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    float accuracy;
    accuracy = 0.0;
    int correct = 0;
    cout<<"Enter 10 numbers. ";
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin>>arr[i];
    
    for ( int i = 0; i < 10; i++) {
    int count = 1;
    int x;
    double prediction, weight, bias, learningRate, error;
    int fx;
    prediction = 0.00;
    x = arr[i];
    fx = 2*pow(x,2) - 4;
    error = fx - prediction;
    learningRate = 0.01;
    weight = 0.0;
    bias = 0.0;
    // cout<<"Step 0: prediction = "<<fixed<<setprecision(2)<<prediction<<", error = "<<error<<endl;

    while (count < 1000) {
        prediction = (((weight * x) + bias));
        error = fx - prediction;
        weight += (learningRate * error * x);
        bias += (learningRate * error);
        // if (count % 100 == 0 && count < 901)
        //     cout<<"Step "<<count<<": prediction = "<<fixed<<setprecision(2)<<prediction<<", error = "<<fixed<<setprecision(2)<<error<<endl;
        count += 1;
    }

    cout<<"X = "<<x<<", ";
    cout<<"Y = "<<fixed<<setprecision(2)<<prediction;
    cout<<", Target = "<<fx;
    cout<<", Weight = "<<fixed<<setprecision(2)<<weight<< ", Bias = "<<fixed<<setprecision(2)<<bias;
    if (abs(prediction - fx) < 1) {
        cout<<" Correct\n";
        correct += 1;
    }
    else
        cout<<" Incorrect\n";

}
    accuracy = (correct / 10.0) * 100;
    cout<<accuracy<<" % of the outputs were correct.";

    return 0;
}