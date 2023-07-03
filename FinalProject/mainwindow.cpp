#include "mainwindow.h"

QWidget* MainWindow::CreateFirstTab()
{
    first_tab=new QWidget;

    lst_surname=new QComboBox;


    QCursor cursor(Qt::IBeamCursor);

    fill_name=new QLineEdit;
    fill_name->setCursor(cursor);

    fill_second_name=new QLineEdit;
    fill_second_name->setCursor(cursor);

    fill_surname=new QLineEdit;
    fill_surname->setCursor(cursor);

    fill_group=new QLineEdit;
    fill_group->setCursor(cursor);

    fill_av_score=new QLineEdit;
    fill_av_score->setCursor(cursor);

    fill_finance=new QLineEdit;
    fill_finance->setCursor(cursor);


    QLabel *lbl_fill_name=new QLabel("Имя");
    QLabel *lbl_fill_second_name=new QLabel("Отчество");
    QLabel *lbl_fill_surname=new QLabel("Фамилия");
    QLabel *lbl_fill_group=new QLabel("Группа");
    QLabel *lbl_fill_av_score=new QLabel("Средний балл");
    QLabel *lbl_fill_finance=new QLabel("Доходы за последние 6 месяцев");


    QCursor cursor_button(Qt::PointingHandCursor);

    QPushButton *add=new QPushButton("Добавить");
    add->setCursor(cursor_button);

    QPushButton *del=new QPushButton("Удалить");
    add->setCursor(cursor_button);

    QPushButton *sort=new QPushButton("Сортировать по фамилии");
    add->setCursor(cursor_button);

    QPushButton *show_info=new QPushButton("Вывести информацию о студенте");
    add->setCursor(cursor_button);

    QPushButton *exit=new QPushButton("Выход из программы");
    add->setCursor(cursor_button);


    QGridLayout *grid_layout=new QGridLayout;
    grid_layout->setSpacing(20);
    grid_layout->addWidget(add,0,0);
    grid_layout->addWidget(del,0,1);
    grid_layout->addWidget(sort,1,0);
    grid_layout->addWidget(show_info,1,1);


    QVBoxLayout *V_layout=new QVBoxLayout;

    V_layout->addWidget(lst_surname);
    V_layout->addSpacing(200);
    V_layout->addWidget(lbl_fill_name);
    V_layout->addWidget(fill_name);
    V_layout->addWidget(lbl_fill_second_name);
    V_layout->addWidget(fill_second_name);
    V_layout->addWidget(lbl_fill_surname);
    V_layout->addWidget(fill_surname);
    V_layout->addWidget(lbl_fill_group);
    V_layout->addWidget(fill_group);
    V_layout->addWidget(lbl_fill_av_score);
    V_layout->addWidget(fill_av_score);
    V_layout->addWidget(lbl_fill_finance);
    V_layout->addWidget(fill_finance);
    V_layout->addSpacing(50);

    V_layout->addLayout(grid_layout);
    V_layout->addSpacing(50);

    V_layout->addWidget(exit);

    V_layout->setSpacing(20);
    V_layout->addStretch(1);


    //переделать на wgt
    connect(exit,SIGNAL(clicked()),wgt,SLOT(close()));

    //connection first_tag

    connect(add,SIGNAL(clicked()),SLOT(AddData()));
    connect(del,SIGNAL(clicked()),SLOT(DeleteData()));
    connect(show_info,SIGNAL(clicked()),SLOT(GetPersonInfo()));
    connect(sort,SIGNAL(clicked()),SLOT(SortDataBySurname()));

    //-------------------

    first_tab->setLayout(V_layout);

    return first_tab;
}

QWidget *MainWindow::CreateSecondTab()
{

    second_tab=new QWidget;

    display_surname = new QTextEdit;
    display_surname->setReadOnly(true);

    QCursor cursor_second_slider(Qt::OpenHandCursor);
    QCursor exit_cur(Qt::PointingHandCursor);


    finance_slider = new QSlider(Qt::Horizontal);
    finance_slider->setMaximum(10000);
    finance_slider->setMinimum(0);
    finance_slider->setTickPosition(QSlider::TicksBothSides);
    finance_slider->setPageStep(1000);
    finance_slider->setCursor(cursor_second_slider);

    av_score_slider=new QSlider(Qt::Horizontal);
    av_score_slider->setMaximum(10);
    av_score_slider->setMinimum(0);
    av_score_slider->setTickPosition(QSlider::TicksBothSides);
    av_score_slider->setPageStep(0.1);
    av_score_slider->setCursor(cursor_second_slider);

    QLabel *lbl_info_about_this_page=new QLabel("Перемещая ползунки чтобы отсортировать студентов");
    QLabel *lbl_finance=new QLabel("Финансы");
    QLabel *lbl_av_score=new QLabel("Cредний балл");
    QLabel *lbl_display_surname=new QLabel("Фамили студентов");

    QPushButton *quit1=new QPushButton("Выход из приложения");
    quit1->setCursor(exit_cur);

    //second tab layout seting
    QVBoxLayout * v_layout1=new QVBoxLayout;
    v_layout1->addWidget(lbl_info_about_this_page);
    v_layout1->addSpacing(25);
    v_layout1->addWidget(lbl_display_surname);
    v_layout1->addWidget(display_surname);
    v_layout1->addSpacing(100);

    QGridLayout *grid_layout1=new QGridLayout;
    grid_layout1->addWidget(lbl_finance,0,0);
    grid_layout1->addWidget(finance_slider,1,0);
    grid_layout1->addWidget(lbl_av_score,0,1);
    grid_layout1->addWidget(av_score_slider,1,1);

    v_layout1->addLayout(grid_layout1);
    v_layout1->addSpacing(200);
    v_layout1->addWidget(quit1);
    v_layout1->addSpacing(50);

    //-----------------------

    //set connection second layout

    connect(quit1,SIGNAL(clicked()),wgt,SLOT(close()));

    connect(finance_slider,SIGNAL(valueChanged(int)),SLOT(ShowLstStudentFinance(int)));
    connect(av_score_slider,SIGNAL(valueChanged(int)),SLOT(ShowLstStudentScore(int)));

    //--------------------------

    second_tab->setLayout(v_layout1);

    return second_tab;

}


