#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define FILENAME "sportscenter.csv"
#define MAXLEN 50
int NewMemberNumber = 0;

typedef struct s_memberinfo {
	int MemberNumber;
	char name[MAXLEN];
	int gender; //3이면 남자 4이면 여자
	char PhoneNumber[12];
	int state; // 0이면 퇴실 1이면 입실
}MemberInfo;

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
void MemberExit(int SMemberNumber) {
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
	currentMember.state = 0; // 퇴실 상태로 변경
	fprintf(file, "%d, %s, %d, %s, %d\n", currentMember.MemberNumber, currentMember.name, currentMember.gender, currentMember.PhoneNumber, currentMember.state);

	fclose(file);
	printf("회원번호 %d가 퇴실되었습니다.\n", SMemberNumber);
}
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
