
// MFCApplication13.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCApplication13App:
// Сведения о реализации этого класса: MFCApplication13.cpp
//

class CMFCApplication13App : public CWinApp
{
public:
	CMFCApplication13App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication13App theApp;
