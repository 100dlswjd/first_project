#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::wstring> GetFileList(std::wstring targetPath)
{
	int num = 0;
	std::vector<std::wstring> fileList;
	WIN32_FIND_DATA data = { 0, };

	HANDLE hFind = FindFirstFileW(targetPath.c_str(), &data);
	if (hFind == INVALID_HANDLE_VALUE) return fileList;


	do
	{
		num = num + 1;
		if (num > 6 ) {
			break;
		}
		fileList.push_back(data.cFileName);
	} while (FindNextFileW(hFind, &data));

	FindClose(hFind);
	return fileList;
}


int main()
{
	auto fileList = GetFileList(L"C:\\Users\\¿Œ¡§\\Desktop\\*.*");
	for (auto file : fileList)
	{
		std::wcout << file.c_str() << std::endl;
	}

	return 0;
}