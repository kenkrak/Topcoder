#include<vector>
#include<string>
#include<math.h>
#include<limits>

using namespace std;

#define imax std::numeric_limits<double>::max();

class ATaleOfThreeCities {

    public:
    double connect(vector<int> ax, vector<int> ay, vector<int> bx, vector<int> by, vector<int> cx, vector<int> cy) {
		int size = ax.size();
    	double minDistAB = imax;
        double minDistBC = imax;
    	double currDist1;
        double currDist2;
    	for(int i=0;i<size;i++) {
            currDist1 = sqrt(pow((bx.at(i)-ax.at(i)),2)+pow((by.at(i)-ay.at(i)),2));
            if(currDist1<minDistAB) {
                minDistAB = currDist;
            }

            currDist2 = sqrt(pow((cx.at(i)-bx.at(i)),2)+pow((cy.at(i)-by.at(i)),2));
            if(currDist2<minDistBC) {
                minDistBC = currDist2;
            }
        }
        return minDistBC+minDistAB;
    }
};
