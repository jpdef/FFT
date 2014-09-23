// $Id: main.cpp,v 1.13 2014-05-08 18:32:56-07 - - $

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cmath>
using namespace std;
#define PI  3.14159265359

#include "FFT.h"

double func(double x){
	return sin(2.0*PI*x);
}

int main(){
    fourier_pair fp{}; 
    fp.intialize_fp(8, 0.1, func,1);
    cout << fp << endl;
    fp.transform(8);
    cout << fp <<endl;
    
    return 0;
}

