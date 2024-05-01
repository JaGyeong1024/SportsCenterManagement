void MemberEnter(int SMemberNumber) {
    FILE* file = fopen(FILENAME, "r+");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    MemberInfo currentMember;
    int found = 0;

    // 파일에서 회원 정보를 읽어와서 해당 회원 번호에 해당하는 회원의 상태를 변경
    char line[256];
    long int pos = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d, %[^,], %d, %[^,], %d", &currentMember.MemberNumber, currentMember.name, &currentMember.gender, currentMember.PhoneNumber, &currentMember.state);
        if (currentMember.MemberNumber == SMemberNumber) {
            found = 1;
            break;
        }
        pos = ftell(file); // 현재 파일 포인터 위치 저장
    }

    if (!found) {
        printf("해당 회원 번호를 가진 회원이 존재하지 않습니다.\n");
        fclose(file);
        return;
    }

    // 찾은 회원의 상태를 수정하고 파일 포인터를 수정된 레코드의 시작 위치로 이동
    fseek(file, pos, SEEK_SET);
    currentMember.state = 1; // 입실 상태로 변경
    fprintf(file, "%d, %s, %d, %s, %d\n", currentMember.MemberNumber, currentMember.name, currentMember.gender, currentMember.PhoneNumber, currentMember.state);

    fclose(file);
    printf("회원번호 %d가 입실되었습니다.\n", SMemberNumber);
}
