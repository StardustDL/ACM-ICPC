/*
Ӳ��
������������ȫ�����ķ�����ע���ֵ����ֵ�Ͻ磬����Ҫ�����װ��������װ֮ǰҪ��� 
*/
#include<iostream>
using namespace std;
const int MAXW=103,MAXV=(MAXW/2)*50;
int w,n,v,mx,mn,mxv=0,ans=0;
bool opt[MAXW][MAXV+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>w>>n;
	opt[0][0]=true;//��������һ��Ҫ����ֵ 
	while(n-->0){
		cin>>v>>mn>>mx;
		for(int i=mn;i<=mx;i++){//ö������ 
			for(int j=i;j<=w;j++){//��ȫ����ö������ 
				for(int k=0;k<=mxv;k++){//ö����ֵ��Ҫ��0��ʼ 
					if(opt[j-i][k]){
						opt[j][k+v]=true;
						mxv=max(mxv,k+v); 
					}
				}
			}
		}
	}
	for(int i=0;i<=mxv;i++){
		ans+=opt[w][i];
	}
	cout<<ans;
	return 0;
}
