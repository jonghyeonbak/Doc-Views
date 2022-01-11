
// DocViewTestView.cpp : CDocViewTestView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DocViewTest.h"
#endif

#include "DocViewTestDoc.h"
#include "DocViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocViewTestView

IMPLEMENT_DYNCREATE(CDocViewTestView, CView)

BEGIN_MESSAGE_MAP(CDocViewTestView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDocViewTestView ����/�Ҹ�

CDocViewTestView::CDocViewTestView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CDocViewTestView::~CDocViewTestView()
{
}

BOOL CDocViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CDocViewTestView �׸���

void CDocViewTestView::OnDraw(CDC* pDC)
{
	CDocViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rc(200, 200, 1000, 400);
	//GetClientRect(&rc); 
	// square in square
	//pDC->Rectangle(&rc); 
	//int width = rc.Width();
	//int height = rc.Height();
	//rc.DeflateRect(width / 4, height / 4);
	//pDC->Rectangle(&rc);

	if (pDoc->m_ShapeType == RECTANGLE) {
			pDC->Rectangle(&rc);
	}
	else if (pDoc->m_ShapeType == ELLIPSE) {
			pDC->Ellipse(&rc);
	}
	else if (pDoc->m_ShapeType == LINE) {
			pDC->MoveTo(rc.left, rc.top);
			pDC->LineTo(rc.right, rc.bottom);
	}
	
}


// CDocViewTestView �μ�

BOOL CDocViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CDocViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CDocViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CDocViewTestView ����

#ifdef _DEBUG
void CDocViewTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDocViewTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocViewTestDoc* CDocViewTestView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewTestDoc)));
	return (CDocViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocViewTestView �޽��� ó����
