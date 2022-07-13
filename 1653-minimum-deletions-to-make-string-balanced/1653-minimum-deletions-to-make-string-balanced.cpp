class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int dpa=0, dpb=0;
        for(int i=0;i<n;i++)
        {
            int new_dpa=dpa;
            int new_dpb=min(dpa,dpb);
            if(s[i]=='a')
            {
                new_dpb++;
            }
            else
            {
                new_dpa++;
            }
            dpa=new_dpa;
            dpb=new_dpb;
        }//for i
        return min(dpa,dpb);
        
    }
};