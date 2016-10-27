// GDIObjectDemoDoc.cpp : implementation of the CGDIObjectDemoDoc class
//

#include "stdafx.h"
#include "GDIObjectDemo.h"

#include "GDIObjectDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoDoc

IMPLEMENT_DYNCREATE(CGDIObjectDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIObjectDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CGDIObjectDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoDoc construction/destruction

CGDIObjectDemoDoc::CGDIObjectDemoDoc()
{
	// TODO: add one-time construction code here

}

CGDIObjectDemoDoc::~CGDIObjectDemoDoc()
{
}

BOOL CGDIObjectDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoDoc serialization

void CGDIObjectDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoDoc diagnostics

#ifdef _DEBUG
void CGDIObjectDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIObjectDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoDoc commands
