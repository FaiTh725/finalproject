#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "Vector.h"
#include "Student.h"
#include "mergesort.h"


class MainWindow:public QWidget
{
    Q_OBJECT


    //1-ая вкладка добавление удаление элементов
    //2-ая просмотр статистики о зарплатах плюс надо реализовать ползунки
    QTabWidget *wgt;

    QWidget *first_tab;
    QWidget *second_tab;

    Vector<Student> vec;
    //for first _tab
    QComboBox *lst_surname;

    QLineEdit *fill_name, *fill_second_name, *fill_surname,
        *fill_group, *fill_av_score, *fill_finance;

    QComboBox *show_lst;
    //----------------

    //for second_tab

    QTextEdit *display_surname;
    QSlider *finance_slider;
    QSlider *av_score_slider;

    //-----------------

    QWidget* CreateFirstTab();
    QWidget* CreateSecondTab();

public:
    MainWindow();
    ~MainWindow();


//signals:


public slots:
    //for first tab
    void AddData();
    void DeleteData();
    void GetPersonInfo();
    void SortDataBySurname();
    //----

    //for second tab

    void ShowLstStudentFinance(int value);
    void ShowLstStudentScore(int value);
    //--------------
};

#endif // MAINWINDOW_H
