#include<iostream> 
#include<functional>
#include<vector> 
#include<cmath> 
#include<math.h>
#include "gnuplot-iostream.hpp"

 
// funzione che mi fa l auto correlazione  
std::vector<double>  autocorr(std::vector<double> &a , std::vector<double> &b , std::vector<double> &x, int &size ){


// i due cicli servono per far scorrere il vettore b mentre quello a sta fermo, guarda i disegni dove gli ASTERISCHI sono 
// gli elementi del vettore
//Questo è come devono scorrere i vettori 

//     * * * *         -->  * * * *      -->   * * * *    -->   * * * *  -->    * * * *  -->      * * * * -->       * * *  *
//           * * * *            * * * *          * * * *        * * * *       * * * *         * * * *          * * * *



				std::vector<double> result(2*size) ; 
				double sum {0}; 
				int k {0}; 
				for ( int m {99}; m>=0 ; --m ) {          // questo ciclo fa   * * * * -->
									 //		             * * * *
					for (int  i {0} ; i!=100-m; i++  ){
									
					sum+= a[i]*b[m+i] ; 
					}
					
					result [k]=sum ;
					sum = 0 ;
					k++; 	
					} 
				
					
				for ( int m=1; m!=100; m++) {        // questo fa         * * * * --> 
								    //	            * * * *
					for ( int i=0; i!=100-m;i++) {
					
					sum += a[i+m]*b[i];
					}
					
					
					result[k] = sum ; 					
					sum = 0 ;
					k++ ;  
}
					


return result ; }












int main ( int argc, char** argv){
	
	double x_0 {0} ; 
	double x_end {1} ; 
	int size {100}; 
	double step{ x_end/size} ; 
	double T{0.5}; 

	std::vector<double> x(size) ; 
	std::vector<double> a(size) ;
	std::vector<double> b(size) ;
	
	auto n = a.begin() ; 
	auto m = b.begin() ; 
	
	int i {0}; 
	for ( auto j=x.begin(); j!=x.end();j++){
         
 	
	*j = i*step ; 
	*m++ = 5*sin(2*3.14*(*j)/T); 
	*n++ = 5*sin(2*3.14*(*j)/T); 
	i++; 
	}


 std::vector<double>ans(2*size); 
 ans = autocorr(a,b,x,size) ; 



	
	
	Gnuplot gp ; 
gp<<"plot"<<gp.file1d(ans)<<"w lp"<<std::endl ;
//<<gp.file1d(boost::make_tuple(x,a))<<"w lp,"<<gp.file1d(boost::make_tuple(x,b))<<"w lp,"

return 0 ;
} 
	 		
