void MemberSearch(int SMemberNumber) {
	printf("-----------------------------------------------------------------------------------------------\n");
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	char line[256];
	int found = 0; // 검색 결과를 나타내는 변수

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
			found = 1; // 검색 성공 표시
		}
	}

	fclose(file);

	if (!found) {
		printf("유효하지 않은 회원번호입니다.\n");
		fclose(file);
	}
}
