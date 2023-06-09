
// MsgTestView.h : CMsgTestView 类的接口
//

#pragma once
#include "atltypes.h"
#define WM_MYMESSAGE WM_USER+1

class CMsgTestView : public CView
{
protected: // 仅从序列化创建
	CMsgTestView();
	DECLARE_DYNCREATE(CMsgTestView)

// 特性
public:
	CMsgTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMsgTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_pos;
	CString m_str;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	int m_flag;
};

#ifndef _DEBUG  // MsgTestView.cpp 中的调试版本
inline CMsgTestDoc* CMsgTestView::GetDocument() const
   { return reinterpret_cast<CMsgTestDoc*>(m_pDocument); }
#endif

