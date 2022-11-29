#include <stdio.h>
#include <stdlib.h>
#define N 6
//邻接矩阵数据结构
typedef struct
{
    int vcount;     //顶点数
    int type;       // 0 无向图，1 有向图
    char vexs[N];   // 顶点信息
    int arcs[N][N]; //关系矩阵
} GraphMatrix;

//邻接表数据结构
struct EdgeNode
{
    int endvex;                //对应顶点的边表下标
    int weight;                //边的权
    struct EdgeNode *nextedge; //链字段
};
typedef struct EdgeNode *EdgeList;

//顶点表
typedef struct
{
    char vertex;       //记录顶点的信息
    int degree;        //用于记录顶点的入度，在拓扑排序时需使用
    EdgeList edgelist; //指向边表的指针
} VexNode;

//邻接表
typedef struct
{
    VexNode vexs[N]; // N个顶点
    int type;        // 0无向图，1有向图
    int vcount;      //顶点数
} GraphList;

/*第一关 完成图初始化*/
void printGraph(GraphMatrix *G)
{ //本函数输出图的邻接矩阵
    int i, j;
    for (i = 0; i < G->vcount; i++)
    {
        // printf("%c ",G->vexs[i]);
        for (j = 0; j < G->vcount; j++)
            printf("%d ", G->arcs[i][j]);
        printf("\n");
    }
}

/*第一关 完成图初始化-邻接矩阵*/
GraphMatrix *initGraphMatrix()
{
    /*
    第一行输入图的类型、图的顶点数和边数
    第二行输入各条边的两顶点的编号
    按顶点编号从小到大的顺序输入
    输出邻接矩阵，不需要考虑输入的数字非法情况
    不输入顶点的信息
    */
    GraphMatrix *map = (GraphMatrix *)malloc(sizeof(GraphMatrix));
    int n;
    scanf("%d%d%d", &map->type, &map->vcount, &n);

    for (int i = 0; i < map->vcount; i++)
        for (int j = 0; j < map->vcount; j++)
            map->arcs[i][j] = 0;
    //初始化关系矩阵
    int i = 0;
    while (i < n)
    {
        int j, k;
        scanf("%d%d", &j, &k);
        map->arcs[j][k] = 1;
        if(map->type==0)
        {
            map->arcs[k][j]=1;
        }
        i++;
    }
    return map;
}
/*第二关 完成图初始化-邻接表,并完成输出图的邻接表函数*/
GraphList *initGraphList()
{
    /*
    第一行输入图的类型、图的顶点数和边数
    第二行输入顶点（对应下标）信息
    第三行输入各条边的两顶点的编号
    按顶点编号从小到大的顺序输入。
    输出邻接表。
    不需考虑输入的数字非法情况
    输入顶点的信息
    */
    GraphList *map = (GraphList *)malloc(sizeof(GraphList));
    int n;
    scanf("%d%d%d", &map->type, &map->vcount, &n);

    char c[map->vcount + 1];
    scanf("%s", c);
    for(int i=0; i<map->vcount; i++)
    {
        map->vexs[i].vertex = c[i];
        map->vexs[i].degree = 0;
    }
    //输入顶点数据

    int j,k,m;
    int i=0;
    for(int i=0;i<map->vcount;i++)
    {
        map->vexs[i].edgelist=NULL;
    }
    while(i<n)
    {
        if (!map->type){
            scanf("%d%d%d",&j,&k,&m);
        } else {
            scanf("%d%d",&j,&k);
        }
        EdgeList s=(EdgeList)malloc(sizeof(struct EdgeNode));

        s->endvex=k;
        s->nextedge=map->vexs[j].edgelist;
        map->vexs[j].edgelist=s;
         
        if(map->type==0)
        {
            EdgeList s1=(EdgeList)malloc(sizeof(struct EdgeNode));
            s1->endvex=j;
            s1->nextedge=map->vexs[k].edgelist;
            map->vexs[k].edgelist=s1;
            s->weight = s1->weight = m;
        } else {
            map->vexs[k].degree ++;
        }
        i++;
    }
    return map;
}

void printGraphLit(GraphList *G)
{
    /*输出邻接表，输出格式：顶点->邻接顶点编号->...*/
    for (int i = 0; i < G->vcount; i++)
    {
        EdgeList p = G->vexs[i].edgelist;
        printf("%c", G->vexs[i].vertex);
        while (p != NULL)
        {
            printf("->%d", p->endvex);
            p=p->nextedge;
        }
        printf("\n");
    }
}

