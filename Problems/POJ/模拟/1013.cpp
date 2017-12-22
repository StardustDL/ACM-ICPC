/*
Counterfeit Dollar
���⣺��һ��12ö��Ӳ�ң��������ҽ���1ö�ٱң�11ö���
	  ��A~L��Ϊ����Ӳ�ҵĴ���
	  �ٱҿ��ܱ�������ᣬҲ��������
	  �����������ң�����Input�����3�γ������ҳ��ٱң�������ٱ����ỹ���ء� 
���������ڸ����Ȼ��ȷ�����ж������Լ򵥵Ŀ�����ô�룺
        ����һ��������飬ÿ�γ����ʱ�������"even"��Ѷ�Ӧ������Ϊ"�涫��",����Ϊ10��
        �����"up"��"donw" ���δ�ֱ����ٵ�Ӳ����flag�����ж�Ӧ�� ++ ���� --��ֱ�������ô����֮��
        flag�д���û�б��ϳ���ģ�����һϵ�е����磺 -1,-2,1,2,3����ֵ����ô
        �ٶ����������о���ֵ�����Ǹ�����------�����ɴ�����࣬������Ϊ�١� 
*/
#include<cstdio>
#include<cstring>
#include<cmath>
int main(){
    int n,k,i,t,len,max,flag[12];
    char s1[13],s2[13],temp[10];
    scanf("%d",&n);
    while(n--){
        memset(flag,0,sizeof(flag));
        for(t=1;t<=3;++t){
            scanf("%s%s%s",s1,s2,temp);
            len=strlen(s1);              //���߸����϶���ȣ��������߳���Ҳһ��  
            if(strcmp(temp,"even")==0){
                for(i=0;i<len;++i){
                    flag[s1[i]-'A']=10;  //˵�����߶�Ϊ�棬�����������Ϊ10
                    flag[s2[i]-'A']=10;
                }
            }
            else if(strcmp(temp,"up")==0){//˵�������
                for(i=0;i<len;++i){
                    if(flag[s1[i]-'A']!=10)++flag[s1[i]-'A'];  //��߼�һ
                    if(flag[s2[i]-'A']!=10)--flag[s2[i]-'A'];  //�ұ߼�һ
                }
            }
            else{
                for(i=0;i<len;++i){      //˵���ұ���
                    if(flag[s1[i]-'A']!=10)--flag[s1[i]-'A'];  //��߼�һ
                    if(flag[s2[i]-'A']!=10)++flag[s2[i]-'A'];  //�ұ߼�һ
                }
            }
        }
        max=0;k=0;
        for(i=0;i<12;++i){
            if(flag[i]==10)continue;
            if(max<=abs(flag[i])){
                max=abs(flag[k=i]);
            }
        }
        if(flag[k]>0)printf("%c is the counterfeit coin and it is heavy.\n",'A'+k);
        else printf("%c is the counterfeit coin and it is light.\n",'A'+k);
    }
    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
vector<int> v;
struct data{
	int l[4],r[4],k;
	data(){} 
	data(char* a,char* b,char c){
		for(int i=0;i<4;i++)l[i]=a[i]-'A';
		for(int i=0;i<4;i++)r[i]=b[i]-'A';
		if(c=='e')k=0;
		else if(c=='u')k=1;
		else k=2;
	};
}ds[3];
int isp[13];
void input(){
	memset(isp,-1,sizeof(isp));
	char a[5],b[5],c[6];
	scanf("\n%s %s %s",a,b,c);
	ds[0]=data(a,b,c[0]);
	scanf("\n%s %s %s",a,b,c);
	ds[1]=data(a,b,c[0]);
	scanf("\n%s %s %s",a,b,c);
	ds[2]=data(a,b,c[0]);
}
void solve(){
	memset(isp,-1,sizeof(isp));
	int k=0,flg=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(isp[ds[i].l[j]]==-1)isp[ds[i].l[j]]=0;
			if(isp[ds[i].r[j]]==-1)isp[ds[i].r[j]]=0;
		}
		if(ds[i].k==0){
			for(int j=0;j<4;j++){
				isp[ds[i].l[j]]=isp[ds[i].r[j]]=1;
			}
			continue;
		}
		k=i;
	}
	data &t=ds[k];
	v.clear();
	for(int i=0;i<3;i++){v.push_back(t.l[i]);v.push_back(t.r[i]);}
	for(int i=0;i<12;i++){
		if(isp[i]==0||isp[i]==-1)continue;
		flg=1;
		for(int j=0;j<v.size();j++){
			if(v[j]!=i)if(isp[v[j]]==0){
				flg=0;break;
			}
		}
		if(flg)printf("%c is the counterfeit coin and it is %s.\n",char(i+'A'),(t.k==1?"heavy":"light"));
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		solve();
	}
	return 0;
}
*/
