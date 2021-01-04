/*We will be printing a Hollow Diamond Inscribed in a Rectangle
For Example:
Input  = 5
Output = * * * * * * * * * *             
         * * * *     * * * *
         * * *         * * *
         * *             * *
         *                 *
         * *             * *
         * * *         * * *
         * * * *     * * * *
         * * * * * * * * * *               */


#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n; //taking a number as input, as in the above example, n=5


	/*printing the upper half of the rectangle*/

	for(int i = 0 ; i < n ; i++){
	  for(int j = 0 ; j < (2 * n) ; j++){
	    if(i + j <= n-1)  // upper left triangle
		cout << "*";
	    else
                cout << " ";
            if((i + n) <= j)  // upper right triangle
                cout << "*";
            else
                cout << " ";
		}
		cout << "\n";
	}


	/*printing the lower half of the rectangle*/

	for(int i = 0 ; i < n ; i++){
	  for(int j = 0 ; j < (2 * n) ; j++){
	    if(i >= j)                // bottom left triangle
                cout << "*";
            else
                cout << " ";
            if(i >= (2 * n - 1) - j)  // bottom right triangle
                cout << "*";
            else
                cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
