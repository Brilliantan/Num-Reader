#include<stdio.h>
#include<string.h>
#include"Nbasic.h"

Status ReadIntPre(int zhengshuweishu) {
	if (zhengshuweishu < 0 || zhengshuweishu>26) return ERROR;
	if (zhengshuweishu == 2)	printf("da");
	if (zhengshuweishu == 3)	printf("h");
	if (zhengshuweishu > 3) {
		if (zhengshuweishu <= 6) printf("k");
		else if (zhengshuweishu <= 9) printf("M");
		else if (zhengshuweishu <= 12) printf("G");
		else if (zhengshuweishu <= 15) printf("T");
		else if (zhengshuweishu <= 18) printf("P");
		else if (zhengshuweishu <= 21) printf("E");
		else if (zhengshuweishu <= 24) printf("Z");
		else if (zhengshuweishu <= 27) printf("Y");
	}
	return OK;
}

Status ReadDecimalPre(int prezerosnum) {
	if (prezerosnum < 1 || prezerosnum>24) return ERROR;
	if (prezerosnum == 1) printf("d");
	else if (prezerosnum == 2) printf("c");
	else if (prezerosnum == 3) printf("m");
	else if (prezerosnum <= 6) printf("��");
	else if (prezerosnum <= 9) printf("n");
	else if (prezerosnum <= 12) printf("p");
	else if (prezerosnum <= 15) printf("f");
	else if (prezerosnum <= 18) printf("a");
	else if (prezerosnum <= 21) printf("z");
	else if (prezerosnum <= 24) printf("y");
	return OK;
}

