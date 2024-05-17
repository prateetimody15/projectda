#include <stdio.h>

#define INF 100000

int coin_change_modified(int d[], int n, int k) {
  int M[n+1];
  M[0] = 0;

  int S[n+1];
  S[0] = 0;

  int i, j;
  for(j=1; j<=n; j++) {
    int minimum = INF;
    int coin=0;

    for(i=1; i<=k; i++) {
      if(j >= d[i-1]) {
        if(1+M[j-d[i-1]] < minimum) {
          minimum = 1+M[j-d[i-1]];
          coin = i-1;
        }
      }
    }
    M[j] = minimum;
    S[j] = coin;
  }

  // Code to print the coins
  int l = n;
  printf("The coins are: ");
  while(l>0) {
    printf("%d ", d[S[l]]);
    l = l-d[S[l]];
  }
  printf("\n");

  return M[n];
}

int main() {
  int n, k;
  printf("Enter the amount: ");
  scanf("%d", &n);

  printf("Enter the number of denominations: ");
  scanf("%d", &k);

  int d[k];
  printf("Enter the denominations: ");
  for(int i=0; i<k; i++) {
    scanf("%d", &d[i]);
  }

  int result = coin_change_modified(d, n, k);
  printf("The minimum number of coins is: %d\n", result);

  return 0;
}
