#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(9);
int sum;

void snow_white(){
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(sum-v[i]-v[j]==100){
				for(int k=0;k<9;k++){
					if(k!=i&&k!=j)
						cout<<v[k]<<'\n';
				}
				return;
			}
		}
	}
}

int main(){
	for(int i=0;i<9;i++){
		cin>>v[i];
		sum+=v[i];
	}
	
	sort(v.begin(), v.end());
	snow_white();
	
	return 0;
}
