#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	vector<int> v;
	int num;
	
	cin>>num;
	
	if(num==2 || num==3){
		cout<<num;
		return 0;
	}
	
	for(int i=2;i<=num;i++){
		while(true){
			if(num%i==0){
				v.push_back(i);
				num/=i;	
			}
			else
				break;
		}		
	}
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<'\n';
	
	return 0;
}
