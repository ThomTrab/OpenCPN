/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  GRIB GUI Definition
 * Author:   Thomas Trabattoni
 *
 ***************************************************************************
 *   Copyright (C) 2021 by Thomas Trabattoni   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 *
 */

#include "GribUIDialogBase.h"

///////////////////////////////////////////////////////////////////////////

// Plugin Main window
GRIBUICtrlBarBase::GRIBUICtrlBarBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    wxSizerFlags m_sfVCentered(1);
	m_sfVCentered.Expand()
                  .Border(wxALL, 5)
                  .Align(wxLEFT)
                  .Align(wxALIGN_CENTER_VERTICAL)
                  .Proportion(1);

#ifdef __OCPN__ANDROID__
    const bool m_bcompact = true;
#else
    const bool m_bcompact = false;
#endif

    if(m_bcompact){
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

        m_fgCtrlBarSizer = new wxFlexGridSizer(0, 1, 0, 0 );
        m_fgCtrlBarSizer->AddGrowableCol( 0 );
        m_fgCtrlBarSizer->SetFlexibleDirection( wxHORIZONTAL );
        m_fgCtrlBarSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );

	wxBoxSizer *mainBox = new wxBoxSizer(wxVERTICAL);
        m_fgCtrlBarSizer->Add( mainBox, 1, wxEXPAND, 0 );


	wxBoxSizer *fgSizer50 = new wxBoxSizer(wxHORIZONTAL);
        mainBox->Add( fgSizer50, 0, wxEXPAND, 5 );

	m_bpPrev = new wxBitmapButton( this, ID_BTNPREV, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpPrev->SetToolTip( _("Previous") );

	fgSizer50->Add( m_bpPrev, 0, wxALL, 1 );

	wxArrayString m_cRecordForecastChoices;
        m_cRecordForecastChoices.Add(_T("Item0"));
	m_cRecordForecast = new wxChoice( this, ID_CTRLTIME, wxDefaultPosition, wxDefaultSize, m_cRecordForecastChoices, 0 );
	m_cRecordForecast->SetSelection( 0 );
	fgSizer50->Add( m_cRecordForecast, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	m_bpNext = new wxBitmapButton( this, ID_BTNNEXT, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpNext->SetToolTip( _("Next") );

	fgSizer50->Add( m_bpNext, 0, wxALL, 1 );




        wxBoxSizer *fgSizer51 = new wxBoxSizer(wxHORIZONTAL);
        mainBox->Add( fgSizer51, 0, wxEXPAND, 5 );




	m_bpAltitude = new wxBitmapButton( this, ID_CTRLALTITUDE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpAltitude->SetToolTip( _("Select geoptential altitude") );

        fgSizer51->Add( m_bpAltitude, 0, wxALL, 1 );

	m_bpNow = new wxBitmapButton( this, ID_BTNNOW, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpNow->SetToolTip( _("Now") );

        fgSizer51->Add( m_bpNow, 0, wxALL, 1 );

	m_bpZoomToCenter = new wxBitmapButton( this, ID_BTNZOOMTC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpZoomToCenter->SetToolTip( _("Zoom To Center") );

        fgSizer51->Add( m_bpZoomToCenter, 0, wxALL, 1 );

	m_bpShowCursorData = new wxBitmapButton( this, ID_BTNSHOWCDATA, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        fgSizer51->Add( m_bpShowCursorData, 0, wxALL, 1 );


        fgSizer51->Add( 0, 0, 1, wxEXPAND|wxLEFT|wxRIGHT, 1 );
	m_bpPlay = new wxBitmapButton( this, ID_BTNPLAY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        fgSizer51->Add( m_bpPlay, 0, wxBOTTOM|wxLEFT|wxTOP, 1 );

	m_sTimeline = new wxSlider( this, ID_TIMELINE, 1, 0, 10, wxDefaultPosition, wxSize( 90,-1 ), wxSL_HORIZONTAL );
        fgSizer51->Add( m_sTimeline, 0, wxEXPAND, 1 );

        fgSizer51->Add( 0, 0, 1, wxEXPAND|wxLEFT|wxRIGHT, 1 );

        m_bpOpenFile = NULL;
//         m_bpOpenFile = new wxBitmapButton( this, ID_BTNOPENFILE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
//         m_bpOpenFile->SetToolTip( _("Open a new file") );
//         fgSizer51->Add( m_bpOpenFile, 0, wxALL, 1 );

	m_bpSettings = new wxBitmapButton( this, ID_BTNSETTING, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSettings->SetToolTip( _("Settings") );

        fgSizer51->Add( m_bpSettings, 0, wxALL, 1 );

        m_bpRequest = NULL;

//         m_bpRequest = new wxBitmapButton( this, ID_BTNREQUEST, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
//         fgSizer51->Add( m_bpRequest, 0, wxALL, 1 );

//         wxFlexGridSizer* fgSizer49;
//         fgSizer49 = new wxFlexGridSizer( 0, 1, 0, 0 );
//         fgSizer49->AddGrowableCol( 0 );
//         fgSizer49->SetFlexibleDirection( wxVERTICAL );
//         fgSizer49->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

 	m_fgCDataSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
        m_fgCDataSizer->SetFlexibleDirection( wxVERTICAL );
        m_fgCDataSizer->AddGrowableCol( 0 );
        m_fgCDataSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


 	mainBox->Add( m_fgCDataSizer, 1, wxEXPAND, 5 );



 	m_fgCtrlGrabberSize = new wxFlexGridSizer( 0, 1, 0, 0 );
 	m_fgCtrlGrabberSize->SetFlexibleDirection( wxBOTH );
 	m_fgCtrlGrabberSize->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );




        this->SetSizer( m_fgCtrlBarSizer );
	this->Layout();
        m_fgCtrlBarSizer->Fit( this );
    }
    else{
                this->SetSizeHints( wxDefaultSize, wxDefaultSize );

        m_fgCtrlBarSizer = new wxFlexGridSizer( 1, 2, 0, 0 );
        m_fgCtrlBarSizer->AddGrowableCol( 0 );
        m_fgCtrlBarSizer->SetFlexibleDirection( wxHORIZONTAL );
        m_fgCtrlBarSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );

        wxFlexGridSizer* fgSizer49;
        fgSizer49 = new wxFlexGridSizer( 0, 1, 0, 0 );
        fgSizer49->AddGrowableCol( 0 );
        fgSizer49->SetFlexibleDirection( wxVERTICAL );
        fgSizer49->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

        wxFlexGridSizer* fgSizer50;
        fgSizer50 = new wxFlexGridSizer( 0, 15, 0, 0 );
        fgSizer50->AddGrowableCol( 3 );
        fgSizer50->AddGrowableCol( 7 );
        fgSizer50->AddGrowableCol( 10 );
        fgSizer50->SetFlexibleDirection( wxHORIZONTAL );
        fgSizer50->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

        m_bpPrev = new wxBitmapButton( this, ID_BTNPREV, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpPrev->SetToolTip( _("Previous") );

        fgSizer50->Add( m_bpPrev, 0, wxALL, 1 );

        wxArrayString m_cRecordForecastChoices;
        m_cRecordForecastChoices.Add(_T("Item0"));
        m_cRecordForecast = new wxChoice( this, ID_CTRLTIME, wxDefaultPosition, wxDefaultSize, m_cRecordForecastChoices, 0 );
        m_cRecordForecast->SetSelection( 0 );
        fgSizer50->Add( m_cRecordForecast, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );

        m_bpNext = new wxBitmapButton( this, ID_BTNNEXT, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpNext->SetToolTip( _("Next") );

        fgSizer50->Add( m_bpNext, 0, wxALL, 1 );


        fgSizer50->Add( 0, 0, 1, wxEXPAND|wxLEFT|wxRIGHT, 1 );

        m_bpAltitude = new wxBitmapButton( this, ID_CTRLALTITUDE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpAltitude->SetToolTip( _("Select geoptential altitude") );

        fgSizer50->Add( m_bpAltitude, 0, wxALL, 1 );

        m_bpNow = new wxBitmapButton( this, ID_BTNNOW, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpNow->SetToolTip( _("Now") );

        fgSizer50->Add( m_bpNow, 0, wxALL, 1 );

        m_bpZoomToCenter = new wxBitmapButton( this, ID_BTNZOOMTC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpZoomToCenter->SetToolTip( _("Zoom To Center") );

        fgSizer50->Add( m_bpZoomToCenter, 0, wxALL, 1 );

        m_bpShowCursorData = new wxBitmapButton( this, ID_BTNSHOWCDATA, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        fgSizer50->Add( m_bpShowCursorData, 0, wxALL, 1 );


        fgSizer50->Add( 0, 0, 1, wxEXPAND|wxLEFT|wxRIGHT, 1 );

        m_bpPlay = new wxBitmapButton( this, ID_BTNPLAY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        fgSizer50->Add( m_bpPlay, 0, wxBOTTOM|wxLEFT|wxTOP, 1 );

        m_sTimeline = new wxSlider( this, ID_TIMELINE, 1, 0, 10, wxDefaultPosition, wxSize( 90,-1 ), wxSL_HORIZONTAL );
        fgSizer50->Add( m_sTimeline, 0, wxEXPAND, 1 );


        fgSizer50->Add( 0, 0, 1, wxEXPAND|wxLEFT|wxRIGHT, 1 );

        m_bpOpenFile = new wxBitmapButton( this, ID_BTNOPENFILE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpOpenFile->SetToolTip( _("Open a new file") );

        fgSizer50->Add( m_bpOpenFile, 0, wxALL, 1 );

        m_bpSettings = new wxBitmapButton( this, ID_BTNSETTING, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        m_bpSettings->SetToolTip( _("Settings") );

        fgSizer50->Add( m_bpSettings, 0, wxALL, 1 );

        m_bpRequest = new wxBitmapButton( this, ID_BTNREQUEST, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        fgSizer50->Add( m_bpRequest, 0, wxALL, 1 );


        fgSizer49->Add( fgSizer50, 1, wxEXPAND, 5 );

        m_fgCDataSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
        m_fgCDataSizer->SetFlexibleDirection( wxBOTH );
        m_fgCDataSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


        fgSizer49->Add( m_fgCDataSizer, 1, wxEXPAND, 5 );


        m_fgCtrlBarSizer->Add( fgSizer49, 1, wxEXPAND, 0 );

        m_fgCtrlGrabberSize = new wxFlexGridSizer( 0, 1, 0, 0 );
        m_fgCtrlGrabberSize->SetFlexibleDirection( wxBOTH );
        m_fgCtrlGrabberSize->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


        m_fgCtrlBarSizer->Add( m_fgCtrlGrabberSize, 1, wxEXPAND, 0 );


        this->SetSizer( m_fgCtrlBarSizer );
        this->Layout();
        m_fgCtrlBarSizer->Fit( this );
    }


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GRIBUICtrlBarBase::OnClose ) );
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( GRIBUICtrlBarBase::OnSize ) );

#ifndef __WXQT__
        this->Connect( wxEVT_PAINT, wxPaintEventHandler( GRIBUICtrlBarBase::OnPaint ) );
#endif
	m_bpPrev->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnPrev ), NULL, this );
	m_bpPrev->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_cRecordForecast->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GRIBUICtrlBarBase::OnRecordForecast ), NULL, this );
	m_cRecordForecast->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpNext->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnNext ), NULL, this );
	m_bpNext->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpAltitude->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnAltitude ), NULL, this );
	m_bpAltitude->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpNow->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnNow ), NULL, this );
	m_bpNow->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpZoomToCenter->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnZoomToCenterClick ), NULL, this );
	m_bpZoomToCenter->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpShowCursorData->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnShowCursorData ), NULL, this );
	m_bpShowCursorData->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnPlayStop ), NULL, this );
	m_bpPlay->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_sTimeline->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );

        if(m_bpOpenFile){
            m_bpOpenFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnOpenFile ), NULL, this );
            m_bpOpenFile->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
        }

#ifdef __OCPN__ANDROID__
        m_bpSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnCompositeDialog ), NULL, this );
#else
        m_bpSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnSettings ), NULL, this );
	m_bpSettings->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
#endif

        if(m_bpRequest){
            m_bpRequest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnRequest ), NULL, this );
            m_bpRequest->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
        }
}

GRIBUICtrlBarBase::~GRIBUICtrlBarBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GRIBUICtrlBarBase::OnClose ) );
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GRIBUICtrlBarBase::OnPaint ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GRIBUICtrlBarBase::OnSize ) );
	m_bpPrev->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnPrev ), NULL, this );
	m_bpPrev->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_cRecordForecast->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GRIBUICtrlBarBase::OnRecordForecast ), NULL, this );
	m_cRecordForecast->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpNext->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnNext ), NULL, this );
	m_bpNext->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpAltitude->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnAltitude ), NULL, this );
	m_bpAltitude->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpNow->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnNow ), NULL, this );
	m_bpNow->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpZoomToCenter->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnZoomToCenterClick ), NULL, this );
	m_bpZoomToCenter->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpShowCursorData->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnShowCursorData ), NULL, this );
	m_bpShowCursorData->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_bpPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnPlayStop ), NULL, this );
	m_bpPlay->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );
	m_sTimeline->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GRIBUICtrlBarBase::OnTimeline ), NULL, this );

        if(m_bpOpenFile){
            m_bpOpenFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnOpenFile ), NULL, this );
            m_bpOpenFile->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
        }

	m_bpSettings->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnSettings ), NULL, this );
	m_bpSettings->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );

        if(m_bpRequest){
            m_bpRequest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBUICtrlBarBase::OnRequest ), NULL, this );
            m_bpRequest->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GRIBUICtrlBarBase::OnMouseEvent ), NULL, this );
        }

}

