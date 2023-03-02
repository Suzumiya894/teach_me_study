#ifndef BASIC_CLASS_H
#define BASIC_CLASS_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"
using namespace std;

class  Question                      //题目信息类
{
    public:
        bool _is_content_picture;           //内容是否是图片
        bool _is_answer_picture;            //答案是否是图片
        int _question_id;                   //题目id
        int _question_type;                 //题型
        string _title;                      //题目简介
        float _level;                       //题目难度，浮点数
        int _evaluate_num;                  //评价过难度的人数
        int _likes;                         //点赞的人数
        string _content;                    //保存的地址
        string _answer;                     //保存的地址
        vector<string> _tag;                //题目标签
        string _subject;                    //学科
        int _unlock_times;                  //解锁次数
        int _pass_num;                      //通过审核的次数
        int _reject_num;                    //拒绝审核的次数
        int _upload_user_id;                //上传者id
        vector<int> _judge_pass_user;       //审核通过的user_id
        vector<int> _judge_reject_user;     //审核没通过的user_id
        string _reject_reason;              //拒绝通过的理由的文件地址
        string _upload_time;                //上传的时间
        int _price;                          //解锁题目所需要的积分
        Question();
        ~Question(){}
};


class Comment                           //评论类
{
    public:
        int _question_id;               //题目id
        int _user_id;                   //评论者的id
        string _user_name;              //评论者用户名
        int _comment_id;                //该评论的id
        string _comment;                //评论内容的地址
        string _time;                   //评论的时间
        int _likes;                     //点赞数
        Comment();
        Comment(int question_id, int user_id, string user_name, string comment);
        ~Comment(){};
};


class Database          //测试用，正式运行时删去
{
    private:
        Question que1, que2, que3, que4;
        Comment com1, com2, com3, com4;
    public:
        Database();
        void get_like_question_list(int userID, vector<int> &like_question_list);
        void get_evaluate_question_list(int userID, vector<int> &evaluate_question_list);
        void get_like_comment_list(int userID, vector<int> &like_comment_list);
        void insertNewUser(string name,string password);
        int searchUserName(string name);
        string getUserPassword(int userID);
        string getUserLastSignTime(int userID);
        void addUserPoints(int userID,int addNumber);
        int getUserPoints(int userID);
        void updateSignTime(int userID,string curTime);
        User getUserInfomation(int userID);
        void changeUserInfo(int userID,User u);
        int getQuestionNumbers(string subj,int Type);
        int* getTypeAllID(string subj,int question_type);
        void list(string _subject, int quesType, vector<Question> &_question_list); //返回该科目下的所有题目简介
        void write_likes_question(int _question_id);               //写入数据，和数据库相接，待完成    //修改推荐的人数
        void write_level(float level, int _question_id);    //写入难度
        void write_user_likes_question(int _userID, int _question_id);   //记录该用户点赞过的题目
        void write_user_evaluate_question(int _userID, int _question_id);   //记录该用户评价过的题目
        Question getQuestion(int questionID);       //从数据库中获得题目信息，最后可能放在数据库管理类下面
        void write_likes_comment(int _comment_id){}                         //只更改数据库中的点赞数
        void write_comment(Comment &_comment);                      //向数据库中写入评论
        void get_comment(int questionNo, vector<Comment> &_comment_list);       //从数据库获取评论列表
        void write_user_likes_comment(int _userID, int _question_id);   //记录该用户点赞过的评论
        int get_current_id(){return 10;}       //获取新建的题目id，数据库
        void write_question(Question &_question);   //向数据库写入题目
        Question get_judge_question(int question_id);      //获得待审题目中的下一道题，即id大于question_id的，成功审核次数小于3，失败次数小于2的题目
        void write_tag(string _tag, int _question_id){}     //向数据库写入标签
        void delete_tag(string _tag, int _question_id){}     //删除某一标签
        void write_reject(string reason, int _question_id, int user_id){}  //被拒绝的次数加一，拒绝的理由再加上reason, judge_reject_user增加当前用户id
        void write_success(int _question_id, int user_id){}     //审核通过次数加一，judge_pass_user增加当前用户id
};

#endif