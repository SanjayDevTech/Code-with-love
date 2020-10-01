#include <iostream>
using namespace std;

int input;

void goldbach(int test_value) {
  if (test_value % 2 == 1) {
    return;
  }
  int a = (test_value / 2);
  if (a % 2 == 0) {
    a -= 1;
  }
  for (int i = a; i > 0; i -= 2) {
    int gr = sqrt(i) + 1;
    int hr = sqrt(test_value - i) + 1;
    bool t = 1;
    for (int j = 3; j < max(gr, hr); j += 2) {
      if (j < gr && i % j == 0) {
        t = 0;
        break;
      }
      if (j < hr && (test_value - i) % j == 0) {
        t = 0;
        break;
      }
    }
    if (t) {
      cout << i << " " << test_value - i << "\n";
      return;
    }
  }
}
int main() {
  cin >> input;
  goldbach(input);
}