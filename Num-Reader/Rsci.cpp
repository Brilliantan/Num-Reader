#include<stdio.h>
#include"Nbasic.h"


Status SciReadNum(char shuru[]) {								
	//��ѧ������ģʽ�������
	//��ѧ������ģʽ�£���shuruɨ��һ�鼴�����������
	//����Ҳ��ʹ���˳���IReadNum���������ݴΣ���Ϊ�ú����������Ҫ��Ϊint 
	int i = 0, n = 0, j = 0, fuhaonum;	//i���ڹ�꣬j���ڵײ�Сѭ�� 
	int xiaonum = 0, zerosnum = 0;
	int xszs;	//С��רɱ�����ڽ��00.  00  0  .0001   0.000123��bug
	for (i = 0; shuru[i] == ' ' || shuru[i] == '\t'; i++);	//������ƹ��հ��ַ� 
	for (fuhaonum = 0; shuru[i] == '-'; i++)	fuhaonum++;	//ͳ�Ƹ���������������ƹ����� 
	if (shuru[i] == '\0') {		//���ֻ�пհ��ַ��͸��� 
		printf("  ����ָ�");
		return ERROR;
	}
	for (xszs = i; '0' == shuru[xszs]; xszs++);
	if ('.' == shuru[xszs]) xszs++;
	if ('\0' == shuru[xszs]) {
		printf("��");
		return OK;
	}
	//�����ߣ��������Ŷ�ʮһ


	zerosnum = 0;
	if (shuru[i] == '.') {	//����ƹ���ͷ֮��ֱ�Ӿ���С������ 
		do {
			i++;
			n++;
		} while (shuru[i] == '0');
		if (shuru[i] == '\0') {
			printf("��");
			if (n>1) {
				printf("��");
				for (j = 0; j<n - 1; j++) {
					printf("��");
					xiaonum++;
				}
			}
			if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
			return OK;	//���.000���� 
		}
		//printf("  ");
		if (fuhaonum % 2 == 1)	printf("��");
		ReadOneNum(shuru[i]);
		i++;
		if (shuru[i] != '\0') {
			printf("��");
			for (; shuru[i] != '\0'; i++) {
				ReadOneNum(shuru[i]);
				xiaonum++;
			}
		}
		printf("��ʮ��");
		n = -n;
		IReadNum(n);
		printf("�η�");
		xiaonum -= n;
		if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
		return OK;		//���.001���� 
	}
	else {	//����Ļ�һ����0�����������ֿ�ͷ����0000, 00.0, 100, 0.335 , 100.0�� 
		while (shuru[i] == '0') i++;	//�Ƚ�����ƹ����ܵ���
		if (i>0) { 		//�����Ժ���ʱ 
			if (shuru[i] == '.' || shuru[i] == '\0') i--;	//������ָ����ǽ�������С���㣬����� 
		}
		j = i;
		//shuru[j]Ϊ��һ���������� 
		//ȥͷ�����
		//����Ŀ���ǣ�ɨ��ȥͷ�������֣�����.��EOF�˳�ɨ�� 
		while (1) {	//ֻҪ����С�����EOF���ͼ���... 
			if (shuru[i] == '.')	break;
			if (shuru[i] == '\0') 	break;
			n++;
			i++;
		}
		//��������ʱ��shuru[i]����.����EOF 
		if (shuru[i] == '\0') {	//�����EOF��˵��û��С���� 
			//printf("  ");
			if (shuru[j] != '0') {	//��Ҫ������д��0 
				if (fuhaonum % 2 == 1)	printf("��");
			}
			ReadOneNum(shuru[j]);
			j++;
			for (i = j; shuru[i] != '\0'; i++);
			if (shuru[--i] != '0') {	//����0��β�� 
				if (shuru[j] != '\0') {
					printf("��");
					for (; shuru[j] != '\0'; j++) {
						ReadOneNum(shuru[j]);
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			else {
				for (; shuru[i] == '0'; i--)	zerosnum++;
				if (zerosnum + 1 == n) {
					printf("��ʮ��");
					IReadNum(n - 1);
					printf("�η�");
				}
				else {
					printf("��");
					for (i = 0; i<n - zerosnum - 1; i++) {
						ReadOneNum(shuru[j]);
						j++;
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			if (n>10) printf("\n  �������������ֹ���%dλ", n);
			return OK;		//���123���� 
		}
		//����Ļ�˵����С���㣬��shuru[i]����С���� 
		//printf("  ");
		if (shuru[j] != '0') {		//��Ҫ������д��0 
			if (fuhaonum % 2 == 1)	printf("��");
		}
		i++;
		if (shuru[i] == '\0') {	//�����С�����β�� 
			ReadOneNum(shuru[j]);
			j++;
			for (i = j; shuru[i] != '.'; i++);
			if (shuru[--i] != '0') {	//����0��β�� 
				if (shuru[j] != '\0') {
					printf("��");
					for (; shuru[j] != '.'; j++) {
						ReadOneNum(shuru[j]);
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			else {
				for (; shuru[i] == '0'; i--)	zerosnum++;
				if (zerosnum + 1 == n) {
					printf("��ʮ��");
					IReadNum(n - 1);
					printf("�η�");
				}
				else {
					printf("��");
					for (i = 0; i<n - zerosnum - 1; i++) {
						ReadOneNum(shuru[j]);
						j++;
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			if (n>10) printf("\n  �������������ֹ���%dλ", n);
			return OK;		//���123.���� 
		}
		//���ھ�ʣ��123.35 0.000 -0.000��������Ҫ��
		ReadOneNum(shuru[j]);	//����1
		printf("��");	//ֱ�Ӵ�� 
		j++;
		for (; shuru[j] != '.'; j++) {
			ReadOneNum(shuru[j]);	//˳������������� 
		}
		j++;
		for (; shuru[j] != '\0'; j++) {
			ReadOneNum(shuru[j]);	//˳�����С�����ֲ�ͳ��λ�� 
			xiaonum++;
		}
		if (n != 1) {				//����nֵҲ���Ա�����һ��ʮ����η�����  
			printf("��ʮ��");
			IReadNum(n - 1);
			printf("�η�");
		}
		if (n>10 && xiaonum>10)	printf("\n  �������������ֹ���%dλ��С�����ֹ���%dλ", n, xiaonum);
		else if (n>10) printf("\n  �������������ֹ���%dλ", n);
		else if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
		return OK;		//���123.5���� 
	}
}

/*Status SciReadNum(char shuru[]) {		//Խ��Խ����ֱ�ӷ������ó���
	//��ѧ������ģʽ�������
	//��ѧ������ģʽ�£���shuruɨ��һ�鼴�����������
	//����Ҳ��ʹ���˳���IReadNum���������ݴΣ���Ϊ�ú����������Ҫ��Ϊint 
	int i = 0, n = 0, j = 0, fuhaonum;	//i���ڹ�꣬j���ڵײ�Сѭ�� 
	int xiaonum = 0, zerosnum = 0;
	int spc = 0, XiaoShuKaiTouZeros = 0;	//��ͨ����spc��С����ͷzeros
	int iszero;
	for (i = 0; shuru[i] == ' ' || shuru[i] == '\t'; i++);	//������ƹ��հ��ַ� 
	for (fuhaonum = 0; shuru[i] == '-'; i++)	fuhaonum++;	//ͳ�Ƹ���������������ƹ����� 
	if (shuru[i] == '\0') {		//���ֻ�пհ��ַ��͸��� 
		printf("����ָ�");
		return ERROR;
	}
	if (shuru[i] == '.') {	//����ƹ���ͷ֮��ֱ�Ӿ���С������ 
		do {
			i++;
			n++;
		} while (shuru[i] == '0');
		if (shuru[i] == '\0') {
			printf("��");
			if (n>1) {
				printf("��");
				for (j = 0; j<n - 1; j++) {
					printf("��");
					xiaonum++;
				}
			}
			if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
			return OK;	//���.000���� 
		}

		//printf("  ");
		if (fuhaonum % 2 == 1)	printf("��");

		ReadOneNum(shuru[i]);
		i++;
		if (shuru[i] != '\0') {
			printf("��");
			for (; shuru[i] != '\0'; i++) {
				ReadOneNum(shuru[i]);
				xiaonum++;
			}
		}
		printf("��ʮ��");
		n = -n;
		IReadNum(n);
		printf("�η�");
		xiaonum -= n;
		if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
		return OK;		//���.001���� 
	}
	else {	//����Ļ�һ����0�����������ֿ�ͷ����0000, 00.0, 100, 0.335 , 100.0�� 
		//0000 00. �������
		//.00 0.00 00.0���������
		while (shuru[i] == '0') i++;	//�Ƚ�����ƹ����ܵ���
		if (i>0) { 		//�����Ժ���ʱ 
			if (shuru[i] == '.' || shuru[i] == '\0') i--;	//������ָ����ǽ�������С���㣬����� 
		}
		iszero = i;
		//shuru[i]Ϊ��һ����������
		//ȥͷ�����
		if (shuru[iszero] == '0') {
			iszero++;
			if (shuru[iszero] == '.') iszero++;
			if (shuru[iszero] == '\0') {
				printf("��");
				return OK;
			}
		}
		//����Ŀ���ǣ�ɨ��ȥͷ�������֣�����.��EOF�˳�ɨ�� 
		while (1) {	//ֻҪ����С�����EOF���ͼ���... 
			if (shuru[i] == '.')	break;
			if (shuru[i] == '\0') 	break;
			n++;
			i++;
		}
		//��������ʱ��shuru[i]����.����EOF 
		if (shuru[i] == '\0') {	//�����EOF��˵��û��С���� 
			//printf("  ");
			if (shuru[j] != '0') {	//��Ҫ������д��0 
				if (fuhaonum % 2 == 1)	printf("��");
			}
			ReadOneNum(shuru[j]);
			j++;
			for (i = j; shuru[i] != '\0'; i++);
			if (shuru[--i] != '0') {	//����0��β�� 
				if (shuru[j] != '\0') {
					printf("��");
					for (; shuru[j] != '\0'; j++) {
						ReadOneNum(shuru[j]);
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			else {		//û��С���㣬������0��β
				for (; shuru[i] == '0'; i--)	zerosnum++;	//����0000��0ʱ��Ҫ��bug
				if (zerosnum + 1 == n) {	
					printf("��ʮ��");
					IReadNum(n - 1);
					printf("�η�");
				}
				else {
					printf("��");	///////////////////////////
					for (i = 0; i<n - zerosnum - 1; i++) {
						ReadOneNum(shuru[j]);
						j++;
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			if (n>10) printf("\n  �������������ֹ���%dλ", n);
			return OK;		//���123���� 
		}
		//����Ļ�˵����С���㣬��shuru[i]����С���� 
		//printf("  ");
		if (shuru[j] != '0') {		//��Ҫ������д��0 
			if (fuhaonum % 2 == 1)	printf("��");
		}
		i++;
		if (shuru[i] == '\0') {	//�����С�����β�� 
			ReadOneNum(shuru[j]);
			j++;
			for (i = j; shuru[i] != '.'; i++);
			if (shuru[--i] != '0') {	//����0��β�� 
				if (shuru[j] != '\0') {
					printf("��");
					for (; shuru[j] != '.'; j++) {
						ReadOneNum(shuru[j]);
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			else {
				for (; shuru[i] == '0'; i--)	zerosnum++;
				if (zerosnum + 1 == n) {
					printf("��ʮ��");
					IReadNum(n - 1);
					printf("�η�");
				}
				else {
					printf("��");
					for (i = 0; i<n - zerosnum - 1; i++) {
						ReadOneNum(shuru[j]);
						j++;
					}
					printf("��ʮ��");		//����������Ա���һ��ʮ����η����� 
					IReadNum(n - 1);
					printf("�η�");
				}
			}
			if (n>10) printf("\n  �������������ֹ���%dλ", n);
			return OK;		//���123.���� 
		}
		//���ھ�ʣ��123.35 0.000 -0.000��������Ҫ��
		if (shuru[j] == '0') {
			xiaonum = 0;
			XiaoShuKaiTouZeros++;
			for (spc = j + 2; shuru[spc] == '0'; spc++)	XiaoShuKaiTouZeros++;
			if (shuru[spc] == '\0') {
				printf("��");
				if (XiaoShuKaiTouZeros > 1) {
					printf("��");
					for (i = 1; i < XiaoShuKaiTouZeros; i++) printf("��");
				}
				return 0;
			}
			for (spc = j + 2; shuru[spc] != '\0'; spc++)	xiaonum++;
			j = j + XiaoShuKaiTouZeros + 1;
			if (fuhaonum % 2 == 1)	printf("��");
			ReadOneNum(shuru[j]);
			if (shuru[++j] != '\0') printf("��");
			for (; shuru[j] != '\0'; j++) ReadOneNum(shuru[j]);
			printf("��ʮ�ĸ�");
			IReadNum(XiaoShuKaiTouZeros);
			printf("�η�");
			if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
			return OK;
		}
		ReadOneNum(shuru[j]);	//�������λ
		printf("��");	//ֱ�Ӵ�� 
		j++;
		for (; shuru[j] != '.'; j++) {
			ReadOneNum(shuru[j]);	//˳������������� 
		}
		j++;
		for (; shuru[j] != '\0'; j++) {
			ReadOneNum(shuru[j]);	//˳�����С�����ֲ�ͳ��λ�� 
			xiaonum++;
		}
		if (n != 1) {				//����nֵҲ���Ա�����һ��ʮ����η�����  
			printf("��ʮ��");
			IReadNum(n - 1);
			printf("�η�");
		}
		if (n>10 && xiaonum>10)	printf("\n  �������������ֹ���%dλ��С�����ֹ���%dλ", n, xiaonum);
		else if (n>10) printf("\n  �������������ֹ���%dλ", n);
		else if (xiaonum>10) printf("\n  ������С�����ֹ���%dλ", xiaonum);
		return OK;		//���123.5���� 
	}
}*/