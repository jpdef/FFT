#include <complex>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cmath>
using namespace std;

#include "FFT.h"

#define PI  3.14159265359

void fourier_pair::intialize_fp(int N_,double h, fn_db init_fn_,int isig_){
	/*
	if(N<2 || N&(N-1)) {
		cout << "N must be power of 2" <<endl;
		return ;
	}
	*/
	N = N_; init_fn = init_fn_;
	isig = isig_;
	data = new complex<double>[N];
	inv_data = new complex<double>[N];
	for(int i =0;i<N;++i){
		data[i] = {double(i),0.0};
		//data[i] = {init_fn(i*h),0.0};
	}

}

double fourier_pair::transform(int k){
    double W = cos(2*PI*k/N);
  
    //optimize by doing inplace
    //Order the array
    int j = N/2;
    for(int i = 0; i<N/2;++i){
        if(i%2 !=0){
        	cout << i ;
        	while(j<N){
        		if(j%2 !=1){ 
        		   cout << j << endl;
        		   complex<double> temp = data[i];
                   data[i] = data[j];
                   data[j] = temp;
                   ++j;
                   break;
        	     }
        	     ++j;
        	}
            
        }
    }
     
   
    //Combine the elements
}


ostream& operator<<(ostream& out, fourier_pair& fp){
       for(int i =0;i<fp.N;++i){
             out << "{" << real(fp.data[i]) << "," << imag(fp.data[i]) << "}" << endl;
        }
 return out;
}


