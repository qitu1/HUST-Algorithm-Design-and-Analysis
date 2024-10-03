#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int dp[505][505];//dp[i][j]表示：坐标为i,j的最长滑坡长度为dp[i][j]
int matrix[500][500];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;
int ans;//记录答案
struct Node{
    int val;
    int x;
    int y;
    Node(){}
    Node(int vv, int xx, int yy){
        val = vv;
        x = xx;
        y = yy;
    }
};
vector<Node> nodes;
bool cmp(Node n1, Node n2){
    return n1.val < n2.val;
}
int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &matrix[i][j]);
            dp[i][j] = 1;
            nodes.push_back(Node(matrix[i][j], i, j));
        }
    }
    sort(nodes.begin(), nodes.end(), cmp);
    ans = dp[nodes[0].x][nodes[0].y] = 1;
    for(int i = 1; i < nodes.size(); ++i){
        int xx = nodes[i].x;
        int yy = nodes[i].y;
        int vv = nodes[i].val;
        for(int k = 0; k < 4; ++k){
            int tx = xx + dir[k][0];
            int ty = yy + dir[k][1];
            if(tx >= 0 && tx < m && ty >= 0 && ty < n){
                if(vv > matrix[tx][ty]){
                    dp[xx][yy] = max(dp[xx][yy], dp[tx][ty] + 1);
                    if(dp[xx][yy] > ans){
                        ans = dp[xx][yy];
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


