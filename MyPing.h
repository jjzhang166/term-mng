#include "stdafx.h"
#include"Page10.h"
#include "winsock.h"
#pragma once
#pragma pack(1)

#define ICMP_ECHOREPLY	0
#define ICMP_ECHOREQ	8

// IP Header -- RFC 791
typedef struct tagIPHDR
{
	u_char  VIHL;			// Version and IHL
	u_char	TOS;			// Type Of Service
	short	TotLen;			// Total Length
	short	ID;				// Identification
	short	FlagOff;		// Flags and Fragment Offset
	u_char	TTL;			// Time To Live
	u_char	Protocol;		// Protocol
	u_short	Checksum;		// Checksum
	struct	in_addr iaSrc;	// Internet Address - Source
	struct	in_addr iaDst;	// Internet Address - Destination
}IPHDR, *PIPHDR;


typedef struct tagICMPHDR
{
	u_char	Type;			// Type
	u_char	Code;			// Code
	u_short	Checksum;		// Checksum
	u_short	ID;				// Identification
	u_short	Seq;			// Sequence
	char	Data;			// Data
}ICMPHDR, *PICMPHDR;


#define REQ_DATASIZE 32		// Echo Request Data size

// ICMP Echo Request
typedef struct tagECHOREQUEST
{
	ICMPHDR icmpHdr;
	DWORD	dwTime;
	char	cData[1024];
}ECHOREQUEST, *PECHOREQUEST;


// ICMP Echo Reply
typedef struct tagECHOREPLY
{
	IPHDR	ipHdr;
	ECHOREQUEST	echoRequest;
	char    cFiller[256];
}ECHOREPLY, *PECHOREPLY;


#pragma pack()
class MyPing
{
public:
	MyPing(void);
	MyPing(CPage10 *ppWnd);
	~MyPing(void);
	void	 Ping();
	void	 Ping(LPCSTR pstrHost);
	void	 SetHost(CString pp);
	void	 ReportError(LPCSTR pstrFrom);
	int		 WaitForEchoReply(SOCKET s);
	int	     SendEchoRequest(SOCKET s,LPSOCKADDR_IN lpstToAddr);
	u_short	 in_cksum(u_short *addr, int len);
	DWORD	 RecvEchoReply(SOCKET s, LPSOCKADDR_IN lpsaFrom, u_char *pTTL);
	LPCSTR   GetHost();
 
public:
	CPage10	*pWnd;
	LPCSTR		pstrHost;
	CString		Hostbuf;
	BOOL		ThreadSign;
	SOCKET		rawSocket; 
	LPHOSTENT   lpHost;    
	struct      sockaddr_in saDest;
	struct      sockaddr_in saSrc;
	DWORD	    dwTimeSent;
	DWORD	    dwElapsed;
	u_char      cTTL;
	int         nLoop;
	int         nRet;
};
