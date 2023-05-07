#pragma once

using namespace System;
using namespace System::Collections;

ref class Data_New
{
public:
	Data_New();
	void AddToList(String^);
	void Search_License_time(String^ key);
	void delete_elem(String^ temp);
	int get_size_new();
	String^ str_index(int i);
	void clear();

private:
	ArrayList^ mass;
	int Ans_bool;
	ArrayList^ mass_NEW;
};
