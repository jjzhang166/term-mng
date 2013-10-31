// ButtonST.cpp : implementation file
//
#include "stdafx.h"
#include"CButtonST.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BS_TYPEMASK SS_TYPEMASK
/////////////////////////////////////////////////////////////////////////////
// CButtonST
CButtonST::CButtonST()
{   
    m_IsPressed = FALSE;
    m_BkColor = RGB(216,233,216);
    m_nShOffset = 30;
    m_TextColor = RGB(0,0,0);
    m_strURL = "";
    m_pBitMapBK = NULL;
}
CButtonST::~CButtonST()
{
    if(m_pBitMapBK!=NULL)
    {
        delete m_pBitMapBK;
        m_pBitMapBK = NULL;
    }
}
BEGIN_MESSAGE_MAP(CButtonST, CButton)
    //{{AFX_MSG_MAP(CButtonST)
    ON_WM_MOUSEMOVE()
    ON_WM_NCACTIVATE()
    ON_WM_NCMOUSEMOVE()
    ON_WM_KILLFOCUS()
    ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
    ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CButtonST message handlers
//ÉèÖÃ±³¾°ÑÕÉ«
void CButtonST::SetBkColor(COLORREF BkColor)
{
    m_BkColor = BkColor;
    this->Invalidate();
}
//ÉèÖÃÊó±êÔÚ°´Å¥ÉÏµÄÆ«ÒÆÑÕÉ«
void CButtonST::SetShOffset(int nShOffset)
{
    m_nShOffset = nShOffset;
    this->Invalidate();
}
//ÉèÖÃ×ÖÌåÑÕÉ«
void CButtonST::SetTextColor(COLORREF TextColor)
{
    m_TextColor = TextColor;
    this->Invalidate();
}
//ÉèÖÃÍøÒ³Á´½Ó
void CButtonST::SetURL(CString strURL)
{
    m_strURL = strURL;
}
//ÉèÖÃ±³¾°Í¼Æ¬
void CButtonST::SetBkPicture(CBitmap *pBitMap)
{
    if(m_pBitMapBK==pBitMap)
        return;
    if(m_pBitMapBK!=NULL)
    {
        delete m_pBitMapBK;
        m_pBitMapBK = pBitMap;
    }
    m_pBitMapBK = pBitMap;
    this->Invalidate();
}
//±³¾°ÑÕÉ«Æ«ÒÆ
COLORREF CButtonST::OffsetColor(COLORREF color,int nOffset)
{
    BYTE    byRed = 0;
    BYTE    byGreen = 0;
    BYTE    byBlue = 0;
    short   shOffsetR = nOffset;
    short   shOffsetG = nOffset;
    short   shOffsetB = nOffset;
    if (nOffset < -255 || nOffset > 255)
    {
        nOffset = 30;
    }
    
    // Get RGB components of specified color
    byRed = GetRValue(color);
    byGreen = GetGValue(color);
    byBlue = GetBValue(color);
    
    // Calculate max. allowed real offset
    if (nOffset > 0)
    {
        if (byRed + nOffset > 255)      shOffsetR = 255 - byRed;
        if (byGreen + nOffset > 255)    shOffsetG = 255 - byGreen;          
        if (byBlue + nOffset > 255)     shOffsetB = 255 - byBlue;
        nOffset = min(min(shOffsetR, shOffsetG), shOffsetB);
    }
    else
    {
        if (byRed + nOffset < 0)        shOffsetR = -byRed;
        if (byGreen + nOffset < 0)      shOffsetG = -byGreen;
        if (byBlue + nOffset < 0)       shOffsetB = -byBlue;
        
        nOffset = max(max(shOffsetR, shOffsetG), shOffsetB);
    }
    int r,g,b;
    r = byRed + nOffset;
    g =byGreen + nOffset;
    b =byBlue + nOffset;
    return RGB(r,g,b);
}
void CButtonST::DrawItem1(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
    // TODO: Add your code to draw the specified item   
    
    
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    CRect offRect = rect;
    int ndist = 2;
    offRect.left+= ndist;
    offRect.right -=ndist;
    offRect.top += ndist;
    offRect.bottom -=ndist;
    
    
    pDC->SetBkMode(TRANSPARENT);
    pDC->SetTextColor(m_TextColor);
    
    //»æÖÆ±³¾°
    if(m_pBitMapBK!=NULL)
    {
        CDC* pNewDC = new CDC;
        pNewDC->CreateCompatibleDC(pDC);
        pNewDC->SelectObject(m_pBitMapBK);
        BITMAP   bmp;
        m_pBitMapBK->GetBitmap(&bmp);
        if(m_IsPressed)
        {
            pDC->StretchBlt(0,0,rect.Width(),rect.Height(),pNewDC,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
        }
        else
        {
            CBrush brush(RGB(220,220,220));//RGB(m_nShOffset,m_nShOffset,m_nShOffset));
            pDC->FillRect(&rect,&brush);
            pDC->StretchBlt(0,0,rect.Width(),rect.Height(),pNewDC,0,0,bmp.bmWidth,bmp.bmHeight,SRCAND);
        }
        
        delete pNewDC;
        pNewDC = NULL;
    }
    else
    {
        if(m_IsPressed)
        {
            CBrush brush(OffsetColor(m_BkColor,m_nShOffset));
            pDC->FillRect(rect,&brush);             
            CBrush brush1(RGB(128,128,128));
            pDC->FrameRect(rect,&brush1);
            pDC->FrameRect(offRect,&brush1);            
        }
        else
        {
            CBrush brush(m_BkColor);
            pDC->FillRect(rect,&brush);
            CBrush brush1(RGB(128,128,128));
            pDC->FrameRect(offRect,&brush1);
        }
    }
    
    
    CString sTitle;
    GetWindowText(sTitle);
    offRect.OffsetRect(0,rect.Height()/2-8);
    //  pDC->DrawText(sTitle, sTitle.GetLength(),offRect, DT_WORDBREAK | DT_CENTER);
    pDC->DrawText(sTitle, sTitle.GetLength(),offRect, DT_WORDBREAK|DT_CENTER);
}
void CButtonST::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
    // TODO: Add your code to draw the specified item  
    DrawItem1(lpDrawItemStruct);
    return;
    
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    CRect offRect = rect;
    int ndist = 2;
    offRect.left+= ndist;
    offRect.right -=ndist;
    offRect.top += ndist;
    offRect.bottom -=ndist;
    CDC* pResetDC=new CDC();
    pResetDC->CreateCompatibleDC(pDC);
    CBitmap bitmap;
    bitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
    pResetDC->SelectObject(&bitmap);
    
    pResetDC->SetBkMode(TRANSPARENT);
    pResetDC->SetTextColor(m_TextColor);
    
    //»æÖÆ±³¾°
    if(m_pBitMapBK!=NULL)
    {
        CDC* pNewDC = new CDC;
        pNewDC->CreateCompatibleDC(pResetDC);
        pNewDC->SelectObject(m_pBitMapBK);
        BITMAP   bmp;
        m_pBitMapBK->GetBitmap(&bmp);
        if(m_IsPressed)
        {
            pResetDC->StretchBlt(0,0,rect.Width(),rect.Height(),pNewDC,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
        }
        else
        {
            CBrush brush(RGB(220,220,220));//RGB(m_nShOffset,m_nShOffset,m_nShOffset));
            pResetDC->FillRect(&rect,&brush);
            pResetDC->StretchBlt(0,0,rect.Width(),rect.Height(),pNewDC,0,0,bmp.bmWidth,bmp.bmHeight,SRCAND);
        }
        
        delete pNewDC;
        pNewDC = NULL;
    }
    else
    {
        if(m_IsPressed)
        {
            CBrush brush(OffsetColor(m_BkColor,m_nShOffset));
            pResetDC->FillRect(rect,&brush);                
            CBrush brush1(RGB(128,128,128));
            pResetDC->FrameRect(rect,&brush1);
            pResetDC->FrameRect(offRect,&brush1);
            
        }
        else
        {
            CBrush brush(m_BkColor);
            pResetDC->FillRect(rect,&brush);
            CBrush brush1(RGB(128,128,128));
            pResetDC->FrameRect(offRect,&brush1);
        }
    }
    
    
    CString sTitle;
    GetWindowText(sTitle);
    offRect.OffsetRect(0,rect.Height()/2-8);
//  pDC->DrawText(sTitle, sTitle.GetLength(),offRect, DT_WORDBREAK | DT_CENTER);
    pResetDC->DrawText(sTitle, sTitle.GetLength(),offRect, DT_CENTER);
    pDC->StretchBlt(0,0,rect.Width(),rect.Height(),pResetDC,0,0,rect.Width(),rect.Height(),SRCCOPY);
    delete pResetDC;
}
void CButtonST::OnMouseMove(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    TRACKMOUSEEVENT     csTME;
    csTME.cbSize = sizeof(csTME);
    csTME.dwFlags = TME_LEAVE;
    csTME.hwndTrack = m_hWnd;
    ::_TrackMouseEvent(&csTME); 
    if(m_IsPressed==FALSE)
    {
        m_IsPressed = TRUE;     
        this->Invalidate();
    }
 
    CButton::OnMouseMove(nFlags, point);
}
BOOL CButtonST::OnNcActivate(BOOL bActive) 
{
    // TODO: Add your message handler code here and/or call default
    return CButton::OnNcActivate(bActive);
}
void CButtonST::OnNcMouseMove(UINT nHitTest, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    
    
    CButton::OnNcMouseMove(nHitTest, point);
}
void CButtonST::OnKillFocus(CWnd* pNewWnd) 
{
    CButton::OnKillFocus(pNewWnd);  
    // TODO: Add your message handler code here
}
LRESULT CButtonST::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
    m_IsPressed = FALSE;
    this->Invalidate();
    return 0;
} // End of OnMouseLeave
BOOL CButtonST::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
    // TODO: Add your specialized code here and/or call the base class  
    dwStyle |= BS_OWNERDRAW;
    return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
void CButtonST::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    if(m_strURL.IsEmpty()==FALSE)
    {
        SHELLEXECUTEINFO    csSEI;
        
        memset(&csSEI, 0, sizeof(csSEI));
        csSEI.cbSize = sizeof(SHELLEXECUTEINFO);
        csSEI.fMask = SEE_MASK_FLAG_NO_UI;
        csSEI.lpVerb = _T("open");
        csSEI.lpFile = m_strURL;
        csSEI.nShow = SW_SHOWMAXIMIZED;
        ::ShellExecuteEx(&csSEI);
    }
    CButton::OnLButtonDown(nFlags, point);
}
BOOL CButtonST::PreCreateWindow(CREATESTRUCT& cs) 
{
    // TODO: Add your specialized code here and/or call the base class
    
    return CButton::PreCreateWindow(cs);
}
void CButtonST::PreSubclassWindow() 
{
    // TODO: Add your specialized code here and/or call the base class
    ModifyStyle(BS_TYPEMASK, BS_OWNERDRAW, SWP_FRAMECHANGED);   
    CButton::PreSubclassWindow();
}
 

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

 
 