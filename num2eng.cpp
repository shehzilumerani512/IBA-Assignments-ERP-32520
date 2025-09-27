#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int figure, ones, tens, hundreds, thousands, tenthousands, hundredthousands;
    string sign;
    string singles[] = {"","one","two","three","four","five","six","seven","eight","nine"};
    string teens_words[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string multiples[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string amount = "";
    ones = 0;
    tens = 0;
    hundreds = 0;
    thousands = 0;
    tenthousands = 0;
    hundredthousands = 0;
    cout<<"Enter an amount in figures: ";
    cin>>figure;
    if (figure < 0 and figure > -999999)
        sign = "-";
    else if (figure > 0 and figure < 999999)
        sign = "+";
    
    figure = abs(figure);

    if (figure == 0)
        cout<<"zero";
    else if (figure > 999999)
        cout<<"Number out of bounds.";
    else {
        ones = figure % 10;
        figure /= 10;
        tens = figure % 10;
        figure /= 10;
        hundreds = figure % 10;
        figure /= 10;
        thousands = figure % 10;
        figure /= 10;
        tenthousands = figure % 10;
        figure /= 10;
        hundredthousands = figure % 10;
        figure /= 10;

        if (hundredthousands != 0)
            amount += singles[hundredthousands] + " hundred ";
        if (thousands > -1 and tenthousands == 1)
            amount += teens_words[thousands] + " thousand ";
        else if (thousands > 0)
           amount += multiples[tenthousands] + " " + singles[thousands] + " thousand ";
        if (thousands == 0 and tenthousands == 0)
            amount += " thousand ";
        if (hundreds != 0)
            amount += singles[hundreds] + " hundred ";
        if (ones > -1 and tens == 1)
            amount += teens_words[ones];
        else
            amount += multiples[tens] + " " + singles[ones];
        }
    if (sign == "-")
        cout<<"negative " + amount;
    else
        cout<<amount;
    return 0;
}