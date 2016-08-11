class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if((int)nums.size()==0)
            return 0;
         if((int)nums.size()==1)
            return 1;
        else
        {   vector<int> ::iterator it=nums.begin();
            int previous=nums.front();
            while (it != nums.end()) {
                if(((*it)==previous)&&(it!=nums.begin()))
                  it = nums.erase(it);
                 else
                 {previous=*it;
                     it++;
                 }
                                     }
            return (int)nums.size();
        }
        
    }
};
