/*
Pots
题意：倒水问题，要求输出方案
分析：先想的DFS，然后爆栈了，网上都用BFS，但都很复杂 
*/
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<stack>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
const char OUT[3][10]={"FILL","DROP","POUR"};
struct oper{
	int v,a,b;
	oper(int v,int a,int b):v(v),a(a),b(b){}
};
stack<oper> ans;
int T,ma,mb;
bool dfs(int a,int b){
	if(a==T||b==T)return true;
	if(a<ma){
		ans.push(oper(1,1,0));
		if(dfs(ma,b))return true;
		ans.pop();
	}
	if(b<mb){
		ans.push(oper(1,b,0));
		if(dfs(a,mb))return true;
		ans.pop();
	}
	if(a>0){
		ans.push(oper(2,1,0));
		if(dfs(0,b))return true;
		ans.pop();
	}
	if(b>0){
		ans.push(oper(2,2,0));
		if(dfs(a,0))return true;
		ans.pop();
	}
	ans.push(oper(3,1,2));
	int t=a+b>mb?mb:a+b;
	if(dfs(a+b-t,t))return true;
	ans.pop();
	
	ans.push(oper(3,2,1));
	t=a+b>ma?ma:a+b;
	if(dfs(t,a+b-t))return true;
	ans.pop();
	return false;
}
void output(){
	oper t=ans.top();ans.pop();
	if(!ans.empty())output();
	if(t.v==3)printf("%s(%d,%d)\n",OUT[t.v-1],t.a,t.b);
	else printf("%s(%d)\n",OUT[t.v-1],t.a);
}
int main(){
	scanf("%d%d%d",&ma,&mb,&T); 
	if(!dfs(0,0))printf("impossible\n");
	else output();
	return 0;
}
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int MAXN=100; 
const char OUT[8][15]={"impossible","DROP(2)","FILL(2)","DROP(1)","FILL(1)","POUR(1,2)","POUR(2,1)"};
struct Node{
	bool checked;
	int action;
	int x,y;
	int step;
	int box1,box2;
};
Node setnode(Node &a,Node &b,int action){
	a.checked=true;
	a.step=b.step+1;a.x=b.box1;a.y=b.box2;a.action=action;
	return a;
}
queue<Node> q;
stack<Node> s;
Node node[MAXN+3][MAXN+3];
int a,b,c;
int main(){
	Node tmp;
	int tmpbox1,tmpbox2;
	scanf("%d%d%d",&a,&b,&c);
	while(!q.empty())q.pop();
	while(!s.empty())s.pop();
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++){
			node[i][j].checked=false;
			node[i][j].box1=i;
			node[i][j].box2=j;
		}
	node[0][0].checked=true;
	node[0][0].step=0;
	q.push(node[0][0]);
	while(q.empty()==false){
		tmp=q.front();q.pop();
		if(tmp.box1==c||tmp.box2==c)break;
		tmpbox1=tmp.box1;tmpbox2=tmp.box2;
		//DROP(2)
		if(node[tmpbox1][0].checked==false)
			q.push(setnode(node[tmpbox1][0],tmp,1));
		//FILL(2)
		if(node[tmpbox1][b].checked==false)
			q.push(setnode(node[tmpbox1][b],tmp,2));
		//DROP(1)
		if(node[0][tmpbox2].checked==false)
			q.push(setnode(node[0][tmpbox2],tmp,3));
		//FILL(1)
		if(node[a][tmpbox2].checked==false)
			q.push(setnode(node[a][tmpbox2],tmp,4));
		//POUR(1,2)
		if(tmpbox1<=(b-tmpbox2)&&node[0][tmpbox1+tmpbox2].checked==false)
			q.push(setnode(node[0][tmpbox1+tmpbox2],tmp,5));
		//POUR(1,2)
		else if(tmpbox1>(b-tmpbox2)&&node[tmpbox1-(b-tmpbox2)][b].checked==false)
			q.push(setnode(node[tmpbox1-(b-tmpbox2)][b],tmp,5));
		//POUR(2,1)
		if(tmpbox2<=(a-tmpbox1)&&node[tmpbox1+tmpbox2][0].checked==false)
			q.push(setnode(node[tmpbox1+tmpbox2][0],tmp,6));
		//POUR(2,1)
		else if(tmpbox2>(a-tmpbox1)&&node[a][tmpbox2-(a-tmpbox1)].checked==false)
			q.push(setnode(node[a][tmpbox2-(a-tmpbox1)],tmp,6));
	}
	if(q.empty()){printf("%s\n",OUT[0]);return 0;}
	printf("%d\n",tmp.step);
	while(1){
		s.push(tmp);
		if(tmp.x==0&&tmp.y==0)break;
		tmp=node[tmp.x][tmp.y];
	}
	while(!s.empty()){
		tmp=s.top();s.pop();
		printf("%s\n",OUT[tmp.action]);
	}
	return 0;
} 

