#include "basic_class.h"
#include <time.h>

Comment::Comment()
{
    _question_id = 0;
    _user_id =  0;
    _user_name = "";
    _comment_id = 0;
    _comment = "";
    time_t comment_time;
    time(&comment_time);
    _time = ctime(&comment_time);
    _likes = 0;
}

Comment::Comment(int question_id, int user_id, string user_name, string comment):_question_id(question_id),
 _user_id(user_id), _user_name(move(user_name)), _comment(move(comment)), _likes(0)
{
    time_t comment_time;
    time(&comment_time);
    _time = ctime(&comment_time);
}

Question::Question()
{
    _is_content_picture = false;           //内容是否是图片
    _is_answer_picture = false;            //答案是否是图片
    _question_id = 0;                   //题目id
    _question_type = 0;                 //题型
    _title = "";                      //题目简介
    _level = 0.0;                       //题目难度，浮点数
    _evaluate_num = 0;                  //评价过难度的人数
    _likes = 0;                         //点赞的人数
    _content = "";                    //保存的地址
    _answer = "";                     //保存的地址
    _subject = "";                    //学科
    _unlock_times = 0;                  //解锁次数
    _pass_num = 0;                      //通过审核的次数
    _reject_num = 0;                    //拒绝审核的次数
    _upload_user_id = 0;                //上传者id
    _reject_reason = "";              //拒绝通过的理由的文件地址
    time_t tmp;
    time(&tmp);
    _upload_time = ctime(&tmp);                //上传的时间
    _price = 5;                          //解锁题目所需要的积分
}

//以下皆为测试用，实际运行时删去

Database::Database()
{
    que1._question_id = 1;
    que1._title = "第一题题目";
    que1._content = "第一题内容";
    que1._subject = "高数";
    que1._unlock_times = 5;
    que1._upload_user_id = 1;

    que2._question_id = 2;
    que2._title = "第二题题目";
    que2._content = "第二题内容";
    que2._subject = "高数";
    que2._unlock_times = 11;
    que2._upload_user_id = 1;

    que3._question_id = 3;
    que3._title = "第三题题目";
    que3._content = "第三题内容";
    que3._subject = "高数";
    que3._unlock_times = 20;
    que3._upload_user_id = 2;

    que4._question_id = 4;
    que4._title = "第四题题目";
    que4._content = "第四题内容";
    que4._subject = "高数";
    que4._unlock_times = 1;
    que4._upload_user_id = 3;

    com1._question_id = 1;
    com1._user_name = "张三";
    com1._comment = "还可以";
    com1._likes = 3;

    com2._question_id = 1;
    com2._user_name = "李四";
    com2._comment = "不错";
    com2._likes = 2;

    com3._question_id = 1;
    com3._user_name = "王五";
    com3._comment = "ez";
    com3._likes = 3;

    com4._question_id = 1;
    com4._user_name = "赵柳";
    com4._comment = "好";
    com4._likes = 4;
}

void Database::get_like_question_list(int userID, vector<int> &like_question_list)
{
    like_question_list.emplace_back(1);
    return;
}

void Database::get_evaluate_question_list(int userID, vector<int> &evaluate_question_list)
{
    evaluate_question_list.emplace_back(1);
    return;
}

void Database::get_like_comment_list(int userID, vector<int> &like_comment_list)
{
    like_comment_list.emplace_back(1);
    return;
}

void Database::list(string _subject, int quesType, vector<Question> &_question_list)
{
    _question_list.emplace_back(que1);
    _question_list.emplace_back(que2);
    _question_list.emplace_back(que3);
    _question_list.emplace_back(que4);
    return ;
}

Question Database::getQuestion(int questionID)
{
    return que1;
}

void Database::get_comment(int questionNo, vector<Comment> &_comment_list)
{
    _comment_list.emplace_back(com1);
    _comment_list.emplace_back(com2);
    _comment_list.emplace_back(com3);
    _comment_list.emplace_back(com4);
    return ;
}

Question Database::get_judge_question(int question_id)
{
    if(!question_id)
        return que1;
    else return que2;
}

void Database::insertNewUser(string name,string password){
    cout<<"insert success"<<endl;
}

int Database::searchUserName(string n){
    int id;
    cout<<"id is"<<endl;
    cin>>id;
    return id;
}

string Database::getUserPassword(int userID){
    string new_password_input;
    cout<<"right Password"<<endl;
    cin>>new_password_input;
    return new_password_input;
}

string Database::getUserLastSignTime(int userID){
    cout<<"input last sign in time"<<endl;
    string lastSignTime;
    cin>>lastSignTime;
    return lastSignTime;
}

void Database::addUserPoints(int userID,int addNumber){
    cout<<"add "<<addNumber<<" points"<<endl;
}

void Database::updateSignTime(int userID,string curTime){
    cout<<"update sign in time success"<<endl;
}

User Database::getUserInfomation(int userID){
    User database_info;
        database_info.name="name";
        database_info.password="password";
        database_info.grade=1;
        database_info.college="2";
        database_info.tel="3";
        database_info.email="4";
        database_info.points=5;
    return database_info;
}

void Database::changeUserInfo(int userID,User u){

}

int Database::getQuestionNumbers(string subj,int Type){
    cout<<"the number of the type"<<endl;
    int num;
    cin>>num;
    return num;
}

int* Database::getTypeAllID(string subj,int Type){
    int num=getQuestionNumbers(subj,Type);
    int* IDlist=new int[num];
    for(int i=0;i<num;++i){
        IDlist[i]=i;
    }
    return IDlist;
}

