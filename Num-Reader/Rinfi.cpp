#include<stdio.h>
#include<string.h>
#include"Nbasic.h"

//�� �� �� �� �� ��gai ��zi �rang �� �� �� �� �� ���ɳ ��ɮ�� ������ ����˼�� ���� ����  

Status readzhao(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 12 || zuigao>16)	return ERROR;

	ReadQian(zuigao - 1, 12, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 12, TransNum);
	if (zeros != 4) printf("��");

	readyi(TransNum, 12);

	return OK;
}

Status readjing(char TransNum[], int zuigao) {
	int zeros;

	if (zuigao <= 16 || zuigao>20)	return ERROR;

	ReadQian(zuigao - 1, 16, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 16, TransNum);
	if (zeros != 4) printf("��");

	readzhao(TransNum, 16);

	return OK;
}

Status readgai(char TransNum[], int zuigao) {
	int zeros;

	if (zuigao <= 20 || zuigao>24)	return ERROR;

	ReadQian(zuigao - 1, 20, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 20, TransNum);
	if (zeros != 4) printf("��");

	readjing(TransNum, 20);

	return OK;
}

Status readzi(char TransNum[], int zuigao) {
	int zeros;

	if (zuigao <= 24 || zuigao>28)	return ERROR;

	ReadQian(zuigao - 1, 24, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 24, TransNum);
	if (zeros != 4) printf("��");

	readgai(TransNum, 24);

	return OK;
}

Status readrang(char TransNum[], int zuigao) {
	int zeros;

	if (zuigao <= 28 || zuigao>32)	return ERROR;

	ReadQian(zuigao - 1, 28, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 28, TransNum);
	if (zeros != 4) printf("�");

	readzi(TransNum, 28);

	return OK;
}

Status readgou(char TransNum[], int zuigao) {//�޸�ʱ����<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 32 || zuigao>36)	return ERROR;

	ReadQian(zuigao - 1, 32, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 32, TransNum);
	if (zeros != 4) printf("��");

	readrang(TransNum, 32);

	return OK;
}

Status readjian(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 36 || zuigao>40)	return ERROR;

	ReadQian(zuigao - 1, 36, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 36, TransNum);
	if (zeros != 4) printf("��");

	readgou(TransNum, 36);

	return OK;
}

Status readzheng(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 40 || zuigao>44)	return ERROR;

	ReadQian(zuigao - 1, 40, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 40, TransNum);
	if (zeros != 4) printf("��");

	readjian(TransNum, 40);

	return OK;
}

Status readzai(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 44 || zuigao>48)	return ERROR;

	ReadQian(zuigao - 1, 44, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 44, TransNum);
	if (zeros != 4) printf("��");

	readzheng(TransNum, 44);

	return OK;
}

Status readji(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 48 || zuigao>52)	return ERROR;

	ReadQian(zuigao - 1, 48, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 48, TransNum);
	if (zeros != 4) printf("��");

	readzai(TransNum, 48);

	return OK;
}

Status readhenghesha(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 52 || zuigao>56)	return ERROR;

	ReadQian(zuigao - 1, 52, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 52, TransNum);
	if (zeros != 4) printf("���ɳ");

	readji(TransNum, 52);

	return OK;
}

Status readasengzhi(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 56 || zuigao>60)	return ERROR;

	ReadQian(zuigao - 1, 56, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 56, TransNum);
	if (zeros != 4) printf("��ɮ��");

	readhenghesha(TransNum, 56);

	return OK;
}

Status readnayouta(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 60 || zuigao>64)	return ERROR;

	ReadQian(zuigao - 1, 60, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 60, TransNum);
	if (zeros != 4) printf("������");

	readasengzhi(TransNum, 60);

	return OK;
}

Status readbukesiyi(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 64 || zuigao>68)	return ERROR;

	ReadQian(zuigao - 1, 64, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 64, TransNum);
	if (zeros != 4) printf("����˼��");

	readnayouta(TransNum, 64);

	return OK;
}

Status readwuliang(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 68 || zuigao>72)	return ERROR;

	ReadQian(zuigao - 1, 68, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 68, TransNum);
	if (zeros != 4) printf("����");

	readbukesiyi(TransNum, 68);

	return OK;
}

Status readdashu(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����4������>����printf������readXXX 
	int zeros;

	if (zuigao <= 72 || zuigao>76)	return ERROR;

	ReadQian(zuigao - 1, 72, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 72, TransNum);
	if (zeros != 4) printf("����");

	readwuliang(TransNum, 72);

	return OK;
}

//����InfiReadNum�����Ľ���Pretreatment��������Ϊ�����֣���" 	----.350000" 
//Ϊ��ʵ�ֳ����ܣ�InfiReadNum����Ӧ������
//1. ɾ�����õĿհ��ַ�
//2. ͳ�Ƹ����������������ӡ����ż��������������ɾ������
//3. �����ֿ�ͷ���ֵ�0ȫ��ɾ�⣬ֱ��ֻʣһ��0����1-9��.��ͷΪֹ 
//4. ���������ֵ���ժ�����������������ֳ��ȵõ�numlen������ͨ���������������� 
//5. ������򵥵�ReadOneNum����С������
//6. �ر�ģ������������������ôС�����־Ͳ����� 