// Undefined
GRIBUICDataBase::GRIBUICDataBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxFlexGridSizer* fgSizer57;
	fgSizer57 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer57->SetFlexibleDirection( wxBOTH );
	fgSizer57->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_fgCdataSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgCdataSizer->SetFlexibleDirection( wxBOTH );
	m_fgCdataSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgSizer57->Add( m_fgCdataSizer, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer57 );
	this->Layout();
	fgSizer57->Fit( this );

	this->Centre( wxBOTH );
}

GRIBUICDataBase::~GRIBUICDataBase()
{
}

// Cursor value window
CursorDataBase::CursorDataBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
    wxSizerFlags m_sfVCentered(1);
	m_sfVCentered.Expand()
                 .Border(wxALL, 5)
                 .Align(wxALIGN_LEFT)
                 .Align(wxALIGN_CENTER_VERTICAL)
                 .Proportion(1);

	m_fgMainSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	//m_fgMainSizer->AddGrowableRow( 1 );
	m_fgMainSizer->SetFlexibleDirection( wxBOTH );
	m_fgMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	m_stTrackingText = new wxStaticText( this,
	                                     wxID_ANY,
                                         _("MyLabel"),
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         0 );
    // No word wrapping. Usefullness ??
	//m_stTrackingText->Wrap( -1 );
	m_fgMainSizer->Add( m_stTrackingText, 0, wxEXPAND|wxLEFT, 5 );

	//Useless additional Sizer
	//wxSizer *sizerRow = new wxBoxSizer(wxHORIZONTAL);
	//sizerRow->SetFlexibleDirection( wxBOTH );
	//sizerRow->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    ////////////////////////////////////////////////////////////////
    // Widgets Definition
    ////////////////////////////////////////////////////////////////

	m_cbWind = new wxCheckBox( this,
                               ID_CB_WIND,
                               _("Wind"),
                               wxDefaultPosition,
                               wxDefaultSize,
                               0 );

	m_tcWindSpeed = new wxTextCtrl( this,
	                                wxID_ANY,
	                                wxEmptyString,
	                                wxDefaultPosition,
	                                wxSize( 70,-1 ),
	                                wxTE_READONLY );

	m_tcWindSpeedBf = new wxTextCtrl( this,
	                                  wxID_ANY,
                                      wxEmptyString,
                                      wxDefaultPosition,
                                      wxSize( 45,-1 ),
                                      wxTE_READONLY );

	m_tcWindDirection = new wxTextCtrl( this,
                                        wxID_ANY,
                                        wxEmptyString,
                                        wxDefaultPosition,
                                        wxSize( 45,-1 ),
                                        wxTE_READONLY );

	m_cbWindGust = new wxCheckBox( this,
	                               ID_CB_WIND_GUSTS,
	                               _("Wind Gust"),
	                               wxDefaultPosition,
	                               wxDefaultSize,
	                               0 );

	m_tcWindGust = new wxTextCtrl( this,
	                               wxID_ANY,
                                   wxEmptyString,
                                   wxDefaultPosition,
                                   wxSize( 70,-1 ),
                                   wxTE_READONLY );

	m_cbPressure = new wxCheckBox( this,
                                   ID_CB_PRESSURE,
                                   _("Pressure"),
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   0 );

	m_tcPressure = new wxTextCtrl( this,
                                   wxID_ANY,
                                   wxEmptyString,
                                   wxDefaultPosition,
                                   wxSize( 300,-1 ),
                                   wxTE_READONLY );
	m_tcPressure->SetToolTip( _("Mean Sea Level Pressure (MSLP)") );
	m_tcPressure->SetMinSize( wxSize( 300,-1 ) );

	m_cbWave = new wxCheckBox( this,
	                           ID_CB_WAVES,
	                           _("Waves"),
	                           wxDefaultPosition,
	                           wxDefaultSize,
	                           0 );

	m_tcWaveHeight = new wxTextCtrl( this,
                                     wxID_ANY,
                                     wxEmptyString,
                                     wxDefaultPosition,
                                     //wxSize( 70,-1 ),
                                     wxSize( -1,-1 ),
                                     wxTE_READONLY );
	m_tcWaveHeight->SetToolTip( _("Significant Wave Height") );

	m_tcWavePeriode = new wxTextCtrl( this,
	                                  wxID_ANY,
	                                  wxEmptyString,
	                                  wxDefaultPosition,
	                                  wxSize( 45,-1 ),
	                                  wxTE_READONLY );
	m_tcWavePeriode->SetToolTip( _("Waves period") );

	m_tcWaveDirection = new wxTextCtrl( this,
	                                    wxID_ANY,
	                                    wxEmptyString,
	                                    wxDefaultPosition,
	                                    wxSize( 45,-1 ),
	                                    wxTE_READONLY );
	m_tcWaveDirection->SetToolTip( _("Waves Direction") );

	m_cbCurrent = new wxCheckBox( this,
	                              ID_CB_CURRENT,
	                              _("Current"),
	                              wxDefaultPosition,
	                              wxDefaultSize,
	                              0 );

	m_tcCurrentVelocity = new wxTextCtrl( this,
	                                      wxID_ANY,
	                                      wxEmptyString,
	                                      wxDefaultPosition,
	                                      wxSize( 70,-1 ),
	                                      wxTE_READONLY );
	m_tcCurrentVelocity->SetToolTip( _("Surface Current Speed") );

	m_tcCurrentDirection = new wxTextCtrl( this,
                                           wxID_ANY,
                                           wxEmptyString,
                                           wxDefaultPosition,
                                           wxSize( 45,-1 ),
                                           wxTE_READONLY );
	m_tcCurrentDirection->SetToolTip( _("Surface Current Direction") );

	m_cbPrecipitation = new wxCheckBox( this,
	                                    ID_CB_RAINFALL,
                                        _("Rainfall"),
                                        wxDefaultPosition,
                                        wxDefaultSize,
                                        0 );

	m_tcPrecipitation = new wxTextCtrl( this,
	                                    wxID_ANY,
	                                    wxEmptyString,
	                                    wxDefaultPosition,
	                                    wxSize( 70,-1 ),
	                                    wxTE_READONLY );
	m_tcPrecipitation->SetToolTip( _("Cumulative Rainfall per Hour") );

	m_cbCloud = new wxCheckBox( this,
                                ID_CB_CLOUD_COVER,
                                _("Cloud Cover"),
                                wxDefaultPosition,
                                wxDefaultSize,
                                0 );

	m_tcCloud = new wxTextCtrl( this,
	                            wxID_ANY,
	                            wxEmptyString,
	                            wxDefaultPosition,
	                            wxSize( 70,-1 ),
	                            wxTE_READONLY );
	m_tcCloud->SetToolTip( _("Cloud Cover") );

	m_cbAirTemperature = new wxCheckBox( this,
	                                     ID_CB_AIR_TEMP,
	                                     _("Air Temp"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize, 0 );

	m_tcAirTemperature = new wxTextCtrl( this,
	                                     wxID_ANY,
	                                     wxEmptyString,
	                                     wxDefaultPosition,
	                                     wxSize( -1,-1 ),
	                                     //wxSize( 70,-1 ),
	                                     wxTE_READONLY );

	m_cbSeaTemperature = new wxCheckBox( this,
	                                     ID_CB_SEA_TEMP,
	                                     _("Sea Temp"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize,
	                                     0 );

	m_tcSeaTemperature = new wxTextCtrl( this,
	                                     wxID_ANY,
                                         wxEmptyString,
                                         wxDefaultPosition,
                                         wxSize( 70,-1 ),
                                         wxTE_READONLY );
	m_tcSeaTemperature->SetToolTip( _("Sea or Air Temperature at Surface Level") );

	m_cbCAPE = new wxCheckBox( this,
	                           ID_CB_CAPE, _("CAPE"),
	                           wxDefaultPosition,
	                           wxDefaultSize,
	                           0 );

	m_tcCAPE = new wxTextCtrl( this,
                               wxID_ANY,
                               wxEmptyString,
                               wxDefaultPosition,
                               wxSize( 70,-1 ),
                               wxTE_READONLY );
	m_tcCAPE->SetToolTip( _("Convective Available Potential Energy") );

	m_cbReflC = new wxCheckBox( this,
	                            ID_CB_COMP_REFL,
	                            _("Comp. Refl."),
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            0 );

	m_tcReflC = new wxTextCtrl( this,
	                            wxID_ANY,
                                wxEmptyString,
                                wxPoint( -1,-1 ),
                                wxSize( 70,-1 ),
                                wxTE_READONLY );
	m_tcReflC->SetToolTip( _("Composite Reflectivity") );

	m_cbAltitude = new wxCheckBox( this,
                                   wxID_ANY,
                                   _("Altitude"),
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   0 );
	m_cbAltitude->SetValue(true);
	m_cbAltitude->Enable( false );

	m_tcAltitude = new wxTextCtrl( this,
                                   wxID_ANY,
                                   wxEmptyString,
                                   wxDefaultPosition,
                                   wxSize( -1,-1 ),
                                   wxTE_READONLY );
	m_tcAltitude->SetMinSize( wxSize( 70,-1 ) );

	m_cbTemp = new wxCheckBox( this,
                               wxID_ANY,
                               _("Temp."),
                               wxDefaultPosition,
                               wxDefaultSize,
                               0 );
	m_cbTemp->SetValue(true);
	m_cbTemp->Enable( false );

	m_tcTemp = new wxTextCtrl( this,
	                           wxID_ANY,
	                           wxEmptyString,
	                           wxDefaultPosition,
	                           wxDefaultSize,
	                           wxTE_READONLY );
	m_tcTemp->SetMinSize( wxSize( 70,-1 ) );

	m_cbRelHumid = new wxCheckBox( this,
                                   wxID_ANY,
                                   _("Relat. Hum."),
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   0 );
	m_cbRelHumid->SetValue(true);
	m_cbRelHumid->Enable( false );

	m_tcRelHumid = new wxTextCtrl( this,
	                               wxID_ANY,
	                               wxEmptyString,
	                               wxDefaultPosition,
	                               wxDefaultSize,
	                               wxTE_READONLY );
	m_tcRelHumid->SetMinSize( wxSize( 70,-1 ) );


    ////////////////////////////////////////////////////////////////
    // Layout Definition
    ////////////////////////////////////////////////////////////////

    //Sizer for all displayed value
	m_fgTrackingControls = new wxFlexGridSizer( 0, 8, 0, 0 );
	m_fgTrackingControls->SetFlexibleDirection( wxBOTH );
	m_fgTrackingControls->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_fgTrackingControls->Add( m_cbWind,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWindSpeed,
                               m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWindSpeedBf,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWindDirection,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_cbWindGust,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWindGust,
                               m_sfVCentered);
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 1 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 1 ); //Spacer

	m_fgTrackingControls->Add( m_cbPressure,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcPressure,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbWave,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWaveHeight,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWavePeriode,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcWaveDirection,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_cbCurrent,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcCurrentVelocity,
                               m_sfVCentered );
	m_fgTrackingControls->Add( m_tcCurrentDirection,
                               m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbPrecipitation,
                               m_sfVCentered );
	m_fgTrackingControls->Add( m_tcPrecipitation,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 1 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbCloud,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcCloud,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 1 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbAirTemperature,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcAirTemperature,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 1 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbSeaTemperature,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcSeaTemperature,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTrackingControls->Add( m_cbCAPE,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcCAPE,
	                           m_sfVCentered );
    m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( m_cbReflC,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcReflC,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( m_cbAltitude,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcAltitude,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( m_cbTemp,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcTemp,
                               m_sfVCentered );
	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( 0, 0, 1, wxEXPAND, 5 );//Spacer

	m_fgTrackingControls->Add( m_cbRelHumid,
	                           m_sfVCentered );
	m_fgTrackingControls->Add( m_tcRelHumid,
	                           m_sfVCentered );

	m_fgMainSizer->Add( m_fgTrackingControls, 1, wxEXPAND, 1 );


	this->SetSizer( m_fgMainSizer );
	this->Layout();
	m_fgMainSizer->Fit( this );

	// Connect Events
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	m_stTrackingText->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_MOTION, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_cbWind->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWind->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbWindGust->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWindGust->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbPressure->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbPressure->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbWave->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWave->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCurrent->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCurrent->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbPrecipitation->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbPrecipitation->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCloud->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCloud->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbAirTemperature->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbAirTemperature->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbSeaTemperature->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbSeaTemperature->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCAPE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCAPE->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbReflC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbReflC->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );

}

CursorDataBase::~CursorDataBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	this->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( CursorDataBase::OnMouseEvent ) );
	m_stTrackingText->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_MOTION, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_stTrackingText->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( CursorDataBase::OnMouseEvent ), NULL, this );
	m_cbWind->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWind->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbWindGust->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWindGust->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbPressure->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbPressure->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbWave->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbWave->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCurrent->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCurrent->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbPrecipitation->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbPrecipitation->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCloud->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCloud->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbAirTemperature->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbAirTemperature->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbSeaTemperature->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbSeaTemperature->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbCAPE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbCAPE->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );
	m_cbReflC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CursorDataBase::OnCBAny ), NULL, this );
	m_cbReflC->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CursorDataBase::OnMenuCallBack ), NULL, this );

}

