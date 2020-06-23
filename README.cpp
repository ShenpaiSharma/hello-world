# hello-world

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
stringstream ss(str);
vector<int> out;
char ch;
int temp;
while(ss >> temp)
{
out.push_back(temp);
ss >> ch;
}
return out;
}

int main()
{

string str;
cin >> str;

vector<int> integers = parseInts(str);

for(int i = 0; i < integers.size(); i++)
{
cout << integers[i] << "\n";
}

return 0;
}

/*
string a;
cin>>a;
for (int i=0;i<a.size();i++)
{
    if (a[i]!=',')
        cout<<a[i];
    else
        cout<<"\n";    
}
*/
