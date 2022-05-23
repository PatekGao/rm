#include<iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;

map<int,char> red_map;
map<int,char> blue_map;
enum Types{
    Bubing,Shaobing,Yingxiong,Gongcheng
};
enum Teams{
    red,blue
};
class Robot{
private:
    int blood;
    int heat;
public:

};

int main(){
    char team,type;
    int num;
    char cmd[4]="000";
    while(1){
        cin>>cmd;
        if(cmd[0]=='A'){
            cin>>team;
            cin>>type;
            cin>>num;
            if(team=='R'){
                red_map.insert(pair<int,char>(num,type));
            } else if(team=='B'){
                blue_map.insert(pair<int,char>(num,type));
            }
        }
    }

}