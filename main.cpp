#include<iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;

map<int,char> red_map;
map<int,char> blue_map;

class Robot{
private:
    int blood;
    int heat;
public:
    char tmp_type;
    char tmp_team;
    int tmp_num;
    Robot(int r_num,char r_team,char r_type){
        tmp_type=r_type;
        tmp_team=r_team;
        tmp_num=r_num;

    }
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