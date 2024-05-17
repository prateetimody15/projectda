#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100

struct edge {
  int s, d, w;
};

int bellmanFord(int n, int e, int src, struct edge edge[], int dist[]) {
  int i, j;
  int s, d, w;

  i = src;

  dist[i] = 0;

  // n-1 passes
  for(i=1; i<n; i++) {
    // for each edge
    for(j=0; j<e; j++) {
      s = edge[j].s;
      d = edge[j].d;
      w = edge[j].w;

      // if we can get a smaller value of dist[d] using this edge, replace it
      if(dist[s] != INT_MAX && dist[s] + w < dist[d]) {
        dist[d] = dist[s] + w;
      }
    }
  }

  // this loop is to detect a negative loop
  for(j=0; j<e; j++) {
    s = edge[j].s;
    d = edge[j].d;
    w = edge[j].w;

    if(dist[s] != INT_MAX && dist[s] + w < dist[d]) {
      // we have caught a negative loop
      return 0;
    }
  }

  // all okay signal
  // indicating no negative loop
  return 1;
}

int main() {
  int i;
  int n, e;
  int s, d, w;
  int src;

  printf("Enter the number of vertices ");
  scanf("%d", &n);

  printf("Enter the number of edges ");
  scanf("%d", &e);

  struct edge edge[e];

  printf("Enter the src, dest and weight of each edge\n");
  for(i=0; i<e; i++) {
    scanf("%d%d%d", &s, &d, &edge[i].w);
    edge[i].s = s-1;
    edge[i].d = d-1;
  }

  printf("Enter the source vertex ");
  scanf("%d", &src);

  // create a vector of size n(for n vertices) and initialize the value of each element to infinity
  // dist[i]=the minimum distance of vertex i from source vertex
  int dist[n];
  for(i=0; i<n; i++) {
    dist[i] = INT_MAX;
  }

  i = bellmanFord(n, e, src, edge, dist);

  printf("\n");

  if(i) {
    printf("vectex      Min. distance from source\n");
    for(i=0; i<n; i++) {
      printf("%d         %d\n", i+1, dist[i]);
    }
  }

  else {
    // negative loop
    printf("There is a negative weight loop in the graph \n");
  }

  return 0;
}
