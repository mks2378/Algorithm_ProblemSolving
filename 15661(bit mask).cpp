#include <iostream>
#include <algorithm>
#include <cmath> 
#include <vector>
using namespace std;

int N;
int MAP[20][20];
int result = 987654321;

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>MAP[i][j];
	
	for(int b=1;b<(1<<N)-1;b++){
		vector<int> v_start;
		vector<int> v_link;
		for(int i=0;i<N;i++){
			if((b&(1<<i))!=0)
				v_start.push_back(i);
			else
				v_link.push_back(i);
		}
		
		int start_sum=0;
		int link_sum=0;
		
		if(v_start.size()==1)
			start_sum=0;
		else{
			for(int i=0;i<v_start.size()-1;i++){
				for(int j=i+1;j<v_start.size();j++){
					start_sum+=MAP[v_start[i]][v_start[j]];
					start_sum+=MAP[v_start[j]][v_start[i]];	
				}
			}
		}
		
		if(v_link.size()==1)
			link_sum=0;
		else{
			for(int i=0;i<v_link.size()-1;i++){
				for(int j=i+1;j<v_link.size();j++){
					link_sum+=MAP[v_link[i]][v_link[j]];
					link_sum+=MAP[v_link[j]][v_link[i]];	
				}
			}
		}
		
		result = min(result,abs(start_sum-link_sum));
	}
	
	cout<<result;
	return 0;
}
