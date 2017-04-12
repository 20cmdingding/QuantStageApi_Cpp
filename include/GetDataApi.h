#ifndef GETDATAAPI_H
#define GETDATAAPI_H

#ifdef WIN32
#ifndef API_EXPORT  
#define API_EXPORT _declspec(dllexport)  
#else  
#define API_EXPORT _declspec(dllimport)  
#endif
#endif

namespace PT_QuantPlatform{
	class TradeDataApi;
	class GetDataSpi{
	public:
		///�����,��¼�ɹ��󼴻����ϵ��øûص�
		virtual void OnRecvCode(TDF_CODE* pCode, int codeNum, TDF_OPTION_CODE* pOptionCode, int optionCodeNum){};
		///10����Ʊ�������������ݻص�
		virtual void OnRecvMarket(TDF_MARKET_DATA* pMarket){};
		///5���ڻ�����������ݻص�
		virtual void OnRecvFuture(TDF_FUTURE_DATA* pFuture){};
		///5����Ȩ����������ݻص�
		virtual void OnRecvFutureOption(TDF_FUTURE_DATA* pFuture){};
		///ָ������������ݻص�
		virtual void OnRecvIndex(TDF_INDEX_DATA* pIndex){};
		///��Ʊlevel2��ʳɽ����ݻص�
		virtual void OnRecvTransaction(TDF_TRANSACTION* pTransaction){};
		///��Ʊ��һ��һί�ж������ݻص�
		virtual void OnRecvOrderQueue(TDF_ORDER_QUEUE* pOrderQueue){};
		///��Ʊ���ί�����ݣ��������У��ص�
		virtual void OnRecvOrder(TDF_ORDER* pOrder){};
		///������K������ͳһ�ص�������Ʊ��ָ�����ڻ�����Ȩ��
		virtual void OnRecvGDKLine(GD_Kline_Data* pKline){};									
	public:
		///ģ��ʱ����ȷ�ϻص�
		virtual void OnRecvRspSimulationTimelineConfirmed(GD_SimulationTimelineConfirmed_Rsp* pConfirmed){};
		///��ǰ���ݽ����տ�ʼ֪ͨ�ص�	
		virtual void OnRecvDayBegin(GD_ISODateTimeType pDate){};
		///��ǰ���ݽ����ս���֪ͨ�ص�����ʵʱ�����м�Ϊ�����ź�	
		virtual void OnRecvDayEnd(GD_ISODateTimeType pDate){};
		///��ʷ���ݷ��ͽ���ÿ����ʷ����������������������ӿ�
		virtual void OnRecvRspOver(){};												
	public:
		///�����ղ�ѯȷ�ϻص�
		virtual void OnRspTradingDay(GD_ISODateTimeType* pDay, int dayNum){};			
		///���������ӳɹ�֪ͨ
		virtual void OnConnect(PT_ServerTypeCD serverType){};
		///����������֪ͨ
		virtual void OnDisconnect(PT_ServerTypeCD serverType){};
		///�������Զ���������״̬�仯֪ͨ
		virtual void OnReconnectStatus(PT_ServerTypeCD serverType, const bool successed){};
	public:
		///����ʱЧ��״̬�л�֪ͨ��ͨ�����
		virtual void OnRecvDataTimeless(GD_Stock_Timeliness_Notification* pData){};	
		///������Ϣ֪ͨ
		virtual void OnError(string error){};											
		GetDataSpi(){};
		~GetDataSpi(){};
	};
#ifdef WIN32
	class API_EXPORT GetDataApi{
#else
	class GetDataApi{
#endif
	public:
		/// ��¼�ɹ�ʱ�����յ��� OnRecvCode �ص�
		/// @param [char*] user		�û��� 
		/// @param [char*] pass		����
		/// @see OnRecvCode
		bool Login(char* user, char* pass, int &err);
	public:
		/// ������ʵʱ�������ͣ�ʵ���п��Զ���ظ����ã���ε���֮��̳����һ�ε���ʱ�����õĲ���
		/// @param [std::vector<char*>] &subCodes			������������֧��һ���ʽ 600000 ��wind���� 600000.SH 
		/// @param [bool] isAllMarket						�Ƿ���ȫ�г�
		/// @param [int] beginTime							����Ӹ�ʱ��㿪ʼ���ܵ��յ����ݣ�ʱ���ʽΪhhmmsszzzz, ��0ʱ�ӵ�ǰʱ�̿�ʼ���գ���Ϊ-1ʱ�ӿ��̿�ʼ����
		/// @param [int] subDataType						���ĵ��������ͣ��μ� GD_SubDataType�� ����	market_GD_SubDataType | transaction_GD_SubDataType ���Ŀ��պ���ʳɽ�����
		void ReqRealtimeData(std::vector<char*> &subCodes, bool isAllMarket, int beginTime, int subDataType, int &err);
		/// ������ʵʱk�����ͣ�ʵ���п��Զ���ظ����ã���ε���֮��̳����һ�ε���ʱ�����õĲ���
		/// @param [int] &cycType							����k���������ͣ��μ� GD_CycType, �����û�����ͬʱ���Ķ������ڣ��� minute_GD_CycType | minute_5_GD_CycType Ϊͬʱ���ķ����ߺ�5������
		/// @param [std::vector<char*>] &subCodes			������������֧��һ���ʽ 600000 ��wind���� 600000.SH 
		/// @param [bool] isAllMarket						�Ƿ���ȫ�г�
		/// @param [int] beginTime							����Ӹ�ʱ��㿪ʼ���ܵ��յ����ݣ�ʱ���ʽΪhhmmsszzzz, ��0ʱ�ӵ�ǰʱ�̿�ʼ���գ���Ϊ-1ʱ�ӿ��̿�ʼ����
		void ReqRealtimeGDKlineData(int cycType, std::vector<char*> &subCodes, bool isAllMarket, int beginTime, int &err);				//����ʵʱk�� type Ϊk���������ͣ�һ��ֻ�ܶ���һ�����ڣ���������ͬ�ϡ����ݻص�Ϊ OnRecvGDKLine
		/// ����ʵʱ���Ĵ�����������ӡ��滻��ɾ�����ĵĴ���
		/// �ڵ����� ReqRealtimeData �� ReqRealtimeGDKlineData ֮��ýӿڲŻ���Ч�� ReqRealtimeData �� ReqRealtimeGDKlineData����ͬʱ���ã�������ͬһ�ݴ���� 
		/// @param [GD_UpdateSubCodeType] &cycType			���¶��Ĵ���������Ӷ��ġ�ɾ�����ġ��滻�������ָ���ģʽ
		/// @param [std::vector<char*>] &subCodes			������������֧��һ���ʽ 600000 ��wind���� 600000.SH 
		/// @param [bool] isAllMarket						�Ƿ���ȫ�г�
		void ReqUpdateSubStockCode(GD_UpdateSubCodeType reqType, std::vector<char*> &subCodes, bool isAllMarket, int &err);
	public:
		/// ����ģ��ʱ���ߡ��ڷǽ���ʱ���ڣ�ʵʱ��������������ά���������ṩ�˸ýӿڽ������ģ�ⶩ��ʵʱ����Ĺ���ģʽ���ڸ�ģʽ��
		/// ����ѡ������ط��ٶȽ�����ʷ��ĳ���������ݽ��лطţ����ṩ��ʵʱ����һ�µĸ��¶��ĵķ���
		/// @param [GD_ISODateTimeType] beginTime			��ʼ�������ݻطŵ�ʱ���
		/// @param [GD_PlaybackSpeedType] speadTyp			����ط��ٶ�, �μ� GD_PlaybackSpeedType
		void ReqSimulationTimeline(GD_ISODateTimeType beginTime, GD_PlaybackSpeedType speadTyp, int &err);

