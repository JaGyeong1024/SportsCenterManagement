void MemberRegi(){

	MemberInfo NewMemberInfo;

	printf("이름을 입력하세요: ");
	fgets(NewMemberInfo.name, MAXLEN, stdin);
	NewMemberInfo.name[strcspn(NewMemberInfo.name, "\n")] = 0;

	printf("전화번호를 입력하세요: ");
	fgets(NewMemberInfo.PhoneNumber, 12, stdin);
	NewMemberInfo.PhoneNumber[strcspn(NewMemberInfo.PhoneNumber, "\n")] = 0;

	printf("성별을 입력하세요 (남성이면 3, 여성이면 4): ");
	scanf("%d", &NewMemberInfo.gender);
	getchar();

	NewMemberInfo.MemberNumber = NewMemberInfo.gender * 10000 + NewMemberNumber;
	NewMemberNumber++;

	NewMemberInfo.state = 0;

	FILE* file = fopen(FILENAME, "a");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	fprintf(file, "%d, %s, %d, %s, %d \n", NewMemberInfo.MemberNumber, NewMemberInfo.name, NewMemberInfo.gender, NewMemberInfo.PhoneNumber, NewMemberInfo.state);
	fclose(file);

	printf("%d, %s, %d, %s, %d \n", NewMemberInfo.MemberNumber, NewMemberInfo.name, NewMemberInfo.gender, NewMemberInfo.PhoneNumber, NewMemberInfo.state);
	printf("\n인원 정보가 성공적으로 저장되었습니다.\n");
	printf("===============================================================================================\n");
}
