// CStarRTCMenuDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CStarRTCMenuDialog.h"
#include "afxdialogex.h"
#include "starrtcdemoDlg.h"
#include "CMultipleMeetingDialog.h"
#include "CSettingDialog.h"
#include "CInteracteLiveDlg.h"
#include "CIMDialog.h"
#include "CVoipDlg.h"
#include "CVoipP2PDlg.h"
#include <windows.h>
#include "CLogin.h"

// CStarRTCMenuDialog 对话框

IMPLEMENT_DYNAMIC(CStarRTCMenuDialog, CDialogEx)

CStarRTCMenuDialog::CStarRTCMenuDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MENU, pParent)
{
	m_pUserManager = new CUserManager();
}

CStarRTCMenuDialog::~CStarRTCMenuDialog()
{
	m_bLogIn = false;
	if (m_pUserManager != NULL)
	{
		delete m_pUserManager;
		m_pUserManager = NULL;
	}
}

void CStarRTCMenuDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_USERID, m_UserIDEdit);
	DDX_Control(pDX, IDC_STATIC_USER_PIC, m_UserPicPicControl);
}


BEGIN_MESSAGE_MAP(CStarRTCMenuDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_IM, &CStarRTCMenuDialog::OnBnClickedButtonIm)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLE_MEETING, &CStarRTCMenuDialog::OnBnClickedButtonMultipleMeeting)
	ON_BN_CLICKED(IDC_BUTTON_INTERACTE_LIVE, &CStarRTCMenuDialog::OnBnClickedButtonInteracteLive)
	//ON_BN_CLICKED(IDC_BUTTON_PARAM_SETTING, &CStarRTCMenuDialog::OnBnClickedButtonParamSetting)
	ON_BN_CLICKED(IDC_BUTTON_LIVE_MONITOR, &CStarRTCMenuDialog::OnBnClickedButtonLiveMonitor)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CStarRTCMenuDialog::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_VOIP, &CStarRTCMenuDialog::OnBnClickedButtonVoip)
	ON_BN_CLICKED(IDC_BUTTON_VOICE_CHATROOM, &CStarRTCMenuDialog::OnBnClickedButtonVoiceChatroom)
	ON_BN_CLICKED(IDC_BUTTON_VOIP_P2P, &CStarRTCMenuDialog::OnBnClickedButtonVoipP2p)
END_MESSAGE_MAP()


// CStarRTCMenuDialog 消息处理程序


void CStarRTCMenuDialog::OnBnClickedButtonIm()
{
	CIMDialog dlg(m_pUserManager);
	dlg.DoModal();
}


void CStarRTCMenuDialog::OnBnClickedButtonMultipleMeeting()
{
	CMultipleMeetingDialog dlg(m_pUserManager, this);
	dlg.DoModal();
}


void CStarRTCMenuDialog::OnBnClickedButtonInteracteLive()
{
	CInteracteLiveDlg dlg(m_pUserManager, this);
	dlg.DoModal();
}


/*void CStarRTCMenuDialog::OnBnClickedButtonParamSetting()
{
	CSettingDialog dlg(m_pUserManager);
	dlg.DoModal();
}
*/

BOOL CStarRTCMenuDialog::OnInitDialog()
{
	CLogin login(m_pUserManager);
	m_bLogIn = false;
	CDialogEx::OnInitDialog();
	
	if (m_pUserManager != NULL)
	{
		m_UserIDEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUserId.c_str());
		bool bSuccess = login.logIn();
		if (bSuccess)
		{
			m_bLogIn = true;
			m_UserIDEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUserId.c_str());
		}
		else
		{
			m_bLogIn = false;
			AfxMessageBox("登录失败，请检查配置信息");
			OnOK();
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void CStarRTCMenuDialog::OnBnClickedButtonLiveMonitor()
{
	/*CstartrtcdemoDlg dlg(m_pUserManager, this);
	dlg.DoModal();*/
}


void CStarRTCMenuDialog::OnBnClickedButtonLogin()
{
	if (m_pUserManager != NULL)
	{
		m_UserIDEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUserId.c_str());
		CLogin login(m_pUserManager);
		bool bSuccess = login.logIn();
		if (bSuccess)
		{
			m_bLogIn = true;
			m_UserIDEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUserId.c_str());
		}
		else
		{
			m_bLogIn = false;
			AfxMessageBox("user login failed");
		}

	}
}

void CStarRTCMenuDialog::OnBnClickedButtonVoip()
{
	CVoipDlg dlg(m_pUserManager);
	dlg.DoModal();
}


void CStarRTCMenuDialog::OnBnClickedButtonVoiceChatroom()
{
	
}


void CStarRTCMenuDialog::OnBnClickedButtonVoipP2p()
{
	CVoipP2PDlg dlg;
	dlg.DoModal();
}
