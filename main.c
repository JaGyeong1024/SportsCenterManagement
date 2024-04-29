#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define FILENAME "sportscenter.csv"
#define NowMember 10
#define MAXLEN 50
#define NewMemberNumber 0
int increased = 1;

typedef struct s_memberinfo {
	int MemberNumber;
	char name[MAXLEN]; //동적할당으로 바꾸기
	int gender; //3이면 남자 4이면 여자
	char PhoneNumber[12];
	int state; // 0이면 퇴실 1이면 입실
}MemberInfo;
int main() {

	MemberInfo* RTUser;
	RTUser = (MemberInfo*)malloc(sizeof(MemberInfo) * NowMember);

	int num = 0;

	while (1) {
		printf("0.현재이용인원 1.회원입장 2.회원퇴장 3.회원등록 4.회원삭제 5.회원정보검색 9.프로그램 종료\n");
		scanf("%d", &num);
		getchar();

		if (num == 9) {
			free(RTUser);
			break;
		}
		else if (num == 0) {
			//RealTimeUserShow();
		}
		else {
			int MemberNumber;
			switch (num) {
			/*case 1:
				printf("회원번호를 입력해주십시오: ");
				scnaf("%d", &MemberNumber);
				MemberEnter(MemberNumber, RTUser);
				break;
			case 2:
				MemberExit(MemberNumber);
				break;*/
			case 3:
				MemberRegi();
				break;
			/*case 4:
				MemberDel(MemberNumber);
				break;
			case 5:
				MemberSearch(MemberNumber);
				break;*/
			}
		}

	}

	return 0;
}
