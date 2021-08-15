#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct person{
	string name;
	int age;
	int priority;
};

vector<person> v;
int cnt;

bool cmp(person a, person b){
	if(a.age!=b.age)
		return a.age<b.age;
	else
		return a.priority<b.priority;
}

int main(){
	cin>>cnt;
	
	person p;
	for(int i=0;i<cnt;i++){
		cin>>p.age>>p.name;
		p.priority = i;
		v.push_back(p);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<cnt;i++)
		cout<<v[i].age<<' '<<v[i].name<<'\n';
	
	return 0;
}
