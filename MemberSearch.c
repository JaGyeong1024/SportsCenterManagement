void MemberSearch(int SMemberNumber) {
	// CSV 파일에서 조건에 맞는 행을 가져오는 함수
	printf("-----------------------------------------------------------------------------------------------\n");
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	char line[256];
	while (fgets(line, sizeof(line), file)) {
		int MemberNumber = 0;
		char name[MAXLEN];
		int gender = 0;
		char PhoneNumber[12];
		int state = 0;

		sscanf(line, "%d, %[^,], %d, %[^,], %d", &MemberNumber, name, &gender, PhoneNumber, &state);

		if (MemberNumber == SMemberNumber) {
			printf("회원번호, 이름, 성별, 전화번호, (0:퇴실, 1:입실)\n");
			printf(" %d,  %s, %d,  %s,      %d\n", MemberNumber, name, gender, PhoneNumber, state);
			fclose(file);
			return;
		}
	}
