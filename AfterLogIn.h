#pragma once
#include"wx/wx.h"

class AfterLogIn : public wxFrame 
{
public:
	AfterLogIn(const wxString& title);
public:
	wxStaticText* txt1 = nullptr;
	wxStaticText* txt2 = nullptr;
	wxStaticText* txt3 = nullptr;
	wxButton* btn1 = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};