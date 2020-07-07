#include <stdio.h>
#include <Windows.h>
#include "Structure.h"

//現在のディレクトリを取得
void getGurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}


int main(void) {


	//ファイル入出力
	FILE* fi1, * fi2, * fi3,  * fo1, * fo2;
	char std1[255],std2[255],std3[255];
	Mag a;
	int result;

	fprintf_s(stdout, "今から診断テストを始めます。\n３つの質問に(1,2,3のいずれかで)回答してください。\n\n");

	
	//質問１
	if ((fi1=fopen("question1.txt", "r")) == NULL) {
		fprintf_s(stderr,"ファイルをオープンできません。\n");
		return 1;

	}

	while (fgets(std1, 256, fi1) != NULL) {
		fprintf_s(stdout,"%s", std1);
	}
	fclose(fi1);

	
	scanf_s("%d",&a.Ans1);
	fprintf_s(stdout, "\n");

	

	//質問２
	if ((fi2 = fopen("question2.txt", "r")) == NULL) {
		fprintf_s(stderr, "ファイルをオープンできません。\n");
		return 1;

	}

	while (fgets(std2, 256, fi2) != NULL) {
		fprintf_s(stdout, "%s", std2);
	}
	fclose(fi2);

	scanf_s("%d", &a.Ans2);
	fprintf_s(stdout, "\n");

	//質問３
	if ((fi3 = fopen("question3.txt", "r")) == NULL) {
		fprintf_s(stderr, "ファイルをオープンできません。\n");
		return 1;

	}

	while (fgets(std3, 256, fi3) != NULL) {
		fprintf_s(stdout, "%s", std3);
	}
	fclose(fi3);

	scanf_s("%d", &a.Ans3);
	fprintf_s(stdout, "\n");


	//出力結果の計算
	result = ((a.Ans1 * 9) + (a.Ans2 * 3) + (a.Ans3));
	
	fprintf_s(stdout, "%d\n\n",result);



	//iniファイル、charの読み込み
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "section1");
	/*char keyWord[CHARBUFF];
	sprintf_s(keyWord, "13");
	*/
	char keyValue[CHARBUFF];
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "setting.ini", currentDirectory);

	//char読み込み関数
	if (GetPrivateProfileString(section, "13", "fault", keyValue, CHARBUFF, settingFile) != 0) {
		fprintf_s(stdout, "%s , %s\n", settingFile, keyValue);
	}
	/*else {
		fprintf_s(stdout, "%s doesn't contain[%s]%s\n", settingFile, section, keyWord);
	}
	*/
	return 0;



}