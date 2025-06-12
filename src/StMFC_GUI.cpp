#include "StMFC_GUI.hpp"
#include <string>

bool StMFC_GUI::OnInit() {
    wxInitAllImageHandlers();
    mv = new MainWindow();
    mv->Show(true);
    return true;
}

MainWindow::MainWindow() :
        wxFrame(nullptr, wxID_ANY, "StMFC",
                wxPoint(100, 500), wxSize(220, 150),
                (wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP)) {
    wxFileName f(wxStandardPaths::Get().GetExecutablePath());
    this->appPath = f.GetPath().ToStdString();
    TSFP = new TheSingleOneFuckingPanel(this, this->appPath);
    TSFP->DragAcceptFiles(true);
    this->SetClientSize(200, 100);
    icon.LoadFile(this->appPath + "/StMFC_logo.png", wxBITMAP_TYPE_PNG);
    this->SetIcon(icon);
    Bind(wxEVT_CLOSE_WINDOW, &MainWindow::OnClose, this);

    std::ifstream ifs;
    ifs.open(appPath + "/config.ini");
    if (ifs.is_open()) {
        int x, y;
        ifs >> x;
        ifs >> y;
        this->SetPosition(wxPoint(x, y));
    }
    ifs.close();
}

void MainWindow::OnClose(wxCloseEvent &event) {
    std::ofstream ofs;
    ofs.open(appPath + "/config.ini");
    ofs << std::to_string(this->GetPosition().x) << "\n" << std::to_string(this->GetPosition().y);
    ofs.close();
    TSFP->Destroy();
    this->Destroy();
}

TheSingleOneFuckingPanel::TheSingleOneFuckingPanel(wxFrame *parent, const std::string &appPath) : wxPanel(parent) {
    interfaceBitmap.LoadFile(wxString(appPath + "/StMFC_interface.png"), wxBITMAP_TYPE_PNG);
}

void TheSingleOneFuckingPanel::paintEvent(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    render(dc);
}

void TheSingleOneFuckingPanel::render(wxDC &dc) {
    dc.DrawBitmap(interfaceBitmap, 0, 0);
}

void TheSingleOneFuckingPanel::DragNDrop(wxDropFilesEvent &event) {
    int done = 0;
    for (int i = 0; i < event.GetNumberOfFiles(); i++) {
        try {
            convert(event.GetFiles()[i].ToStdString());
            done++;
        } catch (FileNotOpenedException &e) {
            wxMessageBox(e.what(), "StMFC - Error", wxOK | wxICON_ERROR);
        } catch (FileNotCreatedException &e) {
            wxMessageBox(e.what(), "StMFC - Error", wxOK | wxICON_ERROR);
        } catch (NotStereoException &e) {
            wxMessageBox(e.what(), "StMFC - Error", wxOK | wxICON_ERROR);
        }
    }
}


BEGIN_EVENT_TABLE(TheSingleOneFuckingPanel, wxPanel)
                EVT_PAINT(TheSingleOneFuckingPanel::paintEvent)
                EVT_DROP_FILES(TheSingleOneFuckingPanel::DragNDrop)
END_EVENT_TABLE()

IMPLEMENT_APP_NO_MAIN(StMFC_GUI)
