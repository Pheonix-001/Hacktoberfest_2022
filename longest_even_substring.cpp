#include<iostream>
#include<string>
using namespace std;


bool isEqual(string str, int n)
{
	int sum_left=0;
	int sum_right=0;

	for(int i=0; i<n/2; i++)
	{
	    ///convert character values to integers
		sum_left+=str[i]-'0';
		sum_right+=str[n-i-1]-'0';
	}

	return sum_left==sum_right;
}

int generateSubstrings(string str, int n, int m)
{
	if(m==0)
	{
		return 0;
	}

	for(int i=0; i<n-m; i++)
	{
		if(isEqual(str.substr(i,m), m))
		{
			return m;
		}
	}

	return generateSubstrings(str, n, m-2);
}


int main() {
	string str;
	cin>>str;

	int n=str.length();
	int m=n%2==0? n: n-1;

	cout<<generateSubstrings(str,n, m);
	return 0;
}
