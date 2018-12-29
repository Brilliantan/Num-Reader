#include<stdio.h>
#include<ctype.h>
#include"Nbasic.h"

int IReadOneNum(int onenum) {		//����I��Ϊʵ�ð� 
	if (onenum>9 || onenum<0) return 0;
	if (onenum == 0)	printf("��");
	else if (onenum == 1)	printf("һ");
	else if (onenum == 2)	printf("��");
	else if (onenum == 3)	printf("��");
	else if (onenum == 4)	printf("��");
	else if (onenum == 5)	printf("��");
	else if (onenum == 6)	printf("��");
	else if (onenum == 7)	printf("��");
	else if (onenum == 8)	printf("��");
	else if (onenum == 9)	printf("��");
	return 1;
}

int ICountZerosEnd(int gao, int di, int qianwei[]) {//����ĩβ0�ĸ��� 
	int zerosnum;
	for (zerosnum = 0; gao >= di; di++) {
		if (qianwei[di] == 0)	zerosnum++;
		else return zerosnum;
	}
	return zerosnum;
}

int IZerosBtw(int gao, int di, int qianwei[]) {//����ж�4λ�� 
	if (gao - di<3)	return 0;
	if (qianwei[gao - 1] != 0)	return 0;
	if (qianwei[gao] == 0) {
		if (qianwei[gao - 2] == 0 && qianwei[di] == 0)	return 0;
		return 1;
	}
	if (qianwei[gao] != 0) {
		if (qianwei[gao - 2] == 0 && qianwei[di] != 0)	return 1;
		return 0;
	}
}

int IReadQian(int gao, int di, int qianwei[]) {
	int tailzerosnum, havebtwzeros;
	if (gao<di || gao>di + 3)	return 0;
	if (gao == di)	IReadOneNum(qianwei[gao]);
	else if (gao - 1 == di) {
		if (qianwei[gao] != 1)	IReadOneNum(qianwei[gao]);
		printf("ʮ");
		gao--;
		if (qianwei[gao] != 0) IReadOneNum(qianwei[gao]);
	}
	else if (gao - 2 == di) {
		tailzerosnum = ICountZerosEnd(gao, di, qianwei);
		if (tailzerosnum == 0) {
			IReadOneNum(qianwei[gao]);
			printf("��");
			gao--;
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0) printf("ʮ");
			gao--;
			IReadOneNum(qianwei[gao]);
		}
		else if (tailzerosnum == 1) {
			IReadOneNum(qianwei[gao]);
			printf("��");
			gao--;
			IReadOneNum(qianwei[gao]);
			printf("ʮ");

		}
		else if (tailzerosnum == 2) {
			IReadOneNum(qianwei[gao]);
			printf("��");
		}
	}
	else if (gao - 3 == di) {
		tailzerosnum = ICountZerosEnd(gao, di, qianwei);
		if (tailzerosnum == 4)	return 1;
		else if (tailzerosnum == 3) {
			IReadOneNum(qianwei[gao]);
			printf("ǧ");
		}
		else if (tailzerosnum == 2) {
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0)	printf("ǧ");
			gao--;
			IReadOneNum(qianwei[gao]);
			printf("��");
		}
		else if (tailzerosnum == 1) {
			havebtwzeros = IZerosBtw(gao, di, qianwei);
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0) printf("ǧ");
			gao--;
			if (havebtwzeros == 1) {
				gao--;
				IReadOneNum(qianwei[gao]);
				printf("ʮ");
				return 1;
			}
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0) printf("��");
			gao--;
			IReadOneNum(qianwei[gao]);
			printf("ʮ");
		}
		else {
			havebtwzeros = IZerosBtw(gao, di, qianwei);
			if (havebtwzeros == 1) {
				IReadOneNum(qianwei[gao]);
				if (qianwei[gao] != 0) {
					printf("ǧ��");
					gao -= 3;
					IReadOneNum(qianwei[gao]);
					return 1;
				}
				gao -= 2;
				if (qianwei[gao] != 0) {
					IReadOneNum(qianwei[gao]);
					printf("ʮ");
					gao--;
					IReadOneNum(qianwei[gao]);
					return 1;
				}
				gao--;
				IReadOneNum(qianwei[gao]);
				return 1;
			}
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0) printf("ǧ");
			gao--;
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0)	printf("��");
			gao--;
			IReadOneNum(qianwei[gao]);
			if (qianwei[gao] != 0)	printf("ʮ");
			gao--;
			IReadOneNum(qianwei[gao]);
		}
	}
	return 1;
}