		/// ���� ReqSimulationTimeline ������֮����Ч
		/// @see ReqRealtimeData
		void ReqSimulationTickData(std::vector<char*> &subCodes, bool isAllMarket, int beginTime, int subDataType, int &err);

		/// ���� ReqSimulationTimeline ������֮����Ч
		/// @see ReqRealtimeGDKlineData
		void ReqSimulationGDKlineData(int type, std::vector<char*> &subCodes, bool isAllMarket, int beginTime, int &err);

		/// ���� ReqSimulationTimeline ������֮����Ч
		/// @see ReqUpdateSubStockCode
		void ReqSimulationUpdateSubStockCode(GD_UpdateSubCodeType reqType, std::vector<char*> &subCodes, bool isAllMarket, int &err);

		/// ������ʷ��������
		/// @param [GD_ISODateTimeType] beginTime			��ʼ�������ݻطŵ�ʱ���
		/// @param [GD_ISODateTimeType] endTime				�����طŵ�ʱ���
		/// @param [GD_PlaybackSpeedType] speadTyp			����ط��ٶ�, �μ� GD_PlaybackSpeedType
		/// @param [std::vector<char*>] &subCodes			������������֧��һ���ʽ 600000 ��wind���� 600000.SH 
		/// @param [bool] isAllMarket						�Ƿ���ȫ�г�
		int ReqHistoryData(GD_ISODateTimeType beginTime, GD_ISODateTimeType endTime, GD_PlaybackSpeedType speadTyp, std::vector<char*> &subCodes, bool isAllMarket, int &err);	//������ʷlevel2 tick���� GD_SimuModelTypeΪ���ݻط��ٶ�ѡ��, fastΪ����٣�normalΪ����ʵ����ͬ�����ٶ�
		
