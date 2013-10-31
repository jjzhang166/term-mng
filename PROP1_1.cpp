// PROP1_1.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "PROP1_1.h"
#include "afxdialogex.h"


// CPROP1_1 对话框

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


// CPROP1_1 消息处理程序


LRESULT CPROP1_1::OnWizardNext()
{
	UpdateData();
	if(m_connect=="")
	{
		MessageBox("连接名称不能为空!");
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

	m_combox1.AddString("大众版");
	m_combox1.AddString("QAD专用版");
	m_combox1.AddString("中国建行专用版");
	m_combox1.AddString("保险专用版");
	m_combox1.AddString("邮政专用版");
	m_combox1.AddString("农行专用版");
	m_combox1.AddString("交行专用版");
	m_combox1.AddString("商行专用版");
	m_combox1.AddString("江苏邮政版");
	m_combox1.AddString("焦作商行版");
	m_combox1.AddString("太保人寿专用版");
	m_combox1.AddString("温州信合专用版");
	m_combox1.AddString("枣庄农信专用版");
	m_combox1.AddString("义乌农信专用版");
	m_combox1.AddString("浙江信合专用版");
	m_combox1.AddString("广州信合专用版");
	m_combox1.AddString("武汉信合专用版");
	m_combox1.AddString("广东建行专用版");
	m_combox1.AddString("浦东发展专用版");
	m_combox1.AddString("深圳邮政专用版");
	m_combox1.AddString("鞍山商行专用版");
	m_combox1.AddString("温州建行专用版");
	m_combox1.AddString("山东中行专用版");
	m_combox1.AddString("广东佛山农信版");
	m_combox1.AddString("青岛公积金专版");
	m_combox1.AddString("厦门农行专用版");
	m_combox1.AddString("山西农行专用版");
	m_combox1.AddString("广西建行专用版");
	m_combox1.AddString("江苏商行专用版");
	m_combox1.AddString("宁波中行专用版");
	m_combox1.AddString("浙江信合二代专用版");
	m_combox1.AddString("苏州建行专用版");
	m_combox1.AddString("宁波中信专用版");
	m_combox1.AddString("海南建行专用版");
	m_combox1.AddString("成都中信专用版");
	m_combox1.AddString("珠海商行专用版");
	m_combox1.AddString("广西信合专用版");
	m_combox1.AddString("广州农信专用版");
	m_combox1.AddString("江苏建行专用版");
	m_combox1.AddString("南宁商行专用版");
	m_combox1.AddString("中国建行广东版");
	m_combox1.AddString("中国建行江苏版");
	m_combox1.AddString("中国建行广西版");
	m_combox1.AddString("中国建行山东版");
	m_combox1.AddString("中国建行吉林版");
	m_combox1.AddString("福州商行专用版");
	m_combox1.AddString("江苏银行镇江版");
	m_combox1.AddString("驻马店诚信版");
	m_combox1.AddString("中国建行海南版");
	m_combox1.AddString("山东建行专用版");
	m_combox1.AddString("吉林建行专用版");
	m_combox1.AddString("厦门国际银行版");
	m_combox1.AddString("山东农信新一代专用版");
	m_combox1.AddString("莱芜商业银行版");
	m_combox1.AddString("中国建行上海版");
	m_combox1.AddString("上海建行专用版");
	m_combox1.AddString("广州农信新系统专用版");
	m_combox1.AddString("河北邮政专用版");
	m_combox1.AddString("河南邮储专用版");

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

	m_combox3.AddString("大众版");
	m_combox3.AddString("电信版");
	m_combox3.AddString("邮政版");
	m_combox3.AddString("人寿版");
	m_combox3.AddString("中国建行专用版");
	m_combox3.AddString("浙江农行专用版");
	m_combox3.AddString("广州中信专用版");
	m_combox3.AddString("广东中行专用版");
	m_combox3.AddString("天津中行专用版");
	m_combox3.AddString("东莞商行专用版");
	m_combox3.AddString("云南建行专用版");
	m_combox3.AddString("浙江邮政专用版");
	m_combox3.AddString("广东农行专用版");
	m_combox3.AddString("南充电信专用版");
	m_combox3.AddString("广州邮政专用版");
	m_combox3.AddString("无锡交行专用版");
	m_combox3.AddString("苏州建行专用版");
	m_combox3.AddString("上海邮政电子汇兑版");
	m_combox3.AddString("江苏邮政电子汇兑版");
	m_combox3.AddString("浙江宁波中行专用版");
	m_combox3.AddString("上海邮政电子化支局版");
	m_combox3.AddString("广东中行OFP系统专用版");
	m_combox3.AddString("广东邮政国际普邮专用版");
	m_combox3.AddString("中国邮政EMS系统专用版");
	m_combox3.AddString("宁波中信专用版");
	m_combox3.AddString("焦作商行版");
	m_combox3.AddString("海南建行专用版");
	m_combox3.AddString("湖州建设银行专用版");
	m_combox3.AddString("广西信合专用版");
	m_combox3.AddString("广州农信专用版");
	m_combox3.AddString("江苏建行专用版");
	m_combox3.AddString("重庆华夏专用版");
	m_combox3.AddString("海南建行普通版");
	m_combox3.AddString("Linux键值版本");
	m_combox3.AddString("宁波农行专用版");
	m_combox3.AddString("吉林建行专用版");
	m_combox3.AddString("北部湾商行专用版");
	m_combox3.AddString("成都华夏专用版");
    m_combox3.AddString("山东农信综合业务专用版");
	m_combox3.AddString("贵州建行专用版");
	m_combox3.AddString("广州农信新系统专用版");
	m_combox3.AddString("沈阳华夏银行专用版");

	m_combox1.SetCurSel(0);
	m_combox2.SetCurSel(0);
	m_combox3.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
