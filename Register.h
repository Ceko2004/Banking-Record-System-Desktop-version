#pragma once
#include<wx/wx.h>

class Register :public wxFrame
{
public:
	Register(const wxString& title);
public:

	wxTextCtrl* txt1 = nullptr;
	wxTextCtrl* txt2 = nullptr;
	wxButton* btn1 = nullptr;
	void OnButtonClick(wxCommandEvent& evt);

	DECLARE_EVENT_TABLE();
};