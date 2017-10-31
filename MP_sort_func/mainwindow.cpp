#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->size_box->text()="777";


    connect(ui->GenerateButton,SIGNAL(clicked()),SLOT(slotGenerate()));
    connect(ui->InSortButton,SIGNAL(clicked()),SLOT(slotInSort()));
    connect(ui->OutSortButton,SIGNAL(clicked()),SLOT(slotOutSort()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//===== Описание словтов и функц3444ий ========

void MainWindow::slotGenerate()
{
    int trash;
    size = ui->size_box->text().toInt();
    MyArray.clear();
    OutArray.clear();

    for(int i=0;size!=MyArray.size();i++)
    {
        trash = qrand()+qrand()-qrand();
        MyArray.push_back(trash);
        OutArray.push_back(trash);
    }
    show_array();

    QFile genFile("File.txt");
    bool file_delte = genFile.remove();
    if(genFile.open(QIODevice::WriteOnly))
    {
        QTextStream MyStream(&genFile);
        QString str;
        for(int i=0;i<MyArray.size();i++)
        {
            str = QString::number(MyArray[i])+" ";
            MyStream << str << endl;
        }
    }
    genFile.close();

}

void MainWindow::show_array()
{
    ui->textEdit->clear();
    for(int i=MyArray.size()-1; i>=0 ;i--)
    {
        ui->textEdit->append(QString(QString::number(MyArray[i])+" "));
    }
}

void MainWindow::slotInSort()
{
    QTime MyTime;

    int Buble_time;
    int Insert_time;
    int SortFunc_time;

    MyTime.start();
    Buble_time = clock();
    //========= сортировка пузырьком
    bool no_swap=false;
    bool swap=false;
    int trash;

    while(!no_swap)
    {
        swap=false;
        for(int i=0;i<size-1;i++)
        {

            if(MyArray[i]>MyArray[i+1])
            {
                trash=MyArray[i];
                MyArray[i]=MyArray[i+1];
                MyArray[i+1]=trash;
                swap=true;
            }

        }
        if(!swap) no_swap = true;
    }
    Buble_time = MyTime.restart();

    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);

    //========= сортировка вставокой
    MyTime.start();
    Insert_time = clock();

    int min;
    int num_min;

    for(int i=0;i<size;i++)
    {
        min=MyArray[i];
        num_min=i;
        for(int j=i+1;j<size;j++)
        {
            if(MyArray[j]>min)
            {
                num_min=j;
                min=MyArray[j];
            }
        }
        trash=MyArray[num_min];
        MyArray[num_min]=MyArray[i];
        MyArray[i]=trash;
    }
    Insert_time = MyTime.restart();

    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);

    //========= сортировка C++Sort
    MyTime.start();
    SortFunc_time = clock();

    sort(MyArray.begin(),MyArray.end());

    SortFunc_time = MyTime.restart();
    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


    //============================
    // тут будет передаваться в формы время работы алгоритмов
    ui->Line_Time_BubleSort->setText(QString::number(Buble_time)+" ms");
    ui->Line_Time_InsertSort->setText(QString::number(Insert_time)+" ms");
    ui->Line_Time_SortFunc->setText(QString::number(SortFunc_time)+" ms");

    sort(OutArray.begin(),OutArray.end());
    show_array();
}


void MainWindow::slotOutSort()
{
    QTime MyTime;
    MyTime.start();

    MyArray.clear();
    OutArray.clear();
    QFile MyFile("File.txt");
    if(MyFile.open(QIODevice::ReadWrite))
    {
        QTextStream MyStream(&MyFile);
        QString str;
        while(!MyStream.atEnd())
        {
            str = MyStream.readLine();
            MyArray.push_back(str.toInt());
            OutArray.push_back(str.toInt());
        }

        int Buble_time;
        int Insert_time;
        int SortFunc_time;

        MyTime.start();
        Buble_time = clock();
        //========= сортировка пузырьком
        bool no_swap=false;
        bool swap=false;
        int trash;

        while(!no_swap)
        {
            swap=false;
            for(int i=0;i<size-1;i++)
            {

                if(MyArray[i]>MyArray[i+1])
                {
                    trash=MyArray[i];
                    MyArray[i]=MyArray[i+1];
                    MyArray[i+1]=trash;
                    swap=true;
                }

            }
            if(!swap) no_swap = true;
        }
        Buble_time = MyTime.restart();



        MyArray.clear();
        for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


        //========= сортировка вставокой
        MyTime.start();
        Insert_time = clock();

        int min;
        int num_min;

        for(int i=0;i<size;i++)
        {
            min=MyArray[i];
            num_min=i;
            for(int j=i+1;j<size;j++)
            {
                if(MyArray[j]>min)
                {
                    num_min=j;
                    min=MyArray[j];
                }
            }
            trash=MyArray[num_min];
            MyArray[num_min]=MyArray[i];
            MyArray[i]=trash;
        }
        Insert_time = MyTime.restart();

        MyArray.clear();
        for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);

        //========= сортировка C++Sort
        MyTime.start();
        SortFunc_time = clock();

        sort(MyArray.begin(),MyArray.end());

        SortFunc_time = MyTime.restart();
        MyArray.clear();
        for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


        //============================
        // тут будет передаваться в формы время работы алгоритмов
        ui->Line_Time_BubleSort->setText(QString::number(Buble_time)+" ms");
        ui->Line_Time_InsertSort->setText(QString::number(Insert_time)+" ms");
        ui->Line_Time_SortFunc->setText(QString::number(SortFunc_time)+" ms");

        sort(OutArray.begin(),OutArray.end());

        bool file_delte = MyFile.remove();
        if(MyFile.open(QIODevice::ReadWrite))
        {
            for(int i=0;i<OutArray.size();i++)
            {
                str = QString::number(OutArray[i]);
                MyStream << str << endl;
            }
        }
        show_array();
    }
    // записываем все в файл и закрываем его
    MyFile.close();

    sort(OutArray.begin(),OutArray.end());

    show_array();
}

