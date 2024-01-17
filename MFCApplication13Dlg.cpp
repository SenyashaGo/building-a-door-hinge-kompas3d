
// MFCApplication13Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication13.h"
#include "MFCApplication13Dlg.h"
#include "afxdialogex.h"
//#include "stdafx.h"
#include "afxdialogex.h"
#include "math.h"
#include "D:\компас\SDK\Include\ksConstants.h"
#include "D:\компас\SDK\Include\ksConstants3D.h"
#include <comutil.h>
#include <cmath>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#import "D:\компас\SDK\lib\kAPI5.tlb"

using namespace Kompas6API5;
KompasObjectPtr pKompasApp5;

ksPartPtr pPart; // = PartDoc->GetTopPart();
ksDocument3DPtr pDoc;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication13Dlg



CMFCApplication13Dlg::CMFCApplication13Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION13_DIALOG, pParent)
	, h(80)
	, w(60)
	, deep(20)
	, d1(10)
	, faskaLenght(5)
	, faskaDepth(5)
	, l1(25)
	, l2(5)
	, l3(25)
	, d2(8)
	, d3(22)
	, l4(27)
	, l5(20)
	, x(15)
	, y(40)
	, r1(5)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication13Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, h);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT2, w);
	//DDV_MinMaxDouble(pDX, w, 10, 200);
	DDX_Text(pDX, IDC_EDIT3, deep);
	//DDV_MinMaxDouble(pDX, deep, 10, 200);
	DDX_Text(pDX, IDC_EDIT4, d1);
	//DDV_MinMaxDouble(pDX, d1, 10, 200);
	DDX_Text(pDX, IDC_EDIT5, faskaLenght);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT6, faskaDepth);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT7, l1);
	DDV_MinMaxDouble(pDX, l1, 5, w-1);
	DDX_Text(pDX, IDC_EDIT8, l2);
	DDV_MinMaxDouble(pDX, l2, 1, deep-1);
	DDX_Text(pDX, IDC_EDIT9, l3);
	//DDV_MinMaxDouble(pDX, h, 5, h/2-l5);
	DDX_Text(pDX, IDC_EDIT10, d2);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT11, d3);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT12, l4);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT13, l5);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT14, x);
	//DDV_MinMaxDouble(pDX, h, 10, 200);
	DDX_Text(pDX, IDC_EDIT15, y);
	DDV_MinMaxDouble(pDX, y, 10, h-d1);
	DDX_Text(pDX, IDC_EDIT16, r1);
	DDV_MinMaxDouble(pDX, r1, 1, 20);
}

BEGIN_MESSAGE_MAP(CMFCApplication13Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication13Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication13Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CMFCApplication13Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT6, &CMFCApplication13Dlg::OnEnChangeEdit6)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication13Dlg

BOOL CMFCApplication13Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication13Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication13Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication13Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication13Dlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


void CMFCApplication13Dlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

double CMFCApplication13Dlg::Prov(double h, double w, double deep, double d1, double faskaLenght, double faskaDepth, double l1, double l2, double l3, double l4, double l5, double d2, double d3, double x, double y)
{
	int k = 0;
	if (h < 0) {
		k = 1;
	}
	if (w < 0) {
		k = 1;
	}
	if (deep < 0) {
		k = 1;
	}
	if (d1 < 0) {
		k = 1;
	}
	if (faskaLenght < 0) {
		k = 1;
	}
	if (faskaDepth < 0) {
		k = 1;
	}
	if (l1 < 0) {
		k = 1;
	}
	if (l2 < 0) {
		k = 1;
	}
	if (l3 < 0) {
		k = 1;
	}
	if (l4 < 0) {
		k = 1;
	}
	if (l5 < 0) {
		k = 1;
	}
	if (d2 < 0) {
		k = 1;
	}
	if (d3 < 0) {
		k = 1;
	}
	if (x < 0) {
		k = 1;
	}
	if (y < 0) {
		k = 1;
	}
	if (h < y) {
		k = 1;
	}
	if (l3 > h) {
		k = 1;
	}
	/*if (l5 > (1/3)*h/2) {
		k = 1;
	}*/
	if (l2 > deep) {
		k = 1;
	}
	if (l1 > w) {
		k = 1;
	}
	if (d2 > d3) {
		k = 1;
	}
	if (y > (h-r1)) {
		k = 2;
	}
	return k;
}

