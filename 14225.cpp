#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000001

int N;
bool visited[MAX];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	
	for(int b=1;b<(1<<N);b++){
		int sum=0;
		for(int i=0;i<N;i++){
			if((b&(1<<i))!=0)
				sum+=v[i];
		}
		if(!visited[sum])
			visited[sum] = true;			
	}
	
	for(int i=1;i<MAX;i++){
		if(!visited[i]){
			cout<<i;
			break;	
		}
	}

	return 0;
}
