#ifndef _GRAPH_
#define _GRAPH_

#define Max_Vertex_Num 100

typedef int VertexType;

// 邻接表存储
// 表结点
typedef struct ArcNode {
  int adjvex; // 顶点的位置
  struct ArcNode * firstarc;
}ArcNode;

// 头结点
typedef struct {
  VertexType data; // 顶点信息
  ArcNode * nextarc;
}VNode, AdjList[Max_Vertex_Num];

typedef struct {
  AdjList vertices;
  int vexnum, arcnum;
  int kind;
}ALGraph;

#endif