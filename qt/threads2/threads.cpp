#include "threads.h"
/*
void run_chat(const int& n, list<string>&l)
{
    int lock = 0;
    int safe = 0;
	thread** th = new thread * [n];
	for (int i = 0; i < n; i++)
        th[i] = new thread(f, i, std::ref(l), std::ref(lock), std::ref(safe));
	for (int i = 0; i < n; i++)
	{
		th[i]->join();
		delete th[i];
	}
    delete[] th;
}

void f(int id, list<string>& l, int&lock, int&safe)
{
	string str, tmp, path = "f" + to_string(id) + ".txt";
	ifstream f(path);
	if (f.is_open())
	{
		int i = 0;
		while (!f.eof())
		{
			tmp = "";
			f >> tmp;
			//this_thread::sleep_for(1ns);
            while (lock != id)
			{
			}
			str = to_string(id) + " #" + to_string(i) + "\t" + tmp + "\n";
            l.push_back(str);
			i++;
            if (safe == 0)
            lock = (int)fabs(id - 1);
            if (f.eof()) safe = 1;
		}
    f.close();
    }
}
*/
