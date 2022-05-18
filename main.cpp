#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Robot{
public:
    void Red_Blood_Init(char x, int k){
        if(x=='B'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 100);
        }
        else if(x=='S'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 200);
        }
        else if(x=='Y'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 200);
        }
        else if(x=='G'){
            Red_Blood.erase(Red_Blood.begin() + k);
            Red_Blood.insert(Red_Blood.begin() + k, 200);
        }
    }
    void Red_Heat17_Init(char x, int k){
        if(x=='B'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 200);
        }
            //Red_Heat17.push_back(200);
        else if(x=='S'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 300);
        }
            //Red_Heat17.push_back(300);
        else if(x=='Y'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 0);
        }
            //Red_Heat17.push_back(0);
        else if(x=='G'){
            Red_Heat17.erase(Red_Heat17.begin() + k);
            Red_Heat17.insert(Red_Heat17.begin() + k, 0);
        }
            //Red_Heat17.push_back(0);
    }

    void Red_Heat42_Init(char x, int k){
        if(x=='B'){
            Red_Heat42.erase(Red_Heat42.begin() + k);
            Red_Heat42.insert(Red_Heat42.begin() + k, 0);
        }
            //Red_Heat42.push_back(0);
        else if(x=='S'){
            Red_Heat42.erase(Red_Heat42.begin() + k);
            Red_Heat42.insert(Red_Heat42.begin() + k, 0);
        }
            //Red_Heat42.push_back(0);
        else if(x=='Y'){
            Red_Heat42.erase(Red_Heat42.begin() + k);
            Red_Heat42.insert(Red_Heat42.begin() + k, 300);
        }
            //Red_Heat42.push_back(300);
        else if(x=='G'){
            Red_Heat42.erase(Red_Heat42.begin() + k);
            Red_Heat42.insert(Red_Heat42.begin() + k, 0);
        }
            //Red_Heat42.push_back(0);
    }
    void Blue_Blood_Init(char x, int k){
        if(x=='B'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 100);
        }
            //Blue_Blood.push_back(100);
        else if(x=='S'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 200);
        }
            //Blue_Blood.push_back(200);
        else if(x=='Y'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 200);
        }
            //Blue_Blood.push_back(200);
        else if(x=='G'){
            Blue_Blood.erase(Blue_Blood.begin() + k);
            Blue_Blood.insert(Blue_Blood.begin() + k, 200);
        }
            //Blue_Blood.push_back(200);
    }
    void Blue_Heat17_Init(char x, int k){
        if(x=='B'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 200);
        }
            //Blue_Heat17.push_back(200);
        else if(x=='S'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 300);
        }
            //Blue_Heat17.push_back(300);
        else if(x=='Y'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 0);
        }
            //Blue_Heat17.push_back(0);
        else if(x=='G'){
            Blue_Heat17.erase(Blue_Heat17.begin() + k);
            Blue_Heat17.insert(Blue_Heat17.begin() + k, 0);
        }
            //Blue_Heat17.push_back(0);
    }

    void Blue_Heat42_Init(char x, int k){
        if(x=='B'){
            Blue_Heat42.erase(Blue_Heat42.begin() + k);
            Blue_Heat42.insert(Blue_Heat42.begin() + k, 0);
        }
            //Blue_Heat42.push_back(0);
        else if(x=='S'){
            Blue_Heat42.erase(Blue_Heat42.begin() + k);
            Blue_Heat42.insert(Blue_Heat42.begin() + k, 0);
        }
            //Blue_Heat42.push_back(0);
        else if(x=='Y'){
            Blue_Heat42.erase(Blue_Heat42.begin() + k);
            Blue_Heat42.insert(Blue_Heat42.begin() + k, 300);
        }
            //Blue_Heat42.push_back(300);
        else if(x=='G'){
            Blue_Heat42.erase(Blue_Heat42.begin() + k);
            Blue_Heat42.insert(Blue_Heat42.begin() + k, 0);
        }
            //Blue_Heat42.push_back(0);
    }
    int Check_Red_Number() const{
        int number_r;
        number_r=Red_Blood.size();
        return number_r;
    }
    int Check_Blue_Number() const{
        int number_b;
        number_b=Blue_Blood.size();
        return number_b;
    }
    vector<int>Red_Blood=vector<int>(99);
    vector<int>Red_Heat17=vector<int>(99);
    vector<int>Red_Heat42=vector<int>(99);
    vector<int>Blue_Blood=vector<int>(99);
    vector<int>Blue_Heat17=vector<int>(99);
    vector<int>Blue_Heat42=vector<int>(99);
};

int main() {
    char cmd[20];
    vector<char> Red_Robot(99);
    vector<char> Blue_Robot(99);
    Robot iRobot;
    int Flag = 0;
    char Team_Number, Robot_Number;
    int Number;
    while (Flag != 1) {
        cin.getline(cmd, 20);
        if (cmd[0] != 'E') {
            if (cmd[0] == 'A') {                           //ÃüÁî×ÖÅÐ¶Ï
                Team_Number = cmd[2];
                Robot_Number = cmd[4];
                Number = atoi(&cmd[6]);
                if (Team_Number == 'R') {
                    Red_Robot.erase(Red_Robot.begin() + Number);
                    Red_Robot.insert(Red_Robot.begin() + Number, Robot_Number);
                    //Red_Robot.push_back(Robot_Number);
                    iRobot.Red_Blood_Init(Robot_Number, Number);
                    iRobot.Red_Heat17_Init(Robot_Number, Number);
                    iRobot.Red_Heat42_Init(Robot_Number, Number);
                } else if (Team_Number == 'B') {
                    Blue_Robot.erase(Blue_Robot.begin() + Number);
                    Blue_Robot.insert(Blue_Robot.begin() + Number, Robot_Number);
                    //Blue_Robot.push_back(Robot_Number);
                    iRobot.Blue_Blood_Init(Robot_Number, Number);
                    iRobot.Blue_Heat17_Init(Robot_Number, Number);
                    iRobot.Blue_Heat42_Init(Robot_Number, Number);
                }
            }
        }else {
            Flag = 1;
        }
    }
    cout<<"Team : Red"<<endl;
    for (int tmp = 0; tmp < iRobot.Check_Red_Number(); tmp++){
        if(iRobot.Red_Blood[tmp]!=0)
        cout << "Robot Type:" << Red_Robot[tmp] << "   Blood:" << iRobot.Red_Blood[tmp] << "  17mm:" << iRobot.Red_Heat17[tmp] << "  42mm:" << iRobot.Red_Heat42[tmp] << endl;
    }
    cout<<"Team : Blue"<<endl;
    for (int tmp = 0; tmp < iRobot.Check_Blue_Number(); tmp++){
        if(iRobot.Blue_Blood[tmp]!=0)
        cout << "Robot Type:" << Blue_Robot[tmp] << "  Blood:" << iRobot.Blue_Blood[tmp] << "  17mm:" << iRobot.Blue_Heat17[tmp] << "  42mm:" << iRobot.Blue_Heat42[tmp] << endl;
    }

    return 0;

}
