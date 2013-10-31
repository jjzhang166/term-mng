/********************************************************************/
/* 文件名: MaskKey.h												*/
/*																	*/
/* 功能: 标准 DLL 导出函数头文件, 在使用该DLL的程序中包含此文件		*/
/*																	*/
/* 作者: 卢培培 (goodname008)			时间: 2004.8.21				*/
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
