#include <iostream>
#include <vector>
using namespace std;

int num;
vector<char> v[26];

void preorder(char ch){
	cout<<ch;
	
	if(v[ch-'A'][0] != '.' && !v[ch-'A'].empty())
		preorder(v[ch-'A'][0]);
	if(v[ch-'A'][1] != '.' && !v[ch-'A'].empty())
		preorder(v[ch-'A'][1]);	
}

void inorder(char ch){
	if(v[ch-'A'][0] != '.' && !v[ch-'A'].empty())
		inorder(v[ch-'A'][0]);
		
	cout<<ch;
	
	if(v[ch-'A'][1] != '.' && !v[ch-'A'].empty())
		inorder(v[ch-'A'][1]);	
}

void postorder(char ch){
	if(v[ch-'A'][0] != '.' && !v[ch-'A'].empty())
		postorder(v[ch-'A'][0]);
	
	if(v[ch-'A'][1] != '.' && !v[ch-'A'].empty())
		postorder(v[ch-'A'][1]);	
		
	cout<<ch;
}

int main(){
	char node, node_left, node_right;
	cin>>num;
	
	for(int i=0;i<num;i++){
		cin>>node>>node_left>>node_right;
		
		v[node-'A'].push_back(node_left);	
		v[node-'A'].push_back(node_right);		
	}
	
	preorder('A');
	cout<<'\n';
	inorder('A');
	cout<<'\n';
	postorder('A');
	
	return 0;
}
