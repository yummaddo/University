#include <windows.h>
#include <psapi.h>
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include <atlbase.h>
#include <atlconv.h>
using namespace std;
#define ARRAY_SIZE 1024
map<int, vector<string>> mapProc;
void killProc(int pr_ID) {//Деактивування процесу
	HANDLE explorer;
	explorer = OpenProcess(PROCESS_ALL_ACCESS, false, pr_ID);
	TerminateProcess(explorer, 1);//Зупинка
}
int PrintModules(DWORD processID)
{
	HMODULE proc[1024];
	HANDLE Process;
	DWORD dword;
	cout << endl << "ID: " << endl << processID;//Id процеса
	PROCESS_MEMORY_COUNTERS pmc;
	Process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE,
		processID);//Процес
	if (NULL == Process)
		return 1;
	vector<string> names;
	if (EnumProcessModules(Process, proc, sizeof(proc), &dword))//Інформація
	{
		for (unsigned int i = 0; i < (dword / sizeof(HMODULE)); i++)
		{
			TCHAR Name[MAX_PATH];
			if (GetModuleFileNameEx(Process, proc[i], Name, sizeof(Name) /
				sizeof(TCHAR)))//Ім'я
			{
				USES_CONVERSION;//Конвертація
				printf(T2A(Name));
				names.push_back(T2A(Name));//Запис у векторр
				cout << endl;
			}
		}
	}
	mapProc.insert(make_pair(processID, names));//Запис у map
	CloseHandle(Process);
	return 0;
}
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LPVOID drivers[ARRAY_SIZE];
	DWORD dword;
	int Drive;
	vector<string> names2;
	if (EnumDeviceDrivers(drivers, sizeof(drivers), &dword) && dword <
		sizeof(drivers))
	{
		TCHAR Name2[ARRAY_SIZE];
		Drive = dword / sizeof(drivers[0]);
		printf("Виявлено %d драйверів:\n", Drive);
		for (int i = 0; i < Drive; i++)
		{
			if (GetDeviceDriverBaseName(drivers[i], Name2, sizeof(Name2) /
				sizeof(Name2[0])))//Ім'я драйвера
			{
				USES_CONVERSION;
				printf(T2A(Name2));
				names2.push_back(T2A(Name2));//Запис у вектор
				cout << endl;
			}
		}
	}
	for (int i = 0; i < names2.size(); i++) {
		cout << i << " " << names2[i] << endl;//Виведення усіх драйверів
	}
	string end1;//Для закінчення
	cout << "Введіть закінчення(.sys, .dll...):" << endl;
	cin >> end1;
	cout << "Відфільтровані драйвери:" << endl;
	for (int idx = 0; idx < names2.size(); idx++) {
		if (names2[idx].substr(names2[idx].find_last_of('.'), 4) == end1)
		{//Перевірка на правильність
			cout << names2[idx] << endl;
		}
	}
	Sleep(2000);
	DWORD aProcesses[1024];
	DWORD cProcesses;
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &dword))
		return 1;
	cProcesses = dword / sizeof(DWORD);
	for (unsigned int i = 0; i < cProcesses; i++)
	{
		PrintModules(aProcesses[i]);//Виведення усіх процесів
	}
	string end2;
	cout << endl << "Введіть закінчення(.exe...):" << endl;
	cin >> end2;
	cout << "Відфільтровані процеси:" << endl;
	for (auto it = mapProc.begin(); it != mapProc.end(); ++it) {
		cout << it->first << endl;
		for (int i = 0; i < it->second.size(); i++) {
			if (it->second[i].substr(it->second[i].find_last_of('.'), 4) ==
				end2) {
				cout << it->second[i] << endl;
			}
		}
	}
	while (1)
	{
		cout << "Для видалення процесу натисніть 1, для завершення роботи 0: ";
		int k; cin >> k;
		if (k == 1)
		{
			cout << "Для видалення процесу введіть ID процесу: ";
			int idproc;
			cin >> idproc;
			killProc(idproc);//Завершення процесу
			cout << "Процес видалено!" << endl;
			break;
		}
		else if (k == 0) break;
		else cout << "Ви ввели невірне число, спробуйте знову!" << endl;
	}
	return 0;
}
