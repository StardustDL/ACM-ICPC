/*
[Zjoi2013]K大数查询
分析：注意题目中的注释，不要理解错
	  具体做法：树套树【还不会】，整体二分【不会那么复杂的编法】
	  暴力！由于是第K大，一开始数列是空的，所以，将所有插入操作从大到小排序，第二关键字为执行时间
	  然后按执行顺序扫一遍所有操作，对于插入标记，跳过
	  对于查询：按上述排序顺序扫一遍插入操作，统计数的个数，当大于当前查询的个数时，跳出，输出答案 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000;
struct oper{
	int tme,tp,a,b,c;
	bool operator < (const oper &t)const{
		return c==t.c?(tme<t.tme):(c>t.c);
	}
}ops[MAXN+3];
vector<oper> chs;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		ops[i].tme=i;
		scanf("%d%d%d%d",&ops[i].tp,&ops[i].a,&ops[i].b,&ops[i].c);
		if(ops[i].tp==1)chs.push_back(ops[i]);
	}
	sort(chs.begin(),chs.end());
	for(int i=1;i<=m;i++){
		if(ops[i].tp==1)continue;
		int cnt=0,j;
		for(j=0;j<chs.size();j++){
			if(chs[j].tme>i)continue; 
			int len=min(chs[j].b,ops[i].b)-max(chs[j].a,ops[i].a)+1;
			if(len<0)continue;
			if((cnt+=len)>=ops[i].c)break;
		}
		printf("%d\n",chs[j].c);
	}
	return 0;
}

