#include <iostream>
#include <cmath>
#include <iomanip>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>

using namespace std;
using namespace CGAL;

typedef Gmpz ET;
typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

void solve(int p,int a,int b){

	cout<<setprecision(15);
	const int X=0;
	const int Y=1;
	const int Z=2;

	if(p==1){
		Program lp(SMALLER,true,0,false,0);

		lp.set_a(X,0,1); lp.set_a(Y,0,1); lp.set_b(0,4);
		lp.set_a(X,1,4); lp.set_a(Y,1,2); lp.set_b(1,a*b);
		lp.set_a(X,2,-1); lp.set_a(Y,2,1); lp.set_b(2,1);

		lp.set_c(Y,-b);
		lp.set_d(X,X,2*a);

		Solution s = solve_quadratic_program(lp,ET());

		if(s.is_optimal()){
			cout<<floor((-1)*to_double(s.objective_value()))<<endl;
		}else if(s.is_unbounded()){
			cout<<"unbounded"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	if(p==2){
		Program lp(LARGER,false,0,true,0);

		lp.set_a(X,0,1); lp.set_a(Y,0,1); lp.set_b(0,-4);
		lp.set_a(X,1,4); lp.set_a(Y,1,2); lp.set_a(Z,1,1); lp.set_b(1,-a*b);
		lp.set_a(X,2,-1); lp.set_a(Y,2,1); lp.set_b(2,-1);

		lp.set_l(Z,true,0);
		lp.set_u(Z,false,0);

		lp.set_d(X,X,2*a);
		lp.set_c(Y,b);
		lp.set_d(Z,Z,2);

		Solution s = solve_quadratic_program(lp,ET());

		if(s.is_optimal()){
			if(ceil(to_double(s.objective_value()))==-0)
				cout<<0<<endl;
			else
				cout<<ceil(to_double(s.objective_value()))<<endl;
		}	
		else if(s.is_unbounded()){
			cout<<"unbounded"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}

int main(){

	while(true){
		int p,a,b;
		cin>>p;
		if(p==0)
			break;

		cin>>a>>b;
		solve(p,a,b);
	}
}