void CMFCApplication13Dlg::OnBnClickedOk()
{
	UpdateData(true);
	int res = Prov(h, w, deep, d1, faskaLenght, faskaDepth, l1, l2, l3, l4, l5, d2, d3, x, y);
	
	if (res == 0)
	{


		BeginWaitCursor();

		CComPtr<IUnknown> pKompasAppUnk = nullptr;
		if (!pKompasApp5)
		{
			// Получаем CLSID для Компас
			CLSID InvAppClsid;
			HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}

			// Проверяем есть ли запущенный экземпляр Компас
			//если есть получаем IUnknown
			hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
			if (FAILED(hRes)) {
				// Приходится запускать Компас самим так как работающего нет
				// Также получаем IUnknown для только что запущенного приложения Компас
				TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
				hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
				if (FAILED(hRes)) {
					pKompasApp5 = nullptr;
					return;
				}
			}

			// Получаем интерфейс приложения Компас
			hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
			if (FAILED(hRes)) {
				return;
			}
		}

		// делаем Компас видимым
		pKompasApp5->Visible = true;

		pDoc = pKompasApp5->Document3D();

		pDoc->Create(false, true);

		pPart = pDoc->GetPart(pTop_Part);

		ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);

		ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();

		pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

		pSketch->Create();

		ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();
		//UpdateData();


		// создаем главный эскиз детали
		p2DDoc->ksLineSeg(w / 2, h / 2, w / 2, -(h / 2), 1);
		p2DDoc->ksLineSeg(-w / 2, -h / 2, -w / 2, h / 2, 1);
		p2DDoc->ksLineSeg(w / 2, -h / 2, -w / 2, -h / 2, 1);
		p2DDoc->ksLineSeg(w / 2, h / 2, -w / 2, h / 2, 1);


		pSketchDef->EndEdit();

		//делаем выдавливание первого эскиза
		ksEntityPtr pExtrudeDowel = pPart->NewEntity(o3d_baseExtrusion);
		ksBaseExtrusionDefinitionPtr pBaseDef = pExtrudeDowel->GetDefinition();
		pBaseDef->directionType = dtNormal;
		pBaseDef->SetSketch(pSketch);
		pBaseDef->SetSideParam(true, etBlind, deep, 0, false);
		pExtrudeDowel->Create();




		//скругления по бокам
		ksEntityCollectionPtr fledges1 = pPart->EntityCollection(o3d_edge);
		ksEntityPtr pFillet = pPart->NewEntity(o3d_fillet);

		ksFilletDefinitionPtr pFilletDef = pFillet->GetDefinition();
		pFilletDef->radius = r1;
		ksEntityCollectionPtr fl1 = pFilletDef->array();
		fl1->Clear();

		for (int i = 0; i < fledges1->GetCount(); i++)
		{
			ksEntityPtr ed = fledges1->GetByIndex(i);
			ksEdgeDefinitionPtr def = ed->GetDefinition();
			
				if (def->IsStraight())
				{

					ksVertexDefinitionPtr p1 = def->GetVertex(true);
					ksVertexDefinitionPtr p2 = def->GetVertex(false);
					double x1, y1, z1, x2, y2, z2;
					if (p1 && p2)
					{
						p1->GetPoint(&x1, &y1, &z1);
						p2->GetPoint(&x2, &y2, &z2);
						//((x1 > 0 && y1 > 0) || (x2 > 0 && y2 < 0)) && 
						if (abs(x1 - x2) < 0.0001 && abs(y1 - y2) < 0.0001 && x1>0)
						{
							//ed->Putname("LoftEdge");
							fl1->Add(ed);
						}
					}

				}
		}
		pFillet->Create();

		ksEntityPtr pFilletZ = pPart->NewEntity(o3d_fillet);
		ksFilletDefinitionPtr pFilletZDef = pFilletZ->GetDefinition();
		pFilletZDef->radius = 5;
		pFilletZDef->tangent = true;

		//ksEntityCollectionPtr pCollectionZ = pPart->EntityCollection(o3d_edge);
		//ksEntityCollectionPtr pCollectionFil = pFilletZDef->array();
		//pCollectionFil->Clear();
		////pCollectionFil->Add(pCollectionZ->GetByIndex(2));
		////pCollectionFil->Add(pCollectionZ->GetByIndex(3));
		//pCollectionFil->Add(pCollectionZ->GetByIndex(4));
		//pCollectionFil->Add(pCollectionZ->GetByIndex(5));
		//pFilletZ->Create();





		ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);

		//ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();

		pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

		pSketch->Create();
		//смещенная плоскость
		//ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();
		ksEntityPtr pPlane = pPart->NewEntity(o3d_planeOffset);
		ksPlaneOffsetDefinitionPtr pPlaneDef = pPlane->GetDefinition();

		pPlaneDef->direction = true;
		pPlaneDef->offset = deep;
		pPlaneDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

		pPlane->Create();

		//делаем отверстия в эскизе
		ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch2->GetDefinition();
		pSketchDef->SetPlane(pPlane);
		pSketch2->Create();
		p2DDoc = pSketchDef->BeginEdit();
		p2DDoc->ksCircle(x, y/2, d1 / 2, 1);
		p2DDoc->ksCircle(x, -y/2, d1 / 2, 1);
		pSketchDef->EndEdit();

		//вырезаем отверстия
		ksEntityPtr pExtrude2 = pPart->NewEntity(o3d_cutExtrusion);
		ksCutExtrusionDefinitionPtr pCutDef = pExtrude2->GetDefinition();
		pCutDef->directionType = dtNormal;
		pCutDef->SetSketch(pSketch2);
		pCutDef->SetSideParam(true, etThroughAll, 0, 0, false);
		pExtrude2->Create();


		//делаем фаски

		ksEntityPtr pLoft = pPart->NewEntity(o3d_bossLoft);

		ksBossLoftDefinitionPtr pLoftDef = pLoft->GetDefinition();
		pLoftDef->SetLoftParam(FALSE, TRUE, TRUE);

		ksEntityCollectionPtr sk = pLoftDef->Sketchs();
		sk->Clear();
		sk->Add(pExtrude2);
		pLoft->Create();


		ksEntityCollectionPtr fledges = pPart->EntityCollection(o3d_edge);
		ksEntityPtr pChamfer = pPart->NewEntity(o3d_chamfer);

		ksChamferDefinitionPtr pChamferDef = pChamfer->GetDefinition();
		pChamferDef->SetChamferParam(false, faskaLenght, faskaDepth);
		ksEntityCollectionPtr fl = pChamferDef->array();
		fl->Clear();

		for (int i = 0; i < fledges->GetCount(); i++)
		{

			ksEntityPtr ed = fledges->GetByIndex(i);
			ksEdgeDefinitionPtr def = ed->GetDefinition();

			if (def->IsCircle())
			{
				//def->Get
				ksVertexDefinitionPtr p1 = def->GetVertex(true);
				ksVertexDefinitionPtr p2 = def->GetVertex(false);

				double x1, y1, z1, x2, y2, z2;
				if (p1 && p2)
				{
					p1->GetPoint(&x1, &y1, &z1);
					p2->GetPoint(&x2, &y2, &z2);

					if (abs(z1) < 0.001 )
					{
						//ed->Putname("LoftEdge");
						fl->Add(ed);
					}
				}
			}
		}
		pChamfer->Create();

		//смещенная плоскость для скоса
		ksEntityPtr pPlane3 = pPart->NewEntity(o3d_planeOffset);
		ksPlaneOffsetDefinitionPtr pPlaneDef3 = pPlane3->GetDefinition();

		pPlaneDef3->direction = true;
		pPlaneDef3->offset = -h / 2;
		pPlaneDef3->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

		pPlane3->Create();

		//эскиз скоса

		ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch3->GetDefinition();
		pSketchDef->SetPlane(pPlane3);
		pSketch3->Create();
		p2DDoc = pSketchDef->BeginEdit();
		p2DDoc->ksLineSeg(-w / 2 + l1, 0, -w / 2, 0, 1);
		p2DDoc->ksLineSeg(-w / 2, 0, -w / 2, -(deep - l2), 1);
		p2DDoc->ksLineSeg(-w / 2, -(deep - l2), -w / 2 + l1, 0, 1);
		pSketchDef->EndEdit();


		//создаем скос выдавливанием
		ksEntityPtr pExtrude3 = pPart->NewEntity(o3d_cutExtrusion);
		ksCutExtrusionDefinitionPtr pCutDef2 = pExtrude3->GetDefinition();
		pCutDef2->directionType = dtReverse;
		pCutDef2->SetSketch(pSketch3);
		pCutDef2->SetSideParam(false, etThroughAll, 0, 0, false);
		pExtrude3->Create();

		/*ksEntityPtr pChamfer1 = pPart->NewEntity(o3d_chamfer);

		pChamferDef = pChamfer1->GetDefinition();
		pChamferDef->SetChamferParam(true, 2, 2);

		fl = pChamferDef->array();
		fl->Clear();

		for (int i = 0; i < fledges->GetCount(); i++)
		{
			ksEntityPtr ed = fledges->GetByIndex(i);
			ksEdgeDefinitionPtr def = ed->GetDefinition();

			if (def->GetOwnerEntity() == pRotate)
			{
				if (def->IsCircle())
				{
					ksVertexDefinitionPtr p1 = def->GetVertex(true);
					ksVertexDefinitionPtr p2 = def->GetVertex(false);
					double x1, y1, z1;

					p1->GetPoint(&x1, &y1, &z1);
					if (y1 == m_Dcentr / 2.f)
					{
						ed->Putname("RotateEdge");
						fl->Add(ed);
						if (x1 == 0) {
							ksFaceDefinitionPtr f = def->GetAdjacentFace(true);
							ksEntityPtr face = f->GetEntity();
							face->Putname("Face4Assembly");
							face->Update();
						}
					}

				}

			}
		}

		pChamfer1->Create();*/


		// смещенная вспомогательная плоскость для петли
		ksEntityPtr pPlane2 = pPart->NewEntity(o3d_planeOffset);
		ksPlaneOffsetDefinitionPtr pPlaneDef1 = pPlane2->GetDefinition();

		pPlaneDef1->direction = true;
		pPlaneDef1->offset = -l3;//-l3 
		pPlaneDef1->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

		pPlane2->Create();

		// создаем эскиз скругления петель
		ksEntityPtr pSketch5 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch5->GetDefinition();
		pSketchDef->SetPlane(pPlane2);
		pSketch5->Create();
		p2DDoc = pSketchDef->BeginEdit();
		p2DDoc->ksCircle(-l4, 0, d3 / 2, 1);
		//p2DDoc->ksCircle(-27, 0, 5 / 2, 1);
		pSketchDef->EndEdit();


		//выдавливаем скругления
		ksEntityPtr pExtrudeDowel2 = pPart->NewEntity(o3d_baseExtrusion);
		ksBaseExtrusionDefinitionPtr pBaseDef2 = pExtrudeDowel2->GetDefinition();
		pBaseDef2->directionType = dtNormal;
		pBaseDef2->SetSketch(pSketch5);
		pBaseDef2->SetSideParam(true, etBlind, l5, 0, false);
		pExtrudeDowel2->Create();

		//доделываем петли эскизом!!!!
		ksEntityPtr pSketch6 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch6->GetDefinition();
		pSketchDef->SetPlane(pPlane2);
		pSketch6->Create();
		p2DDoc = pSketchDef->BeginEdit();

		p2DDoc->ksLineSeg(-w / 2, -(deep - l2), -w / 2 + l1, 0, 1);

		p2DDoc->ksLineSeg(-w / 2 + l1, 0, -l4, d3 / 2, 1);
		p2DDoc->ksLineSeg(-l4, d3 / 2, -w / 2, -(deep - l2), 1);
		pSketchDef->EndEdit();

		// так же выдавливаем
		ksEntityPtr pExtrudeDowel4 = pPart->NewEntity(o3d_baseExtrusion);
		ksBaseExtrusionDefinitionPtr pBaseDef4 = pExtrudeDowel4->GetDefinition();
		pBaseDef4->directionType = dtNormal;
		pBaseDef4->SetSketch(pSketch6);
		pBaseDef4->SetSideParam(true, etBlind, l5, 0, false);
		pExtrudeDowel4->Create();

		// эскиз среза для скругления
		ksEntityPtr pSketch7 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch7->GetDefinition();
		pSketchDef->SetPlane(pPlane2);
		pSketch7->Create();
		p2DDoc = pSketchDef->BeginEdit();

		p2DDoc->ksLineSeg(-l4, d3 / 2, (l1 - w / 2), d3 / 2, 1);
		p2DDoc->ksLineSeg(-w / 2 + l1, 0, (l1 - w / 2), d3 / 2, 1);
		p2DDoc->ksLineSeg(-w / 2 + l1, 0, -l4, d3 / 2, 1);
		pSketchDef->EndEdit();

		// срезаем ненужную часть
		ksEntityPtr pExtrudeDowel3 = pPart->NewEntity(o3d_cutExtrusion);
		ksCutExtrusionDefinitionPtr pBaseDef3 = pExtrudeDowel3->GetDefinition();
		pBaseDef3->cut = true;
		pBaseDef3->directionType = dtReverse;
		pBaseDef3->SetSketch(pSketch7);
		pBaseDef3->SetSideParam(false, etThroughAll, 0, 0, false);
		pExtrudeDowel3->Create();



		// делаем маленькое отверстие
		ksEntityPtr pSketch8 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch8->GetDefinition();
		pSketchDef->SetPlane(pPlane2);
		pSketch8->Create();
		p2DDoc = pSketchDef->BeginEdit();

		p2DDoc->ksCircle(-l4, 0, d2 / 2, 1);
		pSketchDef->EndEdit();

		// вырезаем маленькое отверстие
		ksEntityPtr pExtrudeDowel5 = pPart->NewEntity(o3d_cutExtrusion);
		ksCutExtrusionDefinitionPtr pBaseDef5 = pExtrudeDowel5->GetDefinition();
		pBaseDef5->cut = true;
		pBaseDef5->directionType = dtReverse;
		pBaseDef5->SetSketch(pSketch8);
		pBaseDef5->SetSideParam(false, etThroughAll, 0, 0, false);
		pExtrudeDowel5->Create();

		// зеркальный массив петель
		ksEntityPtr pMirrorCopy = pPart->NewEntity(o3d_mirrorOperation);
		ksMirrorCopyDefinitionPtr pMirrorDef = pMirrorCopy->GetDefinition();
		pMirrorDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));
		fl = pMirrorDef->GetOperationArray();
		fl->Clear();
		fl->Add(pExtrudeDowel2);
		fl->Add(pExtrudeDowel4);
		fl->Add(pExtrudeDowel3);
		fl->Add(pExtrudeDowel5);
		pMirrorCopy->Create();

		//смещенная плоскость для скоса на петлях
		ksEntityPtr pPlane9 = pPart->NewEntity(o3d_planeOffset);
		ksPlaneOffsetDefinitionPtr pPlaneDef9 = pPlane9->GetDefinition();
		pPlaneDef9->direction = true;
		pPlaneDef9->offset = -d3 / 2;
		pPlaneDef9->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));
		pPlane9->Create();

		//эскиз скоса петли
		ksEntityPtr pSketch10 = pPart->NewEntity(o3d_sketch);
		pSketchDef = pSketch10->GetDefinition();
		pSketchDef->SetPlane(pPlane9);
		pSketch10->Create();
		p2DDoc = pSketchDef->BeginEdit();
		p2DDoc->ksLineSeg(-(w / 2) + 5, -l3, -((w / 2)), -(l3 - 5), 1);
		p2DDoc->ksLineSeg(-((w / 2)), -(l3 - 5), -d3 / 2 - (w / 2), -(l3 - 5), 1);
		p2DDoc->ksLineSeg(-d3 / 2 - (w / 2), -(l3 - 5), -d3 / 2 - (w / 2), -(l3 - 5) - 5, 1);
		p2DDoc->ksLineSeg(-d3 / 2 - (w / 2), -(l3 - 5) - 5, -(w / 2) + 5, -l3, 1);
		pSketchDef->EndEdit();

		// вырезаем скос
		ksEntityPtr pExtrudeDowel8 = pPart->NewEntity(o3d_cutExtrusion);
		ksCutExtrusionDefinitionPtr pBaseDef8 = pExtrudeDowel8->GetDefinition();
		pBaseDef8->cut = true;
		pBaseDef8->directionType = dtReverse;
		pBaseDef8->SetSketch(pSketch10);
		pBaseDef8->SetSideParam(false, etBlind, d3, 0, false);
		pExtrudeDowel8->Create();

		/*ksEntityPtr pCircularCopy = pPart->NewEntity(o3d_curveCopy);
		ksCurveCopyDefinitionPtr pCirk = pCircularCopy->GetDefinition();
		pCirk->count = 2;
		pCirk->fullCurve = TRUE;
		ksEntityCollectionPtr EntityCollection = pCirk->CurveArray();
		EntityCollection->Clear();
		EntityCollection->Add(pExtrudeDowel8);
		pCircularCopy->Create();*/

		ksEntityPtr pCircularCopy = pPart->NewEntity(o3d_meshCopy);
		ksMeshCopyDefinitionPtr pCirk = pCircularCopy->GetDefinition();
		pCirk->insideFlag = true;
		pCirk->SetCopyParamAlongAxis(true, 90, 2, 30, false);
		ksEntityCollectionPtr EntityCollection = pCirk->OperationArray();
		EntityCollection->Clear();
		/*EntityCollection->Add(pExtrudeDowel2);
		EntityCollection->Add(pExtrudeDowel4);
		EntityCollection->Add(pExtrudeDowel3);
		EntityCollection->Add(pExtrudeDowel5);*/
		EntityCollection->Add(pExtrudeDowel8);
		pCircularCopy->Create();

	}
	else {
		if (res == 2)
		{
			AfxMessageBox(L"Неправильно введен y, он БОЛЬШЕ чем h(высота детали)!");
		}
		else {
			AfxMessageBox(L"Ошибка данных!");
		}
		

	}
	
	/*ksEntityPtr pSketch11 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch11->GetDefinition();
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));
	pSketch11->Create();
	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksCircle((w/2) - 11, -((h/2)-11), 11, 1);
	pSketchDef->EndEdit();*/
	

	//// смещенная плоскость для петли
	//ksEntityPtr pPlane4 = pPart->NewEntity(o3d_planeOffset);
	//ksPlaneOffsetDefinitionPtr pPlaneDef4 = pPlane4->GetDefinition();

	//pPlaneDef4->direction = true;
	//pPlaneDef4->offset = -h / 2 + 15;
	//pPlaneDef4->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	//pPlane4->Create();

	////
	//ksEntityPtr pPlane6 = pPart->NewEntity(o3d_planeAngle);
	//ksPlaneAngleDefinitionPtr pPlaneDef6 = pPlane6->GetDefinition();

	//pPlaneDef6->angle = -45;
	//pPlaneDef6->SetPlane(pPart->GetDefaultEntity(pPlane4));

	//pPlane6->Create();

	//// создание эскиза скругления
	//ksEntityPtr pSketch5 = pPart->NewEntity(o3d_sketch);
	//pSketchDef = pSketch5->GetDefinition();
	//pSketchDef->SetPlane(pPlane4);
	//pSketch5->Create();
	//p2DDoc = pSketchDef->BeginEdit();
	//p2DDoc->ksCircle(-27, 0, 22 / 2, 1);
	////p2DDoc->ksCircle(-27, 0, 5 / 2, 1);
	//pSketchDef->EndEdit();



	//// выдавливание окружности петли
	//ksEntityPtr pExtrude4 = pPart->NewEntity(o3d_cutExtrusion);
	//ksCutExtrusionDefinitionPtr pCutDef4 = pExtrude4->GetDefinition();
	//pCutDef4->directionType = dtReverse;
	//pCutDef4->SetSketch(pSketch5);
	//pCutDef4->SetSideParam(false, 0, 20, 0, false);
	//pExtrude4->Create();


	//ksEntityPtr pPlane7 = pPart->NewEntity(o3d_planeAngle);
	//ksPlaneAngleDefinitionPtr pPlaneDef2 = pPlane7->GetDefinition();

	////pPlaneDef1->direction = true;
	////pPlaneDef1->offset = deep - 5;
	//pPlaneDef2->angle = -50;
	//pPlaneDef2->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));
	//pPlaneDef2->SetAxis(pPart->GetDefaultEntity(o3d_planeXOY));

	//pPlane7->Create();
	//
	//
}

void CMFCApplication13Dlg::OnEnChangeEdit6()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
