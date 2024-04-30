void MemberExit(int SMemberNumber) {
	MemberInfo* members;
	int numMembers;
	FILE* file = fopen(FILENAME, "r+");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	// 파일에서 회원 정보를 읽어옴
	char line[256];
	numMembers = 0;
	members = NULL;

	while (fgets(line, sizeof(line), file)) {
		members = realloc(members, (numMembers + 1) * sizeof(MemberInfo));
		MemberInfo* currentMember = &(members)[numMembers];
		char* name = malloc(MAXLEN);
		if (name == NULL) {
			printf("메모리 할당 오류\n");
			exit(1);
		}

		sscanf(line, "%d, %[^,], %d, %[^,], %d", &currentMember->MemberNumber, name, &currentMember->gender, currentMember->PhoneNumber, &currentMember->state);
		strcpy(currentMember->name, name); // name을 currentMember->name에 복사
		free(name);
		numMembers++;
	}

	fclose(file);

	// 파일의 내용을 수정하여 회원 상태를 변경
	file = fopen(FILENAME, "w");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	for (int i = 0; i < numMembers; i++) {
		if (members[i].MemberNumber == SMemberNumber) {
			members[i].state = 0; // 퇴실 상태로 변경
		}
		fprintf(file, "%d, %s, %d, %s, %d\n", members[i].MemberNumber, members[i].name, members[i].gender, members[i].PhoneNumber, members[i].state);
	}

	// 동적 할당 해제 및 파일 닫기
	free(members);
	fclose(file);

	printf("회원번호 %d가 퇴실되었습니다.\n", SMemberNumber);
}