MainWindow::MainWindow()
{
    wgt=new QTabWidget;

    first_tab=CreateFirstTab();
    second_tab=CreateSecondTab();

    wgt->addTab(first_tab,"Добавление удаление студентов");
    wgt->addTab(second_tab,"Зарплаты");
    wgt->resize(700,900);
    wgt->show();
}

MainWindow::~MainWindow()
{
    delete wgt;
    delete fill_name;
    delete fill_second_name;
    delete fill_surname;
    delete fill_group;
    delete fill_av_score;
    delete fill_finance;
}

void MainWindow::AddData()
{

    try
    {
        vec.PushBack(Student(fill_name->text(), fill_second_name->text(), fill_surname->text(),
                             fill_group->text().toInt(), fill_av_score->text().toDouble(),
                             fill_finance->text().toDouble()));
    }
    catch (QString message)
    {
        QWidget *error =new QWidget;
        error->setWindowTitle("Error");

        QPixmap er;
        er.load(":/er.jpg");
        QLabel lbl_er;
        lbl_er.resize(er.size());
        lbl_er.setPixmap(er);

        QLabel *lbl_error=new QLabel(message);

        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(&lbl_er);
        layout->addWidget(lbl_error);

        error->setLayout(layout);
        error->resize(200,100);
        error->show();
        return ;
    }

    lst_surname->addItem(vec[vec.Size()-1].GetSurname());

}

void MainWindow::DeleteData()
{
    vec.Erase(lst_surname->currentIndex());
    lst_surname->clear();

    for(int i=0;i<vec.Size();i++)
    {
        lst_surname->addItem(vec[i].GetSurname());
    }
}

void MainWindow::GetPersonInfo()
{

    if(vec.Size()==0)
    {
        QLabel *error=new QLabel("Вы еще ничего не добавили");
        error->resize(100,100);
        error->show();

        return;
    }

    int ind_picked_st=lst_surname->currentIndex();

    QWidget *wgt_info=new QWidget;
    wgt_info->setWindowTitle("Profile");


    QLabel *window_info=new QLabel("Окно вывода информации о студенте");
    QLabel *lbl_name=new QLabel("Имя студента -");
    QLabel *lbl_second_name=new QLabel("Отчество -");
    QLabel *lbl_surname=new QLabel("Фамилия -");
    QLabel *lbl_group=new QLabel("№ группы -");
    QLabel *lbl_av_score=new QLabel("Средний балл -");
    QLabel *lbl_finance=new QLabel("Доход родителей за последние 60 месяцев -");

    QLabel *show_name=new QLabel(vec[ind_picked_st].GetName());
    QLabel *show_second_name=new QLabel(vec[ind_picked_st].GetSecondName());
    QLabel *show_surname=new QLabel(vec[ind_picked_st].GetSurname());
    QLabel *show_group=new QLabel(QString::number(vec[ind_picked_st].GetGroup()));
    QLabel *show_av_score=new QLabel(QString::number(vec[ind_picked_st].GetAvScore()));
    QLabel *show_finance=new QLabel(QString::number(vec[ind_picked_st].GetFinance()));

    QVBoxLayout *layout=new QVBoxLayout;

    layout->addWidget(window_info);
    layout->setSpacing(30);

    QGridLayout *main_layout=new QGridLayout;
    main_layout->addWidget(lbl_name, 0, 0);
    main_layout->addWidget(show_name, 0, 1);
    main_layout->addWidget(lbl_second_name, 1, 0);
    main_layout->addWidget(show_second_name, 1, 1);
    main_layout->addWidget(lbl_surname, 2, 0);
    main_layout->addWidget(show_surname, 2, 1);
    main_layout->addWidget(lbl_group, 3, 0);
    main_layout->addWidget(show_group, 3, 1);
    main_layout->addWidget(lbl_av_score, 4, 0);
    main_layout->addWidget(show_av_score, 4, 1);
    main_layout->addWidget(lbl_finance, 5, 0);
    main_layout->addWidget(show_finance, 5, 1);

    layout->addLayout(main_layout);


    wgt_info->setLayout(layout);
    wgt_info->resize(300,400);
    wgt_info->show();
}

void MainWindow::SortDataBySurname()
{
    lst_surname->clear();

    for(int i=0;i<vec.Size();i++)
    {
        lst_surname->addItem(vec[i].GetSurname());
    }
}

void MainWindow::ShowLstStudentFinance(int value)
{
    display_surname->clear();
    for(int i=0;i<vec.Size();i++)
    {
        if(vec[i].GetFinance()<=value && vec[i].GetAvScore()<=av_score_slider->value())
        {
            display_surname->append(vec[i].GetSurname()+" - "+QString::number(vec[i].GetFinance())
                                    +'\t'+QString::number(vec[i].GetAvScore()));
        }
    }
}

void MainWindow::ShowLstStudentScore(int value)
{
    display_surname->clear();

    for(int i=0;i<vec.Size();i++)
    {
        if(vec[i].GetAvScore()<=value && vec[i].GetFinance()<=finance_slider->value())
        {
            display_surname->append(vec[i].GetSurname()+" - "+QString::number(vec[i].GetFinance())
                                    +'\t'+QString::number(vec[i].GetAvScore()));
        }
    }
}
