#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Robot{
public:
    void Red_Blood_Init(char x,long long int k){
        if(x=='B'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 100);
        }else if(x=='S'||x=='Y'||x=='G'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 200);
        }
    }
    void Red_Heat17_Init(char x,long long int k){
        if(x=='B'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 200);
        }else if(x=='S'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 300);
        }
    }
    void Red_Heat42_Init(char x,long long int k){
        if(x=='Y'){
            Red_Heat42.erase(Red_Heat42.begin() + k);
            Red_Heat42.insert(Red_Heat42.begin() + k, 300);
        }
    }
    void Blue_Blood_Init(char x,long long int k){
        if(x=='B'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 100);
        }else if(x=='S'||x=='Y'||x=='G'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 200);
        }
    }
    void Blue_Heat17_Init(char x,long long int k){
        if(x=='B'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 200);
        }else if(x=='S'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 300);
        }
    }

    void Blue_Heat42_Init(char x,long long int k){
        if(x=='Y'){
            Blue_Heat42.erase(Blue_Heat42.begin() + k);
            Blue_Heat42.insert(Blue_Heat42.begin() + k, 300);
        }
    }
    long long int Check_Red_Number() const{
        long long int number_r;
        number_r=Red_Blood.size();
        return number_r;
    }
    long long int Check_Blue_Number() const{
        long long int number_b;
        number_b=Blue_Blood.size();
        return number_b;
    }
    vector<long long int>Red_Blood=vector<long long int>(999999);
    vector<long long int>Red_Heat17=vector<long long int>(999999);
    vector<long long int>Red_Heat42=vector<long long int>(999999);
    vector<long long int>Blue_Blood=vector<long long int>(999999);
    vector<long long int>Blue_Heat17=vector<long long int>(999999);
    vector<long long int>Blue_Heat42=vector<long long int>(999999);
};
int Extra;
void weishu(long long int n){
    int i=0;
    while (n!=0){
        n=n/10;
        i++;
    }
    Extra = i-1;
}
int main() {
    char cmd[20];
    vector<char> Red_Robot(999999);
    vector<char> Blue_Robot(999999);
    Robot iRobot;
    int Flag = 0;
    char Team_Number, Robot_Number;
    int Damage, Bullet;
    long long int Number;
    long long int RH17,RH42;
    long long int BH17,BH42;
    while (Flag != 1) {
        cin.getline(cmd, 20);
        if (cmd[0] != 'E'&&cmd[0] !=  'e') {
            if (cmd[0] == 'A') {
                Team_Number = cmd[2];
                Robot_Number = cmd[4];
                Number = atoi(&cmd[6]);
                if (Team_Number == 'R') {
                    Red_Robot.erase(Red_Robot.begin() + Number);
                    Red_Robot.insert(Red_Robot.begin() + Number, Robot_Number);
                    iRobot.Red_Blood_Init(Robot_Number, Number);
                    iRobot.Red_Heat17_Init(Robot_Number, Number);
                    iRobot.Red_Heat42_Init(Robot_Number, Number);
                } else if (Team_Number == 'B') {
                    Blue_Robot.erase(Blue_Robot.begin() + Number);
                    Blue_Robot.insert(Blue_Robot.begin() + Number, Robot_Number);
                    iRobot.Blue_Blood_Init(Robot_Number, Number);
                    iRobot.Blue_Heat17_Init(Robot_Number, Number);
                    iRobot.Blue_Heat42_Init(Robot_Number, Number);
                }
            }
            if (cmd[0] == 'F') {
                Team_Number = cmd[2];
                Number = atoi(&cmd[4]);
                weishu(Number);
                Damage = atoi(&cmd[6 + Extra]);
                long long int tmp_Blood;
                if (Team_Number == 'R') {
                    tmp_Blood = iRobot.Red_Blood[Number] - Damage;
                    if (tmp_Blood <= 0) {
                        iRobot.Red_Blood.erase(iRobot.Red_Blood.begin() + Number);
                        iRobot.Red_Blood.insert(iRobot.Red_Blood.begin() + Number, -1);
                        iRobot.Red_Heat17.erase(iRobot.Red_Heat17.begin() + Number);
                        iRobot.Red_Heat17.insert(iRobot.Red_Heat17.begin() + Number, 0);
                        iRobot.Red_Heat42.erase(iRobot.Red_Heat42.begin() + Number);
                        iRobot.Red_Heat42.insert(iRobot.Red_Heat42.begin() + Number, 0);
                    }else{
                        iRobot.Red_Blood.erase(iRobot.Red_Blood.begin() + Number);
                        iRobot.Red_Blood.insert(iRobot.Red_Blood.begin() + Number, tmp_Blood);
                    }
                }
                if (Team_Number == 'B') {
                    tmp_Blood = iRobot.Blue_Blood[Number] - Damage;
                    if (tmp_Blood <= 0) {
                        iRobot.Blue_Blood.erase(iRobot.Blue_Blood.begin() + Number);
                        iRobot.Blue_Blood.insert(iRobot.Blue_Blood.begin() + Number, -1);
                        iRobot.Blue_Heat17.erase(iRobot.Blue_Heat17.begin() + Number);
                        iRobot.Blue_Heat17.insert(iRobot.Blue_Heat17.begin() + Number, 0);
                        iRobot.Blue_Heat42.erase(iRobot.Blue_Heat42.begin() + Number);
                        iRobot.Blue_Heat42.insert(iRobot.Blue_Heat42.begin() + Number, 0);
                    }else{
                        iRobot.Blue_Blood.erase(iRobot.Blue_Blood.begin() + Number);
                        iRobot.Blue_Blood.insert(iRobot.Blue_Blood.begin() + Number, tmp_Blood);
                    }
                }
            }
            if (cmd[0] == 'H') {
                Team_Number = cmd[2];
                Number = atoi(&cmd[4]);
                weishu(Number);
                Bullet = atoi(&cmd[6 + Extra]);
                long long int tmp_Heat, tmp_Type;
                if (Team_Number == 'R') {
                    tmp_Type = Red_Robot[Number];
                    if (tmp_Type == 'B' || tmp_Type == 'S') {
                        tmp_Heat = iRobot.Red_Heat17[Number] - (Bullet * 15);
                        if (tmp_Heat <= 0) {
                            iRobot.Red_Blood.erase(iRobot.Red_Blood.begin() + Number);
                            iRobot.Red_Blood.insert(iRobot.Red_Blood.begin() + Number, 0);
                            iRobot.Red_Heat17.erase(iRobot.Red_Heat17.begin() + Number);
                            iRobot.Red_Heat17.insert(iRobot.Red_Heat17.begin() + Number, -1);
                            iRobot.Red_Heat42.erase(iRobot.Red_Heat42.begin() + Number);
                            iRobot.Red_Heat42.insert(iRobot.Red_Heat42.begin() + Number, 0);
                        }else{
                            iRobot.Red_Heat17.erase(iRobot.Red_Heat17.begin() + Number);
                            iRobot.Red_Heat17.insert(iRobot.Red_Heat17.begin() + Number, tmp_Heat);
                        }
                    }
                    if (tmp_Type == 'Y') {
                        tmp_Heat = iRobot.Red_Heat42[Number] - (Bullet * 30);
                        if (tmp_Heat <= 0) {
                            iRobot.Red_Blood.erase(iRobot.Red_Blood.begin() + Number);
                            iRobot.Red_Blood.insert(iRobot.Red_Blood.begin() + Number, 0);
                            iRobot.Red_Heat17.erase(iRobot.Red_Heat17.begin() + Number);
                            iRobot.Red_Heat17.insert(iRobot.Red_Heat17.begin() + Number, 0);
                            iRobot.Red_Heat42.erase(iRobot.Red_Heat42.begin() + Number);
                            iRobot.Red_Heat42.insert(iRobot.Red_Heat42.begin() + Number, -1);
                        }else{
                            iRobot.Red_Heat42.erase(iRobot.Red_Heat42.begin() + Number);
                            iRobot.Red_Heat42.insert(iRobot.Red_Heat42.begin() + Number, tmp_Heat);
                        }
                    }
                }
                if (Team_Number == 'B') {
                    tmp_Type = Blue_Robot[Number];
                    if (tmp_Type == 'B' || tmp_Type == 'S') {
                        tmp_Heat = iRobot.Blue_Heat17[Number] - (Bullet * 15);
                        if (tmp_Heat <= 0) {
                            iRobot.Blue_Blood.erase(iRobot.Blue_Blood.begin() + Number);
                            iRobot.Blue_Blood.insert(iRobot.Blue_Blood.begin() + Number, 0);
                            iRobot.Blue_Heat17.erase(iRobot.Blue_Heat17.begin() + Number);
                            iRobot.Blue_Heat17.insert(iRobot.Blue_Heat17.begin() + Number, -1);
                            iRobot.Blue_Heat42.erase(iRobot.Blue_Heat42.begin() + Number);
                            iRobot.Blue_Heat42.insert(iRobot.Blue_Heat42.begin() + Number, 0);
                        }else{
                            iRobot.Blue_Heat17.erase(iRobot.Blue_Heat17.begin() + Number);
                            iRobot.Blue_Heat17.insert(iRobot.Blue_Heat17.begin() + Number, tmp_Heat);
                        }
                    }
                    if (tmp_Type == 'Y') {
                        tmp_Heat = iRobot.Red_Heat42[Number] - (Bullet * 30);
                        if (tmp_Heat <= 0) {
                            iRobot.Blue_Blood.erase(iRobot.Blue_Blood.begin() + Number);
                            iRobot.Blue_Blood.insert(iRobot.Blue_Blood.begin() + Number, 0);
                            iRobot.Blue_Heat17.erase(iRobot.Blue_Heat17.begin() + Number);
                            iRobot.Blue_Heat17.insert(iRobot.Blue_Heat17.begin() + Number, 0);
                            iRobot.Blue_Heat42.erase(iRobot.Blue_Heat42.begin() + Number);
                            iRobot.Blue_Heat42.insert(iRobot.Blue_Heat42.begin() + Number, -1);
                        }else{
                            iRobot.Blue_Heat42.erase(iRobot.Blue_Heat42.begin() + Number);
                            iRobot.Blue_Heat42.insert(iRobot.Blue_Heat42.begin() + Number, tmp_Heat);
                        }
                    }
                }
            }
        } else Flag = 1;
    }
    cout << "Team : Red" << endl;
    for (long long int tmp = 0; tmp < iRobot.Check_Red_Number(); tmp++) {
        if (iRobot.Red_Blood[tmp]==-1){
            RH17=0;
            RH42=0;
            cout << "Number: " << tmp << " Robot Type:" << Red_Robot[tmp] << "   Blood:" << iRobot.Red_Blood[tmp] << "  17mm:"
                 << RH17 << "  42mm:" << RH42 << endl;
        }
        if (iRobot.Red_Heat17[tmp] != 0 || iRobot.Red_Heat42[tmp] != 0) {
            if(Red_Robot[tmp]=='B') {
                RH17 = 200 - iRobot.Red_Heat17[tmp];
                if (RH17 > 200) RH17 = -1;
                RH42=0;
            }else if(Red_Robot[tmp]=='S') {
                RH17 = 300 - iRobot.Red_Heat17[tmp];
                if (RH17 > 300) RH17 = -1;
                RH42=0;
            }else if(Red_Robot[tmp]=='Y') {
                RH42 = 300 - iRobot.Red_Heat42[tmp];
                if (RH42 > 300) RH42 = -1;
                RH17 = 0;
            }else if(Red_Robot[tmp]=='G'){
                RH17=0;
                RH42=0;
            }
            cout << "Number: " << tmp << " Robot Type:" << Red_Robot[tmp] << "   Blood:" << iRobot.Red_Blood[tmp] << "  17mm:"
                 << RH17 << "  42mm:" << RH42 << endl;
        }
    }
    cout << "Team : Blue" << endl;
    for (long long int tmp = 0; tmp < iRobot.Check_Blue_Number(); tmp++) {
        if(iRobot.Blue_Blood[tmp]==-1){
           BH17=0;
           BH42=0;
            cout << "Number: "<< tmp << " Robot Type:" << Blue_Robot[tmp] << "  Blood:" << iRobot.Blue_Blood[tmp] << "  17mm:"
                 << BH17 << "  42mm:" << BH42 << endl;
        }
        if(iRobot.Blue_Heat17[tmp] != 0 || iRobot.Blue_Heat42[tmp] != 0) {
            if(Blue_Robot[tmp]=='B') {
                BH17 = 200 - iRobot.Blue_Heat17[tmp];
                if (BH17 > 200) BH17 = -1;
                BH42=0;
            }else if(Blue_Robot[tmp]=='S') {
                BH17 = 300 - iRobot.Blue_Heat17[tmp];
                if (BH17 > 300) BH17 = -1;
                BH42=0;
            }else if(Blue_Robot[tmp]=='Y') {
                BH42 = 300 - iRobot.Blue_Heat42[tmp];
                if (BH42 > 300) BH42 = -1;
                BH17 = 0;
            }else if(Blue_Robot[tmp]=='G'){
                BH17=0;
                BH42=0;
            }
            cout << "Number: "<< tmp << " Robot Type:" << Blue_Robot[tmp] << "  Blood:" << iRobot.Blue_Blood[tmp] << "  17mm:"
                 << BH17 << "  42mm:" << BH42 << endl;
        }
    }
    return 0;
}