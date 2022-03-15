#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include "vector"

using namespace std;

namespace ariel {


    string just_height(int height, char symbol1);

    string just_width(int width, char symbol1);

    vector<int> add_number(int n);

    vector <vector<int>> get_min(vector<int> a, vector<int> b);

    vector <vector<int>> upside(vector <vector<int>> min, int height, int width);

    vector <vector<int>> merge_min(vector <vector<int>> min, vector <vector<int>> reverse);

    vector <vector<char>> symbol(vector <vector<int>> together, char symbol1, char symbol2);








    /**
     * This function get input and return mat .
     * the algorithm step by step :
     * 1. create vector of vector(2D array) of min( (0 - (width-1) ) , (0 - (height-1)) ) . let's call it min_2D.
     * 2. create vector of vector(2D array) as a reverse of the rows and the cols of the the 2D array we create above. let's call it reverse_2D.
     * 3. create vector of vector (2D array) of the minimum between each number in every rows and cols between min_2D and reverse_2D .let's call it together.
     * 4. modulo by 2 the the 2D array - together .
     * 5. create vector of vector (2D array of char)  let's call it answer_2D.
     * 6. if together_2D at row i in positions j = 0 add to answer_2D symbol1 else add to answer_2D symbol2.
     * 7. convert answer_2D into string.
     * 8. return string .
     * @param width positive odd number.
     * @param height positive odd number.
     * @param symbol1 any  33 < symbol < 126.
     * @param symbol2 any  33 < symbol < 126.
     * @return string represent the mat .
     *
     *i took the idea from the comment https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
     */






    std::string mat(int width, int height, char symbol1, char symbol2) {


        //-----------------------throw invalid_argument -----------------------------------
        //width and height need to be odd
        if (width % 2 == 0 || height % 2 == 0) {

            throw std::invalid_argument("Mat size is always odd");
        }
        // ! = 33 , ~ = 126
        if (symbol1 < '!' || symbol2 < '!' || symbol1 > '~' || symbol2 > '~') {

            throw std::invalid_argument(" whitespace ,space, newline and tab are not valid symbol ! ");
        }
        //positive
        if (width < 0 || height < 0) {

            throw std::invalid_argument("Mat size is always positive");
        }

        string answer;


        // if width = 1 no need to continue
        if (width == 1) {
            answer = just_height(height, symbol1);
            return answer;
        }


        // if height = 1 no need to continue
        if (height == 1) {
            answer = just_width(width, symbol1);
            return answer;
        }

        //add the number from 0 to width-1 / height-1
        vector<int> a = add_number(width); // vector for width
        vector<int> b = add_number(height);  // vector for height


        //find the minimum between a and b for each row
        vector <vector<int>> min_2D = get_min(a, b);


        //upside min and revers the row
        //int size = min.size() - 1;
        vector <vector<int>> reverse_2D = upside(min_2D, height, width);


        //take the minimum number from min and reverse and insert to a new vector
        vector <vector<int>> together_2D = merge_min(min_2D, reverse_2D);


        // modulo 2 the vector ;
        for (int i = 0; i < together_2D.size(); i++) {
            for (int j = 0; j < together_2D.at(i).size(); j++) {
                together_2D.at(i).at(j) = together_2D.at(i).at(j) % 2;
            }
        }

        // change number to symbols
        vector <vector<char>> ans_2D = symbol(together_2D, symbol1, symbol2);

        //convert vector to string
        for (int i = 0; i < ans_2D.size(); i++) {
            for (int j = 0; j < ans_2D.at(i).size(); j++) {
                answer += ans_2D.at(i).at(j);
            }
            answer += '\n';
        }

        return answer;


    }

    vector <vector<char>> symbol(vector <vector<int>> together, char symbol1, char symbol2) {
        vector <vector<char>> ans;
        for (int i = 0; i < together.size(); i++) {
            vector<char> temp;
            for (int j = 0; j < together.at(i).size(); j++) {
                if (together.at(i).at(j) == 0) {
                    temp.push_back(symbol1);
                } else { temp.push_back(symbol2); }

            }
            ans.push_back(temp);
        }
        return ans;
    }


    vector <vector<int>> merge_min(vector <vector<int>> min, vector <vector<int>> reverse) {
        vector <vector<int>> together;
        for (int i = 0; i < min.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < min.at(i).size(); j++) {
                if (min.at(i).at(j) < reverse.at(i).at(j)) {
                    temp.push_back(min.at(i).at(j));
                } else { temp.push_back(reverse.at(i).at(j)); }

            }
            together.push_back(temp);

        }
        return together;
    }

    vector <vector<int>> upside(vector <vector<int>> min, int height, int width) {
        vector <vector<int>> reverse;
        for (int i = height - 1; i >= 0; i--) {
            vector<int> temp;
            for (int j = width - 1; j >= 0; j--) {
                temp.push_back(min.at(i).at(j));
            }
            reverse.push_back(temp);
        }
        return reverse;
    }

    vector <vector<int>> get_min(vector<int> a, vector<int> b) {

        vector <vector<int>> vector_min;

        if (a.size() > b.size()) {

            for (int i = 0; i < b.size(); i++) {
                vector<int> temp;
                for (int j = 0; j < a.size(); j++) {
                    if (a.at(j) > b.at(i)) {
                        temp.push_back(b.at(i));
                    } else {
                        temp.push_back(a.at(j));
                    }

                }
                vector_min.push_back(temp);
            }
        } else {
            for (int i = 0; i < b.size(); i++) {
                vector<int> temp;
                for (int j = 0; j < a.size(); j++) {
                    if (b.at(i) > a.at(j)) {
                        temp.push_back(a.at(j));
                    } else {
                        temp.push_back(b.at(i));
                    }

                }
                vector_min.push_back(temp);
            }
        }

        return vector_min;
    }

    vector<int> add_number(int n) {
        vector<int> a;
        a.reserve(n);
        for (int i = 0; i < n; i++) {
            a.push_back(i);
        }
        return a;
    }

    std::string just_width(int width, char symbol1) {
        string ans;
        for (int i = 0; i < width; ++i) {
            ans += symbol1;
        }
        return ans;
    }


    std::string just_height(int height, char symbol1) {
        string ans;
        for (int i = 0; i < height; ++i) {
            ans += symbol1;
            ans += '\n';
        }
        return ans;
    }

}

