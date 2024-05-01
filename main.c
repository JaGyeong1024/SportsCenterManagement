int main() {

	int num = 0;

	while (1) {
		printf("===============================================================================================\n");
		printf("0.현재이용인원 1.회원입장 2.회원퇴장 3.회원등록 4.회원삭제 5. 회원정보검색 9.프로그램 종료\n");
		printf("===============================================================================================\n");
		scanf("%d", &num);
		getchar();

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

				printf("입실할 회원의 회원번호를 입력하세요: ");
				scanf("%d", &MemberNumber);
				getchar();
				printf("\n");

				MemberEnter(MemberNumber);
				break;

			case 2:

				printf("퇴실할 회원의 회원번호를 입력하세요: ");
				scanf("%d", &MemberNumber);
				getchar();
				printf("\n");

				MemberExit(MemberNumber);
				break;

			case 3:

				MemberRegi();
				break;

			case 4:

				printf("회원번호를 입력해주세요: ");
				scanf("%d", &MemberNumber);
				getchar();

				MemberDel(MemberNumber);
				break;

			case 5:

				printf("회원번호를 입력해주세요: ");
				scanf("%d", &MemberNumber);
				getchar();

				MemberSearch(MemberNumber);
				break;

			}
		}
	}

	return 0;
}
