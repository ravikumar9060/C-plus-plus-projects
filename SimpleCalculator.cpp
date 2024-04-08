#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    char opr;
  cout<<"Welcome to calculator"<<endl;

  cout<<"Enter the first number \n";
  cin>>a;
  cout<<"Enter the second number \n";
  cin>>b;
   cout<<"enter the operator \n +  -  *  /: \n";
  cin>>opr;
switch(opr){
      case '+':
  cout<<a<<" + "<<b <<" = "<< a+b<<endl;
break;
case '-':
  cout<<a<<" - "<<b <<" = "<< a-b<<endl;
  break;
case '*':
  cout<<a<<" * "<<b <<" = "<< a*b<<endl;
  break;
case '/':
  cout<<a<<" / "<<b <<" = "<< a/b<<endl;
  break;
}
}
