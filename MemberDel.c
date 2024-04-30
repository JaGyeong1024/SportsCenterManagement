void MemberDel(int SMemberNumber) {
	//회원 삭제
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	FILE* tempFile = fopen("temp.csv", "w");
	if (tempFile == NULL) {
		printf("임시 파일을 열 수 없습니다.\n");
		fclose(file);
		return;
	}

	char line[256];
	int found = 0;

	while (fgets(line, sizeof(line), file)) {
		int MemberNumber;
		char name[MAXLEN];
		int gender;
		char PhoneNumber[12];
		int state;

		sscanf(line, "%d, %[^,], %d, %[^,], %d", &MemberNumber, name, &gender, PhoneNumber, &state);

		if (MemberNumber == SMemberNumber) {
			found = 1; // 회원번호를 찾음
			continue; // 해당 행은 임시 파일에 쓰지 않고 건너뜀
		}

		fputs(line, tempFile); // 임시 파일에 행 쓰기
	}

	fclose(file);
	fclose(tempFile);

	if (!found) {
		printf("해당 회원 번호를 가진 회원이 존재하지 않습니다.\n");
		remove("temp.csv"); // 임시 파일 삭제
		return;
	}

	// 임시 파일을 원본 파일로 이동
	remove(FILENAME);
	rename("temp.csv", FILENAME);

	printf("회원 번호 %d에 해당하는 회원을 삭제했습니다.\n", SMemberNumber);
}
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
		else {
			printf("유효하지 않은 회원번호입니다.\n");
			return;
		}
	}
}
