/*
�Ȳ�������
���������и����ĵȲ����У����Ȼ�г���Ϊ3��
	  ��Ϊ��һ��n�����У��������е�������1<=x<=n�ģ����Կ�����һ��01�ַ���������λ����ʾ������Ƿ���ֹ���
	  ���뵱ǰ�������λ�϶���1��Ȼ������λΪ���ģ��ж����ߵȾ�������Ƿ����Ϊ1��
	  ���Ϊ1˵������Ȳ����еĲ���Ǹ������ں�����������Կ϶������Ȳ�������
*/
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=10000;
bitset<MAXN+3> B;
int n,m,t,e;
bool flg;
int main(){
	cin>>t;
	while(t-->0){
		flg=false;B=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e;
			if(flg)continue;
			B[e]=1;
			for(int j=e-1;j>0&&(e<<1)-j<=n&&!flg;j--)
				if(B[j]^B[(e<<1)-j])flg=true;
		}
		if(flg)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}
