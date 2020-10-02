/* Input:-

4

Output:-

       ****                         ****                     
      ****                         *  *
     ****                         *  *
    ****                         ****  

  Solid Rhombus                Hollow Rhombus   */

  //Solution for Printing a solid and hollow Rhombus in C++ :

  #include <iostream>
using namespace std;
int main()
{
int i, j, n;
cin >> n;

// solid rhombus

cout << "Solid Rhombus" << endl;
for(i = 0; i < n; i++)
{
for(j = 0; j < n - i; j++)
{
cout << " ";  // leading spaces
}
for(j = 0; j < n; j++)
{
cout << "*";
}
cout << "\n";
}

// hollow rhombus

cout << "Hollow Rhombus" << endl;
for(i = 0; i < n; i++)
{
for(j = 0; j < n - i; j++)
{
cout << " ";  // leading spaces
}
for(j = 0; j < n; j++)
{

// upper horizontal, bottom horizontal, left diagonal, right diagonal

if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
cout << "*";
else
cout << " "; 
}
cout << "\n";
}
return 0;
}

