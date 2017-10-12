#include <cmath>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>


using std::chrono::high_resolution_clock;
using std::chrono::duration;


// MAIN program
int main(int argc, char const *argv[]) {


  auto ts = high_resolution_clock::now();

  /* code */

  // ----- EXERCISE 1 ----- //
  // optimize initialization of vector and matrix

  // initialize 1e8 vector to 1
  std::vector<double> myvector;
  for (int i=0; i<1e8; i++) {
    myvector.push_back(1);
  }


  // initialize 1e8 matrix to 1
  std::vector<std::vector<double>> mymatrix;
  for (int i=0; i<1e4; i++) {

    std::vector<double> tmpvector;
    for (int j=0; j<1e4; j++) {
      tmpvector.push_back(1);
    }
    mymatrix.push_back(tmpvector);
  }
  // ----- END EXERCISE 1 ----- //


  // ----- EXERCISE 2 ----- //
  // optimize time

  // fill matrix with column numbers
    for (size_t j=0; j<1e4; j++) {
  for (size_t i=0; i<1e4; i++) {
      mymatrix[i][j] = j;
    }
  }

  // delete mymatrix
  mymatrix.clear();


  // set all vector elements multiples of 1e3 to zero
  for (size_t i=0; i<myvector.size(); ++i) {
    myvector[i] = (0 == i%1000) ? 0.0 : 1.0;
  }
  // ----- END EXERCISE 2 ----- //


  /* end code */

  auto te = high_resolution_clock::now();
  std::cout << "Time running " << duration<double>(te - ts).count() << " s." << std::endl;

  return 0;
}
