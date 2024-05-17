#include <stdio.h>
#include <limits.h>

#define MAX 9

void min_distance(int arr[][MAX], int n, int d[], int p[], int cost[]) {
  cost[n] = 0;
  for(int i=n-1; i>0; i--) {
    int min = INT_MAX;
    for(int j=i+1; j<=n; j++) {
      if(arr[i][j]!=0 && arr[i][j]+cost[j]<min) {
        min = arr[i][j] + cost[j];
        d[i] = j;
      }
    }
    cost[i] = min;
  }

  p[1] = 1;
  p[n] = n;
  for(int k=2; k<n; k++) {
    p[k] = d[p[k-1]];
  }
}

int main() {
  int arr[][MAX] = {{0,0,0,0,0,0,0,0,0},
                    {0,0,2,1,3,0,0,0,0},
                    {0,0,0,0,0,2,3,0,0},
                    {0,0,0,0,0,6,7,0,0},
                    {0,0,0,0,0,6,8,9,0},
                    {0,0,0,0,0,0,0,0,6},
                    {0,0,0,0,0,0,0,0,4},
                    {0,0,0,0,0,0,0,0,5},
                    {0,0,0,0,0,0,0,0,0}};

  int n = 8;
  int d[MAX];
  int p[MAX];
  int cost[MAX];

  min_distance(arr, n, d, p, cost);

  printf("The minimum distance from start is %d\n", cost[1]);
  printf("The order is ");
  for(int i=1; i<=n; i++) {
    printf("%d->", p[i]);
  }
  printf("\n");

  return 0;
}