		/// ������ʷk����������
		/// @param [int] &cycType							����k���������ͣ��μ� GD_CycType, �����û�����ͬʱ���Ķ������ڣ��� minute_GD_CycType | minute_5_GD_CycType Ϊͬʱ���ķ����ߺ�5������
		/// @param [GD_ISODateTimeType] beginTime			��ʼ�������ݻطŵ�ʱ���
		/// @param [GD_ISODateTimeType] endTime				�����طŵ�ʱ���
		/// @param [GD_PlaybackSpeedType] speadTyp			����ط��ٶ�, �μ� GD_PlaybackSpeedType
		/// @param [std::vector<char*>] &subCodes			������������֧��һ���ʽ 600000 ��wind���� 600000.SH 
		/// @param [bool] isAllMarket						�Ƿ���ȫ�г�
		int ReqHistoryGDKLineData(GD_CycType cycType, GD_ISODateTimeType beginTime, GD_ISODateTimeType endTime, std::vector<char*> &subCodes, bool isAllMarket, int &err);						//������ʷK����������	�����ݻص�Ϊ OnRecvGDKLine
		
		/// ������ʷ�����գ�����һ��ʱ�䣬�������ʱ������н�������Ϣ
		/// @param [GD_ISODateTimeType] beginDay			��ʼ����
		/// @param [GD_ISODateTimeType] endDay				��������
		/// @see OnRspTradingDay
		int ReqTradingDay(GD_ISODateTimeType beginDay, GD_ISODateTimeType endDay, int &err);		//��ѯ�Ľ������б�
	public:
		//////////////////////////////////////////////////////////////////////////
		/// ͨ���������ݼ���k��, �����ṩ��һ��ģʽ, ���������������ݵ�ͬʱ�����Լ���api�ڲ���k�߼���ģ��ʵʱ����k��
		/// �Ľӿڿ����ڵ�¼�ɹ�֮������λ�õ��ã����óɹ�֮���κ�ʵʱ�ġ�ģ��ʱ���ߡ���ʷ��������սӿڶ��ἤ��k�ߵļ���
		/// ֧��ͬʱ������ڵļ���
		void calculateKLineByTick(std::vector<GD_CycType> cycs);

		/// ͬ����ѯ��Ʊ������Ϣ
		/// @param [GD_CodeType] code						��ѯ����
		/// @param [GD_ListStatusType] listType				��Ʊ����״̬���ڲ���ȷ��������� ALL_GD_ListStatusType
		/// @param [GD_EquTypeCD] equType					��Ʊ���ͣ��ֽ�֧��A��B�ɵĲ�ѯ 
		std::vector<GD_StockBaseInfo> getStockBaseInfo(GD_CodeType code, GD_ListStatusType listType, GD_EquTypeCD equType, int &err);

		/// ͬ����ѯĳһ��ʱ����ĳֻ��Ʊ��ǰ��Ȩ����
		/// @param [GD_CodeType] code						��ѯ����
		/// @param [GD_ISODateTimeType] beginDate			��ʼ����
		/// @param [GD_ISODateTimeType] endDate				��������
		std::vector<GD_RestorationFactor> getRestorationFactor(GD_CodeType code, GD_ISODateTimeType beginDate, GD_ISODateTimeType endDate, int &err);

		/// ͬ����ѯĳһ��ʱ����ĳֻ��Ʊ�ĺ�Ȩ����
		/// @param [GD_CodeType] code						��ѯ����
		/// @param [GD_ISODateTimeType] beginDate			��ʼ����
		/// @param [GD_ISODateTimeType] endDate				��������
		std::vector<GD_RestorationFactor> getAFRestorationFactor(GD_CodeType code, GD_ISODateTimeType beginDate, GD_ISODateTimeType endDate, int &err);

		/// ͬ����ѯĳһ��ʱ����ĳֻ��Ʊ����ϸ��k�ߣ������k�ߵ�������Դ��ͨ�����ݣ�
		/// @param [GD_CodeType] code						��ѯ����
		/// @param [GD_ISODateTimeType] beginDate			��ʼ����
		/// @param [GD_ISODateTimeType] endDate				��������
		std::vector<GD_DetailMarketDayKline> getDetailMarketDayKline(GD_CodeType code, GD_ISODateTimeType beginDate, GD_ISODateTimeType endDate, int &err);

