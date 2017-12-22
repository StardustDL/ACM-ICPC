/*
Camelot
题意：一个国际象棋棋盘，有一个国王，和若干个骑士（马）。问要把他们都挪到一个格需要至少多少步。（国王如果和某骑士在同一个格则两者可以同时以骑士的方式移动且只记做一步）
分析：先预处理出马和国王从每个点到每个点的最短路，再暴力枚举终点（汇合点），上马点，所上的马。
	  注意(x,y)映射到x*8+y，即(0..7,0..7)->(0..7*8+7)->(0..63)，所以读数时要注意一下 
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int W=8,MX=W*W,INF=0x3f3f3f3f,
	mv1[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}},
	mv2[8][2]={{-1,-2},{-2,-1},{1,-2},{2,-1},{-1,2},{-2,1},{1,2},{2,1}};
#define nd(x,y) (x*W+y)
typedef int arr[MX][MX];
arr king,knight;
vector<int> vs;
void floyd(arr &A){
	for(int k=0;k<MX;k++){
		for(int i=0;i<MX;i++){
			for(int j=0;j<MX;j++){
				A[i][j]=min(A[i][k]+A[k][j],A[i][j]);
			}
		}
	}
}
void init(){
	memset(king,INF,sizeof(king));
	memset(knight,INF,sizeof(knight));
	for(int i=0;i<MX;i++)king[i][i]=knight[i][i]=0;
	for(int i=0;i<MX;i++){
		int x=i/W,y=i%W;
		for(int j=0;j<8;j++){
			int x2=x+mv1[j][0],y2=y+mv1[j][1];
			if(x2>=0&&y2>=0&&x2<W&&y2<W)king[i][nd(x2,y2)]=1;
		}
	}
	for(int i=0;i<MX;i++){
		int x=i/W,y=i%W;
		for(int j=0;j<8;j++){
			int x2=x+mv2[j][0],y2=y+mv2[j][1];
			if(x2>=0&&y2>=0&&x2<W&&y2<W)knight[i][nd(x2,y2)]=1;
		}
	}
	floyd(king);
	floyd(knight);
}
string str;
bool input(){
	if(!(cin>>str))return false;
	vs.clear();
	for(int i=0;i<str.length();i+=2){
		vs.push_back(nd((str[i]-'A'),(str[i+1]-'1')));
	}
	return true;
}
int solve(){
	int st=vs[0],ans=INF;
	for(int i=0;i<MX;i++){//枚举终点 
		int sum=0;//所有骑士到终点的距离 
		for(int j=1;j<vs.size();j++)sum+=knight[vs[j]][i];
		for(int j=0;j<MX;j++){//枚举国王上马点 
			int t1=king[st][j],t2=INF;//国王到j点
			for(int k=1;k<vs.size();k++){//枚举所上的骑士
				//骑士从X到j+骑士从j到i-sum中累加的骑士从X到i 
				t2=min(t2,knight[vs[k]][j]+knight[j][i]-knight[vs[k]][i]);
			}
			ans=min(ans,sum+t1+t2); 
		}
	}
	return ans;
}
int main(){
	init();
	while(input())cout<<solve()<<endl;
	return 0;
}
