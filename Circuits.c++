#include<sstream>
#include<string>
#include<iostream>
#include<stack>
#include <map>
#include<vector>

using namespace std;

class Circuits {
public:
    std::map<int, vector<int> > adjacencyList;
    std::map<int, vector<int> > dupCosts;
    int getDfsMaxPath(int index) {
        int cost = -1;
        stack<int> path;
        int currNode = index;
        int totalCost = 0;
        stack<int> elem;
        elem.push(index);
        while(true) {
            currNode = elem.top();
            elem.pop();
            vector<int> neighbors = adjacencyList[currNode];
            int cost = -1;
            if(neighbors.size()!=0) {
                for(int i=0;i<neighbors.size();i++) {
                    if(dupCosts[currNode][i] > cost) {
                        cost = dupCosts[currNode][i];
                        currNode = neighbors[i];
                    }
                }
                elem.push(currNode);
                totalCost+=cost;
            }
            else
                break;
        }
        return totalCost;
    }
	int howLong(vector<string> connects, vector<string> costs) {
        for(int i=0;i<connects.size();i++) {
            istringstream connect(connects[i]);
            istringstream cost(costs[i]);
            vector<int> neighbors;
            vector<int> costsN;
            int vertex;
            int currCost;
            while(connect>>vertex) {
                cost>>currCost;

                costsN.push_back(currCost);
                neighbors.push_back(vertex);
            }
            adjacencyList[i] = neighbors;
            dupCosts[i] = costsN;
        }
        // for(int i=0;i<connects.size();i++) {
        //     // cout<<i<<"-> ";
        //     vector<int> list;
        //     list = dupCosts[i];
        //     for(int j=0;j<list.size();j++) {
        //         // cout<<list[j]<<" ";
        //     }
        //     // cout<<endl;
        // }
        int maxCost = -1;
        for(int i=0;i<connects.size();i++) {
            int cost1 = getDfsMaxPath(i);
            if(cost1>maxCost) {
                maxCost = cost1;
            }
        }
        return maxCost;
    }

};


int main() {

Circuits c;
vector<string> costsu;
vector<string> nodes;
nodes.push_back("1 2");
nodes.push_back("2");
nodes.push_back("");
costsu.push_back("5 3");
costsu.push_back("7");
costsu.push_back("");
cout<<c.howLong(nodes,costsu)<<endl;

}
