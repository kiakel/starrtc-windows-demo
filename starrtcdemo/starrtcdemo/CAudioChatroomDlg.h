#pragma once


// CAudioChatroomDlg 对话框

class CAudioChatroomDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAudioChatroomDlg)

public:
	CAudioChatroomDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAudioChatroomDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_AUDIO_CHATROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
