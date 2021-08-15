#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person{
	int korean, math, eng;
	string name;
};

bool cmp(person a, person b){
	if(a.korean!=b.korean)
		return a.korean>b.korean;
	else{
		if(a.eng!=b.eng)
			return a.eng<b.eng;
		else{
			if(a.math!=b.math)
				return a.math>b.math;
			else
				return a.name<b.name;	
		}
	}	
}

int main(){
	vector<person> v;
	person p;
	int cnt;
	
	cin>>cnt;
	
	for(int i=0;i<cnt;i++){
		cin>>p.name>>p.korean>>p.eng>>p.math;
		v.push_back(p);		
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<cnt;i++)
		cout<<v[i].name<<'\n';
	
	return 0;
}
