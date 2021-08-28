#include "Register.h"
#include<wx/wx.h>
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<string.h>
#include"cMain.h"
using namespace std;
wxBEGIN_EVENT_TABLE(Register,wxFrame)
EVT_BUTTON(1,OnButtonClick)
wxEND_EVENT_TABLE()

Register::Register(const wxString& title)
	:wxFrame(NULL,-1,"Register",wxPoint(30,60),wxSize(800,600))

{
	
	btn1 = new wxButton(this, 1, "Register", wxDefaultPosition, wxSize(150, 50));
	txt1 = new wxTextCtrl(this, 2, "", wxDefaultPosition, wxSize(150, 20));
	txt2 = new wxTextCtrl(this, 3, "", wxDefaultPosition, wxSize(150, 20));
	wxBoxSizer* siz = new wxBoxSizer(wxVERTICAL);
	siz->AddStretchSpacer();
	siz->Add(txt1, 0, wxALL | wxALIGN_CENTER, 5);
	siz->Add(txt2, 0, wxALL | wxALIGN_CENTER, 5);
	siz->Add(btn1, 0, wxALL | wxALIGN_CENTER, 5);
	siz->AddStretchSpacer();
	SetSizer(siz);
	

}
void Register::OnButtonClick(wxCommandEvent& evt)
{
	int count = 0;
	int balance = 0;
	ifstream ct("count.txt");
	if (ct.is_open())
	{
		ct >> count;
	}
	else
	{
		wxMessageBox(wxT("count.txt is missing"));
	}
	ct.close();
	remove("count.txt");
	wxString RId = txt1->GetValue(), RPass = txt2->GetValue();
	ofstream file;
	file.open(to_string(count) + ".txt");
	file << RId << endl << RPass<<endl<<balance;
	file.close();
	count++;
	ofstream cet;
	cet.open("count.txt");
	cet << count;
	cet.close();
	Destroy();
	evt.Skip();
}