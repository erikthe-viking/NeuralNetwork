
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include "net.h"
#include <stdlib.h>
#include "train.h"
using namespace std;

void printVector(string label, vector<double> &v)
{
    cout << label;
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << ",";
    }

    cout << endl;
}

int main()
{
    /*
        Parsing the 35 digit input from the standard input
    */
     vector<double> input_list;
     vector<int> temp_list;
     cout << "Enter input list: "<< endl;
     string good;
     cin >> good; 
     cout << endl;
 
     for(int i = 0; i < good.size(); ++i){

         if(good.at(i) != ',' || good.at(i) != ' '){

             int x = int(good.at(i)-48);
             if (x >= 0)
               temp_list.push_back(x);
         }
     }
     for(int i = 0; i < temp_list.size(); ++i){

        double a = double(temp_list.at(i));
        input_list.push_back(a);

     }
     if(input_list.size() != 35) {

         cout << "INPUT IS NOT 35 DIGITS ERROR ! size: " << input_list.size() << endl << endl;
     }
    // Creates Training object with bit sequences of letters and output values
    train data;

    Net myNet(data.dimensions);
    int training_size = 10000;

    vector<double> inputVals, targetVals, resultVals; 

 // Training Routine
    for(int j = 0; j < training_size; ++j){
          
          for(int i = 0; i < data.alphabet.size(); ++i){
                
                inputVals = data.alphabet.at(i);
                targetVals =  data.target_list.at(i);

                myNet.feedForward(inputVals);
                myNet.Output(resultVals);
                myNet.backPropogation(targetVals);

            }
    }
    
    vector<double> output_results;

    myNet.feedForward(input_list);
    myNet.Output(output_results);
    int index_for_num = 0;
 
    /*
    *   Finds the Index with the Highest Value.
    * 
    */

    double temp = -10.0;
    for(int i = 0; i < output_results.size(); ++i){
        if(output_results.at(i) > temp){
            temp = output_results.at(i);
            index_for_num = i;
        }   
    }
 //   printVector("Input:", input_list);
  //  printVector("Results:", output_results);
    cout << "The index is : " << index_for_num;

    if(index_for_num == 0)
        cout << " Letter: A" << endl;
    if(index_for_num == 1)
        cout << " Letter: B" << endl;
    if(index_for_num == 2)
        cout << " Letter: C" << endl;
    if(index_for_num == 3)
        cout << " Letter: D" << endl;
    if(index_for_num == 4)
        cout << " Letter: E" << endl;
    if(index_for_num == 5)
        cout << " Letter: F" << endl;
    if(index_for_num == 6)
        cout << " Letter: G" << endl;
    if(index_for_num == 7)
        cout << " Letter: H" << endl;
    if(index_for_num == 8)
        cout << " Letter: I" << endl;
    if(index_for_num == 9)
        cout << " Letter: J" << endl;
    if(index_for_num == 10)
        cout << " Letter: K" << endl;
    if(index_for_num == 11)
        cout << " Letter: L" << endl;
    if(index_for_num == 12)
        cout << " Letter: M" << endl;
    if(index_for_num == 13)
        cout << " Letter: N" << endl;
    if(index_for_num == 14)
        cout << " Letter: O" << endl;
    if(index_for_num == 15)
        cout << " Letter: P" << endl;
    if(index_for_num == 16)
        cout << " Letter: Q" << endl;
    if(index_for_num == 17)
        cout << " Letter: R" << endl;
    if(index_for_num == 18)
        cout << " Letter: S" << endl;
    if(index_for_num == 19)
        cout << " Letter: T" << endl;
    if(index_for_num == 20)
        cout << " Letter: U" << endl;
    if(index_for_num == 21)
        cout << " Letter: V" << endl;
    if(index_for_num == 22)
        cout << " Letter: W" << endl;
    if(index_for_num == 23)
        cout << " Letter: X" << endl;
    if(index_for_num == 24)
        cout << " Letter: Y" << endl; 
    if(index_for_num == 25)
        cout << " Letter: Z" << endl;    
}