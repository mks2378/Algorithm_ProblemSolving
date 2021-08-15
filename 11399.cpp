#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int total, N;

int main(){
	int min;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>min;
		v.push_back(min);	
	}

	sort(v.begin(),v.end());
	
	for(int i=1;i<=N;i++)
		for(int j=0;j<i;j++)
			total += v[j];		

	cout<<total;	
	
	return 0;
}
