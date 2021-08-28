#include "LogIn.h"
#include"AfterLogIn.h"
#include<wx/wx.h>
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
wxBEGIN_EVENT_TABLE(LogIn,wxFrame)
EVT_BUTTON(3,OnButtonClick)
wxEND_EVENT_TABLE()
LogIn::LogIn(const wxString& title)
    : wxFrame(NULL, -1, title, wxPoint(30, 60), wxSize(300, 200))
{
    txt1 = new wxTextCtrl(this, 1, "", wxDefaultPosition, wxSize(150, 22));
    txt2 = new wxTextCtrl(this, 2, "", wxDefaultPosition, wxSize(150, 22));
    btn1 = new wxButton(this, 3, "LogIn", wxDefaultPosition, wxSize(150, 50));
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(txt1, 0, wxALL | wxALIGN_CENTER, 3);
    buttonSizer->Add(txt2, 0, wxALL | wxALIGN_CENTER, 3);
    buttonSizer->Add(btn1, 0, wxALL | wxALIGN_CENTER, 3);
    buttonSizer->AddStretchSpacer();
    SetSizer(buttonSizer);
}
void LogIn::OnButtonClick(wxCommandEvent& evt)
{
    wxString LId = txt1->GetValue();
    wxString LPass = txt2->GetValue();
    LId.ToStdString();
    LPass.ToStdString();
    int count = 0;
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
    string list[150];
    int f = 0; //list array-inə məlumatları yığmaq
    int g = 0;
    while (f < count - 1)
    {
        ifstream nam(to_string(f + 1) + ".txt");
        if (nam.is_open())
        {
            getline(nam, list[g]);
            getline(nam, list[g + 1]);
            nam.close();
        }
        else
        {
            wxMessageBox( to_string(f + 1) + ".txt is missing");
            break;
        }
        f++;
        g = g + 2;
    }
    int c = 0;
    int y = 0;
    for (; y < count;)
    {
        if (LId == list[c] && LPass == list[c + 1])
        {
            wxMessageBox("You were succesfully loged in");
            AfterLogIn* AfterLogIn1 = new AfterLogIn(wxT("Log In Interface"));
            AfterLogIn1->Show(true);
            Destroy();
            break;
        }
        else if (y == count - 1)
        {
            wxMessageBox(wxT("Invalid username or password"));
            y++;
            Destroy();
        }
        else if (y < count)
        {
            y++;
            c = c + 2;
            continue;
        }
    }
    evt.Skip();
}