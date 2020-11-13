
//github: https://github.com/SagruH/mastermind_solver

//This file contains the main game logic


#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

class game {
private:
  int code_length = 4; //max code length is 16
  int colour_count = 8; //amount of colours
  int code[16];

  //additional game inforamtion
  int amount_of_unique_numbers = 0; //AouN

public:
  game() { //constructor
    //set code
    for (size_t i = 0; i < code_length; i++) {
      code[i] = rand() % colour_count;
    }
  unique_numbers(); //deactivate to speed up
  }

  void unique_numbers() {
    //find amount of unique numbers
    amount_of_unique_numbers = 1;
    vector<int> u_nums;
    u_nums.push_back(code[0]);

    for (size_t j = 0; j < code_length; j++) {

      for (size_t i = 1; i < code_length; i++) {
        if ( code[j] == code[i]) break;
      }

    }

  }

  void print_code() {
    for (size_t i = 0; i < code_length; i++) {
      cout << code[i] << " ";
    }
    if (amount_of_unique_numbers =! 0) {
      cout << " AouN: " << amount_of_unique_numbers;
    }
    cout << endl;
  }

};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  srand(time(NULL));

  for (size_t i = 0; i < 50; i++) {
    game game1;
    game1.print_code();
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}
