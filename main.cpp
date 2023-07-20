#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char keych,ch[9];
struct Trie
{
	int t[N][26],cnt;
	bool ed[N];
	Trie()
	{
		cnt=0;
		memset(t,0,sizeof(t));
		memset(ed,0,sizeof(ed));
	}
	void insert(string x)
	{
		int ts=0,len=x.length();
		for(int i=0;i<len;++i)
		{
			if(!t[ts][x[i]-'a'])	t[ts][x[i]-'a']=++cnt;
			if(cnt>=N)
			{
				cout<<"trie too big"<<endl;
				exit(-1);
			}
			ts=t[ts][x[i]-'a'];
		}
		ed[ts]=1;
	}
	void dfs(int x,bool used,string str)
	{
		if(used&&ed[x])	cout<<str<<endl;
		for(int i=0;i<6;++i)
			if(t[x][ch[i]-'a'])	dfs(t[x][ch[i]-'a'],used,str+ch[i]);
		if(t[x][keych-'a'])	dfs(t[x][keych-'a'],1,str+keych);
	}
}tr;
int main()
{
	ifstream fin("data.in");
	streambuf *oldcin;
	oldcin=cin.rdbuf(fin.rdbuf());
	cout<<"initializing......\n";
	string s;
	while(cin>>s)	tr.insert(s);
	cout<<"initializing finished\n";
	cout<<"input key character:";
	cin.rdbuf(oldcin);
	cin>>keych;
	cout<<"input other 6 characters, seperated with a space:";
	for(int i=0;i<6;++i)	cin>>ch[i];
	cout<<"start finding......\n";
	cout<<"results are shown below:\n";
	tr.dfs(0,0,"");
	fin.close();
	return 0;
}
