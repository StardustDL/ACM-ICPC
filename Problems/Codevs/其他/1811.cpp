/*
A+B问题 3
分析：此题较坑，首先电脑上开MAXN=100005运行不了，但评测机可以，然后要注意正负判断，还有0 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 100005;
struct bign{
	int len, s[MAXN];
	
	void clean() {
		while(len > 1 && !s[len-1]) len--;
	}

	bign() {
		memset(s, 0, sizeof(s));
		len = 1;
	}

	bign(int num) {
	  *this = num;
	}

	bign(const char* num) {
		*this = num;
	}

	bign operator = (int num) {
		char s[MAXN];
		sprintf(s, "%d", num);
		*this = s;
	 	return *this;
	}

	bign operator = (const char* num) {
		len = strlen(num);
		for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
		clean();
		return *this;
	}
	
	void setstr(const char* num,int start){
		len = strlen(num);
		for(int i = start; i < len; i++) s[i-start] = num[len-i-1+start] - '0';
		clean();//这里可以避免调用clean，但是懒得打了 
	}

	string str() const {
		string res = "";
		for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if(res == "") res = "0";
		return res;
	}

	bign operator + (const bign& b) const{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		c.clean();
		return c;
	}

	bign operator * (const bign& b) {
		bign c; c.len = len + b.len;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < b.len; j++)
				c.s[i+j] += s[i] * b.s[j];
		for(int i = 0; i < c.len-1; i++){
			c.s[i+1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}

	bign operator - (const bign& b) {
		bign c; c.len = 0;
		for(int i = 0, g = 0; i < len; i++) {
			int x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else {
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}

	bool operator < (const bign& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; i--)
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}

	bool operator > (const bign& b) const{
		return b < *this;
	}

	bool operator <= (const bign& b) {
		return !(b > *this);
	}

	bool operator == (const bign& b) {
		return !(b < *this) && !(*this < b);
	}

	bign operator += (const bign& b) {
		*this = *this + b;
		return *this;
	}
};

istream& operator >> (istream &in, bign& x) {
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x) {
	out << x.str();
	return out;
}
bign a,b;
char ca[MAXN],cb[MAXN];
int main(){
	cin>>ca>>cb;
	//cout<<ca<<endl<<cb<<endl;
	if(ca[0]=='-'){
		a.setstr(ca,1);
		if(cb[0]=='-'){
			b.setstr(cb,1);
			//cout<<a<<endl<<b<<endl;
			cout<<'-'<<a+b;
		}
		else{
			b=cb;
			//cout<<a<<endl<<b<<endl;
			if(a>b)cout<<'-'<<a-b;
			else cout<<b-a;
		}
	}
	else{
		a=ca;
		if(cb[0]=='-'){
			b.setstr(cb,1);
			//cout<<a<<endl<<b<<endl;
			if(a>b)cout<<a-b;
			else if(a<b)cout<<'-'<<b-a;
			else cout<<0;
		}
		else{
			b=cb;
			//cout<<a<<endl<<b<<endl;
			cout<<a+b;
		}
	}
	return 0;
} 
