/*
����Ǯ
������̰�ģ�����ÿһ�������������б�����������Ի���̰��˼·���ǣ�����ÿһ�����ڣ���������Ǯ������C������ȡ�����ȡ�����û�ﵽC������ȡС�����㵽C��
	  һ��С�Ż��������һ��Ӳ�ҵĽ�����c����ֱ�ӰѴ˽���Ӳ������(m)����������(ans)�У��൱��ÿ������ֻ��һ���˽���Ӳ�Ҿ����ˣ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=20,INF=0x3f3f3f3f;
int n,c,ans=0;
struct data{
	int v,b;
	bool operator < (const data &t)const{return v<t.v;}
}ds[MAXN+3];
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>ds[i].v>>ds[i].b;
	sort(ds+1,ds+n+1);
	for(;ds[n].v>=c;ans+=ds[n--].b);
	//cout<<ds[1].v<<endl;
	while(1){
		int t=c;
		for(int i=n;i>=1;i--){
			while(t>=ds[i].v&&ds[i].b){
				t-=ds[i].v;ds[i].b--;
			}
		}
		for(int i=1;i<=n;i++){
			while(t>0&&ds[i].b){
				t-=ds[i].v;ds[i].b--;
			}
		}
		if(t>0)break;
		ans++;
	}
	//for(int i=1;i<=n;i++)cout<<ds[i].b<<endl;
	cout<<ans<<endl;
	return 0;
}

