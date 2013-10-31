// PROP1_1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "PROP1_1.h"
#include "afxdialogex.h"


// CPROP1_1 �Ի���

IMPLEMENT_DYNAMIC(CPROP1_1, CPropertyPage)

CPROP1_1::CPROP1_1()
	: CPropertyPage(CPROP1_1::IDD)
{

	m_connect = "";
}

CPROP1_1::~CPROP1_1()
{
}

void CPROP1_1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_connect);
	DDX_Control(pDX, IDC_COMBO1, m_combox1);
	DDX_Control(pDX, IDC_COMBO2, m_combox2);
	DDX_Control(pDX, IDC_COMBO3, m_combox3);
}


BEGIN_MESSAGE_MAP(CPROP1_1, CPropertyPage)
END_MESSAGE_MAP()


// CPROP1_1 ��Ϣ�������


LRESULT CPROP1_1::OnWizardNext()
{
	UpdateData();
	if(m_connect=="")
	{
		MessageBox("�������Ʋ���Ϊ��!");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}


BOOL CPROP1_1::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}


BOOL CPROP1_1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_combox1.AddString("���ڰ�");
	m_combox1.AddString("QADר�ð�");
	m_combox1.AddString("�й�����ר�ð�");
	m_combox1.AddString("����ר�ð�");
	m_combox1.AddString("����ר�ð�");
	m_combox1.AddString("ũ��ר�ð�");
	m_combox1.AddString("����ר�ð�");
	m_combox1.AddString("����ר�ð�");
	m_combox1.AddString("����������");
	m_combox1.AddString("�������а�");
	m_combox1.AddString("̫������ר�ð�");
	m_combox1.AddString("�����ź�ר�ð�");
	m_combox1.AddString("��ׯũ��ר�ð�");
	m_combox1.AddString("����ũ��ר�ð�");
	m_combox1.AddString("�㽭�ź�ר�ð�");
	m_combox1.AddString("�����ź�ר�ð�");
	m_combox1.AddString("�人�ź�ר�ð�");
	m_combox1.AddString("�㶫����ר�ð�");
	m_combox1.AddString("�ֶ���չר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("��ɽ����ר�ð�");
	m_combox1.AddString("���ݽ���ר�ð�");
	m_combox1.AddString("ɽ������ר�ð�");
	m_combox1.AddString("�㶫��ɽũ�Ű�");
	m_combox1.AddString("�ൺ������ר��");
	m_combox1.AddString("����ũ��ר�ð�");
	m_combox1.AddString("ɽ��ũ��ר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("�㽭�ź϶���ר�ð�");
	m_combox1.AddString("���ݽ���ר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("���Ͻ���ר�ð�");
	m_combox1.AddString("�ɶ�����ר�ð�");
	m_combox1.AddString("�麣����ר�ð�");
	m_combox1.AddString("�����ź�ר�ð�");
	m_combox1.AddString("����ũ��ר�ð�");
	m_combox1.AddString("���ս���ר�ð�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("�й����й㶫��");
	m_combox1.AddString("�й����н��հ�");
	m_combox1.AddString("�й����й�����");
	m_combox1.AddString("�й�����ɽ����");
	m_combox1.AddString("�й����м��ְ�");
	m_combox1.AddString("��������ר�ð�");
	m_combox1.AddString("���������򽭰�");
	m_combox1.AddString("פ�����Ű�");
	m_combox1.AddString("�й����к��ϰ�");
	m_combox1.AddString("ɽ������ר�ð�");
	m_combox1.AddString("���ֽ���ר�ð�");
	m_combox1.AddString("���Ź������а�");
	m_combox1.AddString("ɽ��ũ����һ��ר�ð�");
	m_combox1.AddString("������ҵ���а�");
	m_combox1.AddString("�й������Ϻ���");
	m_combox1.AddString("�Ϻ�����ר�ð�");
	m_combox1.AddString("����ũ����ϵͳר�ð�");
	m_combox1.AddString("�ӱ�����ר�ð�");
	m_combox1.AddString("�����ʴ�ר�ð�");

	m_combox2.AddString("VT100");
	m_combox2.AddString("VT52");
	m_combox2.AddString("ANSI");
    m_combox2.AddString("VT220");
	m_combox2.AddString("VT320");
	m_combox2.AddString("VT382");
	m_combox2.AddString("VT510PC");
	m_combox2.AddString("CT100");
	m_combox2.AddString("TV925");
	m_combox2.AddString("XENIX");

	m_combox3.AddString("���ڰ�");
	m_combox3.AddString("���Ű�");
	m_combox3.AddString("������");
	m_combox3.AddString("���ٰ�");
	m_combox3.AddString("�й�����ר�ð�");
	m_combox3.AddString("�㽭ũ��ר�ð�");
	m_combox3.AddString("��������ר�ð�");
	m_combox3.AddString("�㶫����ר�ð�");
	m_combox3.AddString("�������ר�ð�");
	m_combox3.AddString("��ݸ����ר�ð�");
	m_combox3.AddString("���Ͻ���ר�ð�");
	m_combox3.AddString("�㽭����ר�ð�");
	m_combox3.AddString("�㶫ũ��ר�ð�");
	m_combox3.AddString("�ϳ����ר�ð�");
	m_combox3.AddString("��������ר�ð�");
	m_combox3.AddString("��������ר�ð�");
	m_combox3.AddString("���ݽ���ר�ð�");
	m_combox3.AddString("�Ϻ��������ӻ�Ұ�");
	m_combox3.AddString("�����������ӻ�Ұ�");
	m_combox3.AddString("�㽭��������ר�ð�");
	m_combox3.AddString("�Ϻ��������ӻ�֧�ְ�");
	m_combox3.AddString("�㶫����OFPϵͳר�ð�");
	m_combox3.AddString("�㶫������������ר�ð�");
	m_combox3.AddString("�й�����EMSϵͳר�ð�");
	m_combox3.AddString("��������ר�ð�");
	m_combox3.AddString("�������а�");
	m_combox3.AddString("���Ͻ���ר�ð�");
	m_combox3.AddString("���ݽ�������ר�ð�");
	m_combox3.AddString("�����ź�ר�ð�");
	m_combox3.AddString("����ũ��ר�ð�");
	m_combox3.AddString("���ս���ר�ð�");
	m_combox3.AddString("���컪��ר�ð�");
	m_combox3.AddString("���Ͻ�����ͨ��");
	m_combox3.AddString("Linux��ֵ�汾");
	m_combox3.AddString("����ũ��ר�ð�");
	m_combox3.AddString("���ֽ���ר�ð�");
	m_combox3.AddString("����������ר�ð�");
	m_combox3.AddString("�ɶ�����ר�ð�");
    m_combox3.AddString("ɽ��ũ���ۺ�ҵ��ר�ð�");
	m_combox3.AddString("���ݽ���ר�ð�");
	m_combox3.AddString("����ũ����ϵͳר�ð�");
	m_combox3.AddString("������������ר�ð�");

	m_combox1.SetCurSel(0);
	m_combox2.SetCurSel(0);
	m_combox3.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
