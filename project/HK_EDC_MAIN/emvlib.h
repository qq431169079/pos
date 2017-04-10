/*****************************************************/
/* Emvlib.h                                          */
/* Define the Application Program Interface          */
/* of EMV2 for all PAX POS terminals     		     */
/* Created by ZengYun at 20/01/2005                  */
/*****************************************************/

#ifndef _EMV_LIB_H
#define _EMV_LIB_H

// added by liuxl 20070710 ����ͨ���򵥵�ɾ����Ӧ�Ĺ�Կ��������������֤������
// �������ʹ�øù�Կ�����������й�Կ֤���޷�ʹ��
#define  MAX_REVOCLIST_NUM    30      // EMVCOҪ��ÿ��RID����֧��30�������б�

#define MAX_APP_NUM       32         //EMV��Ӧ���б����ɴ洢��Ӧ����
#define MAX_APP_ITEMS     17         //��16�޸�Ϊ17  modify by nt 20091218
#define MAX_KEY_NUM       64         //EMV����֤���Ĺ�Կ�����ɴ洢�Ĺ�Կ��

#define PART_MATCH        0x00       //Ӧ��ѡ��ƥ���־(����ƥ��)
#define FULL_MATCH        0x01       //Ӧ��ѡ��ƥ���־(��ȫƥ��)

#define EMV_CASH          0x01       //��������(�ֽ�)
#define EMV_GOODS	      0x02       //��������(����)
#define EMV_SERVICE       0x04       //��������(����)
#define EMV_CASHBACK      0x08       //��������(����)

//Added by LiYuan on 8/29/2006
#define EMV_INQUIRY		  0x10		 //��������(��ѯ)
#define EMV_TRANSFER	  0x20		 //��������(ת��)
#define EMV_PAYMENT		  0x40		 //��������(֧��)
#define EMV_ADMIN		  0x80		 //��������(����)
#define EMV_CASHDEPOSIT   0x90		 //��������(���)

//add for the private data in ICC 20081118 yingl

#define  ATTR_N    0x04
#define  ATTR_B    0x08
#define  ATTR_CN   0x10
#define  ATTR_AN   0x20
#define  ATTR_ANS  0x40
//���״������������붨��
#define EMV_OK             0         //�ɹ�

#define ICC_RESET_ERR     -1         //IC����λʧ��
#define ICC_CMD_ERR       -2         //IC����ʧ��
#define ICC_BLOCK         -3         //IC������    
   
#define EMV_RSP_ERR       -4         //IC���������
#define EMV_APP_BLOCK     -5         //Ӧ������
#define EMV_NO_APP        -6         //��Ƭ��û��EMVӦ��
#define EMV_USER_CANCEL   -7         //�û�ȡ����ǰ��������
#define EMV_TIME_OUT      -8         //�û�������ʱ
#define EMV_DATA_ERR      -9         //��Ƭ���ݴ���
#define EMV_NOT_ACCEPT    -10        //���ײ�����
#define EMV_DENIAL        -11        //���ױ��ܾ�
#define EMV_KEY_EXP       -12        //��Կ����

//�ص��������������������붨��
#define EMV_NO_PINPAD     -13        //û��������̻���̲�����
#define EMV_NO_PASSWORD   -14        //û��������û���������������
#define EMV_SUM_ERR       -15        //��֤������ԿУ��ʹ���
#define EMV_NOT_FOUND     -16        //û���ҵ�ָ�������ݻ�Ԫ��
#define EMV_NO_DATA       -17        //ָ��������Ԫ��û������
#define EMV_OVERFLOW      -18        //�ڴ����

//��������־
#define NO_TRANS_LOG      -19
#define RECORD_NOTEXIST   -20
#define LOGITEM_NOTEXIST  -21

#define ICC_RSP_6985      -22        // GAC�п�Ƭ����6985, ��Ӧ�þ����Ƿ�fallback
#define EMV_PARAM_ERR     -30        // 20081008 liuxl

// 20080814 ��PED�ӿڸ��¶����ӷ���ֵ����
#define EMV_PED_TIMEOUT   0x01   // PED�ӿڷ��� PED_RET_ERR_INPUT_TIMEOUT
#define EMV_PED_WAIT      0x02   // PED�ӿڷ��� PED_RET_ERR_WAIT_INTERVAL
#define EMV_PED_FAIL      0x03   // PED�ӿڷ�����������


