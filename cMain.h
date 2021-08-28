#pragma once
#include"wx/wx.h"
class cMain : public wxFrame
{

public:
	cMain();
	~cMain();

public:
	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);
	void OnButtonClicked1(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

