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
    char type;
public:
    Robot(int r_num, char r_team){
        team=r_team;
        if(r_team=='R'){
            red_num=r_num;
            type=red_map[r_num];
        }else if(r_team=='B'){
            blue_num=r_num;
            type=blue_map[r_num];
        }
        if(type=='B'){
            blood=100;
            heat=0;
            return;
        }else if(type=='S'||type=='Y'||type=='G'){
            blood=200;
            heat=0;
            return;
        }
//        void show(){
//            cout<< "Number: " << num <<"Type: "
//        }
    };
    char team;
    void damage(int injury);
    void overheat(int bullet);

    int red_num;
    int blue_num;
};
void Robot::overheat(int bullet){
    if(type=='B'||type=='S'){
        heat=heat+15*bullet;
        if(type=='B' && heat>=200){
            blood=0;
            heat=0;
        }else if(type=='S' && heat>=300){
            blood=0;
            heat=0;
        }
    }else if(type=='Y'){
        heat=heat+30*bullet;
        if(heat>=300){
            blood=0;
            heat=0;
        }
    }else return;
}
void Robot::damage(int injury){
    blood=blood-injury;
    if(blood<=0){
        blood=0;
        heat=0;
    }
}
int main(){
    char tmp_team,tmp_type;
    int tmp_num,tmp_injury,tmp_bullet;
    int flag=0;
    char cmd[4]="000";
    vector<Robot> rvec;
    while(flag==0){
        cin>>cmd;
        if(cmd[0]=='A'){
            cin>>tmp_team;
            cin>>tmp_type;
            cin>>tmp_num;
            if(tmp_team=='R'){
                red_map.insert(pair<int,char>(tmp_num,tmp_type));
            } else if(tmp_team=='B'){
                blue_map.insert(pair<int,char>(tmp_num,tmp_type));
            }
            rvec.emplace_back(tmp_num,tmp_team);
        }
        if(cmd[0]=='F'){
            cin>>tmp_team;
            cin>>tmp_num;
            cin>>tmp_injury;
            for(auto & r_t : rvec){
                if(r_t.Robot::team == tmp_team){
                    if(tmp_team=='R'){
                        if(r_t.Robot::red_num == tmp_num){
                            r_t.damage(tmp_injury);
                            break;
                        }
                    }else if(tmp_team=='B'){
                        if(r_t.Robot::blue_num == tmp_num){
                            r_t.damage(tmp_injury);
                            break;
                        }
                    }
                }
            }
        }
        if(cmd[0]=='H'){
            cin>>tmp_team;
            cin>>tmp_num;
            cin>>tmp_bullet;

            for(auto r_t = rvec.begin(); r_t != rvec.end(); r_t++){
                if(r_t->num == tmp_num){
                    if(r_t->team == tmp_team){
                        (*r_t).overheat(tmp_bullet);
                        break;
                    }
                }
            }
        }
        if(cmd[0]=='E'){
            cout<<"Red team:"<<endl;
            for(auto & r_t : rvec){
                if(r_t.team == 'R') show();
            }
            flag=1;
        }
    }

}