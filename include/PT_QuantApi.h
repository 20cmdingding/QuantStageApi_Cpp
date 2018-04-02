#ifndef _PT_StrategyApi_H_
#define _PT_StrategyApi_H_

#ifdef WIN32
#ifdef PT_QUANTAPI_EXPORTS
#define PT_QUANTAPI_EXTERN  _declspec(dllexport)
#else
#define PT_QUANTAPI_EXTERN//  _declspec(dllimport)
#pragma comment(lib, "PT_QuantApi.lib")
#endif
#endif /* WIN32 */

#include "PT_QuantBaseErr.h"
#include "PT_QuantDef.h"

namespace PT_QuantPlatform
{
	class PT_QuantSpi
	{
	public:
		PT_QuantSpi() {}
		virtual ~PT_QuantSpi() {}
	public:
		///@brief ֪ͨ����
		///@param nSrvType ҵ����������� �ο�PT_QuantPlatform::PT_Quant_APPServerType
		///@return ��
		///@note ���źŻ��������������ͨʱ����֪ͨ
		virtual void OnConnect(int nSrvType) = 0;
		///@brief ֪ͨ�Ͽ�
		///@param nSrvType ҵ����������� �ο�PT_QuantPlatform::PT_Quant_APPServerType
		///@return ��
		///@note ���źŻ�������������Ͽ�ʱ����֪ͨ
		virtual void OnDisconnect(int nSrvType) = 0;
		///@brief ֪ͨ�û���Ϣ
		///@param  pInfo �û���Ϣ
		///@return ��
		///@note ��¼�ɹ�֮�󷵻ص��û���Ϣ
		virtual void onRtnUserInfo(PT_QuantUserBase* pInfo) = 0;
	public://��ҵ�񼶱�ָ��ص�
		///��ѯ�û���Ϣ�ص�
		///@param    pUserInfo              �ص���Ϣָ��
		///@param    isEnd                  �Ƿ������һ��
		///@return   ��
		///@remark   reqQueryAllUser�ӿڵĻظ�
		virtual void onRspQueryAllUser(PT_QuantUser* pUserInfo, bool isEnd) = 0;
		///��ѯ�û���Ϣ�ص�
		///@param    pPublicCode              ����ȯ��Ϣ
		///@param    nNum                     ����ȯ����
		///@return   ��
		///@remark   reqQueryAllUser�ӿڵĻظ�
		virtual void onRspPublicCode(PT_QuantUserCodeControl* pPublicCode, int nNum) = 0;
		///�޸��û���Ϣ�ص�
		///@param    TD_QuantUserAuthen                �޸ĺ����Ϣ
		///@param    error                    �����Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@return   ��
		///@remark   reqUpdateUserAuthen�ӿڵĻظ�
		virtual void onRspUpdateUserAuthen(TD_QuantUserAuthen* rsp, int error) = 0;
		///�޸��û�ȯ�ػص�
		///@param    TD_QuantUserCodePool              �޸ĺ����Ϣ
		///@param    error                    �����Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@return   ��
		///@remark   reqUpdateUserCodePool�ӿڵĻظ�
		virtual void onRspUpdateUserCodePool(TD_QuantUserCodePool* rsp, int error) = 0;
	public: //����ҵ���߼��ص�
		///�µ��ص�
		///@param    rsp              �µ��ص���Ϣ
		///@param    error            �µ��Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@return   ��
		///@remark   reqOrderInsert�ӿڵĻظ�
		virtual void onRspOrderInsert(const TD_RspOrderInsert *rsp, int error) = 0;
		///�����ص�
		///@param    rsp              �����ص���Ϣ
		///@param    error            �����Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@return   ��
		///@remark   reqOrderDelete�ӿڵĻظ�
		virtual void onRspOrderDelete(const TD_RspOrderDelete *rsp, int error) = 0;

