#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb; // подключение баз данных Access

[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab6::MyForm form;
	Application::Run(% form);
}

System::Void Lab6::MyForm::загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Подключение БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "SELECT * FROM [table_name]"; //запрос
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // считываем данные

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка", "ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		while (dbReader->Read() == true)
		{
			dataGridView1->Rows->Add(dbReader["id"], dbReader["IP"], dbReader["Date_1"], dbReader["System"]);
		}
	}
	//Закрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Lab6::MyForm::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание");
		return;
	}

	//считываем


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// Подключение БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "INSERT INTO [table_name] VALUES ('"+ id +"','"+ IP +"','"+ Date_1 +"','"+ System +"')"; //запрос
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // команда
	
	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполения запроса!", "Ошибка");
	}
	else
	{
		MessageBox::Show("Данные добавлены!", "Готово!");
	}

	dbConnection->Close();


	return System::Void();
}

System::Void Lab6::MyForm::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание");
		return;
	}

	//считываем


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// Подключение БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "UPDATE [table_name] SET IP ='" + IP + "',Date_1=" + Date_1 + ",System=" + System + " WHERE id = "+ id;   //запрос
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // команда

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполения запроса!", "Ошибка");
	}
	else
	{
		MessageBox::Show("Данные обновлены!", "Готово!");
	}

	dbConnection->Close();



	return System::Void();
}

System::Void Lab6::MyForm::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание");
		return;
	}

	//считываем


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// Подключение БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "DELETE FROM [table_name] WHERE id = " + id;  //запрос
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // команда

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполения запроса!", "Ошибка");
	}
	else
	{
		MessageBox::Show("Данные Удалены!", "Готово!");
		dataGridView1->Rows->RemoveAt(index);
	}

	dbConnection->Close();


	return System::Void();
}