/*第三关 完成图的广度遍历（周游），可根据需要添加自定义函数*/
int visited[N];
void ClearFlag(GraphList *G)
{
    for(int i=0;i<G->vcount;i++)
        visited[i]=0;
}
struct SeqQueue
{
    int f,r;
    int len;
    int *Q;
};
typedef struct SeqQueue *PQueue;

void InitQueue(PQueue q,GraphList *G)
{
    q->f=0;
    q->r=0;
    q->len=0;
    q->Q=(int *)malloc(sizeof(int)*G->vcount);
}
void EnQueue(PQueue q,int index)
{
    if(q->r==q->len-1)
    {
        printf("Out of Space");
        return;
    }
    q->Q[q->r]=index;
    q->r=q->r+1;
    q->len=q->len+1;
}
void DeQueue(PQueue q)
{
    q->Q[q->r]=0;
    q->r=q->r-1;
    q->len=q->len-1;
}
void BFS(GraphList *G,int index)
{
    EdgeList p;
    PQueue WaitingQueue=(PQueue)malloc(sizeof(struct SeqQueue));
    InitQueue(WaitingQueue,G);
    if(visited[index]==1)
        return;
    printf("%d ",index);
    visited[index]=1;
    EnQueue(WaitingQueue,index);
    p=G->vexs[index].edgelist;
    while(WaitingQueue->len!=0)
    {
        DeQueue(WaitingQueue);
        while(p)
        {
           if(visited[p->endvex]==1)
                p=p->nextedge;
           else if(visited[p->endvex]==0)
           {
               visited[p->endvex]=1;
               EnQueue(WaitingQueue,p->endvex);
               printf("%d ",p->endvex);
           }
        }
    }
}

void BFS_list(GraphList *G)
{
    ClearFlag(G);
    for(int i=0;i<G->vcount;i++)
        if(!visited[i])
            BFS(G,i);
}
/*第四关 完成图的深度遍历（周游），可根据需要添加自定义函数 */

void DFS(GraphList *G,int index)
{
    EdgeList p=G->vexs[index].edgelist;
    if(visited[index]==1)
        return;
    printf("%d ",index);
    visited[index]=1;
    while(p&&visited[p->endvex]==1)
        p=p->nextedge;
    if(p)
    {
        index=p->endvex;
        DFS(G,index);
    }
}
void DFS_list(GraphList *G)
{
    ClearFlag(G);
    for(int i=0;i<G->vcount;i++)
        if(!visited[i])
            DFS(G,i);
}

/*第五关 生成图的拓扑排序，可根据需要添加自定义函数
*/
int q[N], hh, tt = -1;
void Top_list(GraphList *G)
{
	for (int i = 0; i < G->vcount; i ++) {
        if (G->vexs[i].degree == 0) q[++ tt] = i;
    }
    while (hh <= tt) {
        int t = q[hh ++];
        printf("%c ", G->vexs[t].vertex);
        for (EdgeList p = G->vexs[t].edgelist; p ; p = p->nextedge) {
            int idx = p->endvex;
            G->vexs[idx].degree --;
            if (G->vexs[idx].degree == 0){
                q[++ tt] = idx;
            }
        }
    }
}
/*第六关 prim算法生成最小生成树*/
int st[N], dist[N], from[N];
void Prim_list(GraphList *G)
{
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < G->vcount; i ++) {
        int t = -1;
        /* 选出最小的边 */
        for (int j = 0; j < G->vcount; j ++)
            if (!st[j] && (t == -1 ||  dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == 0x3f3f3f3f){
            puts("无法建树");
            return;
        }
        if (i) {
            printf("%d %d\n", from[t] , t);
        }
        st[t] = 1;
        for (int j = 0; j < G->vcount; j ++) {
            int tdist = 0x3f3f3f3f;
            for (EdgeList p = G->vexs[t].edgelist; p ; p = p->nextedge)
                if (p->endvex == j){
                    tdist = p->weight;
                    break;
                }
            if (dist[j] > tdist) {
                dist[j] = tdist;
                from[j] = t;
            }
        }
    }
}
/*第七关 Kruskal算法生成最小生成树*/

void Kruskal_list(GraphList *G)
{

}

/*第八关 Dijistra算法求最短路径*/

void Dijkstra_list(GraphList *G)
{

}

