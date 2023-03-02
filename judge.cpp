#include "judge.h"

void Judge_Manage::write_tag(string _tag, int _question_id)
{
    DB->write_tag(_tag, _question_id);
    return;
}

void Judge_Manage::delete_tag(string _tag, int _question_id)
{
    DB->delete_tag(_tag, _question_id);
    return;
}

void Judge_Manage::write_reject(string reason, int user_id, Question &_question)
{
    ++_question._reject_num;
    DB->write_reject(reason, _question._question_id, user_id);
    if(_question._reject_num >= 2)      //�ۼ�����δͨ�����
        {
            for(int i = 0; i < 2; ++i)
                DB->addUserPoints(_question._judge_reject_user[i], 10);      
            cout << "��Ŀδ��ͨ����ˣ���û��֡�" << endl;
        }
    _question = DB->get_judge_question(_question._question_id);      //�����һ����
    return ;
}

void Judge_Manage::write_success(int user_id, Question &_question)
{
    ++_question._pass_num;
    DB->write_success(_question._question_id, user_id);
    if(_question._pass_num >= 3)            //�ۼ�ͨ��3�����
        {
            DB->addUserPoints(_question._upload_user_id, 20);
            for(int i = 0; i < 3; ++i)
                DB->addUserPoints(_question._judge_pass_user[i], 10);     
            cout << "��Ŀͨ����ˣ���û��֡�" << endl;
        }
    _question = DB->get_judge_question(_question._question_id);      //�����һ����
    return ;
}