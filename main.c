#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct memberinfo {
	int MemberNumber;
	char name[9]; //동적할당으로 바꾸기
	char sex;
	char PhoneNumber[12];
	bool state;
};
void RealTimeUser() {
	//현재 이용인원
}
void MemberEnter(int MemberNumber) {
	//회원 입장
}
void MemberExit(int MemberNumber) {
	//회원 퇴장
}
void MemberRegi() {
	//회원 등록
}
void MemberDel(int MemberNumber) {
	//회원 삭제
}
void MemberSearch(int MemberNumber) {
	//회원정보검색
	//유효하지 않은 회원번호일 시, 유효하지 않은 회원번호입니다. 띄우기
}
int main() {
	int num = 0;
	while (1) {
		printf("0.현재이용인원 1.회원입장 2.회원퇴장 3.회원등록 4.회원삭제 5.회원정보검색 9.프로그램 종료");
		scanf_s("%d", &num);
		if (num == 9) {
			break;
		}
		else if(num == 0) {
			RealTimeUser();
		} 
		else{
			int MemberNumber;
			switch (num) {
			case 1:
				printf("회원번호를 입력해주십시오: ");
				scnaf_s("%d", &MemberNumber);
				MemberEnter(MemberNumber);
				break;
			case 2:
				MemberExit(MemberNumber);
				break;
			case 3:
				MemberRegi();
				break;
			case 4:
				MemberDel(MemberNumber);
				break;
			case 5:
				MemberSearch(MemberNumber);
				break;
			}
		}






	}
	return 0;
}
