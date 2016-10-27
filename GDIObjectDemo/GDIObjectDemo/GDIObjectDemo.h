// GDIObjectDemo.h : main header file for the GDIOBJECTDEMO application
//

#if !defined(AFX_GDIOBJECTDEMO_H__5EDA4690_D438_4F92_8181_373A9A58DD43__INCLUDED_)
#define AFX_GDIOBJECTDEMO_H__5EDA4690_D438_4F92_8181_373A9A58DD43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoApp:
// See GDIObjectDemo.cpp for the implementation of this class
//

class CGDIObjectDemoApp : public CWinApp
{
public:
	CGDIObjectDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIObjectDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDIObjectDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIOBJECTDEMO_H__5EDA4690_D438_4F92_8181_373A9A58DD43__INCLUDED_)
