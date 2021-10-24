#include <iostream>
#include <string>
using namespace std;

void pencod(string s, string ans)
{
	if (s.length()==0)
		{
		cout<<ans<<endl;
		return;
		}

	int code1 = s[0]-'0';
	char atcode1 = char('a'+code1-1);
	int code2 = stoi(s.substr(0,2));
	char atcode2 = char('a'+code2-1);

	if(code1 != 0)
		pencod(s.substr(1),ans + atcode1);
	if(code2 >=10 && code2 <=26)
		pencod(s.substr(2),ans + atcode2);
}

int main()
{
	string s;
    cin>>s;
	pencod(s,"");

	return 0;
}