// Settings Window (accessible from the plugin)
GribSettingsDialogBase::GribSettingsDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //////////////////////////////////////////////////////////////////////
    // SizerFlags
    //////////////////////////////////////////////////////////////////////
	m_sfVCentered.Border(wxALL, 5)
	             .Align(wxALIGN_LEFT)
	             .Align(wxALIGN_CENTER_VERTICAL)
	             .Proportion(1);

	m_sfExpanded.Border(wxALL, 5)
	            .Expand()
	            .Proportion(1);

	m_sfTop.Border(wxALL, 5)
	       .Align(wxALIGN_LEFT)
	       .Align(wxALIGN_TOP)
	       .Proportion(1);

	m_sfSizers.Expand()
              .Border(wxALL, 5)
              .Proportion(1);

	m_sfSubSizers.Expand()
                 .Proportion(1);

    //////////////////////////////////////////////////////////////////////
    // Sizers - Sub-Sizers Init
    //////////////////////////////////////////////////////////////////////
	this->SetSizeHints( wxDefaultSize, wxSize( -1,-1 ) );

	wxFlexGridSizer* m_fgMainSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgMainSizer->SetFlexibleDirection( wxBOTH );
	m_fgMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_nSettingsBook = new wxNotebook( this,
                                      wxID_ANY,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      0 );

	wxScrolledWindow* m_scSetDataPanel = new wxScrolledWindow( m_nSettingsBook,
	                                                           wxID_ANY,
	                                                           wxDefaultPosition,
	                                                           wxDefaultSize,
	                                                           wxHSCROLL|wxVSCROLL );
	m_scSetDataPanel->SetScrollRate( 5, 5 );

    //////////////////////////////////////////////////////////////////////
    // m_scSetDataPanel - Sub-Sizers Init
    //////////////////////////////////////////////////////////////////////

	m_fgSetDataSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSetDataSizer->AddGrowableCol( 0 );
	m_fgSetDataSizer->AddGrowableRow( 1 );
	m_fgSetDataSizer->SetFlexibleDirection( wxBOTH );
	m_fgSetDataSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbDataDisplay = new wxStaticBoxSizer( new wxStaticBox( m_scSetDataPanel,
	                                                                           wxID_ANY,
	                                                                           _("Data Display Options") ),
	                                                                           wxVERTICAL );;

	wxFlexGridSizer* m_fgOptions = new wxFlexGridSizer( 0, 3, 0, 0 );;
	m_fgOptions->SetFlexibleDirection( wxBOTH );
	m_fgOptions->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	m_fgBarbedData1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgBarbedData1->SetFlexibleDirection( wxBOTH );
	m_fgBarbedData1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgBarbedSpacing = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgBarbedSpacing->SetFlexibleDirection( wxBOTH );
	m_fgBarbedSpacing->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_fgBarbedData2 = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgBarbedData2->SetFlexibleDirection( wxBOTH );
	m_fgBarbedData2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    m_fgBarbedData2->AddGrowableRow( 0 );
	m_fgBarbedData2->AddGrowableRow( 1 );


    m_fIsoBarSpacing = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fIsoBarSpacing->SetFlexibleDirection( wxBOTH );
	m_fIsoBarSpacing->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    m_fIsoBarSpacing->AddGrowableRow( 0 );
    m_fIsoBarSpacing->AddGrowableCol( 0 );

	m_fIsoBarVisibility = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fIsoBarVisibility->SetFlexibleDirection( wxBOTH );
	m_fIsoBarVisibility->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    m_fIsoBarVisibility->AddGrowableRow( 0 );
    m_fIsoBarVisibility->AddGrowableCol( 0 );

	m_fgDirArrData1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgDirArrData1->SetFlexibleDirection( wxBOTH );
	m_fgDirArrData1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgDirArrSpacing = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgDirArrSpacing->SetFlexibleDirection( wxBOTH );
	m_fgDirArrSpacing->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_fgDirArrData2 = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgDirArrData2->SetFlexibleDirection( wxBOTH );
	m_fgDirArrData2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_fgNumData1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgNumData1->SetFlexibleDirection( wxBOTH );
	m_fgNumData1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbTransparency;
	m_sbTransparency = new wxStaticBoxSizer( new wxStaticBox( m_scSetDataPanel,
	                                                          wxID_ANY,
	                                                          _("Transparency for all Overlay Maps") ),
	                                                          wxVERTICAL );

	wxFlexGridSizer* m_fgTransparency;
	m_fgTransparency = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgTransparency->SetFlexibleDirection( wxBOTH );
	m_fgTransparency->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    //////////////////////////////////////////////////////////////////
    // m_scSetDataPanel - Widgets definitions
    //////////////////////////////////////////////////////////////////

	wxArrayString m_cDataTypeChoices;
        m_cDataTypeChoices.Add(_T("Item0"));
	m_cDataType = new wxChoice( m_scSetDataPanel,
	                            wxID_ANY,
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            m_cDataTypeChoices,
	                            0 );
	m_cDataType->SetSelection( 0 );

	wxStaticText* m_stUnits = new wxStaticText( m_scSetDataPanel,
	                                            wxID_ANY,
	                                            _("Units"),
	                                            wxDefaultPosition,
	                                            wxDefaultSize,
	                                            0 );
	//m_stUnits->Wrap( -1 );
	//m_stUnits->SetMinSize( wxSize( 110,-1 ) );

	wxArrayString m_cDataUnitsChoices;
        m_cDataUnitsChoices.Add(_T("Item0"));
	m_cDataUnits = new wxChoice( m_scSetDataPanel,
	                             wxID_ANY,
                                 wxDefaultPosition,
                                 wxDefaultSize,
                                 m_cDataUnitsChoices,
                                 0 );
	m_cDataUnits->SetSelection( 0 );

	m_cbBarbedArrows = new wxCheckBox( m_scSetDataPanel,
	                                   wxID_ANY,
	                                   _("Barbed Arrows"),
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );

	wxString m_cBarbedColoursChoices[] = { _("Default Colour"),
	                                       _("Controlled Colours") };
	int m_cBarbedColoursNChoices = sizeof( m_cBarbedColoursChoices ) / sizeof( wxString );
	m_cBarbedColours = new wxChoice( m_scSetDataPanel,
                                     wxID_ANY,
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     m_cBarbedColoursNChoices,
                                     m_cBarbedColoursChoices,
                                     0 );
	m_cBarbedColours->SetSelection( 0 );

	wxStaticText* m_stSpacing = new wxStaticText( m_scSetDataPanel,
	                                              wxID_ANY,
	                                              _("Spacing(pixels)"),
	                                              wxDefaultPosition,
	                                              wxDefaultSize,
	                                              0 );

	m_cBarbArrFixSpac = new wxCheckBox( m_scSetDataPanel,
	                                    BARBFIXSPACING,
	                                    _("Fixed"),
	                                    wxDefaultPosition,
	                                    wxDefaultSize,
	                                    0 );
	m_stSpacing->Wrap( -1 );

	m_cBarbArrMinSpac = new wxCheckBox( m_scSetDataPanel,
                                        BARBMINSPACING,
                                        _("Minimum"),
                                        wxDefaultPosition,
                                        wxDefaultSize,
                                        0 );
	m_cBarbedVisibility = new wxCheckBox( m_scSetDataPanel,
	                                      wxID_ANY,
	                                      _("Always visible"),
	                                      wxDefaultPosition,
	                                      wxDefaultSize,
	                                      0 );
	m_sBarbArrSpacing = new wxSpinCtrl( m_scSetDataPanel,
	                                    wxID_ANY,
                                        wxEmptyString,
                                        wxDefaultPosition,
                                        wxDefaultSize,
                                        wxSP_ARROW_KEYS,
                                        30,
                                        100,
                                        30 );
	m_cbIsoBars = new wxCheckBox( m_scSetDataPanel,
	                              wxID_ANY,
	                              _("IsoBars"),
	                              wxDefaultPosition,
	                              wxDefaultSize,
	                              0 );
	m_tIsoBarSpacing = new wxStaticText( m_scSetDataPanel,
	                                     wxID_ANY,
	                                     _("Spacing"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize,
	                                     0 );
	m_tIsoBarSpacing->Wrap( -1 );

	m_sIsoBarSpacing = new wxSpinCtrl( m_scSetDataPanel,
                                       wxID_ANY, wxEmptyString,
                                       wxDefaultPosition,
                                       wxDefaultSize,
                                       wxSP_ARROW_KEYS,
                                       1,
                                       1000,
                                       1 );
	m_sIsoBarVisibility = new wxCheckBox( m_scSetDataPanel,
	                                      wxID_ANY,
	                                      _("Always visible"),
	                                      wxDefaultPosition,
	                                      wxDefaultSize,
	                                      0 );
	m_cbAbbrIsoBarsNumbers = new wxCheckBox( m_scSetDataPanel,
	                                         wxID_ANY,
	                                         _("Abbreviated Numbers"),
	                                         wxDefaultPosition,
	                                         wxDefaultSize,
	                                         0 );
	m_cbDirectionArrows = new wxCheckBox( m_scSetDataPanel,
	                                      wxID_ANY,
	                                      _("Direction Arrows"),
	                                      wxDefaultPosition,
	                                      wxDefaultSize,
	                                      0 );
	wxString m_cDirectionArrowFormChoices[] = { _("Single Arrow"),
	                                            _("Double Arrow"),
	                                            _("Proportional Arrow") };
	int m_cDirectionArrowFormNChoices = sizeof( m_cDirectionArrowFormChoices ) / sizeof( wxString );
	m_cDirectionArrowForm = new wxChoice( m_scSetDataPanel,
	                                      wxID_ANY,
	                                      wxDefaultPosition,
	                                      wxDefaultSize,
	                                      m_cDirectionArrowFormNChoices,
	                                      m_cDirectionArrowFormChoices,
	                                      0 );
	m_cDirectionArrowForm->SetSelection( 1 );

	wxStaticText* m_stDirArrSpacing = new wxStaticText( m_scSetDataPanel,
                                                        wxID_ANY,
                                                        _("Spacing(pixels)"),
                                                        wxDefaultPosition,
                                                        wxDefaultSize,
                                                        0 );
	m_stDirArrSpacing->Wrap( -1 );

	m_cDirArrFixSpac = new wxCheckBox( m_scSetDataPanel,
	                                   DIRFIXSPACING,
	                                   _("Fixed"),
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );
	m_cDirArrMinSpac = new wxCheckBox( m_scSetDataPanel,
	                                   DIRMINSPACING,
	                                   _("Minimum"),
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );
	wxString m_cDirectionArrowSizeChoices[] = { _("Default Size"),
	                                            _("Small Size") };
	int m_cDirectionArrowSizeNChoices = sizeof( m_cDirectionArrowSizeChoices ) / sizeof( wxString );
	m_cDirectionArrowSize = new wxChoice( m_scSetDataPanel,
                                          wxID_ANY,
                                          wxDefaultPosition,
                                          wxDefaultSize,
                                          m_cDirectionArrowSizeNChoices,
                                          m_cDirectionArrowSizeChoices,
                                          0 );
	m_cDirectionArrowSize->SetSelection( 0 );

	m_sDirArrSpacing = new wxSpinCtrl( m_scSetDataPanel,
	                                   wxID_ANY,
                                       wxEmptyString,
                                       wxDefaultPosition,
                                       wxDefaultSize,
                                       wxSP_ARROW_KEYS,
                                       30,
                                       100,
                                       30 );
	m_cbOverlayMap = new wxCheckBox( m_scSetDataPanel,
	                                 wxID_ANY,
	                                 _("OverlayMap"),
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 0 );
	m_tOverlayColors = new wxStaticText( m_scSetDataPanel,
	                                     wxID_ANY,
	                                     _("Color scheme"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize,
	                                     0 );
	m_tOverlayColors->Wrap( -1 );

	wxString m_cOverlayColorsChoices[] = { _("Generic"),
	                                       _("Wind"),
	                                       _("Air Temp"),
	                                       _("Sea Temp"),
	                                       _("Rainfall"),
	                                       _("Cloud Cover"),
	                                       _("Current"),
	                                       _("CAPE") };
	int m_cOverlayColorsNChoices = sizeof( m_cOverlayColorsChoices ) / sizeof( wxString );
	m_cOverlayColors = new wxChoice( m_scSetDataPanel,
                                     wxID_ANY,
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     m_cOverlayColorsNChoices,
                                     m_cOverlayColorsChoices,
                                     0 );
	m_cOverlayColors->SetSelection( 0 );

	m_cbNumbers = new wxCheckBox( m_scSetDataPanel,
	                              wxID_ANY,
	                              _("Numbers"),
	                              wxDefaultPosition,
	                              wxDefaultSize,
	                              0 );
	wxStaticText* m_tNumbersSpacing = new wxStaticText( m_scSetDataPanel,
	                                  wxID_ANY,
	                                  _("Spacing(pixels)"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );
	m_tNumbersSpacing->Wrap( -1 );

	m_cNumFixSpac = new wxCheckBox( m_scSetDataPanel,
	                                NUMFIXSPACING,
	                                _("Fixed"),
	                                wxDefaultPosition,
	                                wxDefaultSize,
	                                0 );
	m_cNumMinSpac = new wxCheckBox( m_scSetDataPanel,
	                                NUMMINSPACING,
	                                _("Minimum"),
	                                wxDefaultPosition,
	                                wxDefaultSize,
	                                0 );
	m_sNumbersSpacing = new wxSpinCtrl( m_scSetDataPanel,
	                                    wxID_ANY,
	                                    wxEmptyString,
	                                    wxDefaultPosition,
	                                    wxDefaultSize,
	                                    wxSP_ARROW_KEYS,
	                                    30,
	                                    100,
	                                    50 );
	m_cbParticles = new wxCheckBox( m_scSetDataPanel,
	                                wxID_ANY,
	                                _("Particle Map"),
	                                wxDefaultPosition,
	                                wxDefaultSize,
	                                0 );
	m_ctParticles = new wxStaticText( m_scSetDataPanel,
	                                  wxID_ANY,
	                                  _("Density"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );
	m_ctParticles->Wrap( -1 );

#if defined(__WXOSX__) && !wxCHECK_VERSION(3, 1, 0)
    m_sParticleDensity = new wxSlider( m_scSetDataPanel,
                                       wxID_ANY,
                                       5,
                                       1,
                                       10,
                                       wxDefaultPosition,
                                       wxDefaultSize,
                                       wxSL_BOTTOM|wxSL_HORIZONTAL );
#else
	m_sParticleDensity = new wxSlider( m_scSetDataPanel,
	                                   wxID_ANY,
	                                   5,
	                                   1,
	                                   10,
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   wxSL_BOTTOM|wxSL_HORIZONTAL|wxSL_LABELS );
#endif

	m_stOverlayTrans = new wxStaticText( m_scSetDataPanel,
                                         wxID_ANY,
                                         _("Overlay Transparency (%)"),
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         0 );
	m_stOverlayTrans->Wrap( -1 );

	m_sTransparency = new wxSlider( m_scSetDataPanel,
	                                wxID_ANY,
                                    50,
                                    0,
                                    100,
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    wxSL_BOTTOM|wxSL_HORIZONTAL|wxSL_LABELS );
	m_sTransparency->SetMinSize( wxSize( 250,-1 ) );

    //////////////////////////////////////////////////////////////////////
    //m_scSetDataPanel - Layout definition
    //////////////////////////////////////////////////////////////////////

    //m_fgOptions
	m_fgOptions->Add( m_cDataType,
	                  m_sfExpanded );
	m_fgOptions->Add( m_stUnits,
	                  m_sfVCentered );
	m_fgOptions->Add( m_cDataUnits,
	                  m_sfExpanded);
	m_fgOptions->Add( m_cbBarbedArrows,
                      m_sfTop);
    //m_fgBarbedData1
	m_fgBarbedData1->Add( m_cBarbedColours,
	                      m_sfExpanded);
	//m_fgBarbedSpacing
	m_fgBarbedSpacing->Add( m_stSpacing,
	                        m_sfVCentered);
	m_fgBarbedSpacing->Add( m_cBarbArrFixSpac,
	                        0,
	                        wxALIGN_TOP|wxTOP,
	                        5);
	m_fgBarbedSpacing->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgBarbedSpacing->Add( m_cBarbArrMinSpac,
	                        0,
	                        wxALIGN_TOP,
	                        5);
	//END m_fgBarbedSpacing
	m_fgBarbedData1->Add( m_fgBarbedSpacing,
	                      m_sfSubSizers );
    //END m_fgBarbedData1
	m_fgOptions->Add( m_fgBarbedData1,
	                  m_sfSubSizers );
    //fgBarbedData2
	m_fgBarbedData2->Add( m_cBarbedVisibility,
                          m_sfVCentered );
	m_fgBarbedData2->Add( m_sBarbArrSpacing,
	                      m_sfVCentered );
    //END fgBarbedData2
	m_fgOptions->Add( m_fgBarbedData2,
	                  m_sfSubSizers );
	m_fgOptions->Add( m_cbIsoBars,
	                  m_sfVCentered );
    //m_fIsoBarSpacing
	m_fIsoBarSpacing->Add( m_tIsoBarSpacing,
	                       m_sfVCentered );
	m_fIsoBarSpacing->Add( m_sIsoBarSpacing,
                           m_sfExpanded );
    //END m_fIsoBarSpacing
	m_fgOptions->Add( m_fIsoBarSpacing,
                      m_sfSubSizers );
    //m_fIsoBarVisibility
	m_fIsoBarVisibility->Add( m_sIsoBarVisibility,
	                          m_sfVCentered );
    //END m_fIsoBarVisibility
	m_fgOptions->Add( m_fIsoBarVisibility,
	                  m_sfSubSizers );
	m_fgOptions->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgOptions->Add( m_cbAbbrIsoBarsNumbers,
                      m_sfVCentered );
	m_fgOptions->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgOptions->Add( m_cbDirectionArrows,
	                  m_sfTop );
    //m_fgDirArrData1
	m_fgDirArrData1->Add( m_cDirectionArrowForm,
	                      m_sfExpanded );
    //m_fgDirArrSpacing
	m_fgDirArrSpacing->Add( m_stDirArrSpacing,
	                        m_sfVCentered );
	m_fgDirArrSpacing->Add( m_cDirArrFixSpac,
                            0,
                            wxALIGN_TOP|wxTOP,
                            5);
	m_fgDirArrSpacing->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgDirArrSpacing->Add( m_cDirArrMinSpac,
                            0,
                            wxALIGN_TOP|wxBOTTOM,
                            5);
    //END m_fgDirArrSpacing
	m_fgDirArrData1->Add( m_fgDirArrSpacing,
                          m_sfSubSizers );
    //END m_fgDirArrData1
	m_fgOptions->Add( m_fgDirArrData1,
	                  m_sfSubSizers );
    //m_fgDirArrData2
	m_fgDirArrData2->Add( m_cDirectionArrowSize,
	                      m_sfExpanded );
	m_fgDirArrData2->Add( m_sDirArrSpacing,
                          m_sfExpanded);
    //END m_fgDirArrData2
	m_fgOptions->Add( m_fgDirArrData2,
	                  m_sfSubSizers );
	m_fgOptions->Add( m_cbOverlayMap,
                      m_sfVCentered );
	m_fgOptions->Add( m_tOverlayColors,
                      m_sfVCentered );
    m_fgOptions->Add( m_cOverlayColors,
                      m_sfExpanded );
    m_fgOptions->Add( m_cbNumbers,
                      m_sfTop );
    //m_fgNumData1
	m_fgNumData1->Add( m_tNumbersSpacing,
                       m_sfVCentered);
	m_fgNumData1->Add( m_cNumFixSpac,
                       0,
                       wxALIGN_TOP|wxTOP,
                       5);
	m_fgNumData1->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgNumData1->Add( m_cNumMinSpac,
                       0,
                       wxALIGN_TOP,
                       5);
    //END m_fgNumData1
	m_fgOptions->Add( m_fgNumData1,
	                  m_sfSubSizers );
	m_fgOptions->Add( m_sNumbersSpacing,
                      m_sfVCentered );
	m_fgOptions->Add( m_cbParticles,
	                  m_sfVCentered );
	m_fgOptions->Add( m_ctParticles,
	                  m_sfVCentered );
	m_fgOptions->Add( m_sParticleDensity,
	                  m_sfExpanded );
    //END m_fgOptions
	m_sbDataDisplay->Add( m_fgOptions,
	                      m_sfSizers );
	m_fgSetDataSizer->Add( m_sbDataDisplay,
	                       m_sfSizers );
    m_fgSetDataSizer->Add( 0, 0, 1, wxEXPAND, 5 ); //Spacer

	m_fgTransparency->Add( m_stOverlayTrans,
	                       m_sfVCentered );
	m_fgTransparency->Add( m_sTransparency,
	                       m_sfExpanded );
	m_sbTransparency->Add( m_fgTransparency,
	                       m_sfSubSizers );
	m_fgSetDataSizer->Add( m_sbTransparency,
                           m_sfSizers);

	m_scSetDataPanel->SetSizer( m_fgSetDataSizer );
	m_scSetDataPanel->Layout();
	m_fgSetDataSizer->Fit( m_scSetDataPanel );
	m_nSettingsBook->AddPage( m_scSetDataPanel, _("Data"), false );

    //////////////////////////////////////////////////////////////////////
    // m_scSetPlaybackPanel - Sub-Sizers Init
    //////////////////////////////////////////////////////////////////////

	wxScrolledWindow* m_scSetPlaybackPanel;
	m_scSetPlaybackPanel = new wxScrolledWindow( m_nSettingsBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scSetPlaybackPanel->SetScrollRate( 5, 5 );

	m_fgSetPlaybackSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSetPlaybackSizer->AddGrowableCol( 0 );
	m_fgSetPlaybackSizer->SetFlexibleDirection( wxBOTH );
	m_fgSetPlaybackSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbPlaybackOptions;
	m_sbPlaybackOptions = new wxStaticBoxSizer( new wxStaticBox( m_scSetPlaybackPanel,
                                                                 wxID_ANY,
                                                                 _("Playback Options") ),
                                                                 wxVERTICAL );

    wxFlexGridSizer* m_fgPlaybackOptions;
	m_fgPlaybackOptions = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgPlaybackOptions->SetFlexibleDirection( wxBOTH );
	m_fgPlaybackOptions->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgSlider;
	m_fgSlider = new wxFlexGridSizer( 0, 3, 0, 0 );
	m_fgSlider->SetFlexibleDirection( wxBOTH );
	m_fgSlider->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgLoopMode;
	m_fgLoopMode = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgLoopMode->SetFlexibleDirection( wxBOTH );
	m_fgLoopMode->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgTimeInterval;
	m_fgTimeInterval = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgTimeInterval->SetFlexibleDirection( wxBOTH );
	m_fgTimeInterval->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgTimeInterval->AddGrowableCol( 1 );

    //////////////////////////////////////////////////////////////////
    // m_scSetPlaybackPanel - Widgets definitions
    //////////////////////////////////////////////////////////////////

	wxStaticText* m_stSpeedControl;
	m_stSpeedControl = new wxStaticText( m_scSetPlaybackPanel,
	                                     wxID_ANY,
	                                     _("Speed Control"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize,
	                                     0 );
	m_stSpeedControl->Wrap( -1 );

	wxStaticText* m_stSlow;
	m_stSlow = new wxStaticText( m_scSetPlaybackPanel,
	                             wxID_ANY,
                                 _("Slow"),
                                 wxDefaultPosition,
                                 wxDefaultSize,
                                 0 );
	m_stSlow->Wrap( -1 );

	m_sUpdatesPerSecond = new wxSlider( m_scSetPlaybackPanel,
	                                    wxID_ANY,
	                                    4,
	                                    2,
	                                    12,
	                                    wxDefaultPosition,
	                                    wxSize( -1,-1 ),
	                                    wxSL_HORIZONTAL );

	wxStaticText* m_stFast;
	m_stFast = new wxStaticText( m_scSetPlaybackPanel,
	                             wxID_ANY,
	                             _("Fast"),
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             0 );
	m_stFast->Wrap( -1 );

    m_cLoopMode = new wxCheckBox( m_scSetPlaybackPanel,
                                  wxID_ANY,
                                  _("Loop Mode"),
                                  wxDefaultPosition,
                                  wxDefaultSize,
                                  0 );

	m_stLoopStart = new wxStaticText( m_scSetPlaybackPanel,
	                                  wxID_ANY,
	                                  _("Loop Start"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );
	m_stLoopStart->Wrap( -1 );

	wxString m_cLoopStartPointChoices[] = { _("Top of Grib File"),
	                                        _("Current time forecast") };
	int m_cLoopStartPointNChoices = sizeof( m_cLoopStartPointChoices ) / sizeof( wxString );
	m_cLoopStartPoint = new wxChoice( m_scSetPlaybackPanel,
	                                  wxID_ANY,
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  m_cLoopStartPointNChoices,
	                                  m_cLoopStartPointChoices,
	                                  0 );
	m_cLoopStartPoint->SetSelection( 0 );

	m_cInterpolate = new wxCheckBox( m_scSetPlaybackPanel,
	                                 wxID_ANY,
	                                 _("Interpolate between gribs"),
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 0 );

	m_tSlicesPerUpdate = new wxStaticText( m_scSetPlaybackPanel,
	                                       wxID_ANY,
	                                       _("Time Interval"),
	                                       wxDefaultPosition,
	                                       wxDefaultSize,
	                                       0 );
	m_tSlicesPerUpdate->Wrap( -1 );

	wxArrayString m_sSlicesPerUpdateChoices;
	m_sSlicesPerUpdate = new wxChoice( m_scSetPlaybackPanel,
	                                   wxID_ANY,
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   m_sSlicesPerUpdateChoices,
	                                   0 );
	m_sSlicesPerUpdate->SetSelection( 0 );

    //////////////////////////////////////////////////////////////////////
    // m_scSetPlaybackPanel - Layout definition
    //////////////////////////////////////////////////////////////////////

    //m_fgPlaybackOptions
	m_fgPlaybackOptions->Add( m_stSpeedControl,
	                          m_sfVCentered );
	//m_fgSlider
	m_fgSlider->Add( m_stSlow,
	                 m_sfVCentered );
	m_fgSlider->Add( m_sUpdatesPerSecond,
	                 m_sfExpanded);
	m_fgSlider->Add( m_stFast,
	                 m_sfVCentered );
	//END m_fgSlider
	m_fgPlaybackOptions->Add( m_fgSlider,
	                          0,
	                          wxLEFT|wxRIGHT,
	                          20 );
	m_fgPlaybackOptions->Add( m_cLoopMode,
	                          m_sfVCentered );
	//m_fgLoopMode
	m_fgLoopMode->Add( m_stLoopStart,
	                   m_sfVCentered );
	m_fgLoopMode->Add( m_cLoopStartPoint,
	                   m_sfExpanded );
	//END m_fgLoopMode
	m_fgPlaybackOptions->Add( m_fgLoopMode,
	                          0,
                              wxLEFT|wxRIGHT,
                              20 );
	m_fgPlaybackOptions->Add( m_cInterpolate,
	                          m_sfVCentered );
    //m_fgTimeInterval
	m_fgTimeInterval->Add( m_tSlicesPerUpdate,
	                       m_sfVCentered );
	m_fgTimeInterval->Add( m_sSlicesPerUpdate,
	                       m_sfExpanded );
    //END m_fgTimeInterval
    m_fgPlaybackOptions->Add( m_fgTimeInterval,
                              0,
                              wxLEFT|wxRIGHT,
                              20 );
	m_sbPlaybackOptions->Add( m_fgPlaybackOptions,
	                          m_sfSubSizers );
	m_fgSetPlaybackSizer->Add( m_sbPlaybackOptions,
	                           m_sfSizers );

	m_scSetPlaybackPanel->SetSizer( m_fgSetPlaybackSizer );
	m_scSetPlaybackPanel->Layout();
	m_fgSetPlaybackSizer->Fit( m_scSetPlaybackPanel );
	m_nSettingsBook->AddPage( m_scSetPlaybackPanel, _("Playback"), false );

    //////////////////////////////////////////////////////////////////////
    // m_scSetGuiPanel - Sub-Sizers Init
    //////////////////////////////////////////////////////////////////////
	wxScrolledWindow* m_scSetGuiPanel;
	m_scSetGuiPanel = new wxScrolledWindow( m_nSettingsBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scSetGuiPanel->SetScrollRate( 5, 5 );

	m_fgSetGuiSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSetGuiSizer->AddGrowableCol( 0 );
	m_fgSetGuiSizer->SetFlexibleDirection( wxBOTH );
	m_fgSetGuiSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    //////////////////////////////////////////////////////////////////
    // m_scSetGuiPanel - Widgets definitions
    //////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////
    // m_scSetGuiPanel - Layout definition
    //////////////////////////////////////////////////////////////////////


	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_scSetGuiPanel, wxID_ANY, _("Dialogs Style") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer47;
	fgSizer47 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer47->SetFlexibleDirection( wxBOTH );
	fgSizer47->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_rbCurDataAttaWCap = new wxRadioButton( m_scSetGuiPanel, wxID_ANY, _("Data at cursor dialog is attached to icons bar - with a title/drag bar"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	fgSizer47->Add( m_rbCurDataAttaWCap, 0, wxALL, 5 );

	m_rbCurDataAttaWoCap = new wxRadioButton( m_scSetGuiPanel, wxID_ANY, _("Data at cursor dialog is attached to icons bar - without a title/drag bar"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer47->Add( m_rbCurDataAttaWoCap, 0, wxALL, 5 );

	m_rbCurDataIsolHoriz = new wxRadioButton( m_scSetGuiPanel, wxID_ANY, _("Data at cursor dialog is isolated and displayed horizontally"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer47->Add( m_rbCurDataIsolHoriz, 0, wxALL, 5 );

	m_rbCurDataIsolVertic = new wxRadioButton( m_scSetGuiPanel, wxID_ANY, _("Data at cursor dialog is isolated and displayed vertically"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer47->Add( m_rbCurDataIsolVertic, 0, wxALL, 5 );


	sbSizer9->Add( fgSizer47, 1, wxEXPAND, 5 );


	m_fgSetGuiSizer->Add( sbSizer9, 1, wxEXPAND|wxTOP, 10 );


	m_fgSetGuiSizer->Add( 0, 0, 1, wxALL, 5 );

	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_scSetGuiPanel, wxID_ANY, _("Buttons Visibility") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer52;
	fgSizer52 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer52->SetFlexibleDirection( wxBOTH );
	fgSizer52->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgSizer52->Add( 0, 0, 1, wxEXPAND, 5 );


	fgSizer52->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticText* m_staticText44;
	m_staticText44 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Attached icon bar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	fgSizer52->Add( m_staticText44, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

	wxStaticText* m_staticText45;
	m_staticText45 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Isolated icon bar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	fgSizer52->Add( m_staticText45, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

	m_biAltitude = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biAltitude, 0, wxALL, 2 );

	wxStaticText* m_staticText46;
	m_staticText46 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Geopot. Height Choice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	fgSizer52->Add( m_staticText46, 0, wxALL, 3 );

	wxCheckBox* m_checkBox48;
	m_checkBox48 = new wxCheckBox( m_scSetGuiPanel, AC0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox48, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox49;
	m_checkBox49 = new wxCheckBox( m_scSetGuiPanel, AC1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox49, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biNow = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biNow, 0, wxALL, 3 );

	wxStaticText* m_staticText47;
	m_staticText47 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Now"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText47->Wrap( -1 );
	fgSizer52->Add( m_staticText47, 0, wxALL, 3 );

	wxCheckBox* m_checkBox50;
	m_checkBox50 = new wxCheckBox( m_scSetGuiPanel, NW0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox50, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox51;
	m_checkBox51 = new wxCheckBox( m_scSetGuiPanel, NW1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox51, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biZoomToCenter = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biZoomToCenter, 0, wxALL, 3 );

	wxStaticText* m_staticText48;
	m_staticText48 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Zoom to Center"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	fgSizer52->Add( m_staticText48, 0, wxALL, 3 );

	wxCheckBox* m_checkBox52;
	m_checkBox52 = new wxCheckBox( m_scSetGuiPanel, ZC0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox52, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox53;
	m_checkBox53 = new wxCheckBox( m_scSetGuiPanel, ZC1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox53, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biShowCursorData = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biShowCursorData, 0, wxALL, 3 );

	wxStaticText* m_staticText49;
	m_staticText49 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Show Cursor Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	fgSizer52->Add( m_staticText49, 0, wxALL, 3 );

	wxCheckBox* m_checkBox54;
	m_checkBox54 = new wxCheckBox( m_scSetGuiPanel, SCD0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox54, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox55;
	m_checkBox55 = new wxCheckBox( m_scSetGuiPanel, SCD1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox55, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biPlay = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biPlay, 0, wxALL, 3 );

	wxStaticText* m_staticText50;
	m_staticText50 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Playback"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	fgSizer52->Add( m_staticText50, 0, wxALL, 3 );

	wxCheckBox* m_checkBox56;
	m_checkBox56 = new wxCheckBox( m_scSetGuiPanel, PB0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox56, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox57;
	m_checkBox57 = new wxCheckBox( m_scSetGuiPanel, PB1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox57, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biTimeSlider = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biTimeSlider, 0, wxALL, 3 );

	wxStaticText* m_staticText51;
	m_staticText51 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Time Slider"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer52->Add( m_staticText51, 0, wxALL, 3 );

	wxCheckBox* m_checkBox58;
	m_checkBox58 = new wxCheckBox( m_scSetGuiPanel, TL0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox58, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox59;
	m_checkBox59 = new wxCheckBox( m_scSetGuiPanel, TL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox59, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biOpenFile = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biOpenFile, 0, wxALL, 3 );

	wxStaticText* m_staticText52;
	m_staticText52 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Open File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	fgSizer52->Add( m_staticText52, 0, wxALL, 3 );

	wxCheckBox* m_checkBox60;
	m_checkBox60 = new wxCheckBox( m_scSetGuiPanel, OF0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox60, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox61;
	m_checkBox61 = new wxCheckBox( m_scSetGuiPanel, OF1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox61, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_biSettings = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biSettings, 0, wxALL, 3 );

	wxStaticText* m_staticText53;
	m_staticText53 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	fgSizer52->Add( m_staticText53, 0, wxALL, 3 );

	wxCheckBox* m_checkBox62;
	m_checkBox62 = new wxCheckBox( m_scSetGuiPanel, STS0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox62, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox63;
	m_checkBox63 = new wxCheckBox( m_scSetGuiPanel, STS1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox63, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	m_biRequest = new wxStaticBitmap( m_scSetGuiPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_biRequest, 0, wxALL, 3 );

	wxStaticText* m_staticText54;
	m_staticText54 = new wxStaticText( m_scSetGuiPanel, wxID_ANY, _("Request"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	fgSizer52->Add( m_staticText54, 0, wxALL, 3 );

	wxCheckBox* m_checkBox64;
	m_checkBox64 = new wxCheckBox( m_scSetGuiPanel, RQ0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox64, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );

	wxCheckBox* m_checkBox65;
	m_checkBox65 = new wxCheckBox( m_scSetGuiPanel, RQ1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_checkBox65, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3 );


	sbSizer10->Add( fgSizer52, 1, wxEXPAND, 5 );


	m_fgSetGuiSizer->Add( sbSizer10, 1, wxEXPAND|wxTOP, 5 );


	m_scSetGuiPanel->SetSizer( m_fgSetGuiSizer );
	m_scSetGuiPanel->Layout();
	m_fgSetGuiSizer->Fit( m_scSetGuiPanel );
	m_nSettingsBook->AddPage( m_scSetGuiPanel, _("GUI"), true );

	m_fgMainSizer->Add( m_nSettingsBook, 1, wxEXPAND | wxALL, 5 );

	m_sButton = new wxStdDialogButtonSizer();
	m_sButtonOK = new wxButton( this, wxID_OK );
	m_sButton->AddButton( m_sButtonOK );
	m_sButtonApply = new wxButton( this, wxID_APPLY );
	m_sButton->AddButton( m_sButtonApply );
	m_sButtonCancel = new wxButton( this, wxID_CANCEL, _("Cancel") );
	m_sButton->AddButton( m_sButtonCancel );
	m_sButton->Realize();

	m_fgMainSizer->Add( m_sButton, m_sfSizers);


	this->SetSizer( m_fgMainSizer );
	this->Layout();
	m_fgMainSizer->Fit( this );

	this->Centre( wxBOTH );


	// Connect Events
	m_nSettingsBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GribSettingsDialogBase::OnPageChange ), NULL, this );
	m_cDataType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnDataTypeChoice ), NULL, this );
	m_cDataUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnUnitChange ), NULL, this );
	m_cBarbArrFixSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cBarbArrMinSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cDirArrFixSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cDirArrMinSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cNumFixSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cNumMinSpac->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_cLoopMode->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnIntepolateChange ), NULL, this );
	m_cInterpolate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnIntepolateChange ), NULL, this );
	m_rbCurDataAttaWCap->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataAttaWoCap->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataIsolHoriz->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataIsolVertic->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_sButtonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnApply ), NULL, this );
}

GribSettingsDialogBase::~GribSettingsDialogBase()
{
	// Disconnect Events
	m_nSettingsBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GribSettingsDialogBase::OnPageChange ), NULL, this );
	m_cDataType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnDataTypeChoice ), NULL, this );
	m_cDataUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnUnitChange ), NULL, this );
	m_cBarbArrFixSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cBarbArrMinSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cDirArrFixSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cDirArrMinSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cNumFixSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_cNumMinSpac->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnSpacingModeChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GribSettingsDialogBase::OnTransparencyChange ), NULL, this );
	m_cLoopMode->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnIntepolateChange ), NULL, this );
	m_cInterpolate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnIntepolateChange ), NULL, this );
	m_rbCurDataAttaWCap->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataAttaWoCap->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataIsolHoriz->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_rbCurDataIsolVertic->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GribSettingsDialogBase::OnCtrlandDataStyleChanged ), NULL, this );
	m_sButtonApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribSettingsDialogBase::OnApply ), NULL, this );

}

