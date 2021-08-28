#pragma once
#include <wx/wx.h>

class LogIn : public wxFrame
{
public:
    LogIn(const wxString& title);
public:
    wxButton* btn1 = nullptr;
    wxTextCtrl* txt1 = nullptr;
    wxTextCtrl* txt2 = nullptr;
    void OnButtonClick(wxCommandEvent& evt);
    DECLARE_EVENT_TABLE();
};