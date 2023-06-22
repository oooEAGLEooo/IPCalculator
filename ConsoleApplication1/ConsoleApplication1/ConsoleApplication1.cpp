#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int octet1, octet2, octet3, octet4, mask, mask1octet, mask2octet, mask3octet, mask4octet, hosts;
	unsigned int z = 4294967296;
	system("cls");
	cout << "Введите первый октет IP-адреса: ";
	cin >> octet1;
	cout << "Введите второй октет IP-адреса: ";
	cin >> octet2;
	cout << "Введите третий октет IP-адреса: ";
	cin >> octet3;
	cout << "Введите четвёртый октет IP-адреса: ";
	cin >> octet4;
	cout << "Введите маску в префиксном виде: ";
	cin >> mask;
	if (mask > 32 || mask < 0 || octet1 > 255 || octet1 < 0 || octet2 > 255 || octet2 < 0 || octet3 > 255 || octet3 < 0 || octet4 > 255 || octet4 < 0) {
		system("cls");
		cout << "Неверно введены данные! Нажмите любую клавишу, чтобы заново ввести данные\n";
		system("pause");
		main();
	}
	z = z - (int)pow(2, 32 - mask);
	mask4octet = z % 256;
	z = z / 256;
	mask3octet = z % 256;
	z = z / 256;
	mask2octet = z % 256;
	z = z / 256;
	mask1octet = z % 256;
	hosts = pow(2, 32 - mask) - 2;
	int network1octet, network2octet, network3octet, network4octet;
	network1octet = octet1 & mask1octet;
	network2octet = octet2 & mask2octet;
	network3octet = octet3 & mask3octet;
	network4octet = octet4 & mask4octet;
	int broadcast1octet, broadcast2octet, broadcast3octet, broadcast4octet;
	broadcast1octet = network1octet | (255 - mask1octet);
	broadcast2octet = network2octet | (255 - mask2octet);
	broadcast3octet = network3octet | (255 - mask3octet);
	broadcast4octet = network4octet | (255 - mask4octet);
	system("cls");
	cout << "Вы ввели: " << octet1 << "." << octet2 << "." << octet3 << "." << octet4 << "/" << mask << "\n";
	cout << "Маска в десятичном виде для данной сети: " << mask1octet << "." << mask2octet << "." << mask3octet << "." << mask4octet << "\n";
	cout << "Максимальное количество хостов в данной сети: " << hosts << "\n";
	cout << "Адрес данной сети: " << network1octet << "." << network2octet << "." << network3octet << "." << network4octet << "\n";
	cout << "Широковещательный адрес для данной сети: " << broadcast1octet << "." << broadcast2octet << "." << broadcast3octet << "." << broadcast4octet << "\n";
	cout << "\nНажмите любую клавишу, чтобы выполнить программу заново!\n";
	system("pause");
	main();
	return 0;
}