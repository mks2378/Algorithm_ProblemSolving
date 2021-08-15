#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> tc;
vector<int> prime;
bool pr_table[1000001] = {true,true};
bool test;

bool is_prime(int num){
	if(num==3)
		return true;	
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0)
			return false;
	}
	return true;	
}

int main()
{
	int num;
	int val1, val2;
	
	cin>>num;
	while(num!=0){
		tc.push_back(num);
		cin>>num;
	}
	
	for(int i=2;i<=sqrt(1000000);i++){
		for(int j=2;i*j<=1000000;j++)
			pr_table[i*j] = true;
	}
	
	for(int i=3;i<=1000000;i++){
		if(!pr_table[i]){
			prime.push_back(i);
		}
	}
	
	for(auto it = tc.begin();it!=tc.end();it++){
		for(auto pit = prime.begin();(*pit)<=(*(it)/2);pit++){
			if(is_prime(*(it)-*(pit))){
				cout<<*(it)<<" = "<<*(pit)<<" + "<<(*(it)-*(pit))<<'\n';
				test = true;
				break;					
			}
		}
		if(!test){
			cout<<"Goldbach's conjecture is wrong."<<'\n';
			test = false;
		}
	}
	
	return 0;
}
