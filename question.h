#ifndef QUESTION_H
#define QUESTION_H

#include "basic_class.h"
using namespace std;
#include <algorithm>
#include "user_manager.h"


class Question_Manage               //做题管理类
{
    private:
        Database *DB;
        void write_unlocks(int _question_id){}                   //解锁数加一
    public:
        void list(string _subject, int quesType, vector<Question> &_question_list);//返回该科目下的所有题目简介
        Question_Manage(Database &database):DB(&database){}
};


class Information_Manage               //题目信息管理类
{
    private:
        Database *DB;
    public:
        Question getQuestion(int quesId);       //包装函数
        bool recommend(User &_user, Question &_infor);         //推荐该题目,推荐成功返回true
        bool evaluate(User &_user, Question &_infor, int level);   //评价这道题的难度，评价成功返回true
        Information_Manage(Database &database):DB(&database){}
};


class Comment_Manage                    //评论管理类   
{
    private:    
        Database *DB;
        bool time_HtL(Comment &com1, Comment &com2);                //按时间从近到远
        bool time_LtH(Comment &com1, Comment &com2);                //按时间从远到近
        bool likes_HtL(Comment &com1, Comment &com2);               //按点赞数从高到低
    public:
        void get_comment(int questionNo, vector<Comment> &_comment_list, int sortOrder);      //获取排序后的评论列表,前端用
        void create_comment(int questionNo, User &_user, string newComments);   //前端调用的新建评论函数
        bool like_comment(User &_user, Comment &_comment);          //点赞
        Comment_Manage(Database &database):DB(&database){}

};

#endif