// Preference Window (accessible from OPENCPN plugin tab)
#ifndef __OCPN__ANDROID__
GribPreferencesDialogBase::GribPreferencesDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General Options") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer46;
	fgSizer46 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer46->SetFlexibleDirection( wxBOTH );
	fgSizer46->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_cbUseHiDef = new wxCheckBox( this, wxID_ANY, _("Use High Definition Graphics"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer46->Add( m_cbUseHiDef, 0, wxALL, 5 );

	m_cbUseGradualColors = new wxCheckBox( this, wxID_ANY, _("Use Gradual Colors"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer46->Add( m_cbUseGradualColors, 0, wxALL, 5 );

	m_cbCopyFirstCumulativeRecord = new wxCheckBox( this, wxID_ANY, _("Copy First Cumulative Missing Record"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer46->Add( m_cbCopyFirstCumulativeRecord, 0, wxALL, 5 );

	m_cbCopyMissingWaveRecord = new wxCheckBox( this, wxID_ANY, _("Copy Missing Wave Records"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer46->Add( m_cbCopyMissingWaveRecord, 0, wxALL, 5 );

	m_cbDrawBarbedArrowHead = new wxCheckBox( this, wxID_ANY, _("Draw Barbed Arrows Head"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer46->Add( m_cbDrawBarbedArrowHead, 0, wxALL, 5 );

    m_cZoomToCenterAtInit = new wxCheckBox(this, wxID_ANY, _("Zoom to file center when opened"), wxDefaultPosition, wxDefaultSize, 0);
    fgSizer46->Add(m_cZoomToCenterAtInit, 0, wxALL, 5);

	sbSizer9->Add( fgSizer46, 1, wxEXPAND, 5 );


	fgSizer6->Add( sbSizer9, 1, wxEXPAND, 5 );

	wxString m_rbLoadOptionsChoices[] = { _("Load the More Recent File in Directory"), _("Load the Last Opened File") };
	int m_rbLoadOptionsNChoices = sizeof( m_rbLoadOptionsChoices ) / sizeof( wxString );
	m_rbLoadOptions = new wxRadioBox( this, wxID_ANY, _("Load File Options"), wxDefaultPosition, wxDefaultSize, m_rbLoadOptionsNChoices, m_rbLoadOptionsChoices, 1, wxRA_SPECIFY_COLS );
	m_rbLoadOptions->SetSelection( 0 );
	fgSizer6->Add( m_rbLoadOptions, 0, wxALL|wxEXPAND, 5 );

	wxString m_rbStartOptionsChoices[] = { _("Start at the first forecast in GRIB file"), _("Start at the nearest forecast to current time"), _("Authorize Interpolation to start at current time") };
	int m_rbStartOptionsNChoices = sizeof( m_rbStartOptionsChoices ) / sizeof( wxString );
	m_rbStartOptions = new wxRadioBox( this, wxID_ANY, _("Start Options"), wxDefaultPosition, wxDefaultSize, m_rbStartOptionsNChoices, m_rbStartOptionsChoices, 1, wxRA_SPECIFY_COLS );
	m_rbStartOptions->SetSelection( 0 );
	fgSizer6->Add( m_rbStartOptions, 0, wxALL|wxEXPAND, 5 );

	wxString m_rbTimeFormatChoices[] = { _("Local Time"), _("UTC") };
	int m_rbTimeFormatNChoices = sizeof( m_rbTimeFormatChoices ) / sizeof( wxString );
	m_rbTimeFormat = new wxRadioBox( this, wxID_ANY, _("Time Options"), wxDefaultPosition, wxDefaultSize, m_rbTimeFormatNChoices, m_rbTimeFormatChoices, 1, wxRA_SPECIFY_COLS );
	m_rbTimeFormat->SetSelection( 1 );
	fgSizer6->Add( m_rbTimeFormat, 0, wxALL|wxEXPAND, 5 );

	wxStdDialogButtonSizer* m_sdbSizer2;
	wxButton* m_sdbSizer2OK;
	wxButton* m_sdbSizer2Cancel;
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL, _("Cancel") );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2->Realize();

	fgSizer6->Add( m_sdbSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_rbStartOptions->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GribPreferencesDialogBase::OnStartOptionChange ), NULL, this );
        m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribPreferencesDialogBase::OnOKClick ), NULL, this );

}
#else


GribPreferencesDialogBase::GribPreferencesDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
        this->SetSizeHints( wxDefaultSize, wxDefaultSize );

        wxBoxSizer* topSizer = new wxBoxSizer( wxVERTICAL );
        SetSizer( topSizer );

        wxBoxSizer* labelSizer = new wxBoxSizer( wxHORIZONTAL );
        topSizer->Add( labelSizer, 0, wxEXPAND, 5 );

        wxStaticText *labelBox = new wxStaticText( this, wxID_ANY, _("GRIB PlugIn Preferences"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
        labelSizer->Add(labelBox, 1, wxEXPAND, 0);

        wxScrolledWindow *itemScrollWin = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxVSCROLL);
        topSizer->Add( itemScrollWin, 1, wxEXPAND | wxALL, 0 );
        itemScrollWin->SetScrollRate(2, 2);

        wxBoxSizer* itemBoxSizer2 = new wxBoxSizer( wxVERTICAL );
        itemScrollWin->SetSizer( itemBoxSizer2 );

        wxStaticBoxSizer* sbSizer9;
        sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( itemScrollWin, wxID_ANY, _("General Options") ), wxVERTICAL );
        itemBoxSizer2->Add( sbSizer9, 1, wxEXPAND, 5 );

        m_cbUseHiDef = new wxCheckBox( itemScrollWin, wxID_ANY, _("Use High Definition Graphics"), wxDefaultPosition, wxDefaultSize, 0 );
        sbSizer9->Add( m_cbUseHiDef, 0, wxALL, 5 );

        m_cbUseGradualColors = new wxCheckBox( itemScrollWin, wxID_ANY, _("Use Gradual Colors"), wxDefaultPosition, wxDefaultSize, 0 );
        sbSizer9->Add( m_cbUseGradualColors, 0, wxALL, 5 );

        m_cbCopyFirstCumulativeRecord = new wxCheckBox( itemScrollWin, wxID_ANY, _("Copy First Cumulative Missing Record"), wxDefaultPosition, wxDefaultSize, 0 );
        sbSizer9->Add( m_cbCopyFirstCumulativeRecord, 0, wxALL, 5 );

        m_cbCopyMissingWaveRecord = new wxCheckBox( itemScrollWin, wxID_ANY, _("Copy Missing Wave Records"), wxDefaultPosition, wxDefaultSize, 0 );
        sbSizer9->Add( m_cbCopyMissingWaveRecord, 0, wxALL, 5 );

        m_cbDrawBarbedArrowHead = new wxCheckBox( itemScrollWin, wxID_ANY, _("Draw Barbed Arrows Head"), wxDefaultPosition, wxDefaultSize, 0 );
        sbSizer9->Add( m_cbDrawBarbedArrowHead, 0, wxALL, 5 );

        m_cZoomToCenterAtInit = new wxCheckBox(itemScrollWin, wxID_ANY, _("Zoom to file center when opened"), wxDefaultPosition, wxDefaultSize, 0);
        sbSizer9->Add(m_cZoomToCenterAtInit, 0, wxALL, 5);

        wxString m_rbLoadOptionsChoices[] = { _("Load the More Recent File in Directory"), _("Load the Last Opened File") };
        int m_rbLoadOptionsNChoices = sizeof( m_rbLoadOptionsChoices ) / sizeof( wxString );
        m_rbLoadOptions = new wxRadioBox( itemScrollWin, wxID_ANY, _("Load File Options"), wxDefaultPosition, wxDefaultSize, m_rbLoadOptionsNChoices, m_rbLoadOptionsChoices, 1, wxRA_SPECIFY_COLS );
        m_rbLoadOptions->SetSelection( 0 );
        sbSizer9->Add( m_rbLoadOptions, 0, wxALL|wxEXPAND, 5 );

        wxString m_rbStartOptionsChoices[] = { _("Start at the first forecast in GRIB file"), _("Start at the nearest forecast to current time"), _("Authorize Interpolation to start at current time") };
        int m_rbStartOptionsNChoices = sizeof( m_rbStartOptionsChoices ) / sizeof( wxString );
        m_rbStartOptions = new wxRadioBox( itemScrollWin, wxID_ANY, _("Start Options"), wxDefaultPosition, wxDefaultSize, m_rbStartOptionsNChoices, m_rbStartOptionsChoices, 1, wxRA_SPECIFY_COLS );
        m_rbStartOptions->SetSelection( 0 );
        sbSizer9->Add( m_rbStartOptions, 0, wxALL|wxEXPAND, 5 );

        wxString m_rbTimeFormatChoices[] = { _("Local Time"), _("UTC") };
        int m_rbTimeFormatNChoices = sizeof( m_rbTimeFormatChoices ) / sizeof( wxString );
        m_rbTimeFormat = new wxRadioBox( itemScrollWin, wxID_ANY, _("Time Options"), wxDefaultPosition, wxDefaultSize, m_rbTimeFormatNChoices, m_rbTimeFormatChoices, 1, wxRA_SPECIFY_COLS );
        m_rbTimeFormat->SetSelection( 1 );
        sbSizer9->Add( m_rbTimeFormat, 0, wxALL|wxEXPAND, 5 );


        wxBoxSizer* m_sdbButtonSizer = new wxBoxSizer( wxHORIZONTAL );
        topSizer->Add( m_sdbButtonSizer, 0, wxEXPAND, 5 );

        wxButton *m_sdbButtonSizerOK = new wxButton( this, wxID_OK );
        m_sdbButtonSizer->Add( m_sdbButtonSizerOK, 0, wxALL | wxALIGN_RIGHT, 15 );

        wxButton *m_sdbButtonSizerCancel = new wxButton( this, wxID_CANCEL );
        m_sdbButtonSizer->Add( m_sdbButtonSizerCancel, 0, wxALL | wxALIGN_RIGHT, 15 );

        // Connect Events
        m_rbStartOptions->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GribPreferencesDialogBase::OnStartOptionChange ), NULL, this );
        m_sdbButtonSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribPreferencesDialogBase::OnOKClick ), NULL, this );
}

