#pragma once

#pragma warning(disable:4996)

//�����궨��
#define Status int
#define OK	1
#define ERROR 0
#define YES 1
#define NO	0
#define OVERFLOW 2

//Ԥ�����������ڶ�����ָ����г�������
Status Pretreatment(char numarray[], int &zhiling, int &mode);	//Ԥ����

//ͨ�ú��������ڿ�ѧ������ģʽ��ָ����Ҳ������ֲ����������������Ϊ���֡�������ԡ�
int IReadNum(int TransNum);		//��int��Χ������ int��ģʽ���庯��
int IReadOneNum(int onenum);	//ֱ������ int��
int ICountZerosEnd(int gao, int di, int qianwei[]);		//��������ĩβ0�ĸ��� int��
int IZerosBtw(int gao, int di, int qianwei[]);		//�ж��Ƿ�Ϊ��0���֣�����ж�4λ int��
int IReadQian(int gao, int di, int qianwei[]);		//����λ�������� int��
Status ReadOneNum(char onenum);		//ֱ������ char��
int CountZerosEnd(int gao, int di, char qianwei[]);		//��������ĩβ0�ĸ��� char��
Status ZerosBtw(int gao, int di, char qianwei[]);	//�ж��Ƿ�Ϊ��0���֣�����ж�4λ char��
Status ReadQian(int gao, int di, char qianwei[]);	//����λ�������� char��
Status readwan(char TransNum[], int zuigao);	//����������ʹ��
Status readyi(char TransNum[], int zuigao);		//����
Status OnlyPrintNum(char character);			//��ӡ�ҽ���ӡһλ����������

//ʮ�ż�����������ģʽר�ú���
Status InfiReadNum(char shuru[]);		//��ʮ�ż�����������������֡�ģʽ���庯��
Status readzhao(char TransNum[], int zuigao);	//����
//--------------------�������ķֽ���-------------------------//
Status readjing(char TransNum[], int zuigao);	//����
Status readgai(char TransNum[], int zuigao);	//����
Status readzi(char TransNum[], int zuigao);		//����
Status readrang(char TransNum[], int zuigao);	//���
Status readgou(char TransNum[], int zuigao);	//����
Status readjian(char TransNum[], int zuigao);	//����
Status readzheng(char TransNum[], int zuigao);	//����
Status readzai(char TransNum[], int zuigao);	//����
Status readji(char TransNum[], int zuigao);		//����
//---------------------����ķֽ���-------------------------//
Status readhenghesha(char TransNum[], int zuigao);			//�����ɳ
Status readasengzhi(char TransNum[], int zuigao);			//����ɮ��
Status readnayouta(char TransNum[], int zuigao);			//��������
Status readbukesiyi(char TransNum[], int zuigao);			//������˼��
Status readwuliang(char TransNum[], int zuigao);			//������
Status readdashu(char TransNum[], int zuigao);				//������

//��ͨ����ģʽר�ú�����˵��������������
Status DoubleReadNum(char shuru[]);		//��ͨģʽ����

//��ѧ������ģʽר�ú���
Status SciReadNum(char shuru[]);		//��ѧ������ģʽ����

//���ʵ�λ��ͷģʽר�ú���
Status SipreReadNum(char shuru[]);		//���ʵ�λ��ͷģʽ����
Status ReadIntPre(int weishu);			//����ĳ������Ӧ��Ӧ�Ĵ�ͷ������Ϊ��������λ����
Status ReadDecimalPre(int prezerosnum);	//����ĳС����Ӧ��Ӧ�Ĵ�ͷ������Ϊ��С����ͷ��ĸ�����

//����ģʽ����
Status SpeakNumber(char shuru[]);		//����ģʽ����
