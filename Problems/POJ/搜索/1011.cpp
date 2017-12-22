/*
木棒
题意：乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过50个长度单位。然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。请你设计一个程序，帮助乔治计算木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。ｎ<=64 
分析：dfs+剪枝
	  令InitLen为所求的最短原始棒长，maxlen为给定的棒子堆中最长的棒子，sumlen为这堆棒子的长度之和，那么InitLen必定在范围[maxlen，sumlen]中
	  根据棒子的灵活度（棒子越长，灵活度越低） DFS前先对所有棒子降序排序，这就是搜索时的选择顺序
	  其他剪枝见代码 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void* a,const void* b){return *(int*)b-*(int*)a;}
int n;//木棒数量
bool dfs(int* stick,bool* vist,int len,int InitLen,int s,int num){//len:当前正在组合的棒长  InitLen:目标棒长  s:stick[]的搜索起点  num:已用的棒子数量 
	if(num==n)return true;
	int sample=-1;
	for(int i=s;i<n;i++){
		if(vist[i] || stick[i]==sample)continue;//剪枝3,等长的木棒只搜索一次
		vist[i]=true;
		if(len+stick[i]<InitLen){
			if(dfs(stick,vist,len+stick[i],InitLen,i,num+1))return true;
			else sample=stick[i];//不要直接和i-1比较，有可能i-1并不合法（如已用） 
		}
		else if(len+stick[i]==InitLen){
			if(dfs(stick,vist,0,InitLen,0,num+1))return true;
			else sample=stick[i];
		}
		vist[i]=false;
		if(len==0)break;//剪枝4，构建新棒时，对于新棒的第一根棒子，在搜索完所有棒子后都无法组合，则说明该棒子无法在当前组合方式下组合，不用往下搜索(往下搜索会令该棒子被舍弃)，直接返回上一层 
	}
	return false;
}
int main(){
	while(cin>>n&&n){
		int* stick=new int[n];
		bool* vist=new bool[n];
		int sumlen=0;
		for(int i=0;i<n;i++){
			cin>>stick[i];
			sumlen+=stick[i];
			vist[i]=false;
		}
		qsort(stick,n,sizeof(stick),cmp);
		int maxlen=stick[0];//最大的棒为InitLen的搜索起点
		bool flag=false;//剪枝1,若能在[maxlen,sumlen-InitLen]找到最短的InitLen，该InitLen必也是[maxlen,sumlen]的最短
		for(int InitLen=maxlen;InitLen<=sumlen-InitLen;InitLen++){//InitLen:原始棒长，剪枝2,InitLen必是sumlen的约数
			if(!(sumlen%InitLen) && dfs(stick,vist,0,InitLen,0,0)){
				cout<<InitLen<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)cout<<sumlen<<endl;
		delete stick;
		delete vist;
	}
	return 0;
}