#endif


GribPreferencesDialogBase::~GribPreferencesDialogBase()
{
	// Disconnect Events
	m_rbStartOptions->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GribPreferencesDialogBase::OnStartOptionChange ), NULL, this );
}

// Grib download by email window
GribRequestSettingBase::GribRequestSettingBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    //////////////////////////////////////////////////////////////////////
    // SizerFlags
    //////////////////////////////////////////////////////////////////////
	m_sfVCentered.Border(wxALL, 5)
	             .Align(wxALIGN_LEFT)
	             .Align(wxALIGN_CENTER_VERTICAL)
	             .Proportion(1);

	m_sfExpanded.Border(wxALL, 5)
	            .Expand()
	            .Proportion(1);

	m_sfTop.Border(wxALL, 5)
	       .Align(wxALIGN_LEFT)
	       .Align(wxALIGN_TOP)
	       .Proportion(1);

	m_sfSizers.Expand()
              .Border(wxALL, 5)
              .Proportion(1);

	m_sfSubSizers.Expand()
                 .Proportion(1);

    //////////////////////////////////////////////////////////////////////
    // Sizers - Sub-Sizers Definitions
    //////////////////////////////////////////////////////////////////////
	wxFlexGridSizer* m_fgMainSizer;
	m_fgMainSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgMainSizer->SetFlexibleDirection( wxBOTH );
	m_fgMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_sScrolledDialog = new wxScrolledWindow( this,
	                                          wxID_ANY,
	                                          wxDefaultPosition,
	                                          wxDefaultSize,
	                                          wxHSCROLL|wxTAB_TRAVERSAL|wxVSCROLL );
	m_sScrolledDialog->SetScrollRate( 0, 5 );

	m_fgScrollSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgScrollSizer->SetFlexibleDirection( wxBOTH );
	m_fgScrollSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbProfile;
	m_sbProfile = new wxStaticBoxSizer( new wxStaticBox( m_sScrolledDialog,
	                                                  wxID_ANY,
	                                                  _("Profile") ),
	                                                  wxVERTICAL );

	wxFlexGridSizer* m_fgProfile;
	m_fgProfile = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgProfile->SetFlexibleDirection( wxBOTH );
	m_fgProfile->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_pSenderSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_pSenderSizer->AddGrowableCol( 1 );
	m_pSenderSizer->SetFlexibleDirection( wxBOTH );
	m_pSenderSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer33;
	fgSizer33 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer33->SetFlexibleDirection( wxBOTH );
	fgSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* m_fgMovingGrib;
	m_fgMovingGrib = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgMovingGrib->SetFlexibleDirection( wxBOTH );
	m_fgMovingGrib->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgMovingGrib->AddGrowableRow(0);

	m_fgMovingParams = new wxFlexGridSizer( 0, 3, 0, 0 );
	m_fgMovingParams->SetFlexibleDirection( wxBOTH );
	m_fgMovingParams->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgMovingParams->AddGrowableRow(0);
	m_fgMovingParams->AddGrowableRow(1);
	m_fgMovingParams->AddGrowableCol(1);

	m_fgLog = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgLog->SetFlexibleDirection( wxBOTH );
	m_fgLog->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgLog->AddGrowableRow(0);
	m_fgLog->AddGrowableRow(1);

	wxFlexGridSizer* m_fgModelParameters;
	m_fgModelParameters = new wxFlexGridSizer( 0, 9, 0, 0 );
	m_fgModelParameters->SetFlexibleDirection( wxBOTH );
	m_fgModelParameters->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbAreaSelection;
	m_sbAreaSelection = new wxStaticBoxSizer( new wxStaticBox( m_sScrolledDialog,
	                                                   wxID_ANY,
	                                                   _("Area Selection") ),
	                                                   wxVERTICAL );

	wxFlexGridSizer* m_fgAreaSelection;
	m_fgAreaSelection = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgAreaSelection->SetFlexibleDirection( wxBOTH );
	m_fgAreaSelection->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    wxFlexGridSizer* m_fgAreaSelLeft;
	m_fgAreaSelLeft = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgAreaSelLeft->SetFlexibleDirection( wxBOTH );
	m_fgAreaSelLeft->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgZoneCoordinatesSizer = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgZoneCoordinatesSizer->SetFlexibleDirection( wxBOTH );
	fgZoneCoordinatesSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	fgZoneCoordinatesSizer->AddGrowableRow(0);
	fgZoneCoordinatesSizer->AddGrowableRow(1);
