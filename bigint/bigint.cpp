
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using namespace std;

struct Bgint{
      static int BASE=10000000;
      static int WID=8;
      vector<int> s;
      Bgint (int num){*this=num;}
      Bgint operator=(long long num)
      {
          s.clear();
          do{
                s.push_back(num%BASE);
                num/=BASE;

          }while(num>0);
          return *this;
      }
      Bgint operator=(string str)
      {
            s.clear();
            int x,len=(str.length()-1)/WID+1;
            for(int i=0;i<len;i++)
            {
                int end=str.length()-i*WID;
                int start=max(0,end-WID);
                sscanf(str.substr(start,end-start).c_str(),"%d",&x);
                s.push_back(x);
            }
            return *this;
      }
      friend ostream& operator<<(ostream &out,const Bgint& x)
      {
          out<<x.s.back();
          for(int i=x.s.size()-2;i>=0;i--)
          {
              char buf[20];
              sprintf(buf,"%08d",x.s[i]);
              for(int j=0;j<strlen(buf);j++)out<<buf[j];
          }
      }
      friend istream& operator>>(istream &in,Bgint& x)
      {
            string a;
            if(!(in>>a))return in;
            x=a;
            return in;
      }
};


int main()
{
    Bgint b;
    b=100000000000;
    cout<<b;
    return 0;
}