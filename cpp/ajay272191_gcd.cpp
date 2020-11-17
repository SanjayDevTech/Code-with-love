//GCD of two numbber using class
#include<iostream>
using namespace std;

class Number{
protected:
  long long int number1, number2;
public:
  void setNumber(long long int x, long long int y){
    this->number1 = x;
    this->number2 = y;
  }
  void findGcd(int test_case)
  {
    long long int gcd_iteration;
    if((this->number1 == 0) || (this->number2 == 0))
    {
      cout<< "GCD for test case "<< test_case + 1 << ": " << "1" << "\n";
    }
    else
    {
      if(abs(this->number1) < abs(this->number2))
      {
        gcd_iteration = abs(this->number1);
      }
      else
      {
        gcd_iteration = abs(this->number2);
      }
      long long int gcd = 1;
      for(long long int i = 2; i<gcd_iteration+1; i++)
      {
        if((this->number1 % i == 0) && (this->number2 % i ==0) )
        {
          gcd = i;
        }
      }
      cout << "GCD for test case "<< test_case + 1 << ": " << gcd << '\n';
    }
    return;
  }

};

int main()
{
  int N; //N = Number of test cases
  cin >> N;
  long long int number1, number2;
  Number numbers; //creating object of inputs for which we are going to find the GCD
  for(int i = 0; i < N; i++){
    cin >> number1 >> number2;
    numbers.setNumber(number1, number2);
    numbers.findGcd(i);
  }
	return 0;
}
