#include "cMain.h"
#include<fstream>
#include<string>
#include<iostream>
#include<wx/wx.h>
#include<wx/msgdlg.h>
#include "LogIn.h"
#include"AfterLogIn.h"
#include"Register.h"
using namespace std;
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(1, OnButtonClicked)
EVT_BUTTON(2, OnButtonClicked1)
wxEND_EVENT_TABLE()

cMain::cMain():wxFrame(nullptr,wxID_ANY,"First window hoooray!",wxPoint(10,50),wxSize(800,600)){
	
	
	m_btn1 = new wxButton(this, 1, "LogIn", wxDefaultPosition, wxSize(100,50));
	m_btn2 = new wxButton(this, 2, "Register", wxDefaultPosition, wxSize(100,50));
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
	buttonSizer->AddStretchSpacer();
	buttonSizer->Add(m_btn1, 0, wxALL | wxALIGN_CENTER, 5);
	buttonSizer->Add(m_btn2, 0, wxALL | wxALIGN_CENTER, 5);
	buttonSizer->AddStretchSpacer();
	SetSizer(buttonSizer);

}
cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt) 
{
	LogIn* Login = new LogIn(wxT("LogIn"));
	Login->Show(true);
	evt.Skip();
}

void cMain::OnButtonClicked1(wxCommandEvent& evt)
{
	Register* Register1 = new Register(wxT("Register"));
	Register1->Show(true);
	evt.Skip();
}
