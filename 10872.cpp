#include <iostream>

using namespace std;

int main(){
	long long result = 1;
	int num;
	
	cin>>num;
	
	for(int i=1;i<=num;i++)
		result *= i;
		
	cout<<result;	
	
	return 0;
}
