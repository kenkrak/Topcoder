#include <map>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

class Node {
    public:
        vector<int> neighbors;
};


class Marketing {

    public:
        Node products[30];
        int target[30];
        bool visited[30];

        int competeSize;
        void printAdjacency() {
            for(int i=0;i<competeSize;i++) {
                for(int j=0;j<products[i].neighbors.size();j++) {
                    cout<<products[i].neighbors[j]<<" ";
                }
                cout<<endl;
            }
        }
        long dfs(int startNode, int p) {
            std::stack<int> unvisited;
            memset(visited, 0, sizeof(visited));
            target[startNode] = p;
            unvisited.push(startNode);

            while(!unvisited.empty()) {
                int stackTop = unvisited.top();
                int audience = target[stackTop];
                visited[stackTop] = true;
                unvisited.pop();

              for(int i=0;i<products[stackTop].neighbors.size();i++) {
                  int currNode = products[stackTop].neighbors[i];

                  if(visited[currNode] == true)
                        continue;

                  if(target[currNode]!=audience) {

                    unvisited.push(currNode);
                    target[currNode] = (audience ^ 1);
                    cout<<currNode<<"  "<<target[currNode]<<endl;
                  }
              }
            }
            int permute = 1;
            for(int p=0;p<competeSize;p++) {
                    if(target[p]==-1) {
                        if(products[p].neighbors.size()==0)
                            permute *=2;
                        else
                            return 0;
                    }
            }
            if(permute>1)
                return 1+permute;
            return 1;
        }
        long howMany(vector<string> compete) {
            for(int i=0;i<compete.size();i++) {
                int k=0;int num;
                this->competeSize = compete.size();
                while(k<compete[i].length()) {
                    sscanf(&compete[i][k], "%d", &num);
                    products[i].neighbors.push_back(num);
                    products[num].neighbors.push_back(i);
                    k+=2;
                }
            }
            printAdjacency();
            long countCombinations = 0;
            // for(int i=0;i<compete.size();i++) {
                memset(target,-1, sizeof(target));
                long adult = dfs(0,0);
                memset(target,-1, sizeof(target));
                long youngsters = dfs(1,1);
                // cout<<adult<<"    "<<youngsters<<endl;
                countCombinations+=adult+youngsters;
            // }
            return countCombinations;

        }
};

int main() {
    Marketing m;
    vector<string> com;
    com.push_back("1");
    com.push_back("2");
    com.push_back("3");
    com.push_back("0");
    com.push_back("0 5");
    com.push_back("1");
    cout<<m.howMany(com)<<endl;
}
