#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include"Nbasic.h"

//���뺺�ֻ����
//ϣ������ֻ����س������������������ӡ>>�����ȳ��ֲ���ָ��

//���հ汾Ӧ������ģʽ
//1. ����ģʽ��
//2. ʮ�ż�������ģʽ
//3. ��ѧ����ģʽ
//4. ǧ��λģʽ���°������ʵ�λ��ͷģʽ��
//5. �Գ���ģʽΪ׼�ķ���ģʽ 
//����ģʽ����ʱͨ������ָ������л� 

//��չ����4.5k�������ֵ�֧��  ��1.5*10^3�������ֵ�֧��

int main() {
	char bignumber[502];
	int numlen, i = 0, flag = 0, zhiling = 0, mode = 2;
	memset(bignumber, '\0', 502);//��bignumber���г�ʼ�� 
	system("color 0F");
	printf("          ********************* ��������MARK V������ *************************\n");
	printf("          ************* ����info�鿴����˵��������exit�˳����� *************\n");
	printf(">>���������ֻ�ָ��\n");
	while (1) {
		printf(">>");
		while (1) {
			bignumber[i] = getchar();
			if (bignumber[i] == '\n') {
				break;
			}
			if (i>500) {
				printf("  ��⵽�����ַ�����500λ���������������������롣\n");
				flag = 1;
				//fflush(stdin);	//�������Ѿ����ٱ�֧�֣�Ӧ�������������
				scanf("%*[^\n]%*c");
				//����^\n���������ȡ�������еġ�\n���ַ�֮ǰ�������ַ���
				//������ı�ʾ����ȡ����Щ�ַ�������ǰ������\n���ַ�ʱ��ֹͣ��ȡ������
				//��ʱ��������������һ����\n���ַ�������
				//���Ժ���ģ�*c����ȡ��������������Ļ��з���
				//������Ǻź�ǰ����Ǻ�������ͬ��
				//�������дӼ��̵����붼���Իس������ģ����س������һ����\n���ַ���
				//���Խ���\n����ͬ��֮ǰ���ַ�ȫ����ȡ������֮��Ҳ���൱����������뻺����
				memset(bignumber, '\0', 502);
				break;
			}
			i++;
		}
		bignumber[i] = '\0';
		i = 0;
		if (flag == 1) {
			flag = 0;
			continue;
		}
		//����Ϊ��дgets�������������ڣ�ֻҪ�������ľͻ������
		numlen = strlen(bignumber);
		if (numlen>100 && mode != 2) {
			memset(bignumber, '\0', 502);
			printf("  ��⵽�����ַ�����100λ���������������������롣\n");
			continue;
		}

		//Ԥ������Pretreatment
		Pretreatment(bignumber, zhiling, mode);

		if (zhiling == 1) {
			printf("  ");
			if (mode == 0)			DoubleReadNum(bignumber);
			else if (mode == 1)		InfiReadNum(bignumber);
			else if (mode == 2)		SciReadNum(bignumber);
			else if (mode == 3)		SipreReadNum(bignumber);
			else if (mode == 4)		SpeakNumber(bignumber);
			printf("\n");
		}
		else if (zhiling == 2) {	//2Ϊ�˳�����ָ�� 
			printf("  �����˳�!\n");
			//printf("%c[2K", 27);	//��֪���Ǹ����
			Sleep(1000);
			return 0;
		}
	}
}