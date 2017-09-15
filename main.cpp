#include<iostream>
#include<time.h>

#include "lc_240.cpp" 

using namespace std;



int main() {
	clock_t tStart = clock();
   
	Solution::test()  ;                     

	clock_t tFinish= clock();

	cout << "Running ends!" << endl;
	cout << "Using time [" << double(tFinish - tStart) << "]" << endl;
	system("pause");
}
