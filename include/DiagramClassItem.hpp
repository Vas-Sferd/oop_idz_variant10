#ifndef DIAGRAMCLASSITEM_H
#define DIAGRAMCLASSITEM_H

#include <pch.hpp>

class MovableButton : public wxButton
    {
        bool dragging;
        int x,y;
        wxPanel* parent;

    public:

        MovableButton(wxPanel* parent) : wxButton(parent, wxID_ANY, wxT("Drag me around"))
        {
            MovableButton::parent = parent;
            dragging = false;
        }

        void onMouseDown(wxMouseEvent& evt)
        {
            CaptureMouse();
            x = evt.GetX();
            y = evt.GetY();
            dragging=true;
            //evt.Veto();
        }
        void onMouseUp(wxMouseEvent& evt)
        {
            ReleaseMouse();
            dragging=false;
        }
        void onMove(wxMouseEvent& evt)
        {
            if(dragging)
            {
                wxPoint mouseOnScreen = wxGetMousePosition();
                int newx = mouseOnScreen.x - x;
                int newy = mouseOnScreen.y - y;
                this->Move( parent->ScreenToClient( wxPoint(newx, newy) ) );
            }
        }

        DECLARE_EVENT_TABLE()
    };

BEGIN_EVENT_TABLE(MovableButton,wxButton)
EVT_LEFT_DOWN(MovableButton::onMouseDown)
EVT_LEFT_UP(MovableButton::onMouseUp)
EVT_MOTION(MovableButton::onMove)
END_EVENT_TABLE()

#endif // DIAGRAMCLASSITEM_H
