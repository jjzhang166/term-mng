/********************************************************************/
/* �ļ���: MaskKey.h												*/
/*																	*/
/* ����: ��׼ DLL ��������ͷ�ļ�, ��ʹ�ø�DLL�ĳ����а������ļ�		*/
/*																	*/
/* ����: ¬���� (goodname008)			ʱ��: 2004.8.21				*/
/*																	*/
/* BLOG: http://blog.csdn.net/goodname008							*/
/********************************************************************/

DECLSPEC_IMPORT
BOOL
WINAPI
StartMaskKey(
	LPDWORD lpdwVirtualKey,
	int nLength,
	BOOL bDisableKeyboard = FALSE
	);

DECLSPEC_IMPORT
BOOL
WINAPI
StopMaskKey();