//ע�⣬��������Խ��bug������0.0000001 \0 123 \0 ����������һ����
Status SipreReadNum(char love[]) {	
	//���ʵ�λ��ͷģʽ������� 
	//��Ϊ���֣����־���pretreatment�Ͽ����͵��ַ���. 
	//Pretreatment�Ͽɵ����֣�
	//���ɿո��Tab+���ɸ���+����0��Ϊ��ͷ
	//��ͷ����������ֻ�С���㣬��С����ֻ����һ��
	//����ͷ�������κ�λ�ò����ֿհ��ַ� 

	//ȷʵ����Խλ���⡣����������ض���......
	/*int ceshi;
	shuru[0] = '0';
	shuru[1] = '.';
	for (ceshi = 2; ceshi < 9; ceshi++) shuru[ceshi] = '0';
	shuru[ceshi] = '1';
	shuru[++ceshi] = '0';
	shuru[++ceshi] = '0';
	shuru[++ceshi] = '\0';
	shuru[++ceshi] = '0';
	shuru[++ceshi] = '1';
	shuru[++ceshi] = '2';
	shuru[++ceshi] = '3';
	shuru[++ceshi] = '4';
	shuru[++ceshi] = '\0';
	shuru[++ceshi] = '\0';*/

	//��һ��bug��0.00000001��д�����⡣�Ѿ����

	int i = 0, fuhaonum = 0, weishu = 0, endzeros = 0;
	int judge, j, preflag = 0, lingyudian=0;
	char xuyaodu[4],shuru[502];
	memset(shuru, '\0', 502);
	strcpy(shuru, love);
	while (shuru[i] == ' ' || shuru[i] == '\t')	i++;
	while (shuru[i] == '-') {
		fuhaonum++;
		i++;
	}
	while (shuru[i] == '0')	i++;

	//���´�����ǵĽ����. 000  0. -. -0. -0�����⣬��������0.000 -0.000 -.000 ������
	if (shuru[i] == '.') {
		i++;
		if (shuru[i] == '\0') {
			lingyudian = 1;
		}
		i--;
	}
	else if (shuru[i] == '\0') lingyudian = 1;
	if (lingyudian == 1) {
		printf("������0\n  ��������");
		return OK;
	}

	j = i;		//������ͷ��j��ͷ�ĸ�����
	
	while (shuru[i] != '\0'&&shuru[i] != '.') {
		weishu ++ ;
		i++;
	}		//iΪ��������С����
	if (weishu > 27) {
		printf("�����ֵ��ݴθ���26���������������������롣");
		return OVERFLOW;
	}
	judge = weishu % 3;
	//printf("  ");

	if (weishu == 0) {	//���˵��0.x��.x�����
		for (i = j + 1; shuru[i] == '0'; i++);
		if (shuru[i] == '\0') {		//���ȫ0
			printf("������0.");
			for (i = j + 1; shuru[i] == '0'; i++) printf("0");
			printf("\n  ���������");
			for (i = j + 1; shuru[i] == '0'; i++) printf("��");
			return OK;
		}
		weishu++;
		//ע�⣬shuru[j]=='.'
		for (j++; shuru[j] == '0'; j++)	weishu++;	//�����������ǰ��ĸ���
		if (weishu > 24) {
			printf("�����ֵ��ݴε���-24����������������������");
			return OVERFLOW;
		}
		if (weishu < 3) {		//����ֺ�������⣬ע��û�н����ֶ���
			i = j;
			printf("������");
			if (fuhaonum % 2 == 1)	printf("-");
			printf("%c", shuru[j]);

			if (shuru[++i] != '\0') printf(".");
			for (; shuru[i] != '\0'; i++) OnlyPrintNum(shuru[i]);
			ReadDecimalPre(weishu);

			printf("\n  ������");
			if (fuhaonum % 2 == 1)	printf("��");
			ReadOneNum(shuru[j]);
			if(shuru[++j]!='\0') printf("��");
			for (; shuru[j] != '\0'; j++) ReadOneNum(shuru[j]);
			if(weishu==1) printf("��");
			else printf("��");
			return OK;
		}
		judge = weishu % 3;
		if (judge == 1) {
			//shuru[j]Ϊ��һ��������
			xuyaodu[2] = shuru[j];

			if (shuru[j+1] == '\0') xuyaodu[1] = '0';	//С����������ͬ��
			else xuyaodu[1] = shuru[j+1];

			if (shuru[j+2] == '\0') xuyaodu[0] = '0';
			else xuyaodu[0] = shuru[j+2];

			printf("������");
			if (fuhaonum % 2 == 1)	printf("-");
			printf("%c%c%c", xuyaodu[2], xuyaodu[1], xuyaodu[0]);

			if (shuru[j + 3] != '\0')	printf(".");
			for (i = j + 3; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
			ReadDecimalPre(weishu);
			printf("\n  ������");
			if (fuhaonum % 2 == 1)	printf("��");

			ReadQian(2, 0, xuyaodu);
			if (shuru[j + 3] != '\0')	printf("��");
			for (i = j + 3; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
		}
		else if (judge == 0) {
			printf("������");
			if (fuhaonum % 2 == 1)	printf("-");
			printf("%c", shuru[j]);

			if (shuru[j + 1] != '\0')	printf(".");
			for (i = j + 1; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
			ReadDecimalPre(weishu);
			printf("\n  ������");
			if (fuhaonum % 2 == 1)	printf("��");
			ReadOneNum(shuru[j]);
			if (shuru[j + 1] != '\0')	printf("��");
			for (i = j + 1; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
		}
		else {	//judge=2
			xuyaodu[1] = shuru[j];

			if (shuru[j + 1] == '\0') xuyaodu[0] = '0';
			else xuyaodu[0] = shuru[j + 1];

			printf("������");
			if (fuhaonum % 2 == 1)	printf("-");
			printf("%c%c", xuyaodu[1],xuyaodu[0]);

			if (shuru[j + 2] != '\0')	printf(".");
			for (i = j + 2; shuru[i] != '\0'; i++)	printf("%c", shuru[i]);
			ReadDecimalPre(weishu);

			printf("\n  ������");
			if (fuhaonum % 2 == 1)	printf("��");
			ReadQian(1, 0, xuyaodu);
			if (shuru[j + 2] != '\0')	printf("��");
			for (i = j + 2; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
		}

		if (weishu <= 3) printf("��");
		else if (weishu <= 6) printf("΢");
		else if (weishu <= 9) printf("��[ŵ]");
		else if (weishu <= 12) printf("Ƥ[��]");
		else if (weishu <= 15) printf("��[ĸ��]");
		else if (weishu <= 18) printf("��[��]");
		else if (weishu <= 21) printf("��[����]");
		else if (weishu <= 24) printf("��[����]");
	
		return OK;
	}
	
	//printf("judge=%d i=%d j=%d weishu=%d jָ��%c", judge, i, j, weishu, shuru[j]);//������
	//��Ҫ���������β������������
	if (shuru[i] == '.') {	//��С����
		i++;
		if (shuru[i] != '\0') {		//�������123.��ʽ��Ҳ����˵����С��
			//if (fuhaonum % 2 == 1) printf("��");
			printf("������");
			if (judge == 0) {
				xuyaodu[0] = shuru[j + 2];
				xuyaodu[1] = shuru[j + 1];
				xuyaodu[2] = shuru[j];
				if (fuhaonum % 2 == 1) printf("-");
				if (weishu == 3) {
					printf("%c.", xuyaodu[2]);
					for (i = j + 1; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
				}
				else {
					printf("%c%c%c.", xuyaodu[2], xuyaodu[1], xuyaodu[0]);
					for (i = j + 3; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
				}
				ReadIntPre(weishu);
				printf("\n  ������");
				if (fuhaonum % 2 == 1) printf("��");
				ReadQian(2, 0, xuyaodu);
				printf("��");
				for (i = j + 3; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
			}
			else if (judge == 1) {		//����С�����������С��������weishu%3=1
				if (fuhaonum % 2 == 1) printf("-");
				//if (weishu == 0)	printf("0");
				printf("%c.", shuru[j]);
				for (i = j + 1; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
				ReadIntPre(weishu);
				printf("\n  ������");
				if (fuhaonum % 2 == 1) printf("��");

				//if (weishu == 0)	printf("��aaaaaaaaaaa");	//��俴������bug��
				ReadOneNum(shuru[j]);
				printf("��");
				for (i = j + 1; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
			}
			else {	//judge=2
				xuyaodu[0] = shuru[j + 1];
				xuyaodu[1] = shuru[j];
				if (fuhaonum % 2 == 1) printf("-");
				if (weishu == 2) {
					printf("%c.", xuyaodu[1]);
					for (i = j + 1; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
				}
				else {
					printf("%c%c.",xuyaodu[1], xuyaodu[0]);
					for (i = j + 2; shuru[i] != '\0'; i++)	OnlyPrintNum(shuru[i]);
				}
				ReadIntPre(weishu);
				printf("\n  ������");
				if (fuhaonum % 2 == 1) printf("��");
				ReadQian(1, 0, xuyaodu);
				printf("��");
				for (i = j + 2; shuru[i] != '\0'; i++)	ReadOneNum(shuru[i]);
			}
			if (weishu > 3) {
				if (weishu <= 6) printf("ǧ");
				else if (weishu <= 9) printf("��");
				else if (weishu <= 12) printf("��[��]");
				else if (weishu <= 15) printf("̫[��]");
				else if (weishu <= 18) printf("��[��]");
				else if (weishu <= 21) printf("��[����]");
				else if (weishu <= 24) printf("��[��]");
				else if (weishu <= 27) printf("Ң[��]");
			}
			return OK;
		}
	}
	//����00000000000012134316����ʮ�����׵�����
	//����С�����Ϊ123.��ʽ
	
	i--;
	if (shuru[i] != '.') i++;
	for (i--; shuru[i] == '0'; i--)	endzeros++;		//���β�ж���0
	if (judge == 0) {
		xuyaodu[0] = shuru[j + 2];
		xuyaodu[1] = shuru[j + 1];
		xuyaodu[2] = shuru[j];

		printf("������");
		if (fuhaonum % 2 == 1) printf("-");
		if (weishu == 3) {
			printf("%c", xuyaodu[2]);
			if (weishu - endzeros > 1) printf(".");
			//j�����shuru[j]Ϊ��һ����������
			for (i = j + 1; i < 3 - endzeros + j; i++)	OnlyPrintNum(shuru[i]);
		}
		else {
			printf("%c%c%c", xuyaodu[2], xuyaodu[1], xuyaodu[0]);
			if (weishu - endzeros > 3) printf(".");
			for (i = j + 3; i < weishu - endzeros + j; i++)	OnlyPrintNum(shuru[i]);
		}
		ReadIntPre(weishu);
		printf("\n  ������");
		if (fuhaonum % 2 == 1) printf("��");

		ReadQian(2, 0, xuyaodu);
		if (weishu - endzeros > 3) printf("��");		//�ӵ�������������
		for (i = j + 3; i < weishu - endzeros + j; i++)	ReadOneNum(shuru[i]);
	}
	else if (judge == 1) {

		printf("������");
		if (fuhaonum % 2 == 1) printf("-");
		printf("%c", shuru[j]);
		if (weishu - endzeros > 1) printf(".");
		for (i = j + 1; i < weishu - endzeros + j; i++)	OnlyPrintNum(shuru[i]);
		ReadIntPre(weishu);
		printf("\n  ������");
		if (fuhaonum % 2 == 1) printf("��");

		ReadOneNum(shuru[j]);
		if (weishu - endzeros > 1) printf("��");
		//��һ���ӵ�������Ҳ�Ǻ��������if (weishu - 1 != endzeros)
		for (i = j + 1; i < weishu - endzeros + j; i++)	ReadOneNum(shuru[i]);
	}
	else {	//judge=2
		xuyaodu[0] = shuru[j + 1];
		xuyaodu[1] = shuru[j];

		printf("������");
		if (fuhaonum % 2 == 1) printf("-");
		if (weishu == 2) {
			printf("%c", xuyaodu[1]);
			if (endzeros < 1) printf(".");
			for (i = j + 1; i < 2 - endzeros + j; i++)	OnlyPrintNum(shuru[i]);
		}
		else {
			printf("%c%c", xuyaodu[1], xuyaodu[0]);
			if (weishu - endzeros > 2) printf(".");
			for (i = j + 2; i < weishu - endzeros + j; i++)	OnlyPrintNum(shuru[i]);
		}
		ReadIntPre(weishu);
		printf("\n  ������");
		if (fuhaonum % 2 == 1) printf("��");

		ReadQian(1, 0, xuyaodu);
		//printf("j=%d weishu=%d endzeros=%d ", j, weishu, endzeros);
		if (weishu - endzeros > 2) printf("��");		//ˮ������
		for (i = j + 2; i < weishu - endzeros + j; i++)	ReadOneNum(shuru[i]);
	}
	if (weishu > 3) {
		if (weishu <= 6) printf("ǧ");
		else if (weishu <= 9) printf("��");
		else if (weishu <= 12) printf("��[��]");
		else if (weishu <= 15) printf("̫[��]");
		else if (weishu <= 18) printf("��[��]");
		else if (weishu <= 21) printf("��[����]");
		else if (weishu <= 24) printf("��[��]");
		else if (weishu <= 27) printf("Ң[��]");
	}

	return OK;
}