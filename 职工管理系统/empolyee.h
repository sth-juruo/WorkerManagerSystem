#pragma once
#include "worker.h"
class employee: public worker
{
public:
	employee(int id, string name, int dId);
    void showinfo();
	string getd_name();
};