
// DocViewTestDoc.cpp : CDocViewTestDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DocViewTest.h"
#endif

#include "DocViewTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDocViewTestDoc

IMPLEMENT_DYNCREATE(CDocViewTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocViewTestDoc, CDocument)
		ON_COMMAND(ID_RECTANGLE, &CDocViewTestDoc::OnRectangle)
		ON_COMMAND(ID_ELLIPSE, &CDocViewTestDoc::OnEllipse)
		ON_COMMAND(ID_LINE, &CDocViewTestDoc::OnLine)
END_MESSAGE_MAP()


// CDocViewTestDoc ����/�Ҹ�

CDocViewTestDoc::CDocViewTestDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
		m_ShapeType = ELLIPSE;
}

CDocViewTestDoc::~CDocViewTestDoc()
{
}

BOOL CDocViewTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CDocViewTestDoc serialization

void CDocViewTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CDocViewTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CDocViewTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDocViewTestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDocViewTestDoc ����

#ifdef _DEBUG
void CDocViewTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocViewTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDocViewTestDoc ���


void CDocViewTestDoc::OnRectangle()
{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		m_ShapeType = RECTANGLE;
		UpdateAllViews(NULL);
}


void CDocViewTestDoc::OnEllipse()
{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		m_ShapeType = ELLIPSE;
		UpdateAllViews(NULL);
}


void CDocViewTestDoc::OnLine()
{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		m_ShapeType = LINE;
		UpdateAllViews(NULL);
}
