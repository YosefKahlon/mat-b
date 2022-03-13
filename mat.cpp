#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include "vector"

using namespace std;

namespace ariel {


    std::string mat(int width, int height, char symbol1, char symbol2) {


        //-----------------------throw-----------------------------------
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


        //-----------------------------------------------------------------------------------------------

        vector<int> a;
        vector<int> b;

        a.reserve(width);
        for (int i = 0; i < width; i++) {
            a.push_back(i);
        }
        b.reserve(height);
        for (int i = 0; i < height; i++) {
            b.push_back(i);
        }

        vector<vector<int>> min;

        //find bigger
        for (int i = 0; i < a.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < b.size(); j++) {
                if (a[i] < b[j]) {
                    temp.push_back(a[i]);
                } else {
                    temp.push_back(b[j]);
                }

            }
            min.push_back(temp);
        }

        int size = min.size() - 1;
        vector<vector<int>> res;
        for (int i = size; i >= 0; i--) {
            vector<int> temp;
            for (int j = min[i].size() - 1; j >= 0; j--) {
                temp.push_back(min[i][j]);

            }
            res.push_back(temp);
        }



        //====================================
        vector<vector<int>> yossi;
        for (int i = 0; i < min.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < min[i].size(); j++) {
                if (min[i][j] < res[i][j]) {
                    temp.push_back(min[i][j]);
                } else { temp.push_back(res[i][j]); }

            }
            yossi.push_back(temp);


        }

        // mod 2 ;
        for (int i = 0; i < yossi.size(); i++) {
            for (int j = 0; j < yossi[i].size(); j++) {
                yossi[i][j] = yossi[i][j] % 2;
            }
        }


        //symbol
        vector<vector<char>> ans;
        for (int i = 0; i < yossi.size(); i++) {
            vector<char> temp;
            for (int j = 0; j < yossi[i].size(); j++) {
                if (yossi[i][j] == 0) {
                    temp.push_back(symbol1);
                } else { temp.push_back(symbol2); }

            }
            ans.push_back(temp);
        }



        string ans1 = "";

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                ans1 += ans[i][j];

            }
            ans1 += '\n';

        }

        return ans1;


    }
}

int main() {
//
    std::cout << ariel::mat(9, 7, '@', '-') << std::endl;
    printf("3=============================");
    return 0;


}