int IReadNum(int TransNum) {
	int zeros;
	if (TransNum == 0) {
		printf("��");
		return 1;
	}
	int gewei[20] = { 0 };
	int i = 0, num, weishu = 0;
	if (TransNum >= 0) {
		num = TransNum;
		gewei[0] = 0;
	}
	else {
		num = -TransNum;
		gewei[0] = 1;
	}
	for (i = 1; num>0; i++) {
		gewei[i] = num % 10;
		num = num / 10;
		weishu++;
	}
	if (gewei[0] == 1)	printf("��");
	if (weishu <= 4)	IReadQian(weishu, 1, gewei);
	else if (weishu <= 8) {
		IReadQian(weishu, 5, gewei);
		printf("��");
		IReadQian(4, 1, gewei);
	}
	else if (weishu <= 10) {
		IReadQian(weishu, 9, gewei);
		printf("��");
		IReadQian(8, 5, gewei);
		zeros = ICountZerosEnd(8, 5, gewei);
		if (zeros != 4)	printf("��");
		IReadQian(4, 1, gewei);
	}
	else {
		printf("���ֹ��󣬲���ʶ��");
		return 0;
	}
	return 1;
}

Status ReadOneNum(char onenum) {		
	//���������������֣����123.56 \0��������ѭ��ȫ���ô˺������������Ϊһ��������
	if (isdigit(onenum) == 0) return ERROR;
	if (onenum == '0')	printf("��");
	else if (onenum == '1')	printf("һ");
	else if (onenum == '2')	printf("��");
	else if (onenum == '3')	printf("��");
	else if (onenum == '4')	printf("��");
	else if (onenum == '5')	printf("��");
	else if (onenum == '6')	printf("��");
	else if (onenum == '7')	printf("��");
	else if (onenum == '8')	printf("��");
	else if (onenum == '9')	printf("��");
	return OK;
}

int CountZerosEnd(int gao, int di, char qianwei[]) {//����ĩβ0�ĸ��� 
	int zerosnum;
	for (zerosnum = 0; gao >= di; di++) {
		if (qianwei[di] == '0')	zerosnum++;
		else return zerosnum;
	}
	return zerosnum;
}

Status ZerosBtw(int gao, int di, char qianwei[]) {
	//����ж�4λ��
	//4λ���������16��
	// XXXX X0XX 0XXX 00XX
	// XXX0 X0X0 0XX0 00X0
	// XX0X X00X 0X0X 000X
	// XX00 X000 0X00 0000
	//���е�  00XX 00X0 X00X 000X����YES
	//1-3λֻ�᷵��NO 
	if (gao - di<3)	return NO;
	if (qianwei[gao - 1] != '0')	return NO;
	//�ڶ�λ����0�Ļ�һ������������
	//��ʱֻʣ����8�����
	// X0XX  00XX
	// X0X0  00X0
	// X00X  000X
	// X000  0000
	//�����һλ��0����ôֻ���ж������λ�Ƿ���0������NO�������򷵻�YES
	if (qianwei[gao] == '0') {
		if (qianwei[gao - 2] == '0'&&qianwei[di] == '0')	return NO;
		return YES;
	}
	//�����һλ����0����ôֻ���ж������λ�Ƿ���0X������YES��������NO
	if (qianwei[gao] != '0') {
		if (qianwei[gao - 2] == '0'&&qianwei[di] != '0')	return YES;
		return NO;
	}
}

