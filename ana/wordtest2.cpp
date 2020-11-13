#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void print(){
	_wsetlocale( LC_ALL, L"korean" );
	wprintf(L"가나다라마바사★\n");
}

int main(int argc, char const *argv[])
{
	// _wsetlocale( LC_ALL, L"korean" );
	// wprintf(L"가나다라마바사★\n");
	print();
	return 0;
}