//	fgZoneCoordinatesSizer->AddGrowableCol(0);
//	fgZoneCoordinatesSizer->AddGrowableCol(1);

	wxStaticBoxSizer* m_sbDataSelection;
	m_sbDataSelection = new wxStaticBoxSizer( new wxStaticBox( m_sScrolledDialog,
	                                                           wxID_ANY,
	                                                           _("Data Selection") ),
	                                                           wxVERTICAL );

	wxFlexGridSizer* m_fgDataSelection;
	m_fgDataSelection = new wxFlexGridSizer( 0, 3, 0, 0 );
	m_fgDataSelection->SetFlexibleDirection( wxBOTH );
	m_fgDataSelection->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

//	wxFlexGridSizer* m_fgWaves;
	m_fgWaves = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgWaves->SetFlexibleDirection( wxBOTH );
	m_fgWaves->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgWaves->AddGrowableRow(0);


	m_fgGeopotentialHeight = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgGeopotentialHeight->SetFlexibleDirection( wxBOTH );
	m_fgGeopotentialHeight->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_fgGeopotentialHeight->AddGrowableRow(0);

	m_fgAltitudeData = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgAltitudeData->SetFlexibleDirection( wxBOTH );
	m_fgAltitudeData->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* m_sbMail;
	m_sbMail = new wxStaticBoxSizer( new wxStaticBox( m_sScrolledDialog,
	                                                  wxID_ANY,
	                                                  _("Mail") ),
	                                                  wxVERTICAL );

	wxFlexGridSizer* m_fgMail;
	m_fgMail = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgMail->AddGrowableCol( 0 );
	m_fgMail->SetFlexibleDirection( wxBOTH );
	m_fgMail->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_fgFixedSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	m_fgFixedSizer->SetFlexibleDirection( wxBOTH );
	m_fgFixedSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_rButton = new wxStdDialogButtonSizer();

    //////////////////////////////////////////////////////////////////
    // Widgets definitions
    //////////////////////////////////////////////////////////////////
	wxStaticText* m_stSenderAdress;
	m_stSenderAdress = new wxStaticText( m_sScrolledDialog,
                                       wxID_ANY,
                                       _("Sender eMail Address"),
                                       wxDefaultPosition,
                                       wxDefaultSize,
                                       0 );
	m_stSenderAdress->Wrap( -1 );

	m_pSenderAddress = new wxTextCtrl( m_sScrolledDialog,
	                                   wxID_ANY,
	                                   wxEmptyString,
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );

	wxStaticLine* m_staticline4;
	m_staticline4 = new wxStaticLine( m_sScrolledDialog,
                                      wxID_ANY,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxLI_HORIZONTAL );

	wxStaticLine* m_staticline5;
	m_staticline5 = new wxStaticLine( m_sScrolledDialog,
	                                  wxID_ANY,
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  wxLI_HORIZONTAL );

	wxStaticText* m_stMailTo;
	m_stMailTo = new wxStaticText( m_sScrolledDialog,
	                               wxID_ANY,
	                               _("Mail To "),
	                               wxDefaultPosition,
	                               wxDefaultSize,
	                               0 );
	m_stMailTo->Wrap( -1 );

	wxArrayString m_pMailToChoices;
	m_pMailTo = new wxChoice( m_sScrolledDialog,
                              wxID_ANY,
                              wxDefaultPosition,
                              wxDefaultSize,
                              m_pMailToChoices,
                              0 );
	m_pMailTo->SetSelection( 0 );

	wxStaticText* m_stForecastModel;
	m_stForecastModel = new wxStaticText( m_sScrolledDialog,
	                                      wxID_ANY,
	                                      _("Forecast Model "),
	                                      wxDefaultPosition,
	                                      wxDefaultSize,
	                                      0 );
	m_stForecastModel->Wrap( -1 );

	wxArrayString m_pModelChoices;
	m_pModel = new wxChoice( m_sScrolledDialog,
                             wxID_ANY,
                             wxDefaultPosition,
                             wxDefaultSize,
                             m_pModelChoices,
                             0 );
	m_pModel->SetSelection( 0 );

	m_cMovingGribEnabled = new wxCheckBox( m_sScrolledDialog,
	                                       wxID_ANY,
	                                       _("Moving Grib"),
	                                       wxDefaultPosition,
	                                       wxDefaultSize,
	                                       0 );

	wxStaticText* m_stMovingSpeed;
	m_stMovingSpeed = new wxStaticText( m_sScrolledDialog,
	                                    wxID_ANY,
	                                    _("Speed"),
	                                    wxDefaultPosition,
	                                    wxDefaultSize,
	                                    0 );
	m_stMovingSpeed->Wrap( -1 );

	m_sMovingSpeed = new wxSpinCtrl( m_sScrolledDialog,
	                                 wxID_ANY,
	                                 wxEmptyString,
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 wxSP_ARROW_KEYS,
	                                 1,
	                                 30,
	                                 1 );

	wxStaticText* m_sSpeedUnit;
	m_sSpeedUnit = new wxStaticText( m_sScrolledDialog,
                                     wxID_ANY,
                                     _("Kts"),
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     0 );
	m_sSpeedUnit->Wrap( -1 );

	wxStaticText* m_stMovingCourse;
	m_stMovingCourse = new wxStaticText( m_sScrolledDialog,
	                                     wxID_ANY,
	                                     _("Course"),
	                                     wxDefaultPosition,
	                                     wxDefaultSize,
	                                     0 );
	m_stMovingCourse->Wrap( -1 );

	m_sMovingCourse = new wxSpinCtrl( m_sScrolledDialog,
                                      wxID_ANY,
                                      wxEmptyString,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxSP_ARROW_KEYS,
                                      1,
                                      360,
                                      1 );

	m_sCourseUnit = new wxStaticText( m_sScrolledDialog,
	                                  wxID_ANY,
	                                  _("Deg"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );
	m_sCourseUnit->Wrap( -1 );

    wxStaticText* m_tLogin;
	m_tLogin = new wxStaticText( m_sScrolledDialog,
                                 wxID_ANY,
                                 _("zyGrib Login"),
                                 wxDefaultPosition,
                                 wxDefaultSize,
                                 0 );
	m_tLogin->Wrap( -1 );

	m_pLogin = new wxTextCtrl( m_sScrolledDialog,
	                           wxID_ANY,
	                           wxEmptyString,
	                           wxDefaultPosition,
	                           wxDefaultSize,
	                           0 );
	wxStaticText* m_tCode;
	m_tCode = new wxStaticText( m_sScrolledDialog,
                                wxID_ANY,
                                _("zyGrib Code"),
                                wxDefaultPosition,
                                wxDefaultSize,
                                0 );
	m_tCode->Wrap( -1 );

	m_pCode = new wxTextCtrl( m_sScrolledDialog,
	                          wxID_ANY,
	                          wxEmptyString,
	                          wxDefaultPosition,
	                          wxDefaultSize,
	                          0 );

	wxStaticText* m_stResolution;
	m_stResolution = new wxStaticText( m_sScrolledDialog,
	                                   wxID_ANY,
	                                   _("Resolution"),
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );
	m_stResolution->Wrap( -1 );

	wxArrayString m_pResolutionChoices;
	m_pResolution = new wxChoice( m_sScrolledDialog,
	                              wxID_ANY,
                                  wxDefaultPosition,
                                  wxDefaultSize,
                                  m_pResolutionChoices,
                                  0 );
	m_pResolution->SetSelection( 0 );

	m_tResUnit = new wxStaticText( m_sScrolledDialog,
	                               wxID_ANY,
	                               _("Deg"),
	                               wxDefaultPosition,
	                               wxDefaultSize,
	                               0 );
	m_tResUnit->Wrap( -1 );

	wxStaticText* m_stIntervalParam;
	m_stIntervalParam = new wxStaticText( m_sScrolledDialog,
                                          wxID_ANY,
                                          _("Interval"),
                                          wxDefaultPosition,
                                          wxDefaultSize,
                                          0 );
	m_stIntervalParam->Wrap( -1 );

	wxArrayString m_pIntervalChoices;
	m_pInterval = new wxChoice( m_sScrolledDialog,
	                            wxID_ANY,
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            m_pIntervalChoices,
	                            0 );
	m_pInterval->SetSelection( 0 );

	wxStaticText* m_stHours;
	m_stHours = new wxStaticText( m_sScrolledDialog,
	                              wxID_ANY,
                                  _("Hours"),
                                  wxDefaultPosition,
                                  wxDefaultSize,
                                  0 );
	m_stHours->Wrap( -1 );

	wxStaticText* m_stTimeRange;
	m_stTimeRange = new wxStaticText( m_sScrolledDialog,
	                                  wxID_ANY,
	                                  _("Time Range"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );
	m_stTimeRange->Wrap( -1 );

	wxArrayString m_pTimeRangeChoices;
	m_pTimeRange = new wxChoice( m_sScrolledDialog,
	                             wxID_ANY,
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             m_pTimeRangeChoices,
	                             0 );
	m_pTimeRange->SetSelection( 0 );

	m_stDays = new wxStaticText( m_sScrolledDialog,
	                             wxID_ANY,
	                             _("Days"),
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             0 );
	m_stDays->Wrap( -1 );

	m_cManualZoneSel = new wxCheckBox( m_sScrolledDialog,
	                                   MANSELECT,
	                                   _("Manual Selection"),
	                                   wxDefaultPosition,
	                                   wxDefaultSize,
	                                   0 );

    m_cUseSavedZone = new wxCheckBox( m_sScrolledDialog,
                                      SAVEDZONE,
                                      _("Use Always this Area"),
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      0 );

	wxStaticText* m_stMaxLat;
	m_stMaxLat = new wxStaticText( m_sScrolledDialog,
                                   wxID_ANY,
                                   _("Max Lat"),
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   0 );
	m_stMaxLat->Wrap( -1 );

	m_spMaxLat = new wxSpinCtrl( m_sScrolledDialog,
	                             MAXLAT,
	                             wxEmptyString,
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             wxSP_ARROW_KEYS,
	                             -180,
	                             180,
	                             0 );

	m_stMaxLatNS = new wxStaticText( m_sScrolledDialog,
	                                 wxID_ANY,
	                                 _("N"),
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 0 );
	m_stMaxLatNS->Wrap( -1 );
	m_stMaxLatNS->SetMinSize( wxSize(20,-1) );

	m_stMaxLong = new wxStaticText( m_sScrolledDialog,
	                                wxID_ANY,
	                                _("Max Long"),
	                                wxDefaultPosition,
	                                wxDefaultSize,
	                                0 );
	m_stMaxLong->Wrap( -1 );

	m_spMaxLon = new wxSpinCtrl( m_sScrolledDialog,
	                             MAXLON,
	                             wxEmptyString,
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             wxSP_ARROW_KEYS,
	                             -180,
	                             180,
	                             0 );

	m_stMaxLonEW = new wxStaticText( m_sScrolledDialog,
	                                 wxID_ANY,
	                                 _("E"),
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 0 );
	m_stMaxLonEW->Wrap( -1 );
	m_stMaxLonEW->SetMinSize( wxSize(20,-1) );

	wxStaticText* m_stMinLat;
	m_stMinLat = new wxStaticText( m_sScrolledDialog,
	                               wxID_ANY,
	                               _("Min Lat"),
	                               wxDefaultPosition,
	                               wxDefaultSize,
	                               0 );
	m_stMinLat->Wrap( -1 );

	m_spMinLat = new wxSpinCtrl( m_sScrolledDialog,
	                             MINLAT,
	                             wxEmptyString,
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             wxSP_ARROW_KEYS,
	                             -180,
	                             180,
	                             0 );

	m_stMinLatNS = new wxStaticText( m_sScrolledDialog,
                                     wxID_ANY,
                                     _("S"),
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     0 );
	m_stMinLatNS->Wrap( -1 );
	m_stMinLatNS->SetMinSize( wxSize(20,-1) );

	wxStaticText* m_stMinLong;
	m_stMinLong = new wxStaticText( m_sScrolledDialog,
	                                wxID_ANY,
                                    _("Min Long"),
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    0 );
	m_stMinLong->Wrap( -1 );

	m_spMinLon = new wxSpinCtrl( m_sScrolledDialog,
	                             MINLON,
	                             wxEmptyString,
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             wxSP_ARROW_KEYS,
	                             -180,
	                             180,
	                             0 );

	m_stMinLonEW = new wxStaticText( m_sScrolledDialog,
	                                 wxID_ANY,
	                                 _("W"),
	                                 wxDefaultPosition,
	                                 wxDefaultSize,
	                                 0 );
	m_stMinLonEW->Wrap( -1 );
	m_stMinLatNS->SetMinSize( wxSize(20,-1) );

	m_pWind = new wxCheckBox( m_sScrolledDialog,
	                          wxID_ANY,
	                          _("Wind"),
	                          wxDefaultPosition,
	                          wxDefaultSize,
	                          0 );

	m_pPress = new wxCheckBox( m_sScrolledDialog,
	                           wxID_ANY,
	                           _("Pressure"),
	                           wxDefaultPosition,
	                           wxDefaultSize,
	                           0 );

	m_pWindGust = new wxCheckBox( m_sScrolledDialog,
	                              wxID_ANY,
	                              _("Wind Gust"),
	                              wxDefaultPosition,
	                              wxDefaultSize,
	                              0 );

	m_pRainfall = new wxCheckBox( m_sScrolledDialog,
                                  wxID_ANY,
                                  _("Rainfall"),
                                  wxDefaultPosition,
                                  wxDefaultSize,
                                  0 );
	m_pCloudCover = new wxCheckBox( m_sScrolledDialog,
                                    wxID_ANY,
                                    _("Cloud Cover"),
                                    wxDefaultPosition,
                                    wxDefaultSize, 0 );

	m_pAirTemp = new wxCheckBox( m_sScrolledDialog,
	                             wxID_ANY,
	                             _("Air Temperature(2m)"),
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             0 );
	m_pAirTemp->SetValue(true);

	m_pCAPE = new wxCheckBox( m_sScrolledDialog,
	                          wxID_ANY,
	                          _("CAPE"),
	                          wxDefaultPosition,
	                          wxDefaultSize,
	                          0 );

	m_pReflectivity = new wxCheckBox( m_sScrolledDialog,
	                                  wxID_ANY,
	                                  _("Comp. Reflect."),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );

	m_pSeaTemp = new wxCheckBox( m_sScrolledDialog,
                                 wxID_ANY,
                                 _("Sea Temperature(surf.)"),
                                 wxDefaultPosition,
                                 wxDefaultSize,
                                 0 );

	m_pCurrent = new wxCheckBox( m_sScrolledDialog,
	                             wxID_ANY,
	                             _("Current"),
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             0 );

	m_pWaves = new wxCheckBox( m_sScrolledDialog, wxID_ANY, _("Waves"), wxDefaultPosition, wxDefaultSize, 0 );

	wxArrayString m_pWModelChoices;
	m_pWModel = new wxChoice( m_sScrolledDialog, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_pWModelChoices, 0 );
	m_pWModel->SetSelection( 0 );

	m_pAltitudeData = new wxCheckBox( m_sScrolledDialog,
	                                  wxID_ANY,
	                                  _("Geopotential Height"),
	                                  wxDefaultPosition,
	                                  wxDefaultSize,
	                                  0 );

	m_p850hpa = new wxCheckBox( m_sScrolledDialog,
                                wxID_ANY,
                                _("850 hPa"),
                                wxDefaultPosition,
                                wxDefaultSize,
                                0 );

	m_p700hpa = new wxCheckBox( m_sScrolledDialog,
	                            wxID_ANY,
	                            _("700 hPa"),
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            0 );
	m_p500hpa = new wxCheckBox( m_sScrolledDialog,
	                            wxID_ANY,
	                            _("500 hPa"),
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            0 );
	m_p300hpa = new wxCheckBox( m_sScrolledDialog,
	                            wxID_ANY,
	                            _("300 hPa"),
	                            wxDefaultPosition,
	                            wxDefaultSize,
	                            0 );

	m_MailImage = new wxTextCtrl( m_sScrolledDialog,
                                  wxID_ANY,
                                  wxEmptyString,
                                  wxDefaultPosition,
                                  wxDefaultSize,
                                  wxTE_MULTILINE|wxTE_READONLY );

	wxStaticText* m_stEstFileSize;
	m_stEstFileSize = new wxStaticText( this,
	                                    wxID_ANY,
	                                    _("Estimated File Size"),
	                                    wxDefaultPosition,
	                                    wxDefaultSize,
	                                    0 );
	m_stEstFileSize->Wrap( -1 );

	m_tFileSize = new wxStaticText( this,
                                    wxID_ANY,
                                    wxEmptyString,
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    0 );
	m_tFileSize->Wrap( -1 );

	m_tLimit = new wxStaticText( this,
	                             wxID_ANY,
	                             _(" (Max size )"),
	                             wxDefaultPosition,
	                             wxDefaultSize,
	                             0 );
	m_tLimit->Wrap( -1 );

	m_rButtonYes = new wxButton( this, wxID_YES );

	m_rButtonApply = new wxButton( this, wxID_APPLY );

	m_rButtonCancel = new wxButton( this, wxID_CANCEL, _("Cancel") );

    //////////////////////////////////////////////////////////////////////
    // Layout definitions
    //////////////////////////////////////////////////////////////////////

    // Profile
	m_pSenderSizer->Add( m_stSenderAdress,
	                     m_sfVCentered );
	m_pSenderSizer->Add( m_pSenderAddress,
                         m_sfExpanded );
	m_pSenderSizer->Add( m_staticline4,
	                     m_sfExpanded );
	m_pSenderSizer->Add( m_staticline5,
	                     m_sfExpanded );
	m_fgProfile->Add( m_pSenderSizer,
	                m_sfSubSizers );

	fgSizer33->Add( m_stMailTo,
	                m_sfVCentered );
	fgSizer33->Add( m_pMailTo,
	                m_sfExpanded );
	fgSizer33->Add( m_stForecastModel,
	                m_sfVCentered );
	fgSizer33->Add( m_pModel,
	                m_sfExpanded );
	fgSizer9->Add( fgSizer33,
                   m_sfSubSizers );
	m_fgMovingGrib->Add( m_cMovingGribEnabled,
	                     m_sfVCentered );
	m_fgMovingParams->Add( m_stMovingSpeed,
	                       m_sfVCentered );
	m_fgMovingParams->Add( m_sMovingSpeed,
	                       m_sfExpanded );
	m_fgMovingParams->Add( m_sSpeedUnit,
	                       m_sfVCentered );
	m_fgMovingParams->Add( m_stMovingCourse,
	                       m_sfVCentered );
	m_fgMovingParams->Add( m_sMovingCourse,
	                       m_sfExpanded );
	m_fgMovingParams->Add( m_sCourseUnit,
	                       m_sfVCentered );
	m_fgMovingGrib->Add( m_fgMovingParams,
	                     m_sfSubSizers );
	fgSizer9->Add( m_fgMovingGrib,
	               m_sfSubSizers );
	m_fgLog->Add( m_tLogin,
	              m_sfVCentered );
	m_fgLog->Add( m_pLogin,
                  m_sfExpanded );
	m_fgLog->Add( m_tCode,
	              m_sfVCentered );
	m_fgLog->Add( m_pCode,
	              m_sfExpanded );
	fgSizer9->Add( m_fgLog,
	               m_sfSubSizers );
	m_fgProfile->Add( fgSizer9,
	                  m_sfSubSizers );
	m_fgModelParameters->Add( m_stResolution,
	                          m_sfVCentered );
	m_fgModelParameters->Add( m_pResolution,
	                          m_sfExpanded );
	m_fgModelParameters->Add( m_tResUnit,
	                          m_sfVCentered );
	m_fgModelParameters->Add( m_stIntervalParam,
	                          m_sfVCentered );
	m_fgModelParameters->Add( m_pInterval,
	                          m_sfExpanded );
	m_fgModelParameters->Add( m_stHours,
	                          m_sfVCentered );
	m_fgModelParameters->Add( m_stTimeRange,
	                          m_sfVCentered );
	m_fgModelParameters->Add( m_pTimeRange,
	                          m_sfExpanded );
	m_fgModelParameters->Add( m_stDays,
	                          m_sfVCentered );
	m_fgProfile->Add( m_fgModelParameters,
	                  m_sfSubSizers );
	m_sbProfile->Add( m_fgProfile,
	                  m_sfSubSizers );
	m_fgScrollSizer->Add( m_sbProfile,
	                      m_sfSizers );

    // Area Selection
	m_fgAreaSelLeft->Add( m_cManualZoneSel,
	                      m_sfVCentered );
	m_fgAreaSelLeft->Add( m_cUseSavedZone,
	                      m_sfVCentered );
    m_fgAreaSelection->Add( m_fgAreaSelLeft,
                            m_sfSubSizers );
	fgZoneCoordinatesSizer->Add( m_stMaxLat,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_spMaxLat,
	                             m_sfExpanded );
	fgZoneCoordinatesSizer->Add( m_stMaxLatNS,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_stMaxLong,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_spMaxLon,
	                             m_sfExpanded );
	fgZoneCoordinatesSizer->Add( m_stMaxLonEW,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_stMinLat,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_spMinLat,
	                             m_sfExpanded );
	fgZoneCoordinatesSizer->Add( m_stMinLatNS,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_stMinLong,
	                             m_sfVCentered );
	fgZoneCoordinatesSizer->Add( m_spMinLon,
	                             m_sfExpanded );
	fgZoneCoordinatesSizer->Add( m_stMinLonEW,
	                             m_sfVCentered );
	m_fgAreaSelection->Add( fgZoneCoordinatesSizer,
                            m_sfSubSizers );
	m_sbAreaSelection->Add( m_fgAreaSelection,
	                        m_sfSubSizers );
	m_fgScrollSizer->Add( m_sbAreaSelection,
	                      m_sfSizers );
    // Data Selection
	m_fgDataSelection->Add( m_pWind,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pPress,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pWindGust,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pRainfall,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pCloudCover,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pAirTemp,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pCAPE,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pReflectivity,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pSeaTemp,
	                        m_sfVCentered );
	m_fgDataSelection->Add( m_pCurrent,
	                        m_sfVCentered );
	m_fgWaves->Add( m_pWaves,
                    m_sfVCentered );
	m_fgWaves->Add( m_pWModel,
                    m_sfVCentered );
	m_fgDataSelection->Add( m_fgWaves,
	                        m_sfSubSizers );

//	m_fgDataSelection->Add( m_pAltitudeData, 0, wxALL|wxEXPAND, 5 );

	m_fgGeopotentialHeight->Add( m_pAltitudeData,
	                             m_sfVCentered );
	m_fgAltitudeData->Add( m_p850hpa,
                           m_sfVCentered );
	m_fgAltitudeData->Add( m_p700hpa,
                           m_sfVCentered );
	m_fgAltitudeData->Add( m_p500hpa,
                           m_sfVCentered );
	m_fgAltitudeData->Add( m_p300hpa,
                           m_sfVCentered );
	m_fgGeopotentialHeight->Add( m_fgAltitudeData,
	                             m_sfSubSizers );
	m_fgDataSelection->Add( m_fgGeopotentialHeight,
	                        m_sfSubSizers);
//	m_fgDataSelection->Add( m_fgAltitudeData, 1, wxEXPAND, 5 );
	m_sbDataSelection->Add( m_fgDataSelection,
	                        m_sfSubSizers );
	m_fgScrollSizer->Add( m_sbDataSelection,
	                      m_sfSizers );

    // Mail
	m_fgMail->Add( m_MailImage,
	               m_sfExpanded );
	m_sbMail->Add( m_fgMail,
	               m_sfSubSizers );
	m_fgScrollSizer->Add( m_sbMail,
	                      m_sfSizers );

	m_sScrolledDialog->SetSizer( m_fgScrollSizer );
	m_sScrolledDialog->Layout();

	m_fgScrollSizer->Fit( m_sScrolledDialog );
	m_fgMainSizer->Add( m_sScrolledDialog, 1, 0, 5 );

	m_fgFixedSizer->Add( m_stEstFileSize,
	                     m_sfVCentered );
	m_fgFixedSizer->Add( m_tFileSize,
	                     m_sfVCentered );
	m_fgFixedSizer->Add( m_tLimit,
	                     m_sfVCentered );
	m_fgMainSizer->Add( m_fgFixedSizer,
	                    m_sfSubSizers );

	m_rButton->AddButton( m_rButtonYes );
	m_rButton->AddButton( m_rButtonApply );
	m_rButton->AddButton( m_rButtonCancel );
	m_rButton->Realize();

	m_fgMainSizer->Add( m_rButton,
	                    m_sfSizers );

	this->SetSizer( m_fgMainSizer );
	this->Layout();
	m_fgMainSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GribRequestSettingBase::OnClose ) );
	m_pMailTo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTopChange ), NULL, this );
	m_pModel->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTopChange ), NULL, this );
	m_cMovingGribEnabled->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnMovingClick ), NULL, this );
	m_sMovingSpeed->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnAnySpinChange ), NULL, this );
	m_sMovingCourse->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnAnySpinChange ), NULL, this );
	m_pLogin->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCode->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pResolution->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pInterval->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pTimeRange->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTimeRangeChange ), NULL, this );
	m_cManualZoneSel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnZoneSelectionModeChange ), NULL, this );
    m_cUseSavedZone->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnZoneSelectionModeChange ), NULL, this );
	m_spMaxLat->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMaxLon->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMinLat->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMinLon->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_pWind->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pPress->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWindGust->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pRainfall->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCloudCover->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pAirTemp->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCAPE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pReflectivity->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pSeaTemp->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCurrent->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWaves->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWModel->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pAltitudeData->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p850hpa->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p700hpa->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p500hpa->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p300hpa->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_rButtonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnSaveMail ), NULL, this );
	m_rButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnCancel ), NULL, this );
	m_rButtonYes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnSendMaiL ), NULL, this );
}