//ʹ��˵�����������ͷ�Ǵ�0��ʼ����123������gao=3 di=0������ǧ���ٶ�ʮһ
Status ReadQian(int gao, int di, char qianwei[]) {
	//����ע�⣬ReadQian�������ܶ���0��0��ͷ������ 

	int tailzerosnum, havebtwzeros;

	if (gao<di || gao>di + 3)	return ERROR;

	if (gao == di)	ReadOneNum(qianwei[gao]);//һλ��ֱ������� 

	else if (gao - 1 == di) {	//�������λ������λһ�����㣬��һ���жϼ��ɽ��ʮ������ 
		if (qianwei[gao] != '1')	ReadOneNum(qianwei[gao]);//���12����ʮ������һʮ�������� 
		printf("ʮ");
		gao--;
		if (qianwei[gao] != '0') ReadOneNum(qianwei[gao]);//���ʮ������� 
	}

	else if (gao - 2 == di) {//��λ��ͬ���������������⡣����ʱ��Ҫ�ж�ĩβ��ĸ������������

		tailzerosnum = CountZerosEnd(gao, di, qianwei);	//��¼ÿ��β����ĸ��� 

		if (tailzerosnum == 0) {	//X0X XXX
			ReadOneNum(qianwei[gao]);
			printf("��");
			gao--;
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0') printf("ʮ");
			gao--;
			ReadOneNum(qianwei[gao]);
		}
		else if (tailzerosnum == 1) {	//XX0  
			ReadOneNum(qianwei[gao]);
			printf("��");
			gao--;
			ReadOneNum(qianwei[gao]);
			printf("ʮ");
		}
		else if (tailzerosnum == 2) {	//X00 
			ReadOneNum(qianwei[gao]);
			printf("��");
		}
	}

	else if (gao - 3 == di) {	//��ʱ�ȴ����������⣬Ҳ����β�����⣬Ҳ����һʮ������ 

		tailzerosnum = CountZerosEnd(gao, di, qianwei);
		//��¼ÿ��β����ĸ��� 

		//4λ���������16��

		// XXXX X0XX 0XXX 00XX
		// XXX0 X0X0 0XX0 00X0
		// XX0X X00X 0X0X 000X
		// XX00 X000 0X00 0000

		//����������00XX 00X0 X00X 000X
		if (tailzerosnum == 4)	return OK;//ȫ���㣬���ö� 

		else if (tailzerosnum == 3) {	//������3���㣬ֻ����X000��ʽ 
			ReadOneNum(qianwei[gao]);
			printf("ǧ");
		}

		else if (tailzerosnum == 2) {//�����������㣬������XX00 0X00 
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0')	printf("ǧ");
			gao--;
			ReadOneNum(qianwei[gao]);
			printf("��");
		}

		else if (tailzerosnum == 1) { //������һ���㣬�����XXX0 X0X0 0XX0 00X0 

			havebtwzeros = ZerosBtw(gao, di, qianwei);	//��ʱ��Ҫʹ��ZerosBtw��¼�����Ƿ�������� 

			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0') printf("ǧ");
			gao--;
			if (havebtwzeros == YES) {	//��ʱΪ00X0����� 
				gao--;
				ReadOneNum(qianwei[gao]);
				printf("ʮ");	//��ʱ10����һʮ����10����Ϊ��һʮ�����϶�����ֻ��ĳ��Ϊ��������λ����ʡ��һ�� 
				return OK;
			}

			//��ʱ��ʣXXX0 X0X0 0XX0
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0') printf("��");
			gao--;
			ReadOneNum(qianwei[gao]);//ʮλ��ֱ�� 
			printf("ʮ");	//���˽�� 
		}

		else {

			//����û��0������а��֣�
			//XXXX 0XXX X0XX 00XX XX0X 0X0X X00X 000X
			//���� 00XX X00X 000XΪ������ȷ��� 
			//XXXX 0XXX X0XX XX0X 0X0XΪ��ͨ�������ͨ���������ֱ�ӽ�� 

			havebtwzeros = ZerosBtw(gao, di, qianwei);	//��¼���㡣 

			if (havebtwzeros == YES) {
				//��ʱ��ʣ 00XX X00X 000X ��Ҫ�������һλһ�����㡣
				ReadOneNum(qianwei[gao]);//����һλ 
				if (qianwei[gao] != '0') {//�����X00X 
					printf("ǧ��");
					gao -= 3;
					ReadOneNum(qianwei[gao]);
					return OK;
				}
				//��һλΪ0,���Ϊ00XX 000X
				gao -= 2;
				if (qianwei[gao] != '0') {
					ReadOneNum(qianwei[gao]);
					printf("ʮ");
					gao--;
					ReadOneNum(qianwei[gao]);
					return OK;
				}
				//000X
				gao--;
				ReadOneNum(qianwei[gao]);
				return OK;
			}
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0') printf("ǧ");
			gao--;
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0')	printf("��");
			gao--;
			ReadOneNum(qianwei[gao]);
			if (qianwei[gao] != '0')	printf("ʮ");
			gao--;
			ReadOneNum(qianwei[gao]);//���һλһ����Ϊ0��ֱ���� 
		}
	}
	return OK;
}

Status readwan(char TransNum[], int zuigao) {
	int zeros;

	ReadQian(zuigao - 1, 4, TransNum);
	zeros = CountZerosEnd(7, 4, TransNum);
	if (zeros != 4)	printf("��");

	ReadQian(3, 0, TransNum);
	return OK;
}

Status readyi(char TransNum[], int zuigao) {//�޸�ʱ�������֣���<=����>����printf������readXXX 
	int zeros;

	if (zuigao <= 8 || zuigao>12)	return ERROR;

	ReadQian(zuigao - 1, 8, TransNum);
	zeros = CountZerosEnd(zuigao - 1, 8, TransNum);
	if (zeros != 4) printf("��");

	readwan(TransNum, 8);

	return OK;
}

void Brilliantan() {
	int MyNameIsGengHaoRan;
}

Status OnlyPrintNum(char character) {
	if (isdigit(character)) {
		printf("%c", character);
		return OK;
	}
	return ERROR;
}
