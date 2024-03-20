#include <stdio.h>
#include <stdlib.h>
/*
 * One-Dimensional Cellular Automata Visualization implemented in C
 * if you want to learn more about:  https://github.com/PacLucas/Cellular-Automata-Visualization 
 */
int main(){
  char *CAprev, *CAatu;
  int bit, n, l, rule, M, N;

  printf("\nLine length: ");
  scanf("%d", &N);
  printf("Number of lines: ");
  scanf("%d", &M);
  printf("Rule from 0 to 255: ");
  scanf("%d", &rule);

  // Allocate two char vectors, one for the previous line and one for the current line
  CAprev = (char*) malloc(N*sizeof(char));
  CAatu = (char*) malloc(N*sizeof(char));

  for(n = 0; n < N; n++)  CAprev[n] = 0;

  // Initializes with only one active state in the middle of the previous line
  CAprev[N/2] = 1;

  for(l = 2; l <= M; l++){
    for(n = 1; n < N - 1; n++){
      bit = CAprev[n - 1] << 2 | CAprev[n] << 1 | CAprev[n + 1]; // encodes each neighbor to a bit by bit
      CAatu[n] = (rule & (1 << bit)) != 0;                       // 1 << bit does 2 ^ bit bit shifts | rule & (1 << bit) checks whether the neighborhood matches within the rule | ! = 0 ensures that it will only store 1 or 0
    }

    // CAprev vector print
    for(int p = 0; p < N; p++){
      if(CAprev[p] == 0) printf("  ");
      else  printf("O ");
    }
    puts("");

    // Copy Vector
    for(int p = 0; p < N; p++)  CAprev[p] = CAatu[p];
    system("sleep 0.18");
  }
}