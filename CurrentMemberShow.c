int CurrentMemberShow() {
	MemberInfo* members;
	int numMembers;
	int count = 0;

	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	numMembers = 0;
	members = NULL;
	char line[256];

	while (fgets(line, sizeof(line), file)) {
		members = realloc(members, (numMembers + 1) * sizeof(MemberInfo));
		MemberInfo* currentMember = &(members)[numMembers];

		sscanf(line, "%d, %[^,], %d, %[^,], %d", &currentMember->MemberNumber, currentMember->name, &currentMember->gender, currentMember->PhoneNumber, &currentMember->state);

		numMembers++;
	}

	fclose(file);

	for (int i = 0; i < numMembers; i++) {
		if (members[i].state == 1) {
			count++;
		}
	}

	free(members);

	return count;
}
