/*
COURSES
题意：给你p门课程和n个学生，一个学生可以选0门，1门，或者多门课程，现在要求一个由p个学生组成的集合，满足下列2个条件：
	  1.每个学生选择一个不同的课程，2.每个课程都有不同的代表，如果满足，就输出YES
分析：二分图最大匹配。注意要分清两种点 
*/
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;
const int MAXL=100,MAXP=300,INF=0x3f3f3f3f;
const char OUT[2][5]={"NO","YES"};
vector<int> g[MAXL+3];//存的是左部点连向的右部点
int link[MAXP+3];//存的是右部点对应的左部点 
bitset<MAXP+3> vis;//存的是右部点有没有被访问 
bool find(int u){
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			if(!link[g[u][i]] || find(link[g[u][i]])){link[g[u][i]]=u;return true;}
		}
	}
	return false;
}
int lesson,stu;
int maxp(){
	memset(link,0,sizeof(link));
	int ans=0;
	for(int i=1;i<=lesson;i++)vis=0,ans+=find(i);
	return ans;
}
int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&lesson,&stu);
		for(int i=1,c,t;i<=lesson;i++){
			g[i].clear();
			for(scanf("%d",&c);c;c--){
				scanf("%d",&t);
				g[i].push_back(t);
			}
		}
		puts(OUT[maxp()==lesson]);
	}
	return 0;
}

