/*

*/
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
map<string,int>Map;
char s[105][25][525],name[105][525],ans[105][525],a[25][525];
int num[105],f[25],n,m,i,j,k,P,Today,flag,now,lie,Len,cnt,T;
char day[8][25]={"","Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
inline int equal(char *s1,char *s2){
	int l1=strlen(s1),l2=strlen(s2);
	if (l1!=l2) return 0;
	for (int i=0;i<l1;i++) if (s1[i]!=s2[i]) return 0;
	return 1;
}
inline int check_1(int k){
	if (!equal(s[k][num[k]],"guilty.")||num[k]<3||num[k]>4) return 2;
	if (s[k][1][0]!='I'||s[k][1][1]!='\0'||!equal(s[k][2],"am")) return 2;
	if (num[k]==4 && (!equal(s[k][3],"not"))) return 2;
	if (Map[name[k]]==now)return num[k]!=3;
	return num[k]==3;
}
inline int check_2(int k){
	if (!equal(s[k][num[k]],"guilty.")||num[k]<3||num[k]>4) return 2;
	if (!equal(s[k][2],"is")) return 2;
	if (num[k]==4&&(!equal(s[k][3],"not"))) return 2;
	if (Map[s[k][1]]==now)return !(num[k]==3);
	return (num[k]==3);
}
inline int check_3(int k){
	if (num[k]!=3||!equal(s[k][1],"Today")||!equal(s[k][2],"is")) return 2;
	return equal(day[Today],s[k][3])^1;
}
inline int work(){
	now=Map[a[P]];int res=0,another=0;memset(f,0,sizeof(f));
	for (int i=1;i<=m;i++){
	    int T1=check_1(i),T2=check_2(i),T3=check_3(i),pre=Map[name[i]];
	    if (!T1||!T2||!T3) {if (f[pre]==2) return 0;f[pre]=1;}
	    if (T1&1||T2&1||T3&1) {if (f[pre]==1) return 0;f[pre]=2;}
	}
	for (int i=1;i<=n;i++)
		if (f[i]==2) res++;else if (!f[i]) another++;
	return (res<=lie&&res+another>=lie);
}
inline int OK(char ch){return (ch>='A'&&ch<='Z'||ch>='a'&&ch<='z');}
int main(){
	scanf("%d%d%d",&n,&lie,&m);
	for (i=1;i<=n;i++) scanf("%s",a[i]),Map[a[i]]=i;
	for (i=1;i<=m;i++) {
		scanf("%s",name[i]);
		name[i][strlen(name[i])-1]='\0';
    	scanf("%s",s[i][num[i]=1]);
    	while(OK(s[i][num[i]][strlen(s[i][num[i]])-1]))scanf("%s",s[i][++num[i]]);
	}
	for (P=1;P<=n;P++){
    	flag=0;for (Today=1;Today<=7&&!flag;Today++) flag=work();
    	if (flag) memcpy(ans[++cnt],a[P],sizeof(a[P]));
  	}
  	if (!cnt) printf("Impossible");
  	else if (cnt==1) printf("%s",ans[cnt]);
  	else printf("Cannot Determine");
  	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
#include<map>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const string DAY[7]={"Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
const string STR[5]={"I am guilty.","I am not guilty."," is guilty"," is not guilty","Today is "};
struct word{
	int type;
	string data;
	int person;
	word(int t,string d,int p):type(t),data(d),person(p){}
	word(){}
}ds[103];
string ps[23];
map<string,int> mp;
int m,n,p;
void input(){
	cin>>m>>n>>p;getchar();
	for(int i=1;i<=m;i++){getline(cin,ps[i]);mp[ps[i]]=i;}
	string t;
	for(int i=1;i<=p;i++){
		getline(cin,t);
		int k=t.find(':');
		ds[i].person=mp[t.substr(0,k)];
		ds[i].type=-1;
		for(int j=0,e;j<5;j++){
			if((e=t.find(STR[j],k+2))!=string::npos){
				ds[i].type=j;
				if(j>1){
					if(j!=4){
						ds[i].data=t.substr(k+2,(e-1)-(k+2)+1);
					}
					else ds[i].data=t.substr(e+STR[j].length());
				}
				break;
			}
		}
	}
	for(int i=1;i<=p;i++)cout<<ds[i].type<<" "<<ds[i].person<<" "<<ds[i].data<<"!"<<endl;
}
vector<int> ans;
int isl[MAXN+3];
int solve(){
	for(int i=1;i<=m;i++){
		for(int j=0;j<7;j++){
			memset(isl,-1,sizeof(isl));
			for(int k=1;k<=p;k++){
				if(isl[ds[k].person]!=-1)continue;
				switch(ds[k].type){
					case 0:
						if(ds[k].person!=i)isl[ds[k].person]=1;
						else isl[ds[k].person]=0;
						break;
					case 1:
						if(ds[k].person==i)isl[ds[k].person]=1;
						else isl[ds[k].person]=0;
						break;
					case 2:
						if(ds[k].data!=ps[i])isl[ds[k].person]=1;
						else isl[ds[k].person]=0;
						break;
					case 3:
						if(ds[k].data==ps[i])isl[ds[k].person]=1;
						else isl[ds[k].person]=0;
						break;
					case 4:
						if(ds[k].data!=DAY[j])isl[ds[k].person]=1;
						else isl[ds[k].person]=0;
						break;
				}
			}
			int lies=0,cant=0;
			for(int k=1;k<=m;k++){if(isl[k]==1)lies++;else if(isl[k]==-1)cant++;}
			if(lies+cant>=n&&lies<=n){
				ans.push_back(i);
				break;
			}
		}
	}
}
int main(){
	input();
	solve();
	for(int i=0;i<ans.size();i++)cout<<ps[ans[i]]<<endl;
	if(ans.size()==1){
		cout<<ps[ans[0]]<<endl;
	}
	else if(ans.size()==0){
		puts("Impossible");
	}
	else{
		puts("Cannot Determine");
	}
	return 0;
}
*/
