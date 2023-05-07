#include "Class.h"

Data_New::Data_New()
{
	mass = gcnew ArrayList();
	mass_NEW = gcnew ArrayList();
}

void Data_New::AddToList(String^ string)
{
	mass->Add(string);
}

int Data_New::get_size_new()
{
	return mass_NEW->Count;
}

String^ Data_New::str_index(int i)
{
	return (String^)mass_NEW[i];
}

void Data_New::Search_License_time(String^ key)
{
	for (int i = 0; i < mass->Count; i++)
	{
		String^ e = (String^)mass[i];

		int save_start = 0;

		for (int i = 0; i < e->Length; ++i)
		{
			if (e[i] == ',')
			{
				save_start = i;
				break;
			}
		}

		int end = 0;

		for (int i = save_start + 1; i < e->Length; ++i)
		{
			if (e[i] == ',')
			{
				end = i;
				break;
			}
		}

		int kol = 0;

		for (int i = save_start + 1; i <= end; ++i)
		{
			if (e[i] != ',') kol++;
		}

		int k = 0;
		bool f = true;
		for (int i = save_start + 1; i < e->Length; ++i)
		{
			if (kol != key->Length)
			{
				f = false;
				break;
			}
			else if (e[i] == ',') break;
			else if (e[i] != key[k])
			{
				f = false;
				break;
			}
			k++;

		}

		if (f == true)
		{
			mass_NEW->Add(mass[i]);
		}

	}

}

void Data_New::clear()
{
	mass_NEW->Clear();
}

void Data_New::delete_elem(String^ temp)
{
	mass->Remove(temp);
	mass_NEW->Remove(temp);
}
