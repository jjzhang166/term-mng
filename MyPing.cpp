#include "StdAfx.h"
#include ".\myping.h"

MyPing::MyPing(void)
{
}
MyPing::MyPing(CPage10 *ppWnd)
{
	this->pWnd = ppWnd;
}
LPCSTR MyPing::GetHost(void)
{
	return this->pstrHost;
}
void MyPing::SetHost(CString pp)
{
	this->Hostbuf = pp;
}
MyPing::~MyPing(void)
{
}


void MyPing::Ping()
{
	SOCKET	  rawSocket;  //���ڷ��ͽ��յ��׽���
	struct hostent  *lpHost = NULL;      //Ŀ������ת��
	struct    sockaddr_in saDest;		 //Ŀ���ַ��Ϣ
	struct    sockaddr_in saSrc;		 //Դ��ַ��Ϣ
	DWORD	  dwTimeSent;				 //����ʱ���¼
	DWORD	  dwElapsed;				 //ʱ��� �жϰ��������������˶೤ʱ��
	u_char    cTTL;						 //
	int       nLoop;					 //ѭ��������
	int       nRet;						 //����״̬�ķ���
	int		  SendMes = 4;
	int		  RecvMes = 0;
	int		  LostMes = 0;

	WSADATA wsaData;                                        //
	WSAStartup(MAKEWORD(2,2),&wsaData);						//��ʼ��ԭʼ�׽��� 
	rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);	//
	if (rawSocket == SOCKET_ERROR) 
	{
		ReportError("socket()");
		return;
	}
	
	// Lookup host
	pstrHost = (LPTSTR)(LPCTSTR)Hostbuf;              //���Ŀ��������Ϣ ����Ϊָ��
	lpHost = gethostbyname(pstrHost);				  //�����ҵ���ӦIP��ַ
	if (lpHost == NULL)
	{
		pWnd->m_ResShow += "\nHost not found \r\n";      
		SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);
		return;
	}
	
	// Setup destination socket address
	//saDest.sin_addr.s_addr = *((u_long FAR *) (lpHost->h_addr));
	memcpy(&(saDest.sin_addr),lpHost->h_addr,lpHost->h_length); //��������Ϣװ�ص�Ŀ����Ϣ��
	saDest.sin_family = lpHost->h_addrtype;                 
	saDest.sin_port = 0;

	// Tell the user what we're doing
	CString buff;
	buff.Format("\r\nPinging %s [%s] with %d bytes of data:",
				pstrHost,
				inet_ntoa(saDest.sin_addr),
				REQ_DATASIZE);
	pWnd->m_ResShow += buff;
	SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);
	// Ping multiple times
	for (nLoop = 0; nLoop < 4; nLoop++)
	{
		// Send ICMP echo request//////////////////////////////////////////////////
		SendEchoRequest(rawSocket, &saDest);     //����ICMP ����
		// Use select() to wait for data to be received
		nRet = WaitForEchoReply(rawSocket);       //���в���ȴ�
		if (nRet == SOCKET_ERROR)
		{
			ReportError("select()");
			break;
		}
		if (!nRet)
		{
			pWnd->m_ResShow += "\r\nRequest timed out";
			SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);
			LostMes++;
		}
		else
		{
			// Receive reply
			dwTimeSent = RecvEchoReply(rawSocket, &saSrc, &cTTL);  // ���յ�������Ϣ,������ʱ��

			// Calculate elapsed time////////////////////////////////////////////////////
			dwElapsed = GetTickCount() - dwTimeSent;			   // ���������ʱ��
			CString fbuff;

			fbuff.Format("\r\nReply from: %s: bytes=%d time=%ldms TTL=%d",	//
				inet_ntoa(saSrc.sin_addr),									//
				REQ_DATASIZE,												//
				dwElapsed,													//�����Ϣ
				cTTL);														//
			pWnd->m_ResShow += fbuff;										//
			SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);				//
			RecvMes++;														//
		}
	}
	pWnd->m_ResShow += "\r\n\r\n";
	CString buffer;
	buffer.Format("Ping statistics for %s :\r\n  Packets: Sent = %d, Received = %d, Lost = %d (%d",
		inet_ntoa(saDest.sin_addr),
		SendMes,
		RecvMes,
		LostMes,
		(RecvMes == 4)?0:(RecvMes == 0)?100:RecvMes*100/SendMes);
    pWnd->m_ResShow += buffer;
	pWnd->m_ResShow += "% loss)";
	SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);
	nRet = closesocket(rawSocket);
	if (nRet == SOCKET_ERROR)
		ReportError("closesocket()");
}
int MyPing::SendEchoRequest(SOCKET s,LPSOCKADDR_IN lpstToAddr) 
{//Ӧ�õ��׽��� ��Ŀ���ַ��Ϣ
	static ECHOREQUEST echoReq;  //�ýṹ�����������Ϣ,icmpͷ��Ϣ,ʱ����Ϣ
	static int nId = 1;				
	static int nSeq = 1;
	int nRet;

	// Fill in echo request
	echoReq.icmpHdr.Type		= ICMP_ECHOREQ;
	echoReq.icmpHdr.Code		= 0;
	echoReq.icmpHdr.Checksum	= 0;
	echoReq.icmpHdr.ID			= nId++;
	echoReq.icmpHdr.Seq			= nSeq++;

	// Fill in some data to send
	//for (nRet = 0; nRet < REQ_DATASIZE; nRet++)
	//	echoReq.cData[nRet] = ' '+nRet;
	//�������һ����Ϣ
	CString TempBuf;
	TempBuf.Format("HelloWorld!");
	strcpy(echoReq.cData,TempBuf);
	// Save tick count when sent
	echoReq.dwTime				= GetTickCount();  //��¼����ʱ��ʱ��

	// Put data in packet and compute checksum
	echoReq.icmpHdr.Checksum = in_cksum((u_short *)&echoReq, sizeof(ECHOREQUEST));  //У����㷨

	// Send the echo request  								  
	nRet = sendto(s,						/* socket */
				 (LPSTR)&echoReq,			/* buffer */
				 sizeof(ECHOREQUEST),                     //����
				 0,							/* flags */
				 (LPSOCKADDR)lpstToAddr, /* destination */
				 sizeof(SOCKADDR_IN));   /* address length */
	if (nRet == SOCKET_ERROR) 
		ReportError("sendto()");
	return (nRet);   //���ط��͵�״̬״̬
}




