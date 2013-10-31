#if !defined(AFX_CBUTTON_H__60F5DBE2_D235_4519_98C2_7383C9AE18D4__INCLUDED_)
#define AFX_CBUTTON_H__60F5DBE2_D235_4519_98C2_7383C9AE18D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCButton window
class CButtonST : public CButton
{
// Construction
public:
    CButtonST();
// Attributes
public:
    
// Operations
public:
    //���ñ�����ɫ
    void SetBkColor(COLORREF BkColor);
    //��������ڰ�ť�ϵ�ƫ����ɫ
    void SetShOffset(int nShOffset);
    //����������ɫ
    void SetTextColor(COLORREF TextColor);
    //������ҳ����
    void SetURL(CString strURL);
    //���ñ���ͼƬ
    void SetBkPicture(CBitmap *pBitMap);
// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CButtonST)
    public:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL
// Implementation
public:
    virtual ~CButtonST();
    
    void DrawItem1(LPDRAWITEMSTRUCT lpDrawItemStruct);
    // Generated message map functions
protected:
    //{{AFX_MSG(CButtonST)
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg BOOL OnNcActivate(BOOL bActive);
    afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
    afx_msg void OnKillFocus(CWnd* pNewWnd);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    //}}AFX_MSG
protected:
    //����Ƿ��ڰ�ť����
    BOOL m_IsPressed;
    COLORREF m_BkColor;
    int      m_nShOffset;
    COLORREF m_TextColor;
    CString  m_strURL;
    CBitmap  *m_pBitMapBK;
protected:
    //������ɫƫ��
    COLORREF OffsetColor(COLORREF color,int nOffset);
    //����뿪
    LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
    DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_BUTTONST_H__1271FF9C_E28C_4D3B_B429_AFE65924A5D0__INCLUDED_)
 

 

