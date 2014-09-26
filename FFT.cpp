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
		//data[i] = {double(i),0.0};
		data[i] = {init_fn(i*h),0.0};
		cout << i << " , " << i*h << endl;
	}

}

double fourier_pair::transform(int k){
    //optimize by doing inplace
    //Order the array
    bit_rev();
    return combine(0,N-1,k);

   
    //Combine the elements
}
void fourier_pair::bit_rev(){
    int j = N/2;
    for(int i = 0; i<N/2;++i){
        if(i%2 !=0){
        	while(j<N){
        		if(j%2 !=1){ 
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
}
double fourier_pair::combine(int l , int r, int k){
	//sleep(1);
     if(r-l < 2) {
        complex<double> twiddle = {cos((2*PI*k)/double(r+1)),0.0};
        cout << "k " << k << endl;
        cout <<"twiddle " <<cos((2*PI*k)/double(r+1))  << endl; 
        cout <<" index " << l << "+ index "<< r<<endl;

         
         return real(data[l]) + real(twiddle)*real(data[r]);
     }  else {
        
        complex<double>twiddle = {cos((2*PI*k)/double(r+1)),0.0};
     	cout << " --- recurr ---" << endl;
     	cout << l << " , " << (r+l)/2  << endl;
     	cout << (r+l)/2+1 << " , " << r << endl;
        cout <<" twiddle " << twiddle << endl;
        cout << "k " << k << endl;

     	return combine(l,(r+l)/2, 2*k) + 
                real(twiddle)*combine((r+l)/2+1,r,2*k);
     }   
}


ostream& operator<<(ostream& out, fourier_pair& fp){
       for(int i =0;i<fp.N;++i){
             out << "{" << real(fp.data[i]) << "," << imag(fp.data[i]) << "}" << endl;
        }
 return out;
}


