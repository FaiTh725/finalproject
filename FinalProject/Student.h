#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

QString StringToCorrect(QString name);

class Student
{
    QString name, second_name, surname;
    int group;
    double av_score, finance;

public:
    Student():name(""), second_name(""), surname(""),
             group(0),av_score(0), finance(0){}

    Student(QString, QString, QString, int, double, double);
    Student(Student &other);

    ~Student(){}

    Student operator=(Student other);

    QString GetName(){return name;}
    QString GetSurname(){return surname;}
    QString GetSecondName(){return second_name;}
    int GetGroup(){return group;}
    double GetAvScore(){return av_score;}
    double GetFinance(){return finance;}

};


#endif // STUDENT_H
