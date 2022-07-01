class Solution {
public:
    static bool sorting(vector<int>& a, vector<int>&b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sorting);
        int units=0;
        int boxes=0;
        int i=0;
        while(boxes<=truckSize && i<boxTypes.size())
        {
           if (boxes+boxTypes[i][0] <= truckSize)
            {
                boxes += boxTypes[i][0];
                units += boxTypes[i][1]*boxTypes[i][0];
            }
            else
            {
                units += (truckSize-boxes)*boxTypes[i][1];
                break;
            }
            i++;
        }
        return units;
    }
};