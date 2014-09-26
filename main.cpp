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
	return 5.0 + 2*cos((PI*2.0)*x - PI/2.0) + 3*cos(4*PI*x);
}

int main(){
    fourier_pair fp{}; 
    fp.intialize_fp(4, 1.0/4.0, func,1);
    cout << fp << endl;
    cout << fp.transform(2)<< endl;
    cout << fp <<endl;
    
    return 0;
}

