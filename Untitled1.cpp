#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int a;
    cin >>a;
	int b = a%10;
	int c = a/10;
	string s[] = {" muoi"," mot "," hai "," ba "," bon "," nam "," sau "," bay "," tam "," chin "};	
	cout <<"\nDOC LA: ";
     if (b != 0 && b > 0)
     	cout <<"\n "<<s[c]<<" muoi "<<s[b];
    if ( b!=0 && b < 0)
        	cout <<"\n am "<<s[c*-1]<<" muoi "<<s[b*-1];
	 if (a == 10)
	 	cout <<"\n muoi";
     if ( b== 0)
     {
     	cout <<"\n"<<s[c]<<"muoi";
	 }
	 return 0;
}