		/// ͬ����ѯĳһ��ʱ����ĳֻ��Ʊ��������
		/// @param [GD_CodeType] code						��ѯ����
		/// @param [vector<char*>] factorKeys				���Ӵ���
		/// @param [GD_ISODateTimeType] beginDate			��ʼ����
		/// @param [GD_ISODateTimeType] endDate				��������
		std::vector<GD_StockFactors> getStockFactors(GD_CodeType code, vector<char*> &factorKeys, GD_ISODateTimeType beginDate, GD_ISODateTimeType endDate, int &err);
	public:
		/// ����������������API����ʵ��
		/// �ڸ�ģʽ�»���api�ڲ����������ص��̣߳�ʵʱ����һ������ʷ����һ�����ֱ��Ӧ������ͬ��������������ӡ�������ͬʱ����ʵʱ�������ʷ����ʱ���ڻص���������Ҫ��Ҫ��Դ����������
		/// @param [PT_QuantPlatform::GetDataSpi*] spi		�û������Ļص�����ʵ��ָ��
		/// @param [autoRecon] autoRecon					�Ƿ����Զ��ö�������
		/// @param [int] reconTimeOut						��������ʱ��������λ����
		/// @param [bool] endDate							�����������Ƿ���ŷ������󣬽���֮ǰ�����ݼ�������
		static GetDataApi* CreateGetDataApi(PT_QuantPlatform::GetDataSpi* spi, bool autoRecon, int reconTimeOut, bool autoReq = false);

		/// ����������������API����ʵ����������ģ���ϵĽ���API
		/// �ڸ�ģʽ�£���Ҫ����ģ���ϵĽ���apiʵ��������������ģ���������ʱ���ܹ���ȷ�Ķ�λ�µ�������ʱ���Լ���ʱ��ʵ������״̬
		/// @param [PT_QuantPlatform::TradeDataApi*] tApi	�û�������ģ�⽻�����Ӷ���ʵ��ָ��
		/// @param [PT_QuantPlatform::GetDataSpi*] spi		�û������Ļص�����ʵ��ָ��
		/// @param [autoRecon] autoRecon					�Ƿ����Զ��ö�������
		/// @param [int] reconTimeOut						��������ʱ��������λ����
		/// @param [int&] err								������
		/// @param [bool&] autoReq							���������ɹ����Ƿ���ⲹ����������
		/// @see TradeDataApi* TradeDataApi::CreateSimulationTradeDataApi(PT_QuantPlatform::TradeDataSpi* spi, bool autoRecon, int reconTimeOut);
		static GetDataApi* CreateGetDataApiEnableSimulationTrade(PT_QuantPlatform::TradeDataApi* tApi, PT_QuantPlatform::GetDataSpi* spi, bool autoRecon, int reconTimeOut, int &err, bool autoReq = false);
		
		/// �����̰߳�ȫģʽ������������API����ʵ����������ģ���ϵĽ���API
		/// �ڸ�ģʽ���������ݻص�ֻ��Exec���ڵ��̣߳��û�����ѡ�����Լ�����һ���߳̽������ݻص���ͬʱ�ڸ��߳�ģʽ�£��������Ӷ����뽻�����Ӷ������н��ܴ���һ����������ģ�⽻�ף�
		/// @param [PT_QuantPlatform::GetDataSpi*] spi		�û������Ļص�����ʵ��ָ��
		/// @param [int&] err								������
		static GetDataApi* CreateThreadSafeGetDataApi(PT_QuantPlatform::GetDataSpi* spi, int& err);
		
		/// �����̰߳�ȫģʽ������������API����ʵ����������ģ���ϵĽ���API
		/// �ڸ�ģʽ�£���Ҫ����ģ���ϵĽ���apiʵ��������������ģ���������ʱ���ܹ���ȷ�Ķ�λ�µ�������ʱ���Լ���ʱ��ʵ������״̬
		/// @param [PT_QuantPlatform::TradeDataApi*] tApi	�û��������̰߳�ȫģʽģ�⽻�����Ӷ���ʵ��ָ��
		/// @param [PT_QuantPlatform::GetDataSpi*] spi		�û������Ļص�����ʵ��ָ��
		/// @param [int&] err								������
		static GetDataApi* CreateThreadSafeGetDataApiEnableSimulationTrade(PT_QuantPlatform::TradeDataApi* tApi, PT_QuantPlatform::GetDataSpi* spi, int& err);

		/// �����������Ӷ���
		static void DelGetDataApi(PT_QuantPlatform::GetDataApi* pAPI);
	};
	
	extern "C"
	{
#ifdef WIN32
		/// ��ȡapi�汾��
		API_EXPORT const char* GetQuantPlatformApiVersion();
		/// ������־
		API_EXPORT void EnableLog();
		/// �̰߳�ȫģʽ�½������ݻص�ѭ��
		API_EXPORT int Exec();
		/// �̰߳�ȫģʽ��ǿ���˳����ݻص�ѭ��
		API_EXPORT void Terminate();
#else
		const char* GetQuantPlatformApiVersion();
		void EnableLog();
		int Exec();
		void Terminate();
#endif
	}
};
#endif // GETDATAAPI_H