#include <pch.hpp>
#include <DiagramField.hpp>
#include <DiagramClassItem.hpp>

class MyApp: public wxApp {
    bool OnInit() {
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));

        drawPane = new DiagramField( (wxFrame*) frame );
        sizer->Add(drawPane, 1, wxEXPAND);


        frame->SetSizer(sizer);
        frame->SetAutoLayout(true);

        frame->Show();
        return true;
    }

    wxFrame *frame;
    DiagramField * drawPane;
public:

};

IMPLEMENT_APP(MyApp)
BEGIN_EVENT_TABLE(DiagramField, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

// catch paint events
EVT_PAINT(DiagramField::paintEvent)

END_EVENT_TABLE()
