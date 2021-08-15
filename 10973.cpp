#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	
	if(prev_permutation(v.begin(),v.end())){
		for(int i=0;i<N;i++)
			cout<<v[i]<<' ';
	}
	else
		cout<<-1;	
	
	return 0;
}
