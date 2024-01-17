
// MFCApplication13Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication13Dlg
class CMFCApplication13Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication13Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION13_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	double h;
	double w;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	double deep;
	double d1;
	double faskaLenght;
	double faskaDepth;
	afx_msg void OnEnChangeEdit6();
	double l1;
	double l2;
	double l3;
	double d2;
	double d3;
	double l4;
	double l5;
	double x;
	double y;
	double CMFCApplication13Dlg::Prov(double h, double w, double deep, double d1, double faskaLenght, double faskaDepth, double l1, double l2, double l3, double l4, double l5, double d2, double d3, double x, double y);

	double r1;
};