		///��ѯί�лص�
		///@param    rsp              ί����ϸ��Ϣ
		///@param    error            ��ѯ�Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@param    isEnd            �Ƿ������һ��
		///@return   ��
		///@remark   reqQryOrder�ӿڵĻظ����ýӿ��п��ܻ��ظ�����ֱ�����һ��IsEndΪTrue rspΪ�յ���Ϣ
		virtual void onRspQryOrder(const TD_RspQryOrder *rsp, int error, bool isEnd) = 0;
		///��ѯ�ɽ���ϸ
		///@param    rsp              �ɽ���ϸ��Ϣ
		///@param    error            ��ѯ�Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@param    isEnd            �Ƿ������һ��
		///@return   ��
		///@remark   reqQryMatch�ӿڵĻظ����ýӿ��п��ܻ��ظ�����ֱ�����һ��IsEndΪTrue rspΪ�յ���Ϣ
		virtual void onRspQryMatch(const TD_RspQryMatch *rsp, int error, bool isEnd) = 0;
		///��ѯ�ֲֻص�
		///@param    rsp              �ֲ���ϸ��Ϣ
		///@param    error            ��ѯ�Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@param    isEnd            �Ƿ������һ��
		///@return   ��
		///@remark   reqQryPosition�ӿڵĻظ����ýӿ��п��ܻ��ظ�����ֱ�����һ��IsEndΪTrue rspΪ�յ���Ϣ
		virtual void onRspQryPosition(const TD_RspQryPosition *rsp, int error, bool isEnd) = 0;
		///��ѯ����ί�����ص�
		///@param    rsp              ��ί������ϸ��Ϣ
		///@param    error            ��ѯ�Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@param    isEnd            �Ƿ������һ��
		///@return   ��
		///@remark   reqQryMaxEntrustCount�ӿڵĻظ����ýӿ��п��ܻ��ظ�����ֱ�����һ��IsEndΪTrue rspΪ�յ���Ϣ
		virtual void onRspQryMaxEntrustCount(const TD_RspQryMaxEntrustCount* rsp, int error, bool isEnd) = 0;
		///��ѯ�ʽ��ʺ�����ί�����ص�
		///@param    rsp              ��ί������ϸ��Ϣ
		///@param    error            ��ѯ�Ƿ�ɹ�����0����ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@param    isEnd            �Ƿ������һ��
		///@return   ��
		///@remark   reqQryAccountMaxEntrustCount�ӿڵĻظ����ýӿ��п��ܻ��ظ�����ֱ�����һ��IsEndΪTrue rspΪ�յ���Ϣ
		virtual void onRspQryAccountMaxEntrustCount(const TD_RspQryAccountMaxEntrustCount* rsp, int error, bool isEnd) = 0;

