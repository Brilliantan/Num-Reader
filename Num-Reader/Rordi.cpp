#include<stdio.h>
#include<string.h>
#include"Nbasic.h"

Status DoubleReadNum(char shuru[]) {	//�������˰� 
	int i, fuhaonum, numlen, xiaonumlen, zerosend, zeros;
	char zhengshu[103], zhongjie[103], xiaoshu[103];
	int spc;	//spc���Ǹ���ͨ����������i j k����
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
		for (spc = i + 1; shuru[spc] == '0'; spc++);
		if (shuru[spc] == '\0') {
			printf("��");
			return OK;
		}
		zhengshu[0] = '0';
		zhengshu[1] = '\0';
		strcpy(xiaoshu, shuru + i + 1);	//ע�⣬����һ��С����=0����ôɶҲ���´����ȥ 
	}
	else {	//����Ļ�һ����0�����������ֿ�ͷ����0000, 00.0, 100, 0.335 , 100.0�� 
		for (spc = i; shuru[spc] == '0'; spc++);
		if (shuru[spc] == '.') {
			for (spc++; shuru[spc] == '0'; spc++);
		}
		if (shuru[spc] == '\0') {
			printf("��");
			return OK;
		}
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
	if (fuhaonum % 2 == 1 && numlen <= 16)	printf("��");
	if (numlen <= 4)	ReadQian(numlen - 1, 0, zhengshu);
	else if (numlen <= 8) { readwan(zhengshu, numlen); }
	else if (numlen <= 12) { readyi(zhengshu, numlen); }
	else if (numlen <= 16) {
		ReadQian(numlen - 1, 12, zhengshu);
		printf("��");
		ReadQian(11, 8, zhengshu);
		printf("��");
		ReadQian(7, 4, zhengshu);
		zeros = CountZerosEnd(7, 4, zhengshu);
		if (zeros != 4)	printf("��");
		ReadQian(3, 0, zhengshu);
	}
	else {
		printf("���ֹ���");
		return ERROR;
	}

	if (xiaoshu[0] != '\0') {	//Ҫ����С������ 
		printf("��");
		for (i = 0; xiaoshu[i] != '\0'; i++)
			ReadOneNum(xiaoshu[i]);
	}
	return OK;
}