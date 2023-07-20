#include<bits/stdc++.h>
using namespace std;
char keych,ch[9];
int main()
{
	srand(time(0));
	int len;
	cout<<"input key character:";
	cin>>keych;
	cout<<"input other 6 characters, seperated with a space:";
	for(int i=0;i<6;++i)	cin>>ch[i];
	while(1)
	{
		len=rand()%5+4;
		string output;
		bool used=0;
		for(int i=0;i<len;++i)
		{
			int t=rand()%7;
			if(t==6)
			{
				output+=keych;
				used=1;
			}
			else	output+=ch[t];
		}
		if(!used)	output+=keych;
		cout<<output<<endl;
		getchar();
	}
	return 0;
}
