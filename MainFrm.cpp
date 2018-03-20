
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "Tank_lihongbo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define GAME_WIN_W (800)
#define GAME_WIN_H (600)

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//	ON_WM_SETTINGCHANGE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
#define MY_STYLE (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | FWS_ADDTOTITLE)
	// 创建窗口
	Create(NULL, _T("CQUPT.李洪波.坦克大战"), MY_STYLE, CRect(0, 0, GAME_WIN_W, GAME_WIN_H));
	// 设置客户区大小
	{
		// 获得客户区的大小
		CRect rcCli;
		GetClientRect(rcCli);
		TRACE("%d,%d,%d,%d\r\n", rcCli.left, rcCli.top, rcCli.right, rcCli.bottom);
		assert(rcCli.left == 0);
		assert(rcCli.top == 0);

		// 计算边框的大小，并设置
		RECT rcFrame = { 0, 0, m_Width + m_Width - rcCli.right, m_Height + m_Height - rcCli.bottom };
		MoveWindow(&rcFrame, TRUE);
	}
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_MINIMIZEBOX | WS_SYSMENU;

	return TRUE;
}



// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	SetTimer(ETimerIdGameLoop, 0, NULL);//设置定时器，每次都会进入游戏帧
	m_game.SetHandle(GetSafeHwnd());    //设置游戏主窗口句柄
	return 0;
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case ETimerIdGameLoop: 
		{
		static DWORD dwLastUpdate = GetTickCount();//记录本次时间
		if (GetTickCount() - dwLastUpdate >= 20)
			{
			m_game.EnterFrame(GetTickCount());       //进入游戏帧处理
			dwLastUpdate = GetTickCount();           //记录游戏间隔
			}
		//否则什么也不做
		}
	default:
		break;
	}
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	m_game.OnMouseMove(nFlags, point);     //直接把鼠标消息传给CGame对象
	CFrameWnd::OnMouseMove(nFlags, point);
}

void CMainFrame::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_game.OnLButtonUp(nFlags, point);    //直接把鼠标消息传给CGame对象
	CFrameWnd::OnLButtonUp(nFlags,point);
}