#define REFER_APPROVE     0x01       //�ο�������(ѡ����׼)
#define REFER_DENIAL      0x02       //�ο�������(ѡ��ܾ�)

#define ONLINE_APPROVE    0x00       //����������(������׼)		
#define ONLINE_FAILED     0x01       //����������(����ʧ��)	
#define ONLINE_REFER      0x02       //����������(�����ο�)
#define ONLINE_DENIAL     0x03       //����������(�����ܾ�)
#define ONLINE_ABORT      0x04       //����PBOC(������ֹ)

//add by nt 20091106
#define AC_AAC       0x00
#define AC_TC        0x01
#define AC_ARQC      0x02
#define AC_AAC_HOST  0x03 // add by nt ,used for VisaOnLine
//add by nt 20091106

//added by zhoujie 09.10.14
#ifdef WIN32
#pragma warning(disable:4103)
#pragma pack(1)//�趨Ϊ1�ֽڶ���
// #else
// 	__attribute__((__packed__))
#endif

typedef struct{
	unsigned char AppName[33];       //����Ӧ��������'\x00'��β���ַ���
	unsigned char AID[17];           //Ӧ�ñ�־
	unsigned char AidLen;            //AID�ĳ���
    unsigned char SelFlag;           //ѡ���־(PART_MATCH ����ƥ��  FULL_MATCH ȫƥ��)      
	unsigned char Priority;          //���ȼ���־
	unsigned char TargetPer;         //Ŀ��ٷֱ���
	unsigned char MaxTargetPer;      //���Ŀ��ٷֱ���
 	unsigned char FloorLimitCheck;   //�Ƿ�������޶�
	unsigned char RandTransSel;      //�Ƿ�����������ѡ��
	unsigned char VelocityCheck;     //�Ƿ����Ƶ�ȼ��
    unsigned long FloorLimit;        //����޶�
	unsigned long Threshold;         //��ֵ
 	unsigned char TACDenial[6];      //�ն���Ϊ����(�ܾ�)
	unsigned char TACOnline[6];      //�ն���Ϊ����(����)
	unsigned char TACDefault[6];     //�ն���Ϊ����(ȱʡ)
    unsigned char AcquierId[6];      //�յ��б�־
	unsigned char dDOL[256];         //�ն�ȱʡDDOL
	unsigned char tDOL[256];         //�ն�ȱʡTDOL
	unsigned char Version[3];        //Ӧ�ð汾
	unsigned char RiskManData[10];   //���չ�������
}EMV_APPLIST;

typedef struct{
	unsigned char aucAppPreName[17];  //Ӧ������ѡ�����ƣ���'\0'��β
	unsigned char aucAppLabel[17];  //Ӧ�ñ�ǩ����'\0'��β
	unsigned char aucIssDiscrData[244]; //tag 'BF0C'���ݣ�1���ֽڵĳ����ֽ�+'BF0C'���222���ֽڣ���'\0'��β 
	                                    //tag '73'���ݣ�1���ֽڵĳ����ֽ�+'73'���242���ֽڣ���'\0'��β
	unsigned char aucAID[17]; //��ƬAID����'\0'��β
	unsigned char ucAidLen; //��ƬAID����
}APPLABEL_LIST;

typedef struct {
	unsigned char RID[5];            //Ӧ��ע�������ID
	unsigned char KeyID;             //��Կ����
	unsigned char HashInd;           //HASH�㷨��־
	unsigned char ArithInd;          //RSA�㷨��־
	unsigned char ModulLen;          //ģ����
	unsigned char Modul[248];        //ģ
	unsigned char ExponentLen;       //ָ������
	unsigned char Exponent[3];       //ָ��
	unsigned char ExpDate[3];        //��Ч��(YYMMDD)
	unsigned char CheckSum[20];      //��ԿУ���
}EMV_CAPK;

