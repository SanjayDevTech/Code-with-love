#include <bits/stdc++.h>

using namespace std;

int main() {
   int num, origNum, r, n = 0, res = 0, a;
   cout << "Enter an integer: ";
   cin >> num;

   origNum = num;

   while (origNum != 0) {
      origNum /= 10;
      ++n;
   }
   origNum = num;

   while (origNum != 0) {
      r = origNum % 10;
      a = round(pow(r, n));
      res += a;
      origNum /= 10;
   }

   if (res == num)
      cout << "Yes, " << num << " is an Armstrong number.";
   else
      cout << "No, " << num << " is not an Armstrong number.";
   return 0;
}