GribRequestSettingBase::~GribRequestSettingBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GribRequestSettingBase::OnClose ) );
	m_pMailTo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTopChange ), NULL, this );
	m_pModel->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTopChange ), NULL, this );
	m_cMovingGribEnabled->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnMovingClick ), NULL, this );
	m_sMovingSpeed->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnAnySpinChange ), NULL, this );
	m_sMovingCourse->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnAnySpinChange ), NULL, this );
	m_pLogin->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCode->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pResolution->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pInterval->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pTimeRange->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnTimeRangeChange ), NULL, this );
	m_cManualZoneSel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnZoneSelectionModeChange ), NULL, this );
    m_cUseSavedZone->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnZoneSelectionModeChange ), NULL, this );
	m_spMaxLat->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMaxLon->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMinLat->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_spMinLon->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GribRequestSettingBase::OnCoordinatesChange ), NULL, this );
	m_pWind->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pPress->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWindGust->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pRainfall->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCloudCover->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pAirTemp->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCAPE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pReflectivity->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pSeaTemp->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pCurrent->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWaves->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pWModel->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_pAltitudeData->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p850hpa->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p700hpa->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p500hpa->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_p300hpa->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnAnyChange ), NULL, this );
	m_rButtonApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnSaveMail ), NULL, this );
	m_rButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnCancel ), NULL, this );
	m_rButtonYes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GribRequestSettingBase::OnSendMaiL ), NULL, this );

}

