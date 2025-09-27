#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int main() {

int nume1, nume2, den1, den2, operator2, commonden, commonnume, divisor;
nume1 = 0;
den1 = 0;
nume2 = 0;
den2 = 0;
char operator1;
operator2 = 0;
commonden = 0;
commonnume = 0;
divisor = 1;

cout<<"Enter numerator and denominator of first fraction: ";
cin>>nume1;
cin>>den1;
cout<<"Enter numerator and denominator of second fraction: ";
cin>>nume2;
cin>>den2;
// cout<<nume1<<" "<<den1<<" "<<nume2<<" "<<den2<<endl;

cout<<"Choose operation (+, -, *, /): ";
cin>>operator1;

operator2 = ((operator1 == '+') ? operator2 = 1: ((operator1 == '-') ? operator2 = 2: ((operator1 == '*') ? operator2 = 3 : ((operator1 == '/') ? operator2 = 4 : operator2 = 0))));

switch (operator2) {
    case 1: {
        commonden = lcm(den1, den2);
        nume1 *= commonden/den1;
        nume2 *= commonden/den2;
        commonnume = nume1 + nume2;
        divisor = gcd(commonnume, commonden);
        commonnume /= divisor;
        commonden /= divisor;
        if (commonden == 1)
            cout<<"Result: "<<commonnume;
        else
            cout<<"Result: "<<commonnume<<"/"<<commonden<<endl;
        break;
    }
        case 2: {
        commonden = lcm(den1, den2);
        nume1 *= commonden/den1;
        nume2 *= commonden/den2;
        commonnume = nume1 - nume2;
        divisor = gcd(commonnume, commonden);
        commonnume /= divisor;
        commonden /= divisor;
        if (commonden == 1)
            cout<<"Result: "<<commonnume;
        else
            cout<<"Result: "<<commonnume<<"/"<<commonden<<endl;
        break;
    }
        case 3: {
        commonden = den1 * den2;
        commonnume = nume1 * nume2;
        divisor = gcd(commonnume, commonden);
        commonnume /= divisor;
        commonden /= divisor;
        if (commonden == 1)
            cout<<"Result: "<<commonnume;
        else
            cout<<"Result: "<<commonnume<<"/"<<commonden<<endl;
        break;
    }
        case 4: {
        nume2 = nume2 + den2;
        den2 = nume2 - den2;
        nume2 = nume2 - den2;
        commonnume = nume1 * nume2;
        commonden = den1 * den2;
        divisor = gcd(commonnume, commonden);
        commonnume /= divisor;
        commonden /= divisor;
        if (commonden == 1)
            cout<<"Result: "<<commonnume;
        else
            cout<<"Result: "<<commonnume<<"/"<<commonden<<endl;
        break;
    }
}
return 0;
}