Status InfiReadNum(char shuru[]) {
	int i, fuhaonum, numlen, xiaonumlen, zerosend;
	char zhengshu[103], zhongjie[103], xiaoshu[103];
	memset(zhengshu, '\0', 103);
	memset(zhongjie, '\0', 103);
	memset(xiaoshu, '\0', 103);

	for (i = 0; shuru[i] == ' ' || shuru[i] == '\t'; i++);	//������ƹ��հ��ַ� 

	for (fuhaonum = 0; shuru[i] == '-'; i++)	fuhaonum++;	//ͳ�Ƹ���������������ƹ����� 

	if (shuru[i] == '\0') {		//���ֻ�пհ��ַ��͸��� 
		printf("����ָ�");
		return ERROR;
	}

	if (shuru[i] == '.') {	//����ƹ���ͷ֮��ֱ�Ӿ���С������ 
		zhengshu[0] = '0';
		zhengshu[1] = '\0';
		strcpy(xiaoshu, shuru + i + 1);	//ע�⣬����һ��С����=0����ôɶҲ���´����ȥ 
	}
	else {	//����Ļ�һ����0�����������ֿ�ͷ����0000, 00.0, 100, 0.335 , 100.0�� 
		while (shuru[i] == '0') i++;	//�Ƚ�����ƹ����ܵ���
		if (i>0) { 		//�����Ժ���ʱ 
			if (shuru[i] == '.' || shuru[i] == '\0') i--;	//������ָ����ǽ�������С���㣬����� 
		}
		strcpy(zhongjie, shuru + i);	//�н��������ȥͷ�������
										//�����ǰ��н�������zhengshu��xiaoshu
		for (i = 0; zhongjie[i] != '.'&&zhongjie[i] != '\0'; i++);	//Ѱ��С���㡣���ִ�����Ҫôָ��.Ҫôָ��\0
		if (zhongjie[i] == '\0') {	//���û��С���㣬��ôֱ�ӿ������ɡ�ע�⣬zhengshu��������ǿյ� 
			strcpy(zhengshu, zhongjie);
		}
		else {	//��ʱһ��������+С����(+����)��ʽ ��zhongjie[i]ΪС���� 
			strncpy(zhengshu, zhongjie, i);	//������������ 
			zhengshu[i] = '\0';	//�ֶ���ӽ����� 
			strcpy(xiaoshu, zhongjie + i + 1);	//����С������ 
		}
	}

	//�������ǵõ��˶������������ֺ�С�����֣���С�������п����ǿյġ� 

	strrev(zhengshu);	//Ϊ����ӦReadQian�Ⱥ��������󣬷�תzhengshu���� 
	numlen = strlen(zhengshu);
	xiaonumlen = strlen(xiaoshu);

	//printf("  ");
	if (numlen == 1 && xiaonumlen == 0) {	//������������ 
		if (zhengshu[0] == '0') {
			fuhaonum = 0;
		}
	}
	else if (numlen == 1 && xiaonumlen != 0) {	//����������������� 
		for (i = 0, zerosend = 1; xiaoshu[i] != '\0'; i++) {
			if (xiaoshu[i] != '0')	zerosend = 0;
		}
		if (zerosend)	fuhaonum = 0;
	}

	if (fuhaonum % 2 == 1)	printf("��");

	if (numlen <= 4)	ReadQian(numlen - 1, 0, zhengshu);
	else if (numlen <= 8) { readwan(zhengshu, numlen); }
	else if (numlen <= 12) { readyi(zhengshu, numlen); }
	else if (numlen <= 16) { readzhao(zhengshu, numlen); }
	else if (numlen <= 20) { readjing(zhengshu, numlen); }
	else if (numlen <= 24) { readgai(zhengshu, numlen); }
	else if (numlen <= 28) { readzi(zhengshu, numlen); }
	else if (numlen <= 32) { readrang(zhengshu, numlen); }
	else if (numlen <= 36) { readgou(zhengshu, numlen); }
	else if (numlen <= 40) { readjian(zhengshu, numlen); }
	else if (numlen <= 44) { readzheng(zhengshu, numlen); }
	else if (numlen <= 48) { readzai(zhengshu, numlen); }
	else if (numlen <= 52) { readji(zhengshu, numlen); }
	else if (numlen <= 56) { readhenghesha(zhengshu, numlen); }
	else if (numlen <= 60) { readasengzhi(zhengshu, numlen); }
	else if (numlen <= 64) { readnayouta(zhengshu, numlen); }
	else if (numlen <= 68) { readbukesiyi(zhengshu, numlen); }
	else if (numlen <= 72) { readwuliang(zhengshu, numlen); }
	else if (numlen <= 76) { readdashu(zhengshu, numlen); }
	else {
		printf("��������");
		printf("\n  �����������ֹ���%dλ", numlen);
		if (xiaonumlen == 0)	printf("����С������");
		else	printf(",С�����ֹ���%dλ", xiaonumlen);
		return ERROR;
	}

	if (xiaoshu[0] != '\0') {	//Ҫ����С������ 
		printf("��");
		for (i = 0; xiaoshu[i] != '\0'; i++)
			ReadOneNum(xiaoshu[i]);
	}

	if (numlen>12 && xiaonumlen >= 10) {
		printf("\n  �����������ֹ���%dλ��С�����ֹ���%dλ", numlen, xiaonumlen);
	}
	else if (numlen>12 && xiaonumlen == 0) {
		printf("\n  ��������%dλ", numlen);
	}
	else if (numlen <= 12 && xiaonumlen >= 10) {
		printf("\n  ����С�����ֹ���%dλ", xiaonumlen);
	}
	return OK;

}