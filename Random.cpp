#include<iostream>   //0 1 Knapsack
using namespace std;
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
   int val[] = {2,1,4,3};
   int wt[] = {3,4,6,1};
   int W = 13;
   int n = sizeof(val)/sizeof(val[0]);
   printf("The solution is : %d", knapsack(W, wt, val, n));
}

#include<iostream>  //fractional knapsack
using namespace std;
int main(){
int item; cin>>item;
    float v[item],w[item],comp[item];
    for(int i=0; i<item; i++){
        cin>>v[i];  cin>>w[i];
        comp[i]=v[i]/w[i];
    }
    int ksize; cin>>ksize;
    int index=0;
    float profit=0;
    while(ksize!=0){
        float big=0;
        for(int i=0; i<item; i++){
            if(big<comp[i]){
                big=comp[i]; index=i;
            }
        }
        if(ksize>=w[index]){
            profit+=v[index];  ksize-=w[index];
        }
        else if(ksize<w[index]){
            profit+= ksize*comp[index]; ksize-=ksize;
        }
        comp[index]=0;
    }
    cout<<"Max profit: "<<profit<<endl;
}
#include<iostream>  // coin greedy
using namespace std;
int x; int n;
int main(){
    int siz;   cin>>siz;
    int ar[siz];
    for(int i=0; i<siz; i++) {   cin>>ar[i];  }
    int sum;    cout<<"Enter the amount of change :"; //,1000, 500 , 100, 50, 20 , 10
    cin>>sum;   int i=0;
    while(sum!=0){
        if(ar[i]>sum) {  i++; continue;}
        x=ar[i];    n = sum/ar[i];    cout<<"you will give him "<<n<<" note of "<<x<<" Taka "<<endl;
        sum-= n*ar[i];   i++;
    }  
}

#include <iostream>  //Coin Dynamic
using namespace std;
void minimumNumberOfCoin(int n, int coin[], int amount){
      int solution[n][amount + 1];
      for (int i = 0; i < n; i++) {
            solution[i][0] = 0;
            for (int j = 1; j < amount + 1; j++)
            {
                  solution[0][j] = j;
            }
      }
      for (int i = 1; i < n; i++){
            for (int j = 1; j < amount + 1; j++) {
                  if (coin[i] > j) {
                        solution[i][j] = solution[i - 1][j];
                  }
                  else {
 solution[i][j] = min(solution[i - 1][j], 1 + solution[i][j - coin[i]]);
                  }
            }
      }
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < amount + 1; j++){
                  printf("%d ", solution[i][j]);
            }
 printf("\n");
      }
      printf("Answer is: %d\n", solution[n - 1][amount]);
}
int main()
{
      int n;
      printf("Enter number of coin: ");
      scanf("%d", &n);
      int coin[n];
      printf("Enter coin:\n");
      for (int i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
      }
      int amount;
      printf("Enter amount: ");
      scanf("%d", &amount);
      minimumNumberOfCoin(n, coin, amount);
      return 0;
}

#include <iostream>    //DFS
using namespace std;
#define MAX_NODES 100
bool graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
void dfs(int startNode, int numNodes) {
    cout << startNode << " ";
    visited[startNode] = true;
    for (int i = 0; i < numNodes; ++i) {
        if (graph[startNode][i] && !visited[i]) {
            dfs(i, numNodes);
        }
    }
}
int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = true;
        graph[node2][node1] = true;
    }
    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;
    cout << "DFS traversal: ";
    dfs(startNode, numNodes);
    return 0;
}

#include <iostream>  //SHORTEST PATH
using namespace std;
#include <limits.h>
#define V 9
int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void printSolution(int dist[]){
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(int graph[V][V], int src){
	int dist[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}
int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);
	return 0;
}

#include <stdio.h>  //MIN PATH FOR A GRAPH FOR A SPECEFIC SOURCE
#include <limits.h>
#define V 6
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t%d ", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];
    int parent[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
  visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(dist, parent, src);
}
int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    int src = 0;
    dijkstra(graph, src);

    return 0;
}
#include <iostream> //longest common subsequence
#include <string.h>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
int lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    return 0;
}
#include <iostream> // Longest Increasing subsequence
using namespace std;
int lis(int arr[], int n) {
    int lis[n];
    int i, j, max = 0;
    for (i = 0; i < n; i++)
        lis[i] = 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (max < lis[i])
            max = lis[i];
    }
    return max;
}
int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of the Longest Increasing Subsequence is %d\n", lis(arr, n));
    return 0;
}


