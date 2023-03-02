#include "question.h"
#include <fstream>
#include <time.h>


void Question_Manage::list(string _subject, int quesType, vector<Question> &_question_list)
{
    DB->list(_subject, quesType, _question_list);
    return;
}

Question Information_Manage::getQuestion(int quesId)
{
    return DB->getQuestion(quesId);
}

bool Information_Manage::recommend(User &_user, Question &_infor)
{
    User_manager UM(_user);
    if(!UM.check_like_question(_infor._question_id))
    {
        ++_infor._likes ;          
        DB->write_likes_question(_infor._question_id);
        DB->write_user_likes_question(_user.userID, _infor._question_id);
        return true;
    }
    return false;
}

bool Information_Manage::evaluate(User &_user, Question &_infor, int level)
{
    User_manager UM(_user);
    if(!UM.check_evaluate_question(_infor._question_id))
    {
        _infor._level = ( _infor._level * _infor._evaluate_num + level ) / ++_infor._evaluate_num;
        DB->write_level(_infor._level, _infor._question_id);
        DB->write_user_evaluate_question(_user.userID, _infor._question_id);
        return true;
    }
    return false;
}

void Comment_Manage::create_comment(int questionNo, User &_user, string newComments)
{
    Comment new_comment(questionNo, _user.userID, _user.name, newComments);
    DB->write_comment(new_comment);
    return; 

}

bool Comment_Manage::like_comment(User &_user, Comment &_comment)
{
    User_manager UM(_user);
    if( !UM.check_like_comment(_comment._comment_id) )
    {
        ++_comment._likes;
        DB->write_likes_comment(_comment._comment_id);
        DB->write_user_likes_comment(_user.userID, _comment._comment_id);
        return true;
    }
    return false;
}

bool Comment_Manage::time_HtL(Comment &com1, Comment &com2)
{
    return com1._time > com2._time;
}

bool Comment_Manage::time_LtH(Comment &com1, Comment &com2)
{
    return com1._time < com2._time;
}

bool Comment_Manage::likes_HtL(Comment &com1, Comment &com2)
{
    return com1._likes > com2._likes;
}

void Comment_Manage::get_comment(int questionNo, vector<Comment> &_comment_list, int sortOrder)
{
    DB->get_comment(questionNo, _comment_list);
    switch (sortOrder)
    {
        case 1:
        {
            sort(_comment_list.begin(), _comment_list.end(), time_HtL);
            break;
        }
        case 2:
        {
            sort(_comment_list.begin(), _comment_list.end(), time_LtH);
            break;
        }
        case 3:
        {
            sort(_comment_list.begin(), _comment_list.end(), likes_HtL);
            break;
        }
        default:
            break;
    }
    return ;
}
