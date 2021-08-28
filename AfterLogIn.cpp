#include "AfterLogIn.h"
#include<wx/wx.h>
#include"wx/utils.h"
#include"wx/timer.h"
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
wxBEGIN_EVENT_TABLE(AfterLogIn, wxFrame)
EVT_BUTTON(3,OnButtonClicked)
wxEND_EVENT_TABLE()

class Random
{
public:
	int count = 0;
};

AfterLogIn::AfterLogIn(const wxString& title):
	wxFrame(NULL,-1,title,wxPoint(30,60),wxSize(800,600))
{
	txt1 = new wxStaticText(this,1,"Name:", wxPoint(0, 0), wxSize(200, 40));
	wxString name = "Jalil";
	txt2 = new wxStaticText(this, 2,name , wxPoint(40, 0), wxSize(200, 40));
	txt2->SetForegroundColour(wxColour(60, 173, 231));
	txt1->SetForegroundColour(wxColour(55, 173, 231));
    wxString clock=wxDateTime::Now().FormatISOTime();
	txt3 = new wxStaticText(this, 3, clock, wxPoint(100, 0), wxSize(20, 40));
	txt3->Show(false);
	txt3->SetForegroundColour(wxColour(55, 173, 231));
	btn1 = new wxButton(this, 3, "Show time", wxPoint(200, 10), wxSize(200, 40));
	
}
Random object;
void AfterLogIn::OnButtonClicked(wxCommandEvent& evt)//Show Time Button
{
	
	if(object.count%2==0)
	{
    wxString clock = wxDateTime::Now().FormatISOTime();
	txt3->SetLabelText(clock);
	txt3->Show(true);
	object.count++;
	}
	else if(object.count%2==1)
	{
		txt3->Show(false);
		object.count++;
	}
	
	evt.Skip();
	
}