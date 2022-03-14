//
// Created by 97252 on 3/14/2022.
//

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "mat.hpp"
#include <vector>

using namespace std;
using namespace ariel;

char randsighs()
{
    const char sighs[] = {'!', '@', '#', '$', '%', '^', '&', '*', '-', '_', '=', '+', '`', '~'};
    int idx = rand() % 14;
    return sighs[idx];
}

int main()
{

    char a;
    char b;
    int col, row;
    cout << "enter row and column number: " << endl;
    cin >> row >> col;
    cout << "enter 2 chars: " << endl;
    cin >> a >> b;
    cout << "the outpt is:" << endl
         << ariel::mat(col, row, a, b) << endl;
    a = randsighs();
    b = randsighs();
    cout << "another mat with random chars:" << endl;
    cout << ariel::mat(col, row, a , b) << endl;
    cout << "bye bye.." << endl;
}