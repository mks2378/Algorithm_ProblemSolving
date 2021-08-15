#include <iostream>
using namespace std;

int a[1001];
int d[1001];
int v[1001];

int main(){
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++)
		cin>>a[i];
	
	for(int i=0;i<N;i++){
		d[i] = 1;
		v[i] = 0;
		
		for(int j=0;j<i;j++){
			if(a[j]<a[i] && d[i]<d[j]+1){
				d[i] = d[j]+1;
				v[i] = j;
			}
		}
	}
	
	int max = d[0];
	int maxi = 0;
	for(int i=1;i<N;i++){
		if(max<d[i]){
			max = d[i];
			maxi = i;
		}
	}
	cout<<max<<'\n';
	
	int ans[1001];
	for(int i=0;i<max;i++){
			ans[i] = a[maxi];
			maxi = v[maxi];
	}
	
	for(int i=1;i<=max;i++){
		cout<<ans[max-i]<<' ';
	}

	return 0;
}
