#include<stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define FILENAME "sportscenter.csv"
#define MAXLEN 50
int NewMemberNumber = 0;

typedef struct s_memberinfo {
	int MemberNumber;
	char name[MAXLEN];
	int gender; //3이면 남자 4이면 여자
	char PhoneNumber[12];
	int state; // 0이면 퇴실 1이면 입실
}MemberInfo;

int main() {

	int num = 0;

	while (1) {
		printf("===============================================================================================\n");
		printf("0.현재이용인원 1.회원입장 2.회원퇴장 3.회원등록 4.회원삭제 5.회원정보검색 9.프로그램 종료\n");
		printf("===============================================================================================\n");
		scanf("%d", &num);

		if (num == 9) {
			break;
		}
		else {
			int MemberNumber = 0;
			switch (num) {

			case 0:

				int currentMembers = CurrentMemberShow();
				printf("현재 이용 중인 회원 수는 %d명입니다. \n", currentMembers);
				break;

			case 1:

				printf("입실할 회원의 회원번호를 입력하세요: \n");
				scanf("%d", &MemberNumber);

				MemberEnter(MemberNumber);
				break;

			case 2:

				printf("퇴실할 회원의 회원번호를 입력하세요: \n");
				scanf("%d", &MemberNumber);

				MemberExit(MemberNumber);
				break;

			case 3:

				MemberRegi();
				break;

			case 4:

				printf("회원번호를 입력해주세요: ");
				scanf("%d", &MemberNumber);

				MemberDel(MemberNumber);
				break;

			case 5:

				printf("회원번호를 입력해주세요: ");
				scanf("%d", &MemberNumber);

				MemberSearch(MemberNumber);
				break;

			}
		}
	}

	return 0;
}
