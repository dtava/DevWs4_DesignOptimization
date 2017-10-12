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

  // ----- EXERCISE 1 ----- // - Possible solution
  // optimize initialization of vector and matrix

  // initialize 1e8 vector to 1
  std::vector<double> myvector(1e8, 1.0);





  // initialize 1e8 matrix to 1
  std::vector<double> tmpVector(1e4, 1.0);
  std::vector<std::vector<double>> mymatrix(1e4, tmpVector);
  std::vector<double>().swap(tmpVector);






  // ----- END EXERCISE 1 ----- //


  // ----- EXERCISE 2 ----- // - possible solution
  // optimize time

  // fill matrix with column numbers
  for (size_t i=0; i<1e4; i++) {
    for (size_t j=0; j<1e4; j++) {
      mymatrix[i][j] = j;
    }
  }

  // delete mymatrix
  std::vector<std::vector<double>>().swap(mymatrix);


  // set all elements multiples of 1e3 to zero
  for (size_t i=0; i<myvector.size(); i+=1000) {
    myvector[i] = 0.0;
  }
  // ----- END EXERCISE 2 ----- //


  /* end code */

  auto te = high_resolution_clock::now();
  std::cout << "Time running " << duration<double>(te - ts).count() << " s." << std::endl;

  return 0;
}
