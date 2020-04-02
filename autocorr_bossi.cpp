//
//
//				non ti commento il codice per vedere quanto si capisce di impatto
//				   direi che dopo che lo hai visto li scrivo quelli necessari
//
#include<iostream>
#include<vector>
#include<functional>
#include "gnuplot-iostream.hpp"
#include<algorithm>
#include<cmath>
class basic_fun{//ho usato classi solo per usarle... non c'era un motivo
	public:
	basic_fun(const double &in_min_, const double &in_max_, const double &step):
		in_min{in_min_},
		in_max{in_max_},
		dt{step}{};

	std::vector<double> autocorr(const std::function<double(const double &)> &f, const std::vector<double> &x_){
		std::vector<double> result;
		result.reserve(x_.size());
		double sum;
		for(auto x : x_){
			sum=0;
			for(double t=in_min; t<in_max; t+=dt)
				sum+=f(t)*f(t-x)*dt;
			result.push_back(sum);
			}
		return result;	
	}
	private:
		const double in_min, in_max, dt;
};

int main(){
	const unsigned int size{100};
	basic_fun sample(-100,100,0.1);
	std::vector<double> x;
	std::vector<double> result;
	x.reserve(size);
	x.reserve(size);
	for(unsigned int i=0; i<size; i++)
		x.push_back(static_cast<double>(i)/10.);
	result=sample.autocorr(sin,x);
	Gnuplot gp; 
	gp<<"plot"<<gp.file1d(result)<<"w lp"<<std::endl ;
	return 0;
}


/* test
double f(const double &x){
	if(std::abs(x)<10)
		return 1;
	return 0;

}*/