typedef struct{
	unsigned char MerchName[256];    //�Ӥ�W
	unsigned char MerchCateCode[2];  //�Ӥ����O�X(�S�n�D�i���]�m)
	unsigned char MerchId[15];       //�Ӥ�лx(�Ӥḹ)
	unsigned char TermId[8];         //�׺ݼлx(POS��)
	unsigned char TerminalType;      //�׺�����
	unsigned char Capability[3];     //�׺ݩʯ�
	unsigned char ExCapability[5];   //�׺��X�i�ʯ�
	unsigned char TransCurrExp;      //����f���N�X����
	unsigned char ReferCurrExp;      //�Ѧҳf������
	unsigned char ReferCurrCode[2];  //�Ѧҳf���N�X
	unsigned char CountryCode[2];    //�׺ݰ�a�N�X
	unsigned char TransCurrCode[2];  //����f���N�X
	unsigned long ReferCurrCon;      //�Ѧҳf���N�X�M����N�X���ഫ�Y��(����f����Ѧҳf�����ײv*1000)
	unsigned char TransType;         //���e�������(EMV_CASH EMV_GOODS EMV_SERVICE EMV_GOODS&EMV_CASHBACK EMV_SERVICE&EMV_CASHBACK)
	unsigned char ForceOnline;       //�Ӥ�j���p��(1 �����`�O�p�����)
	unsigned char GetDataPIN;        //�K�X�˴��e�O�_Ū���զ���
	unsigned char SurportPSESel;     //�O�_���PSE��ܤ覡
}EMV_PARAM;

// added by liuxl 20070710 ����ͨ���򵥵�ɾ����Ӧ�Ĺ�Կ��������������֤������
// �������ʹ�øù�Կ�����������й�Կ֤���޷�ʹ�� 
typedef  struct 
{
	unsigned char   ucRid[5];  		        // RID
	unsigned char   ucIndex;   		        // CA��Կ����
	unsigned char   ucCertSn[3];            // ������֤�����к�
}EMV_REVOCLIST;

//added by zhoujie 09.10.14
typedef struct  
{
	unsigned char ucUseTermAIPFlg;   //�Ƿ���ڿ�ƬAIP���з��չ���,0-�ÿ�ƬAIP,1-���ն�AIP,Ĭ��Ϊ0
	unsigned char aucTermAIP[2];    //�ն��Ƿ�ǿ�ƽ��з��չ�����byte1-bit4Ϊ1��ǿ�ƽ��з��չ�����byte1-bit4Ϊ0�������з��չ�����Ĭ�������ֽ�ȫΪ0��
	unsigned char ucBypassAllFlg;         //whether bypass all other pin when one pin has been bypassed 1-Yes, 0-No
}EMV_EXTMPARAM;
//add end

// added by liuxl 20071107 MCK ���ò����ṹ
typedef struct 
{
	unsigned char  ucBypassPin; //0-��֧�֣�1��֧�֣�Ĭ��֧��
	unsigned char  ucBatchCapture;  // 0-online data capture, 1-batch capture
	void *pvoid;
}EMV_MCKPARAM;

// added by liuxl 20070727 for PBOC С��֧��
// �����ն˵����ֽ���ز���
typedef struct 
{
	unsigned char ucECTSIFlg;   // TSI����? 1-���� �����ֽ��ն�֧��ָʾ�� ��EC Terminal Support Indicator��
	unsigned char ucECTSIVal;   // �����ֽ��ն�֧��ָʾ�� = 1,֧��
	unsigned char ucECTTLFlg;   // TTL����? 1-���� �����ֽ��ն˽����޶EC Terminal Transaction Limit��
	unsigned long ulECTTLVal;   // �����ֽ��ն˽����޶�
}EMV_TMECPARAM;

// add end

//add for the private data in ICC 20081118 yingl
typedef struct 
{
    int MaxLen;
    unsigned short Tag;
    unsigned short Attr;
}ELEMENT_ATTR;


//��Կ��Ӧ�ù�����������
int  EMVCoreInit(void);
int  EMVCoreVersion(void);
void EMVGetParameter(EMV_PARAM *tParam);
void EMVSetParameter(EMV_PARAM *tParam);
int  EMVGetTLVData(unsigned short Tag, unsigned char *DataOut, int *OutLen);
int  EMVSetTLVData(unsigned short Tag, unsigned char *DataIn, int DataLen);
int  EMVGetScriptResult(unsigned char *Result, int *RetLen);

