int main() {

	MemberInfo* RTUser;
	RTUser = (MemberInfo*)malloc(sizeof(MemberInfo) * NowMember);

	int num = 0;

	while (1) {
		printf("===============================================================================================\n");
		printf("0.현재이용인원 1.회원입장 2.회원퇴장 3.회원등록 4.회원삭제 5.회원정보검색 9.프로그램 종료\n");
		printf("===============================================================================================\n");
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
					*/
			case 5:

				int SMemberNumber;

				printf("회원번호를 입력해주세요: ");
				scanf("%d", &SMemberNumber);
				getchar();

				MemberSearch(SMemberNumber);

			}
		}
	}

	return 0;
}
