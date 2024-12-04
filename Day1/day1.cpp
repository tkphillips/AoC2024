#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h> 
#include <algorithm>
#include <chrono>
using namespace std;

int main() {
  vector<string> in;
  string word;
  ifstream myfile;
  vector<string> list1;
  vector<string> list2;
  //Import Data
  myfile.open("../Inputs/input1.txt");
  if (myfile.is_open()){
      while (myfile >> word){
        list1.push_back(word);
        myfile >> word;
        list2.push_back(word);
      }
      myfile.close();
  }

  //Part1
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());
  int total = 0;
  for(int i = 0; i < list1.size(); i++){
    total += abs(stoi(list1.at(i)) - stoi(list2.at(i)));
  }
  cout << "Total distance: " << total << endl;

  //Part 2
  total = 0;
  for(int i = 0; i < list1.size(); i++){
    for(int j = 0; j < list1.size(); j++){
      if(stoi(list1.at(i)) == stoi(list2.at(j))){
      total += stoi(list1.at(i));
    }
    }
  }
  cout << "Total similarity: " <<total << endl;
}