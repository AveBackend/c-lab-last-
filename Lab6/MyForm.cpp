#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb; // ����������� ��� ������ Access

[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab6::MyForm form;
	Application::Run(% form);
}

System::Void Lab6::MyForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ����������� ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "SELECT * FROM [table_name]"; //������
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // ��������� ������

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		while (dbReader->Read() == true)
		{
			dataGridView1->Rows->Add(dbReader["id"], dbReader["IP"], dbReader["Date_1"], dbReader["System"]);
		}
	}
	//��������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Lab6::MyForm::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("�� ��� ������ �������!", "��������");
		return;
	}

	//���������


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// ����������� ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "INSERT INTO [table_name] VALUES ('"+ id +"','"+ IP +"','"+ Date_1 +"','"+ System +"')"; //������
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // �������
	
	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ��������� �������!", "������");
	}
	else
	{
		MessageBox::Show("������ ���������!", "������!");
	}

	dbConnection->Close();


	return System::Void();
}

System::Void Lab6::MyForm::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("�� ��� ������ �������!", "��������");
		return;
	}

	//���������


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// ����������� ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "UPDATE [table_name] SET IP ='" + IP + "',Date_1=" + Date_1 + ",System=" + System + " WHERE id = "+ id;   //������
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // �������

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ��������� �������!", "������");
	}
	else
	{
		MessageBox::Show("������ ���������!", "������!");
	}

	dbConnection->Close();



	return System::Void();
}

System::Void Lab6::MyForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[1]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[2]->Value == nullptr
		|| dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
	{
		MessageBox::Show("�� ��� ������ �������!", "��������");
		return;
	}

	//���������


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ IP = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Date_1 = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ System = dataGridView1->Rows[index]->Cells[3]->Value->ToString();


	// ����������� ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "DELETE FROM [table_name] WHERE id = " + id;  //������
	OleDbCommand^ dbComand = gcnew  OleDbCommand(query, dbConnection); // �������

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ��������� �������!", "������");
	}
	else
	{
		MessageBox::Show("������ �������!", "������!");
		dataGridView1->Rows->RemoveAt(index);
	}

	dbConnection->Close();


	return System::Void();
}
