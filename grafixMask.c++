#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<iostream>

int maskedArea[401][601];

using namespace std;


int result;


class grafixMask {

	public:
	int doDfs(int x, int y) {
        result =0;
		std::stack<std::pair<int,int> > traverse;
		traverse.push(std::make_pair(x,y));
		int currX, currY;
		while(!traverse.empty()) {
			currX = (traverse.top()).first;
			currY = (traverse.top()).second;

			traverse.pop();
            if(currX<0 || currX>400)
                continue;
            if(currY<0 || currY>600)
                continue;

			if(maskedArea[currX][currY] == 1)
                continue;
            maskedArea[currX][currY] = 1;
    			result++;
            traverse.push(std::make_pair(currX+1, currY));
            traverse.push(std::make_pair(currX, currY+1));
            traverse.push(std::make_pair(currX-1, currY));
            traverse.push(std::make_pair(currX, currY-1));

		}
		return result;

	}

	vector<int> sortedAreas(vector<string> rectangles) {
		result = 0;
		int coloredSize = sizeof(rectangles)/sizeof(rectangles[0]);
        memset(maskedArea, -1, sizeof(maskedArea));
		for(int i=0;i<coloredSize;i++) {
            int x1,y1,x2,y2;
    		sscanf(rectangles[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
            for(int i=x1;i<=x2;i++)
    			for(int j= y1;j<=y2;j++)
    				maskedArea[i][j] = 1;
        }

    		vector<int> distinctAreas;
    		for(int i=0;i<=400;i++)
    			for(int j=0;j<=600;j++) {

                    if(maskedArea[i][j]!=-1) {
        				int pixels = doDfs(i,j);
        				if(pixels>0)
    					    distinctAreas.push_back(pixels);
                    }
    			}
    		sort(distinctAreas.begin(), distinctAreas.end());
    		return distinctAreas;
	}
};


int main() {

grafixMask k;
vector<int> sortedInt;
vector<string> someStrings;
someStrings.push_back("48 192 351 207");
someStrings.push_back("48 392 351 407");
someStrings.push_back("120 52 135 547");
someStrings.push_back("260 52 275 547");

sortedInt = k.sortedAreas(someStrings);
for(int i=0;i<sortedInt.size();i++)
    cout<<sortedInt[i]<<endl;

  }
