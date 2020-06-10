#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void f(const int& id, list<string>& l, int& lock ,int& safe, QTextEdit* qte)
{
    string str, tmp, path = "f" + to_string(id) + ".txt";
    ifstream f(path);
    if (f.is_open())
    {
        cout << "file opened!" << endl;
        int i = 0;
        while (!f.eof())
        {
            tmp = "";
            f >> tmp;
            this_thread::sleep_for(chrono::nanoseconds(1));
            while (lock != id)
            {
                this_thread::sleep_for(chrono::nanoseconds(1));
            }
            str = to_string(id) + " #" + to_string(i) + "\t" + tmp + "\n";
            l.push_back(str);
            qte->append(QString::fromStdString(str));
            i++;
            if (safe == 0)
            lock = (int)fabs(id - 1);
            if (f.eof()) safe = 1;
        }
    }
    else
        cout << "cannot open script file!" << endl;
}

thread** run_chat(const int& n, list<string>& l, QTextEdit* qte)
{
    int lock = 0;
    int safe = 0;
    thread** th = new thread * [n];
    for (int i = 0; i < n; i++)
        th[i] = new thread(f, i, std::ref(l), std::ref(lock), std::ref(safe), qte);
    return th;
}




void MainWindow::on_pushButton_clicked()
{
    list<string> l;
    auto ** th = run_chat(2, l, ui->textEdit);
    this_thread::sleep_for(chrono::milliseconds(100));
    for (int i = 0; i < 2; i++)
    {
        th[i]->join();
        delete th[i];
    }
    delete th;
    //for (auto it = l.begin(); it != l.end(); it++)
    //cout << *it ;

}
