class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> m;
        priority_queue<int> p;
        for (auto i : arr)
        {
            m[i]++;
        }
        for (auto i : m)
        {
            p.push(i.second);
        }
        int freq = 0, no_ele = 0;
        while (!p.empty())
        {
            freq += p.top();
            p.pop();
            no_ele++;

            if (freq >= arr.size() / 2)
            {
                return no_ele;
            }
        }
        return 0;
    }
};