// GDIObjectDemoDoc.h : interface of the CGDIObjectDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIOBJECTDEMODOC_H__0BADB65A_3B4A_4D98_84FB_5CDF2FBFBF22__INCLUDED_)
#define AFX_GDIOBJECTDEMODOC_H__0BADB65A_3B4A_4D98_84FB_5CDF2FBFBF22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIObjectDemoDoc : public CDocument
{
protected: // create from serialization only
	CGDIObjectDemoDoc();
	DECLARE_DYNCREATE(CGDIObjectDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIObjectDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIObjectDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIObjectDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIOBJECTDEMODOC_H__0BADB65A_3B4A_4D98_84FB_5CDF2FBFBF22__INCLUDED_)
