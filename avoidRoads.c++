#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <cstring>

using namespace std;
std::vector<std::pair<int,int> > cord1, cord2;

long long numPaths[100][100];

class AvoidRoads {

	public:
		long long numWays (int width, int height, vector<string> bad) {
			std::vector<std::pair<int,int> > coordinates;
			int x1,x2,y1,y2;
			memset(numPaths, -1, sizeof(numPaths));

			for(int i=0;i<bad.size();i++) {
				string s = bad[i];
				sscanf(s.c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
                cout<<x1<<y1<<x2<<y2<<endl;
				cord1.push_back(make_pair(min(x1,x2),min(y1,y2)));
                cord2.push_back(make_pair(max(x1,x2),max(y1,y2)));
			}
			numPaths[width][height] = 1;
			// long long p = getNumPaths(0,0,width,height);
            return  getNumPaths(0,0,width,height);
            // for(int i=0;i<=width;i++) {
            //     for(int j=0;j<=height;j++)
            //         cout<<numPaths[i][j]<<"    ";
            //         cout<<endl;
            //     }
		}

		int isBad(int x1, int y1, int x2, int y2) {
			for(int i=0;i<cord1.size();i++) {
                if(cord1[i].first == x1 && cord1[i].second == y1 && cord2[i].first == x2 && cord2[i].second == y2)
                    return 1;
            }
            return 0;
		}

		long long getNumPaths(int x, int y, int width, int height) {

            if(x> width || y> height)
                return 0;
            if(numPaths[x][y] != -1)
				return numPaths[x][y];

			numPaths[x][y] = 0;
			if(!isBad(x,y,x+1,y))
				numPaths[x][y] += getNumPaths(x+1,y,width,height);

			if(!isBad(x,y,x,y+1))
				numPaths[x][y] += getNumPaths(x,y+1,width,height);

			return numPaths[x][y];
		}

};
int main() {

    AvoidRoads a;
     std::vector<string> str;
       str.push_back("0 0 0 1");
       str.push_back("6 6 5 6");
    cout<<a.numWays(6,6, str)<<endl;

}
