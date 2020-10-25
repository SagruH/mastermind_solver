
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
  int colour_count = 8;
  int code[16];
public:
  game() {
    //set code
    for (size_t i = 0; i < code_length; i++) {
      code[i] = rand() % colour_count;
    }
  }

  void print_code() {
    for (size_t i = 0; i < code_length; i++) {
      cout << code[i] << " ";
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
