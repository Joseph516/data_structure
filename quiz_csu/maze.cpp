/**
 * 中南大学2019年考研试题
 * 题目:给定一张迷宫地图，该地图标识了迷宫各处额坐标位置，并已知迷宫各位的的状态信息，
 * 即该处是墙还是路。 移动方向是东，南，西，北4个方向。
 * 设计一个数据结构对迷宫进行储存，并设计算法对任意给定的迷宫，求出一条从入口到出口的通路，或得出没有通路的结论。
 * 牛客网参考试题：华为机试中的迷宫问题
 * 
 */
/* 输入
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 0 1
0 0 0 0 0
*/
/* 输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/


#include <iostream>
#include <stack>
using namespace std;

// (1)采用数组表示法存储迷宫，其中1表示墙，0表示通路。
#define MAX_SIZE 10

// 迷宫通道块状态
// enum { road, wall };

// 迷宫位置类型
typedef struct {
  int r, c;  // 行，列
} PosType;

// Maze
typedef struct {
  int data[MAX_SIZE][MAX_SIZE];  // 1表示墙，0表示路
  int r, c;                      // 迷宫实际行，列
} MazeType;

// 栈的类型
typedef struct {
  PosType seat;
  int di;
} SElemType;

// 方向数组: 东，南，西，北
int dic[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 迷宫输入
void InputMaze(MazeType& maze) {
  cout << "输入迷宫行列数(<10)，并输出其状态(1：墙；0：路):" << endl;
  cin >> maze.r >> maze.c;
  int i, j;
  for (i = 0; i < maze.r; i++) {
    for (j = 0; j < maze.c; j++) {
      cin >> maze.data[i][j];
    }
  }
}

// 迷宫打印
void PrintMaze(MazeType maze) {
  int i, j;
  cout << "打印迷宫" << endl;
  for (i = 0; i < maze.r; i++) {
    for (j = 0; j < maze.c; j++) {
      cout << maze.data[i][j] << " ";
    }
    cout << endl;
  }
}

// 搜索迷宫通路
void FindPath(MazeType maze, PosType start, PosType end) {
  stack<SElemType> s;
  PosType curpos = start;
  SElemType e;

  // 记录访问过的路径状态
  // 0：未访问，1：访问；-1：不通路径
  int visited[MAX_SIZE][MAX_SIZE] = {0};

  do {
    if (visited[curpos.r][curpos.c] == 0 && curpos.r < maze.r &&
        curpos.c < maze.c && maze.data[curpos.r][curpos.c] == 0) {  // 路径通
      // 留下足迹
      visited[curpos.r][curpos.c] = 1;
      e = {curpos, 0};
      s.push(e);
      if (curpos.r == end.r && curpos.c == end.c) {
        stack<SElemType> s1;
        while (!s.empty()) {
          e = s.top();
          s1.push(e);
          s.pop();
        }
        // 打印路径
        cout << "打印迷宫路径" << endl;
        while (!s1.empty()) {
          e = s1.top();
          s1.pop();
          cout << "(" << e.seat.r << "," << e.seat.c << ")" << endl;
        }
        return;
      }
      // 探索下一个位置
      curpos.r = curpos.r + dic[0][0];
      curpos.c = curpos.c + dic[0][1];
    } else {
      if (!s.empty()) {
        e = s.top();
        s.pop();
        while (e.di == 3 && !s.empty()) {
          // 留些不能通过的标记
          visited[curpos.r][curpos.c] = -1;
          e = s.top();
          s.pop();
        }
        if (e.di < 3) {
          e.di++;
          s.push(e);
          // 探索下一个位置
          curpos.r = e.seat.r + dic[e.di][0];
          curpos.c = e.seat.c + dic[e.di][1];
        }
      }
    }
  } while (!s.empty());

  cout << "迷宫无通路" << endl;
}


int main(void) {
  // 获得迷宫
  MazeType maze;

  InputMaze(maze);
  // PrintMaze(maze);
  
  // 测试对角线是否通路
  FindPath(maze, {0, 0}, {maze.r - 1, maze.c - 1});
}