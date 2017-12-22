/*
Number Game
������һ����������2-20�����У�����ɾȥһ������ÿ��ɾ�����������п�������ɾȥ�����Ա�ʾ����ɾȥ
	  �ָ���һ��ʣ�µ����У�����ɾ�ĸ����ܱ�ʤ
	  ����ע�⵽���ַ�Χ��2-20��Ȼ���������ʣ�µģ���ôû�и��������Ѿ���ѡ���ˣ��������ֻ��2��ֻ��3����ôѡ�������һ����ʤ����ͬʱ�У���ô�����˶���������ȥѡ�����Ǳ���ѡ��
	  �õ������ۣ��ӵ�ǰ��״̬�ƶ���һ��״̬�������һ��״̬�л���ֱذ�̬�����״̬��Ϊ��ʤ̬��������һ��״̬�в�����ֱذ�̬�����״̬Ϊ��ʤ̬�����ǲ�����������Ķ��� 
	  ���Լ��仯����+λѹ���洢״̬ 
*/
#include<bitset>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=20;
int bs[1<<MAXN+1],st,kase=0;
vector<int> an;
bool has(int state,int x){//�ж�state��xλ�Ƿ�Ϊ1 
	return state&(1<<x);
}
/*void out(int x){//���������x 
	for(int i=1;i<=MAXN;i++){
		if(has(x,i))cout<<1;else cout<<0;
	cout<<endl;
}*/
int change(int state,int x){//ɾȥx����ͬ��������������Ҳɾȥ 
	int ans=state;
	ans^=1<<(x);//��ɾȥx 
	for(int i=2;i<=MAXN;i++)
		if(!has(ans,i)&&x+i<=MAXN&&has(ans,x+i))//i�Ѿ���ɾ������x+i�ڷ�Χ�ڣ��������д���x+i 
			ans^=1<<(x+i);//��x+iλ��0 
	return ans;
}

bool dfs(int state){
	if(bs[state]!=-1)return bs[state];//�Ѿ��������״̬ 
	if(state==0)return false;//��·���� 
	if(has(state,2)^has(state,3))return bs[state]=1;//ֻ����һ��2��һ��3 
	for(int i=2;i<=MAXN;i++)
		if(has(state,i)&&!dfs(change(state,i)))//�����һ��Ϊ���䣬��˲���Ӯ 
			return bs[state]=1;
	return bs[state]=0;
}
bool input(){
	int n,x;st=0;cin>>n;
	if(n==0)return false;
	while(n-->0){cin>>x;st|=1<<x;}
	return true;
}
int main(){
	while(input()){
		an.clear();
		memset(bs,-1,sizeof(bs));//ע���ʼ�� 
		for(int i=2;i<=MAXN;i++)
			if(has(st,i)&&!dfs(change(st,i)))//ɾ��i���ֺ�Ϊ���� 
				an.push_back(i);
		cout<<"Test Case #"<<++kase<<endl;
		if(an.size()!=0){
			cout<<"The winning moves are: ";
			for(int i=0;i<an.size();i++)cout<<an[i]<<" ";
			cout<<endl;
		}
		else cout<<"There's no winning move."<<endl;
		cout<<endl;
	}
	return 0;
}
