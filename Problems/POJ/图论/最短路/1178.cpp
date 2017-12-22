/*
Camelot
���⣺һ�������������̣���һ�������������ɸ���ʿ��������Ҫ�����Ƕ�Ų��һ������Ҫ���ٶ��ٲ��������������ĳ��ʿ��ͬһ���������߿���ͬʱ����ʿ�ķ�ʽ�ƶ���ֻ����һ����
��������Ԥ�������͹�����ÿ���㵽ÿ��������·���ٱ���ö���յ㣨��ϵ㣩������㣬���ϵ���
	  ע��(x,y)ӳ�䵽x*8+y����(0..7,0..7)->(0..7*8+7)->(0..63)�����Զ���ʱҪע��һ�� 
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
	for(int i=0;i<MX;i++){//ö���յ� 
		int sum=0;//������ʿ���յ�ľ��� 
		for(int j=1;j<vs.size();j++)sum+=knight[vs[j]][i];
		for(int j=0;j<MX;j++){//ö�ٹ�������� 
			int t1=king[st][j],t2=INF;//������j��
			for(int k=1;k<vs.size();k++){//ö�����ϵ���ʿ
				//��ʿ��X��j+��ʿ��j��i-sum���ۼӵ���ʿ��X��i 
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
