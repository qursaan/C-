#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	cout<<min(min(n,m),(n+m)/3)<<endl;
}
