#include <unistd.h>
#define BUF_SIZE 20

int readLine(char *str, int size);    //Читает строку
int ft_atoi(char *str);		      //Преобразует строку с цифрами в число(int)
void ft_putnbr(int num);	      //Выводит целое число в терминал
void ft_putstr(char *str);            //Выводит строку в терминал
void ft_putchar(char ch); 	      //Выводит один символ

int main(){
	//Проверка работоспособности функций
	char str[BUF_SIZE];
	int num = 0;
	//Ввод строки
	ft_putstr("Enter a number: ");
	readLine(str, BUF_SIZE);
	ft_putstr("This is char[] -> ");
	ft_putstr(str);
	ft_putchar('\n');
	//Преобразуем в число
	num = ft_atoi(str);
	ft_putstr("This is int -> ");
	ft_putnbr(num);
	ft_putchar('\n');

	//Калькулятор
	char str1[BUF_SIZE];
	char str2[BUF_SIZE];
	char op;
	int a;
	int b;
	int result;
	char answer;
	int on_process = 1;
	char tmp;

	ft_putstr("\n---------Welcome to integer only calculator on C---------\n");
	while(on_process){
		ft_putstr("Enter first number: ");
		readLine(str1, BUF_SIZE);
		a = ft_atoi(str1);

		ft_putstr("Enter operation (+ - * /): ");
		read(0, &op, 1);
		read(0, &tmp, 1); // съедаем '\n'

		ft_putstr("Enter second number: ");
		readLine(str2, BUF_SIZE);
		b = ft_atoi(str2);

		//Логика калькулятора
		if(op == '+')
			result = a + b;
		else if(op == '-')
			result = a - b;
		else if(op == '*')
			result = a * b;
		else if(op == '/'){
			if(b == 0){
				ft_putstr("Error: division by zero\n");
				return 0;
			}
			result = a / b;
		}
		else{
			ft_putstr("Error: unknown operation\n");
			return 0;
		}
		ft_putstr("Result: ");
		ft_putnbr(result);
		ft_putchar('\n');

		ft_putstr("Do you want to continue? Y/n: ");
		read(0, &answer, 1);
		read(0, &tmp, 1); //съедаем '\n'

		if(answer == 'n' || answer == 'N')
			return 0;
		ft_putchar('\n');
	}
	return 0;
}

int readLine(char *str, int size){
	int i = 0;
	char ch;

	while(i < size - 1){
		if (read(0, &ch, 1) <= 0)
    			break;
		if (ch == '\n')
			break;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	return i;
}
int ft_atoi(char *str){
	int num = 0;
	int i = 0;
	int sign = 1;
    	//Пропуск пробелов
    	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        	i++;

    	//Обработка знака
    	if (str[i] == '-' || str[i] == '+'){
        	if (str[i] == '-')
            		sign = -1;
        	i++;
    	}
	//Сбор числа
	while(str[i] >= '0' && str[i] <= '9'){
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return num * sign;
}
void ft_putnbr(int num){
	char ch;
        if(num == -2147483648){
                write(1, "-2147483648", 11);
		return;
	}
	if(num < 0){
		write(1, "-", 1);
		num = -num;
	}
	if(num >= 10)
		ft_putnbr(num / 10);
	ch = '0' + (num % 10);
	write(1, &ch, 1);
}
void ft_putstr(char *str){
	for (int i = 0; str[i] != '\0'; i++)
    		write(1, &str[i], 1);
}
void ft_putchar(char ch){
	write(1, &ch, 1);
}
