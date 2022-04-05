/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include<ctype.h>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main() {

  

  // Matrix mat({}, 0, 0);
  // cin >> mat;
  // cout << mat << endl;
  
  std::vector<double> identity = {1,2,3,4,5,6};
  // std::vector<double> arr = {1,2,3,4,5,6};
  Matrix a{identity, 3, 2};  // constructor taking a vector and a matrix size
  // Matrix c(arr, 2, 3);
  // 3*=a;

  // cout << a<<endl;
  // cout << 3*a <<endl;
  // std::vector<std::vector<double>> arr2 =a.turnVec2D();
//   for (size_t i = 0; i < arr2.size(); i++)
// {
//     cout << "\n";
//     for (size_t j = 0; j < arr2[i].size(); j++)
//     {
//         cout << arr2[i][j] << " ";
//     }
// }

  // cout<< a << endl;
  // a*=3;
  // cout<< a << endl;
  
  /* prints [1 0 0]
            [0 1 0]
            [0 0 1]*/
  // b -= a;
  // cout << a << endl;
  // cout << b << endl;

  // cout << a-a << endl;
  // cout << (-a) << endl;
  // cout << (a) << endl;

  /* prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]*/
  // cout << (3*a) << endl;
  // /* prints [3 0 0]
  //           [0 3 0]
  //           [0 0 3]*/

  // Matrix b{arr, 3, 3};
  // a *= -3;
  // cout << (a+b) << endl;  // prints the 0 matrix
  // cout << (b-a) << endl;
  // /* prints [6 0 0]
  //           [0 6 0]
  //           [0 0 6]*/

  // // if(a ==b){
  // //   cout<<"true\n";
  // // }else{
  // //   cout <<"false\n";
  // // }

  cout << "End of demo!" << endl;
  return 0;
}