//��Կ��Ӧ�ù�����������
int  EMVAddApp(EMV_APPLIST *App);
int  EMVGetApp(int Index, EMV_APPLIST *App);
int  EMVDelApp(unsigned char *AID, int AidLen);
int  EMVModFinalAppPara(EMV_APPLIST *ptEMV_APP);
int  EMVGetFinalAppPara(EMV_APPLIST *ptEMV_APP);
int  EMVGetLabelList(APPLABEL_LIST  *ptAppLabel, int *pnAppNum); //add by nt 20091218

int  EMVAddCAPK(EMV_CAPK  *capk );
int  EMVGetCAPK(int Index, EMV_CAPK  *capk );
int  EMVDelCAPK(unsigned char KeyID, unsigned char *RID);
int  EMVCheckCAPK(unsigned char *KeyID, unsigned char *RID);

// added by liuxl 20070710 ���޷���Ӧ�ó����ƹ�֤���б���������ӽӿ�
int  EMVAddRevocList(EMV_REVOCLIST *pRevocList);
int  EMVDelRevocList(unsigned char ucIndex, unsigned char *pucRID);
void EMVDelAllRevocList(void);

//���״�����������
int  EMVAppSelect(int Slot,unsigned long TransNo);
int  EMVReadAppData(void);
int  EMVCardAuth(void);
int  EMVProcTrans(void);
int  EMVStartTrans(unsigned long ulAuthAmt, unsigned long ulCashBackAmt, unsigned char *pACType); //add by nt for Visa Online 
int  EMVCompleteTrans(int nCommuStatus, unsigned char *paucScript, int *pnScriptLen, unsigned char *pACType); //add by nt for Visa Online 

//����(�ر�)EMV��CORE�ĵ���״̬
void EMVSetDebug(int EnableFlag);
void EMVGetICCStatus(unsigned char *SWA, unsigned char *SWB);

//����־ʱ����
// 20080623 changed by liuxl ���Ӳ��� ucFlg, ����ȷ���Ƿ����������Ӧ��
int  EMVAppSelectForLog(int Slot, unsigned char ucFlg);

//�ص���������
int  cEMVWaitAppSel(int TryCnt, EMV_APPLIST List[], int AppNum);  
int  cEMVInputAmount(unsigned long *AuthAmt, unsigned long *CashBackAmt);
int  cEMVGetHolderPwd(int TryFlag, int RemainCnt, unsigned char *pin);
int  cEMVReferProc(void);
int  cEMVUnknowTLVData(unsigned short Tag, unsigned char *dat, int len);
int  cEMVOnlineProc(unsigned char *RspCode, unsigned char *AuthCode, int *AuthCodeLen, unsigned char *IAuthData, int *IAuthDataLen, unsigned char *Script, int *ScriptLen);
void cEMVAdviceProc(void);
void cEMVVerifyPINOK(void);
int  cEMVSetParam(void); // 20091029 liuxl �����Ӧ���������ӷ���ֵ����

//֤����֤(PBOC2.0)
int  cCertVerify(void);

//��������־(PBOC2.0)
int ReadLogRecord(int RecordNo);
int GetLogItem(unsigned short Tag, unsigned char *TagData, int *TagLen);

// ��ȡ������־,���ӡǩ����־ added by liuxl 20070710
int EMVGetParamFlag(unsigned char ucParam, int *pnFlg);

// �������ֽ����ʱ����
int EMVGetCardECBalance(unsigned long *plBalance);
int EMVSetTmECParam(EMV_TMECPARAM *tParam);

// ����MCK�����еĲ��������ڽ�MCK�������ô����ں� added by liuxl 20070710
int EMVSetMCKParam(EMV_MCKPARAM *pMCKParam);

// �����Ƿ�ʹ��PCI �ѻ�PIN�����ӿ� 20080416
int EMVSetPCIModeParam(unsigned char ucPciMode, unsigned char *pucExpectPinLen,unsigned long ulTimeoutMs);

// 20081008 liuxl
// ��ȡEMV �ⷢ���汾�ż�����������Ϣ
int EMVReadVerInfo(char *paucVer);
// ���EMV ���б���Ľ�����־��Ϣ�������ն˷��չ����е�����޶��鹦�ܣ�
int EMVClearTransLog(void);
//add for the private data in ICC 20081118 yingl
int EMVAddIccTag(ELEMENT_ATTR tEleAttr[], int nAddNum);
//���������Ƿ�֧��advice�ı�־
void EMVSetConfigFlag(int nConfigflag);

#endif











