#ifndef __FFT__H__
#define __FFT__H__

#include <memory>
#include <vector>
#include <complex>
using namespace std;
using fn_db = std::function<double(const double)>;


class fourier_pair{
  private:
  	int N;
  	int isig;
  	complex<double>* data;
  	complex<double>* inv_data;
  	fn_db init_fn;
    void bit_rev();
  	double combine(int l , int r, int k);

  public:
  	void intialize_fp(int N,double h, fn_db init_fn,int isig);
  	double transform(int k);

  	friend ostream& operator<<(ostream& out,fourier_pair& m);  


};


#endif
