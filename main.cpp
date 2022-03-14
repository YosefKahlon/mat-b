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

    printf("-----inpot from client----- \n");

    int width, height;
    char symbol1, symbol2;
    cout << "Please enter the number for width and the number for height : " << endl;
    cin >> width >> height;
    cout << "enter 2 symbol: " << endl;
    cin >> symbol1 >> symbol2;
    cout << "================================================ \n" << endl;
    cout << ariel::mat(width, height, symbol1, symbol2) << endl;
    cout << "================================================ " << endl;


    printf("-----random input ----- \n");
    srand((unsigned) time(0));
    int num1;
    num1 = (rand() % 30) + 1;
    if (num1 % 2 == 0) {
        num1 += 1;
    }
    int num2;
    num2 = (rand() % 30) + 1;
    if (num2 % 2 == 0) {
        num2 -= 1;
    }
    char arr[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '=', '_', '-', 'W', 'R', 'G', '1', '2', '3',
                  '4', '8',
                  '9', 'Z', 'X', 'y', 'n', ':'};

    char one, two;
    int num3, num4;
    num3 = (rand() % 29);
    num4 = (rand() % 29);
    one = arr[num3];
    two = arr[num4];

    cout << "================================================ \n" << endl;
    cout << " the input ------->    " << num1 << " " << num2 << " " << one << " " << two << " " << endl;
    cout << ariel::mat(num1, num2, one, two) << endl;
    cout << "================================================ " << endl;


    return 0;
}