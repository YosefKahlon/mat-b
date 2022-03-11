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

        matrix = func(matrix, width ,height , symbol1 , symbol2);

        for (int i = 0; i < width; i++) {

            for (int j = 0; j < height; j++) {

                if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {
                    matrix[i][j] = symbol1;

                } else {
                    std::cout << i << ",";
                    std::cout << j << endl;

                    matrix[i][j] = symbol2;


                }


            }
        }
        mat(width - 2, height - 2, symbol1, symbol2);





        //---------------print--------------------------------
        for (int i = 0; i < width; i++) {

            for (int j = 0; j < height; j++) {

                std::cout << matrix[i][j] << " ";

            }
            std::cout << endl;
        }


        return ans;


    }




}

int main() {

    std::cout << ariel::mat(9, 7, '@', '-') << std::endl;

}




