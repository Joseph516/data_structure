/**
 * 给定图G=（V，E）和G中的两个顶点s，t。设计一个算法求一条从s到t的简单路径（路径上任何两个点都不重复）。
 */

// 定义图的结构
#define MAX_VERTEX_NUM 20

typedef struct ArcNode {
  int adjvex;
  struct ArcNode* nextarc;
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode* firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
  AdjList vertices;
  int vexnum, arcnum;
  int kind;
} Graph;

// 记录已经访问结点
int visited[MAX_VERTEX_NUM] = {0};

// 定义函数
void FindPath(Graph* G, int s, int t, int path[], int indx) {
  // 加入起点s，indx初始化为0
  path[++indx] = s;
  visited[s] = 1;
  if(s == t) {
    // 找到终点，并打印出路径
    for(int k = 1; k <= indx; k++) {
      std::cout << path[k];
    }
    exit(0);
  } else {
    // DFS遍历
    for(ArcNode* p = G->vertices[s].firstarc; p != nullptr; p = p->nextarc) {
      if(visited[p->nextarc] == 0) {
        // 未访问结点
        FindPath(G, p->adjvex, t, path, indx);
      }
    }
  }
}