		///����״̬�ı�����
		///@param    notice              ����״̬��Ϣ
		///@return   ��
		///@remark   �ýӿ��ڶ���״̬�ı�ʱ������
		virtual void onRtnOrderStatusChangeNotice(const TD_RtnOrderStatusChangeNotice *notice) = 0;
		///�ɽ���ϸ����
		///@param    notice              �ɽ���ϸ��Ϣ
		///@return   ��
		///@remark   �ýӿ��ڶ��������ɽ�ʱ�����ã����ͳɽ���ϸ
		virtual void onRtnOrderMatchNotice(const TD_RtnOrderMatchNotice *notice) = 0;
		///�ֲָ�ӯ����
		///@param    notice              �ֲָ�ӯ��Ϣ
		///@return   ��
		///@remark   �ýӿ�Ƶ����Tick����ͬ�������ͳֲֵĵĸ�ӯ��Ϣ
		virtual void onRtnProfit(const TD_RtnProfit *notice) = 0;
		///�û�Ȩ����Ϣ����
		///@param    notice              �û�Ȩ����Ϣ
		///@return   ��
		///@remark   ���û�Ȩ����Ϣ���޸�ʱ����
		virtual void onRtnUserAuthen(const TD_QuantUserAuthen* notice) = 0;
	public://����ҵ���߼��ص�
		///@brief ��Ӧ���������б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pWindCode ָ���Ĺ�Ʊ�����б�
		///@param[in] nWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginDay ָ������ʼ����
		///@param[in] szEndDay ָ���Ľ�������
		///@param[in] nErrNo ��Ӧʧ�ܵĴ�����
		///@param[in] szErrMsg ��Ӧʧ�ܵĴ�������
		///@return ��
		virtual void OnRspTradingDay(MD_ReqID nReqID, const MD_CodeType *pWindCode, long nWindCodeNum, MD_ISODateTimeType szBeginDay, MD_ISODateTimeType szEndDay, int nErrNo, const char *szErrMsg) = 0;
		///@brief ��Ӧ����ͣ�����б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pWindCode ָ���Ĺ�Ʊ�����
		///@param[in] nWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginDay ָ������ʼ����
		///@param[in] szEndDay ָ���Ľ�������
		///@param[in] nErrNo ��Ӧʧ�ܵĴ�����
		///@param[in] szErrMsg ��Ӧʧ�ܵĴ�������
		///@return ��
		///@note ���źŻ�������ͣ�����б������֪ͨ
		virtual void OnRspHaltingDay(MD_ReqID nReqID, const MD_CodeType *pWindCode, long nWindCodeNum, MD_ISODateTimeType szBeginDay, MD_ISODateTimeType szEndDay, int nErrNo, const char *szErrMsg) = 0;
		///@brief ��Ӧ����������
		///@param[in] nReqID ��Ϣ�������
		///@param[in] nSubType ָ���Ķ�������
		///@param[in] nCycType ָ����K����������(���nSubTypeδ����K�߶�������, �뽫�ò�����Ϊ0)
		///@param[in] pSubWindCode ָ���Ĺ�Ʊ�����
		///@param[in] nSubWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginTime ָ������ʼʱ��
		///@param[in] szEndTime ָ���Ľ���ʱ��
		///@param[in] nErrNo ��Ӧʧ�ܵĴ�����
		///@param[in] szErrMsg ��Ӧʧ�ܵĴ�������
		///@return ��
		///@note ���źŻ������������������֪ͨ
		virtual void OnRspSubQuote(MD_ReqID nReqID, MD_SubType nSubType, MD_CycType nCycType, const MD_CodeType *pSubWindCode, long nSubWindCodeNum, MD_ISODateTimeType szBeginTime, MD_ISODateTimeType szEndTime, int nErrNo, const char *szErrMsg) = 0;
		///@brief ֪ͨ���״����
		///@param[in] pWindCode ָ���Ĺ�Ʊ�����
		///@param[in] nWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] pOptionCode ָ������Ȩ�����
		///@param[in] nOptionCodeNum ָ������Ȩ��������
		///@return ��
		virtual void OnRtnTradingCode(const MD_DATA_CODE *pWindCode, long nWindCodeNum, const MD_DATA_OPTION_CODE *pOptionCode, long nOptionCodeNum) = 0;
		///@brief ֪ͨ�������б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] szWindCode ָ���Ĺ�Ʊ�Ĵ���(��ָ����Ϊnullptr, ���ʾ�����г��Ľ������б�)
		///@param[in] pDay �������б�
		///@param[in] nDayNum �����ո���
		///@return ��
		///@note ���źŻ������������б������֪ͨ
		virtual void OnRtnTradingDay(MD_ReqID nReqID, const char *szWindCode, const MD_ISODateTimeType *pDay, long nDayNum) = 0;
		///@brief ֪ͨͣ�����б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] szWindCode ָ����Ʊ�Ĵ���
		///@param[in] pDay �������б�
		///@param[in] nDayNum �����ո���
		///@return ��
		///@note ���źŻ�������ͣ�����б������֪ͨ
		virtual void OnRtnHaltingDay(MD_ReqID nReqID, const char *szWindCode, const MD_ISODateTimeType *pDay, long nDayNum) = 0;
		///@brief ֪ͨ��������
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pMarket ���ɵ��������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnMarket(MD_ReqID nReqID, MD_DATA_MARKET *pMarket) = 0;
		///@brief ֪ͨK������
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pKLine K���������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷK���������ʵʱK�����������֪ͨ
		virtual void OnRtnKLine(MD_ReqID nReqID, MD_DATA_KLINE *pKLine) = 0;
		///@brief ָ֪ͨ������
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pIndex ָ���������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnIndex(MD_ReqID nReqID, MD_DATA_INDEX *pIndex) = 0;
		///@brief ֪ͨ��ʳɽ�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pTrans ��ʳɽ����ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnTransaction(MD_ReqID nReqID, MD_DATA_TRANSACTION *pTrans) = 0;
		///@brief ֪ͨί�ж���
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pQueue ί�ж������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnOrderQueue(MD_ReqID nReqID, MD_DATA_ORDER_QUEUE *pQueue) = 0;
		///@brief ֪ͨ���ί��
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pOrder ���ί�����ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnOrder(MD_ReqID nReqID, MD_DATA_ORDER *pOrder) = 0;
		///@brief ֪ͨ�ڻ�����
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pFuture �ڻ��������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnFuture(MD_ReqID nReqID, MD_DATA_FUTURE *pFuture) = 0;
		///@brief ֪ͨ��Ȩ����
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pOption ��Ȩ�������ݵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ����������ʵʱ������������֪ͨ
		virtual void OnRtnFutureOption(MD_ReqID nReqID, MD_DATA_FUTURE *pOption) = 0;
		///@brief ֪ͨ������Ϣ
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pDate �������ڵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ�������ʵʱ���������֪ͨ
		virtual void OnRtnDayBegin(MD_ReqID nReqID, MD_ISODateTimeType pDate) = 0;
		///@brief ֪ͨ������Ϣ
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pDate �������ڵ�ַ
		///@return ��
		///@note ���źŻ���������ʷ�������ʵʱ���������֪ͨ
		virtual void OnRtnDayEnd(MD_ReqID nReqID, MD_ISODateTimeType pDate) = 0;
		///@brief ֪ͨʵЧ����Ϣ
		///@param[in] nReqID
		///@return ��
		///@note ���ź�ֻ������ʵʱ����ʱ����, ���ڱ�ʾ֮�������Ϊʵʱ������������
		virtual void OnRtnTimeless(MD_ReqID nReqID) = 0;
	};

#ifdef WIN32
	class PT_QUANTAPI_EXTERN PT_QuantApi
#else
	class PT_QuantApi
#endif
	{
	public:
		PT_QuantApi();
		virtual ~PT_QuantApi();
	public:
		///��ȡAPI�汾
		///@param    ��
		///@return   API�汾
		///@remark   ��̬����
		static char* getVersion();
		///����ʵ��
		///@param    spi                  �ص�ָ��
		///@param    bEnableLog           �Ƿ�����־
		///@param    nTdType              ���׻���
		///@param    nMdType              ���黷��
		///@return   TradeDataApi���͵Ķ���ʵ��
		///@remark   Ĭ��������ѡ��Ļ���
		static PT_QuantApi* createApi(PT_QuantSpi* spi, bool bEnableLog, PT_QuantTdAppEType nTdType, PT_QuantMdAppEType nMdType);
		///����ʵ��
		///@param    spi                  �ص�ָ��
		///@param    bEnableLog           �Ƿ�����־
		///@param    nTdType              ���׻���
		///@param    bTdConnect           �Ƿ񼤻�׻���
		///@param    nMdType              ���黷��
		///@param    bMdConnect           �Ƿ񼤻����黷��
		///@return   TradeDataApi���͵Ķ���ʵ��
		///@remark   ��̬����
		static PT_QuantApi* createApi(PT_QuantSpi* spi, bool bEnableLog, PT_QuantTdAppEType nTdType, bool bTdConnect, PT_QuantMdAppEType nMdType, bool bMdConnect, bool bIfSyn);
		/// ///ɾ��ʵ��
		///@param    api                  ��Ҫɾ���Ķ���ʵ��
		///@return   ��
		///@remark   ��̬����
		static void deleteApi(PT_QuantApi* api);
		/// ��ʼ��
		///@param    ��
		///@return   ��
		///@remark   ��̬����
		static void Init();
		///��ȡ��Ʊ�����
		///@Param    nErrCode             �����
		///@Param    szErrmsg             ������
		///@Param    len                  szErrmsg�ڴ泤��
		///@remark:  ��̬����������֮ǰ�����ȵ�Init����
		static void GetErrMsg(int nErrCode, char* szErrmsg, int len);
		///���ûز��¼
		///@param    pReq
		///@return   ��
		///@remark   ��������ģʽ,���ڻز�ʱ����
		virtual void SetNewBackTest(PT_BackTestReq* pReq, int &err) = 0;
		///��¼��֤��ȡȨ��
		///@Param    szUseName            ��¼�ʺ�
		///@Param    szPasswd             ��¼����
		///@return   true��¼�ɹ�
		///@remark:  ��������ģʽ
		virtual bool Login(char* szUseName, char* szPasswd) = 0;
		///��ȡ��Ʊ�����
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark:  ��������ģʽ
		virtual int GetCode() = 0;
	public:///����ҵ��ӿ�
		///�µ�
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ,
		///          ����µ�������ǿƽ�Ļ��뽫userid��ֵΪ��Ҫǿƽ���û���userid������nCloseR��ֵΪ1
		virtual int reqOrderInsert(TD_ReqOrderInsert* req) = 0;
		///����
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqOrderDelete(TD_ReqOrderDelete* req) = 0;
		///��ѯί��
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqQryOrder(TD_ReqQryOrder* req) = 0;
		///��ѯ�ɽ���ϸ
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqQryMatch(TD_ReqQryMatch* req) = 0;
		///��ѯ�ֲ�
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqQryPosition(TD_ReqQryPosition* req) = 0;
		///��ѯ����ί����
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqQryMaxEntrustCount(TD_ReqQryMaxEntrustCount* req) = 0;
		///��ѯ�ʽ��˺�����ί����
		///@Param    req                  �µ�������Ϣ
		///@return   ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@remark   ���÷�����ģʽ
		virtual int reqQryAccountMaxEntrustCount(TD_ReqQryAccountMaxEntrustCount* req) = 0;

	public:
		///@brief ���������б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pWindCode ָ���Ĺ�Ʊ�����б�
		///@param[in] nWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginDay ָ������ʼ����
		///@param[in] szEndDay ָ���Ľ�������
		///@return ��
		///@note ���������ΪpWindCode������Ƕ�̬�ڴ�, �ɵ����߸����ͷ�, ���ӿ��ڲ������ͷŴ���
		virtual int ReqTradingDay(MD_ReqID nReqID, const MD_CodeType *pWindCode, long nWindCodeNum, MD_ISODateTimeType szBeginDay, MD_ISODateTimeType szEndDay) = 0;
		///@brief ����ͣ�����б�
		///@param[in] nReqID ��Ϣ�������
		///@param[in] pWindCode ָ���Ĺ�Ʊ�����б�
		///@param[in] nWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginDay ָ������ʼ����
		///@param[in] szEndDay ָ���Ľ�������
		///@return ��
		///@note ���������ΪpWindCode������Ƕ�̬�ڴ�, �ɵ����߸����ͷ�, ���ӿ��ڲ������ͷŴ���
		virtual int ReqHaltingDay(MD_ReqID nReqID, const MD_CodeType *pWindCode, long nWindCodeNum, MD_ISODateTimeType szBeginDay, MD_ISODateTimeType szEndDay) = 0;
		///@brief ����������
		///@param[in] nReqID ��Ϣ�������
		///@param[in] nSubType ������������
		/// �����Ķ�����������:
		/// -# 0x0000-δ֪����(�������κζ�������)
		/// -# 0x0001-��������
		/// -# 0x0002-ָ������
		/// -# 0x0004-��ʳɽ�
		/// -# 0x0008-���ί��
		/// -# 0x0010-ί�ж���
		/// -# 0x0020-�ڻ�����
		/// -# 0x0040-��Ȩ����
		/// -# 0x0080-K������
		///@param[in] nCycType K����������
		/// ������K����������:
		/// -# 0x0000-δ֪����(�������κ�K������)
		/// -# 0x0001-10��K��
		/// -# 0x0002-1����K��
		/// -# 0x0004-5����K��
		/// -# 0x0008-15����K��
		/// -# 0x0010-30����K��
		/// -# 0x0020-1СʱK��
		/// -# 0x0040-1��K��
		///@param[in] pSubWindCode ָ���Ĺ�Ʊ�����б�
		///@param[in] nSubWindCodeNum ָ���Ĺ�Ʊ��������
		///@param[in] szBeginTime ָ������ʼʱ��
		///@param[in] szEndTime ָ���Ľ���ʱ��
		///@return ���ز�Ϊ0������ʧ�ܣ�������ο�TQuantErrorType::EQuantErrorType
		///@note ���������ΪpSubWindCode������Ƕ�̬�ڴ�, �ɵ����߸����ͷ�, ���ӿ��ڲ������ͷŴ���
		virtual int ReqSubQuote(MD_ReqID nReqID, MD_SubType nSubType, MD_CycType nCycType, const MD_CodeType *pSubWindCode, long nSubWindCodeNum, MD_ISODateTimeType szBeginTime, MD_ISODateTimeType szEndTime) = 0;
	};
}
#endif//_PT_StrategyApi_H_
