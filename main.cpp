//
// Created by 97252 on 3/14/2022.
//

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "mat.hpp"
#include <vector>
#include "mat.cpp"

using namespace std;
using namespace ariel;



int main() {

    int width, height;
    char symbol1, symbol2;
    cout << "Please enter the number for width and the number for height : " << endl;
    cin >> width >> height;
    cout << "enter 2 symbol: " << endl;
    cin >> symbol1 >> symbol2;
    cout << "================================================ \n" << endl;
    cout << ariel::mat(width, height, symbol1, symbol2) << endl;
    cout << "================================================ " << endl;

    return 0;
}