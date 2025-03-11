#pragma once
#include "worker.h"
class manage : public worker
{
public:
	manage(int id, string name, int dId);
	void showinfo();
	string getd_name();
};