/*
Counterfeit Dollar
题意：有一打（12枚）硬币，其中有且仅有1枚假币，11枚真币
	  用A~L作为各个硬币的代号
	  假币可能比真币略轻，也可能略重
	  现在利用天枰，根据Input输入的3次称量，找出假币，并输出假币是轻还是重。 
分析：由于该题必然有确定的判定，所以简单的可以这么想：
        设置一个标记数组，每次称球的时候，如果是"even"则把对应的设置为"真东西",即置为10，
        如果是"up"或"donw" 则把未分辨出真假的硬币中flag数组中对应的 ++ 或者 --，直到最后。那么操作之后，
        flag中存在没有辨认出真的，就是一系列的例如： -1,-2,1,2,3等数值，那么
        假东西就是其中绝对值最大的那个！！------被怀疑次数最多，所以它为假。 
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
            len=strlen(s1);              //两边个数肯定相等，所以两边长度也一样  
            if(strcmp(temp,"even")==0){
                for(i=0;i<len;++i){
                    flag[s1[i]-'A']=10;  //说明两边都为真，将标记数组置为10
                    flag[s2[i]-'A']=10;
                }
            }
            else if(strcmp(temp,"up")==0){//说明左边重
                for(i=0;i<len;++i){
                    if(flag[s1[i]-'A']!=10)++flag[s1[i]-'A'];  //左边加一
                    if(flag[s2[i]-'A']!=10)--flag[s2[i]-'A'];  //右边减一
                }
            }
            else{
                for(i=0;i<len;++i){      //说明右边重
                    if(flag[s1[i]-'A']!=10)--flag[s1[i]-'A'];  //左边减一
                    if(flag[s2[i]-'A']!=10)++flag[s2[i]-'A'];  //右边加一
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
