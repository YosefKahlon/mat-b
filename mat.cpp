//
// Created by 97252 on 3/8/2022.
//

#include "mat.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace ariel {

    std::string mat(int width, int height, char symbol1, char symbol2) {

        //width and height need to be odd
        if (width % 2 == 0 || height % 2 == 0) {

            throw std::invalid_argument("Mat size is always odd");
        }
        //bad symbol
        if (symbol1 < 33 || symbol2 < 33) {

            throw std::invalid_argument(" whitespace ,space, newline and tab are not valid symbol ! ");
        }
        //positive
        if (width < 0 || height < 0) {

            throw std::invalid_argument("Mat size is always positive");
        }


        string ans = "";

        string matrix[width][height];

        for (int i = 0; i < height; i++) {

            for (int j = 0; j < width; j++) {
//
//                if (i == 0) {
//                    ans += symbol1;
//
//                    if (j == height-1) {
//                        ans += '\n';
//                    }
//                }


                if (j == 0) {

                    ans += symbol1;
                    ans += '\n';
                }

                if (i ==  height-1 ){
                    ans += symbol1;
                    ans += '\n';
                }
//                else if (i == 0){}



            }
        }

        return ans;

    }


}


int main() {

    std::cout << ariel::mat(9, 7, '@', '-') << endl;

}




