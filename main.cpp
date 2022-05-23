#include<iostream>
#include<vector>
#include <map>

using namespace std;
int flag=0;

map<int,char> red_map;
map<int,char> blue_map;

class Robot{
private:
    int blood;
    int heat;
    char type;
public:
    char team;
    int num;
    Robot(int robot_num, char robot_team){
        team=robot_team;
        num=robot_num;
        if(robot_team == 'R') type=red_map[robot_num];
        else if(robot_team == 'B') type=blue_map[robot_num];
        if(type=='B'){
            blood=100;
            heat=0;
            return;
        }else if(type=='S'||type=='Y'||type=='G'){
            blood=200;
            heat=0;
            return;
        }
    };
    void show();
    void damage(int injury);
    void overheat(int bullet);
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
vector<Robot> vector_robot;
void Robot::show(){
    cout<<"Type: "<<type<<" Number: "<<num<<" Blood: "<<blood<<" Heat: "<<heat<<endl;
}
void error(){
    cout<<"The input is not standardized!"<<endl;
    flag=1;
}
int test(int test_team,int test_num){
        int test = 0;
        for(auto & p : vector_robot){
            if(p.Robot::team == test_team){
                if(p.Robot::num == test_num){
                    test++;
                }
            }
        }
    return test;
}
int main(){
    char tmp_team,tmp_type;
    int tmp_num,tmp_injury,tmp_bullet;
    char cmd[4]="000";
    while(flag==0){
        cin>>cmd;
        if(cmd[0]!='A'&&cmd[0]!='F'&&cmd[0]!='H'&&cmd[0]!='E') error();
        else if(cmd[0]=='A'){
            cin>>tmp_team;
            cin>>tmp_type;
            cin>>tmp_num;
            if((tmp_team!='R'&&tmp_team!='B')||(tmp_type!='B'&&tmp_type!='S'&&tmp_type!='Y'&&tmp_type!='G')||tmp_num<=0||cin.fail()) error();
            if(tmp_team=='R'){
                red_map.insert(pair<int,char>(tmp_num,tmp_type));
            } else if(tmp_team=='B'){
                blue_map.insert(pair<int,char>(tmp_num,tmp_type));
            }
            vector_robot.emplace_back(tmp_num, tmp_team);
        }else if(cmd[0]=='F'){
            cin>>tmp_team;
            cin>>tmp_num;
            cin>>tmp_injury;
            if((tmp_team!='R'&&tmp_team!='B') || test(tmp_team,tmp_num)==0 || cin.fail()) error();
            for(auto & p : vector_robot){
                if(p.Robot::team == tmp_team){
                    if(p.Robot::num == tmp_num){
                        p.damage(tmp_injury);
                        break;
                    }
                }
            }
        }else if(cmd[0]=='H'){
            cin>>tmp_team;
            cin>>tmp_num;
            cin>>tmp_bullet;
            if((tmp_team!='R'&&tmp_team!='B') || test(tmp_team,tmp_num)==0 || cin.fail()) error();
            for(auto & p : vector_robot){
                if(p.Robot::num == tmp_num){
                    if(p.Robot::team == tmp_team){
                        p.overheat(tmp_bullet);
                        break;
                    }
                }
            }
        }else if(cmd[0]=='E'){
            cout<<"Red team:"<<endl;
            for(auto & p :vector_robot){
                if(p.Robot::team == 'R') p.show();
            }
            cout<<"Blue team:"<<endl;
            for(auto & p :vector_robot){
                if(p.Robot::team == 'B') p.show();
            }
            flag=1;
        }
    }
}