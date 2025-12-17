#include <stdio.h>
#define MAX 50

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front=-1, rear=-1;
int vertices;


void enqueue(int v)
{
    if(front==-1)
        front=0;
    queue[++rear]=v;
}

int dequeue()
{
    int v=queue[front++];
    if(front>rear)
        front=rear=-1;
    return v;
}

void BFS(int start)
{
    int i;

    for(i=0; i<vertices; i++)
        visited[i]=0;

    visited[start]=1;
    enqueue(start);

    printf("\nBFS Traversal: ");

    while(front!=-1)
    {
        int cur=dequeue();
        printf("%d ", cur);

        for (i=0; i<vertices; i++)
        {
            if(adj[cur][i]==1&&visited[i]==0)
            {
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}


void DFS(int v)
{
    int i;
    visited[v]=1;
    printf("%d ", v);

    for(i=0; i<vertices; i++)
    {
        if(adj[v][i]==1&&visited[i]==0)
            DFS(i);
    }
}

int main()
{
    int edges, i, j, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Vertices will be numbered from 0 to %d\n", vertices - 1);

    printf("\nEnter number of edges: ");
    scanf("%d", &edges);

    for(i=0; i<vertices; i++)
        for(j=0; j<vertices; j++)
            adj[i][j] = 0;

    printf("\nDefine connections between vertices\n");
    printf("Format: source destination\n");
    printf("Example: 0 1 means vertex 0 is connected to vertex 1\n\n");

    for(i=0; i<edges; i++)
    {
        printf("Connection %d: ", i+1);
        scanf("%d %d", &u, &v);

        adj[u][v]=1;
        adj[v][u]=1;
    }

    printf("\nAdjacency Matrix:\n");
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    BFS(start);

    for(i=0; i<vertices; i++)
        visited[i]=0;

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
