
// DocViewTestView.cpp : CDocViewTestView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDocViewTestView 생성/소멸

CDocViewTestView::CDocViewTestView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDocViewTestView::~CDocViewTestView()
{
}

BOOL CDocViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDocViewTestView 그리기

void CDocViewTestView::OnDraw(CDC* pDC)
{
	CDocViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// CDocViewTestView 인쇄

BOOL CDocViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDocViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDocViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDocViewTestView 진단

#ifdef _DEBUG
void CDocViewTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDocViewTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocViewTestDoc* CDocViewTestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewTestDoc)));
	return (CDocViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocViewTestView 메시지 처리기
