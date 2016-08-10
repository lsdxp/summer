class Solution {
public:
    bool isValid(string s) {
        if(s.length()<2||s.length()%2!=0)
        {
            return false;
        }
        else if(s.length()==2)
        {
            switch(s[0])
        {
            case '(': if (s[1]!=')')
                return false;
            else
                return true;
                break;
            case '[': if (s[1]!=']')
                return false;
            else
                return true;
                break;
            case '{': if (s[1]!='}')
                return false;
            else
                return true;
            default:
                return false;
        }
        }
        else
        {   int j=0;//"[({(())}[()])]"
            int i=1;
            int sum=1;
            int sum2=1;
            while(i<(s.length()-1)&&j<(s.length()-1))
            { cout<<s[i]<<s[j]<<endl;
                if(s[i]==s[j])
                    sum++;
                switch(s[j])
                {
                    case '(':
                    if (s[i]!=')')
                        break;
                    else{
                        if(sum==1)
                        {if((i-j)!=1)
                        {if(isValid(s.substr(j+1,i-j-1)))
                        {    j=i+1;
                            i=j;
                            break;}
                        else
                            return false;}
                        else
                        {   j=i+1;
                            i=j;
                            break;
                        }
                        }
                        sum-=1;
                    }
                        break;
                    case '[':
                    if (s[i]!=']')
                        break;
                    else{
                        if(sum==1)
                        {if((i-j)!=1)
                        {if(isValid(s.substr(j+1,i-j-1)))
                        {    j=i+1;
                             i=j;
                            break;}
                        else
                            return false;}
                        else
                        {   j=i+1;
                            i=j;
                            break;
                        }
                        }
                        sum-=1;
                        }
                        break;
                    case '{':
                      if (s[i]!='}')
                          break;
                      else{
                          if(sum==1)
                          {if((i-j)!=1)
                          {if(isValid(s.substr(j+1,i-j-1)))
                          {    j=i+1;
                              i=j;
                              break;}
                          else
                              return false;}
                          else
                          {   j=i+1;
                              i=j;
                              break;

                          }
                          }
                          sum-=1;
                      }
                        break;
                    default:
                        return false;
                }
                i++;
            }
        if(sum!=1)
            return false;

        }
        return true;
        
    }
    
};
