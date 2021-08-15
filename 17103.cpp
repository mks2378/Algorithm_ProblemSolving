#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime[1000001];

// *** time laps ***
//bool is_prime(int num){
//	if(num==2)
//		return true;
//	else if(num==3)
//		return true;
//	else{
//		for(int i=2;i<=sqrt(num);i++){
//			if(num%i==0)
//				return false;
//		}
//		return true;
//	}
//}

int main()
{
	vector<int> v;
	int num, tc;
	
	cin>>tc;
	
	for(int i=0;i<tc;i++){
		cin>>num;
		v.push_back(num);
	}
	
	for(int i=2;i<=sqrt(1000000);i++){
		for(int j=2;i*j<=1000000;j++){
			is_prime[i*j] = true;
		}
	}
	
	int prime_cnt=0;
	for(int i=0;i<v.size();i++){
		for(int j=2;j<=(v[i]/2);j++){
			if(!is_prime[j] && !is_prime[v[i]-j]){
				prime_cnt++;
			}
		}
		cout<<prime_cnt<<'\n';
		prime_cnt=0;
	}
	
	return 0;
}
