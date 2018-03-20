
// MainFrm.h: CMainFrame 类的接口
//

#pragma once
#include "CGame.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	
	

// 特性
public:

// 操作
public:
CMainFrame();
DECLARE_DYNCREATE(CMainFrame)
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	int m_Width{ 800 };                      //定义客户区大小
	int m_Height{ 600 };

	enum ETimerId {ETimerIdGameLoop=1};      //定时器id

	CGame m_game;                           //游戏对象

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent); //定时器消息处理函数
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);//鼠标移动消息处理函数
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);//鼠标左键抬起事件
};


