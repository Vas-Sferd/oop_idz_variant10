#ifndef DIAGRAMFIELD_HPP
#define DIAGRAMFIELD_HPP

#include "pch.hpp"


class DiagramField : public wxPanel
{
public:
    DiagramField(wxFrame* parent) :
        wxPanel(parent)
    {
    }

    void paintEvent(wxPaintEvent & evt)
    {
        wxPaintDC dc(this);
        render(dc);
    }
    void paintNow()
    {
        wxClientDC dc(this);
        render(dc);
    }

    void render(wxDC &dc)
    {
        // draw some text
        dc.DrawText(wxT("Testing"), 40, 60);

        // draw a circle
        dc.SetBrush(*wxGREEN_BRUSH); // green filling
        dc.SetPen( wxPen( wxColor(255,0,0), 5 ) ); // 5-pixels-thick red outline
        dc.DrawCircle( wxPoint(200,100), 25 /* radius */ );

        // draw a rectangle
        dc.SetBrush(*wxBLUE_BRUSH); // blue filling
        dc.SetPen( wxPen( wxColor(255,175,175), 10 ) ); // 10-pixels-thick pink outline
        dc.DrawRectangle( 300, 100, 400, 200 );

        // draw a line
        dc.SetPen( wxPen( wxColor(0,0,0), 3 ) ); // black line, 3 pixels thick
        dc.DrawLine( 300, 100, 700, 300 ); // draw line across the rectangle

        // Look at the wxDC docs to learn how to draw other stuff
    }

    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */

    DECLARE_EVENT_TABLE()
};

#endif // DIAGRAMFIELD_HPP
