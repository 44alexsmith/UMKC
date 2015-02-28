
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>

using namespace std;

void main(void)
{
	//Define the necessary variables
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	BOOL ret;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	char response = 'z';
	TCHAR szAppName[260] = TEXT(" ");


	//Display a menu for the end user
	while (!(response == 'e'))
	{
		printf("\n\nReady to create process \n\n");
		printf("c) To launch calc.exe \n");
		printf("i) To launch ipconfig.exe \n");
		printf("t) To launch netstat.exe \n");
		printf("p) To launch mspaint.exe \n");
		printf("s) To launch systeminfo.exe \n");
		printf("n) To launch notepad.exe \n");
		printf("e) To exit the main program \n");

		//Capture the user's response
		scanf_s("%c", &response, 1);
		

		//Logic to decide which app to launch
		if (response == 'c')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\calc.exe"));
			continue;
		}
		else if (response == 'i')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\ipconfig.exe"));
			continue;
		}
		else if (response == 't')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\netstat.exe"));
			continue;
		}
		else if (response == 'p')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\mspaint.exe"));
			continue;
		}
		else if (response == 's')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\systeminfo.exe"));
			continue;
		}
		else if (response == 'n')
		{
			wcscpy_s(szAppName, TEXT("C:\\windows\\system32\\notepad.exe"));
			continue;
		}
		else if (response == 'e' || response == 'E')
		{
			return;
		}

		if (!CreateProcess(NULL, szAppName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
				printf(" Create Process failed (%d). \n", GetLastError());
				return;
		}

			WaitForSingleObject(pi.hProcess, INFINITE);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			printf("\n\nProcess terminates \n\n");
			system("cls");
			response = ' '; //reset the response value		
		
	}
	

}




