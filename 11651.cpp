#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt, x, y;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second!=b.second)
		return a.second<b.second;
		
	else
		return a.first<b.first;	
}

int main(){
	cin>>cnt;
	
	for(int i=0;i<cnt;i++){
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<cnt;i++)
		cout<<v[i].first<<' '<<v[i].second<<'\n';
	
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;

int main(){
	int count;
	int value_x,value_y;
	
	cin>>count;
	for(int i=0;i<count;i++){
		cin>>value_x>>value_y;
		v.push_back(make_pair(value_y,value_x));
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<count;i++){
		cout<<v[i].second<<' '<<v[i].first<<'\n';
	}
	
	return 0;
}
*/