DWORD MyPing::RecvEchoReply(SOCKET s, LPSOCKADDR_IN lpsaFrom, u_char *pTTL) 
{//���շ��͵���Ϣ ����Ϊ�׽��� Դ��ַ��Ϣ�Ա���� ����ʱ��
	ECHOREPLY echoReply; //�ýṹ����� ICMPͷ,ʱ����Ϣ,������Ϣ,IPͷ,��������������Ϣ
	int nRet;			 //״̬���
	int nAddrLen = sizeof(struct sockaddr_in); //��ַ��Ϣ�ṹ�峤��

	// Receive the echo reply	
	nRet = recvfrom(s,					// socket                      
					(LPSTR)&echoReply,	// buffer
					sizeof(ECHOREPLY),	// size of buffer
					0,					// flags
					(LPSOCKADDR)lpsaFrom,	// From address
					&nAddrLen);			// pointer to address len

	// Check return value
	if (nRet == SOCKET_ERROR) 
	{	
		ReportError("recvfrom()");
	}
	else
	{
		
	}

	// return time sent and IP TTL
	*pTTL = echoReply.ipHdr.TTL;
	return(echoReply.echoRequest.dwTime);   		
}


void MyPing::ReportError(LPCSTR pWhere)
{
	CString mbuff;
	mbuff.Format("\r\n %s error: %d\r\n",pWhere,WSAGetLastError());
	pWnd->m_ResShow += mbuff;
	SendMessage(pWnd->m_hWnd,WM_UPDATEUISTATE,FALSE,NULL);
}

int MyPing::WaitForEchoReply(SOCKET s)
{
	struct timeval Timeout;
	fd_set readfds;

	readfds.fd_count = 1;
	readfds.fd_array[0] = s;
	Timeout.tv_sec = 5;
    Timeout.tv_usec = 0;

	return(select(1, &readfds, NULL, NULL, &Timeout));
}
u_short MyPing::in_cksum(u_short *addr, int len)
{
	register int nleft = len;
	register u_short *w = addr;
	register u_short answer;
	register int sum = 0;

	/*
	 *  Our algorithm is simple, using a 32 bit accumulator (sum),
	 *  we add sequential 16 bit words to it, and at the end, fold
	 *  back all the carry bits from the top 16 bits into the lower
	 *  16 bits.
	 */
	while( nleft > 1 )  {
		sum += *w++;
		nleft -= 2;
	}

	/* mop up an odd byte, if necessary */
	if( nleft == 1 ) {
		u_short	u = 0;

		*(u_char *)(&u) = *(u_char *)w ;
		sum += u;
	}

	/*
	 * add back carry outs from top 16 bits to low 16 bits
	 */
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);			/* add carry */
	answer = ~sum;				/* truncate to 16 bits */
	return (answer);
}
