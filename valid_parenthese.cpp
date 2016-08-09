class Solution {
public:
    bool isValid(string s) {
        int i=0;
        while(s[i]!='\0')
        {
            switch(s[i])
            {
                case '(':
                    if(s[i+1]!=')')
                        return false;
                    i+=2;
                break;
                case '[':
                    if(s[i+1]!=']')
                        return false;
                    i+=2;
                break;
                case '{':
                    if(s[i+1]!='}')
                        return false;
                    i+=2;
                break;
                default:
                    return false;
                break;
            }
            continue;
          
        }
        return true;
        
    }
};
