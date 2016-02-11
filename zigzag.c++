#include <vector>
#include <cstring>
#include <iostream>
using namespace std;


# Dynamic programming
class ZigZag {
	public:
	int increasing[50];
	int decreasing[50];
		int longestZigZag(vector<int> sequence) {
		vector<int> final;

			for(int i=0;i<sequence.size();i++)
			{
				increasing[i] = 1;
				decreasing[i] = 1;
			}
			for(int i=1;i<sequence.size();i++) {
				for(int j=i-1;j>=0;j--) {
					if(sequence[i]==sequence[j])
						continue;
					if(sequence[j]>sequence[i] && decreasing[i]<increasing[j]+1)
					{
						decreasing[i] = increasing[j]+1;
					}
					if(sequence[j]<sequence[i] && increasing[i]<decreasing[j]+1)
						increasing[i]= decreasing[j]+1;

				}
				final.push_back(max(increasing[i],decreasing[i]));
				cout<<max(increasing[i], decreasing[i])<<endl;

			}
            int max =-1;
            for(int i=0;i<final.size();i++) {
                    if(final[i]>max)
                        max = final[i];
            }
		 return max;
    }

};
