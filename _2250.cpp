#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 10000 + 1;

int N;
int nodeIdx=1; // ���ʿ������� �� ��° node���� ����Ű�� ���� 
int node[MAX];
int low[MAX];
int high[MAX];
pair<int,int> tree[MAX];

// cnt == level
void DFS(int nodeNum, int level){
	//left subtree
	if(tree[nodeNum].first>0)
		DFS(tree[nodeNum].first, level+1);
		
	//visit
	// ���� ������ ���鿡 ����  
	low[level] = min(low[level], nodeIdx);	
	hight[level] = max(hight[level], nodeIdx++);
	
	//right subtree
	if(teee[nodeNum].second>0)
		DFS(tree[nodeNum].second, level+1);
}
 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); // cin �ӵ� ���  
	cin>>N;
	
	for(int i=0;i<MAX;i++)
		low[i] = INT_MAX;
	
	// tree ���� �� root ã�� ���� node �� ����  
	for(int i=0;i<N;i++){
		int parent, child1, child2;
		cin>>parent>>child1>>child2;
		
		node[parent]++;
		
		if(child1 != -1)
			node[childe1]++;
			
		tree[parent].first = child1;
		
		if(child2 != -1)
			node[childe2]++;
		
		tree[parent].second = child2;
	}
	
	// ��Ʈ ã��  
	int root;
	for(int i=1;i<=N;i++)
		if(node[i] == 1)
			root = i;
	
	//DFS
	DFS(root,1);
	
	// �ִ� ���� ���ϱ� 
	int answer_width = high[1] - low[1] + 1;
	int answer_level = 1;
	for(int i=2;i<=N;i++){
		int temp = high[i] - low[i] + 1;
		if(temp>answer_width){
			answer_width = temp;
			answer_level = i;
		}
	}
	cout<<answer_level<<" "<<answer_width<<"\n";	
	return 0;
}
