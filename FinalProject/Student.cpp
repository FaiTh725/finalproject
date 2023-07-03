#include "Student.h"

QString StringToCorrect(QString name)
{
    return name[0].toUpper()+name.right(name.length()-1);
}

Student::Student(QString name,QString second_name, QString surname, int group, double av_score, double finance)
{
    if(name.length()==0 || second_name.length()==0 || surname.length()==0)
    {
        throw QString("incorrect data of string parametrs");
    }

    //длинна группы должна быть ровно 8 символов
    if(QString::number(group).length()!=8)
    {
        throw QString("incorrect name group only 8 symbols");

    }

    if(av_score<0 || finance<0 || group<0 || finance>10000 || av_score>10)
    {
        throw QString("value cannot be less than zero or over than 10000");
    }

    this->name=StringToCorrect(name);
    this->second_name=StringToCorrect(second_name);
    this->surname=StringToCorrect(surname);
    this->group=group;
    this->av_score=av_score;
    this->finance=finance;
}

Student::Student(Student &other)
{
    this->name=other.GetName();
    this->second_name=other.GetSecondName();
    this->surname=other.GetSurname();
    this->group=other.GetGroup();
    this->av_score=other.GetAvScore();
    this->finance=other.GetFinance();
}

Student Student::operator =(Student other)
{
    name=other.GetName();
    second_name=other.GetSecondName();
    surname=other.GetSurname();
    group=other.GetGroup();
    av_score=other.GetAvScore();
    finance=other.GetFinance();
    return *this;
}
