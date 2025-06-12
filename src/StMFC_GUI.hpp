#ifndef STMFC_GUI_HPP
#define STMFC_GUI_HPP

#include <string>
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <fstream>
#include "convert.hpp"

class TheSingleOneFuckingPanel : public wxPanel {
public:
    explicit TheSingleOneFuckingPanel(wxFrame *parent, const std::string &appPath);

private:
    wxBitmap interfaceBitmap;

    void paintEvent(wxPaintEvent &evt);

    void render(wxDC &dc);

    void DragNDrop(wxDropFilesEvent &event);

DECLARE_EVENT_TABLE()
};

class MainWindow : public wxFrame {
private:
    std::string appPath;
public:
    MainWindow();

private:
    wxPanel *TSFP;
    wxIcon icon;
    void OnClose(wxCloseEvent &event);
};

class StMFC_GUI : public wxApp {
private:
    MainWindow *mv;
public:
    bool OnInit() override;
};


#endif //STMFC_GUI_HPP
