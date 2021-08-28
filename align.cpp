#include "align.h"

Align::Align(const wxString& title)
    : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(200, 300))
{

    wxPanel* panel = new wxPanel(this, -1);
    wxFlexGridSizer* gsize = new wxFlexGridSizer(12,wxSize(200,150));
    //wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    //wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    //wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxButton* login = new wxButton(panel, -1, wxT("LogIn"));
    wxButton* register1 = new wxButton(panel, -1, wxT("Register"));

    //hbox1->Add(new wxPanel(panel, -1));
    //vbox->Add(hbox1, 1, wxEXPAND);
    //hbox2->Add(login,wxEXPAND);
    //hbox2->Add(register1);
    //vbox->Add(hbox2, 1.5, wxALIGN_CENTER, 10);
    gsize->Add(new wxPanel(panel, -1));
    gsize->Add(login);
    gsize->Add(register1);
    panel->SetSizer(gsize);
    Centre();
}