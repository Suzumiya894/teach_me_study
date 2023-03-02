#ifndef JUDGE_H
#define JUDGE_H
#include "basic_class.h"
#include "user_manager.h"
using namespace std;

class Judge_Manage
{
    private:
        Database *DB;
    public:
        void write_tag(string _tag, int _question_id);    //向数据库写入标签
        void delete_tag(string _tag, int _question_id);    //删除某一标签
        void write_reject(string reason, int user_id, Question &_question);  //被拒绝的次数加一，拒绝的理由再加上reason, judge_reject_user增加当前用户id
        void write_success(int user_id, Question &_question);     //审核通过次数加一，judge_pass_user增加当前用户id
        Judge_Manage(Database &database):DB(&database){}
};

#endif