// Undefined
GRIBTableBase::GRIBTableBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer18->AddGrowableRow( 1 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );

	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );

	m_pPositionText = new wxStaticText( this, wxID_ANY, _("Data at Position:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_pPositionText->Wrap( -1 );
	fgSizer19->Add( m_pPositionText, 0, wxALL|wxEXPAND, 5 );

	m_pCursorPosition = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_pCursorPosition->Wrap( -1 );
	fgSizer19->Add( m_pCursorPosition, 0, wxALL|wxEXPAND, 5 );


	fgSizer18->Add( fgSizer19, 1, wxEXPAND, 10 );

	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer20->AddGrowableRow( 0 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	m_pGribTable = new CustomGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,50 ), 0, _T(" ") );

	// Cell Defaults
	m_pGribTable->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_pGribTable->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	fgSizer20->Add( m_pGribTable, 0, wxALL|wxEXPAND, 5 );


	fgSizer18->Add( fgSizer20, 1, wxEXPAND, 5 );

	wxStdDialogButtonSizer *m_pButtonTable = new wxStdDialogButtonSizer();
	m_pButtonTableOK = new wxButton( this, wxID_OK, _("Close") );
	m_pButtonTableOK->SetFont( GetOCPNGUIScaledFont_PlugIn(_T("Dialog")) );
	m_pButtonTable->AddButton( m_pButtonTableOK );
	m_pButtonTable->Realize();

	fgSizer18->Add( m_pButtonTable, 1, wxEXPAND, 5 );


	bSizer1->Add( fgSizer18, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GRIBTableBase::OnClose ) );
	m_pButtonTableOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBTableBase::OnOKButton ), NULL, this );
}

GRIBTableBase::~GRIBTableBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GRIBTableBase::OnClose ) );
	m_pButtonTableOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GRIBTableBase::OnOKButton ), NULL, this );

}
