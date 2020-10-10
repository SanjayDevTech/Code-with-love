#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    //variable
int number1,number2,choices;
float result;

cout<<"Calculator Program\n";
cout<<"=============== ==\n\n";

cout<<"Please Choose option in below :\n";
cout<<"[1] Addition\n";
cout<<"[2] Subtraction\n";
cout<<"[3] Multiplication\n";
cout<<"[4] Division\n";
cout<<"Insert your choice : ";
cin>>choices;
cout<<"\n";

switch (choices)
  {
  case 1:
          cout<<"Input number 1 = ";cin>>number1;
          cout<<"Input number 2 = ";cin>>number2;
      result=number1+number2;
      cout<<"Result Addition = "<<result<<endl;
      break;
  case 2:
          cout<<"Input number 1 = ";cin>>number1;
          cout<<"Input number 2 = ";cin>>number2;
      result=number1-number2;
      cout<<"Result Subtraction = "<<result<<endl;
      break;
  case 3:
             cout<<"Input number 1 = ";cin>>number1;
          cout<<"Input number 2 = ";cin>>number2;
      result=number1*number2;
        cout<<"Result Multiplication = "<<result<<endl;
        break;
  case 4:
             cout<<"Input number 1 = ";cin>>number1;
             cout<<"Input number 2 = ";cin>>number2;
        result=number1/number2;
        cout<<"Result Division = "<<result<<endl;
        break;
  default :
        cout<<"Sorry your choice is not there";
   
getch();
}
}
