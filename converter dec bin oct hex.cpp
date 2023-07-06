#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;

string dec_to_bin(double a)
{
	string bin="", temp="";
	int d, epoch=1;
	double b=a, c=a;
	if (a==0)
	{
		bin="0";
	}
	else
	{
		if (a<0)
		{
			c=a*-1;
		}
		d=floor(c);
		c-=d;
		if(d==0)
		{
			temp+="0";
		}
		while(d!=0)
		{
			temp+=to_string(d%2);
			d=d/2;
		}
		if(b<0)
		{
			bin+="-";
		}
		for(int j=int(temp.length()); j>0; j--)
		{
			bin+=temp[j-1];
		}
		if(c>0)
		{
			bin+=".";
			while(c!=0 && epoch<=8)
			{
				c=c*2;
				bin+=to_string(int(floor(c)));
				c-=floor(c);
				epoch+=1;
			}
		}
	}
	return bin;
}

string dec_to_oct(double a)
{
	string oct="", temp="";
	int d, epoch=1;
	double b=a, c=a;
	if (a==0)
	{
		oct="0";
	}
	else
	{
		if (a<0)
		{
			c=a*-1;
		}
		d=floor(c);
		c-=d;
		while(d!=0)
		{
			temp+=to_string(d%8);
			d=d/8;
		}
		if(b<0)
		{
			oct+="-";
		}
		for(int j=int(temp.length()); j>0; j--)
		{
			oct+=temp[j-1];
		}
		if(c>0)
		{
			oct+=".";
			while(c!=0 && epoch<=8)
			{
				c=c*8;
				oct+=to_string(int(floor(c)));
				c-=floor(c);
				epoch+=1;
			}
		}
	}
	return oct;
}

string dec_to_hex(double a)
{
	string hex="", temp="";
	string conv[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	int d, epoch=1;
	double b=a, c=a;
	if (a==0)
	{
		hex="0";
	}
	else
	{
		if (a<0)
		{
			c=a*-1;
		}
		d=floor(c);
		c-=d;
		while(d!=0)
		{
			temp+=conv[d%16];
			d=d/16;
		}
		if(b<0)
		{
			hex+="-";
		}
		for(int j=int(temp.length()); j>0; j--)
		{
			hex+=temp[j-1];
		}
		if(c>0)
		{
			hex+=".";
			while(c!=0 && epoch<=8)
			{
				c=c*16;
				hex+=conv[int(floor(c))];
				c-=floor(c);
				epoch+=1;
			}
		}
	}
	return hex;
}

double bin_to_dec(double a)
{
	double b=a, c=a, dec=0;
	int d, j=0;
	if(a<0)
	{
		c=a*-1;
	}
	d=floor(c);
	c-=d;
	string temp1=to_string(d);
	string temp2=to_string(c);
	string temp=temp1;
	for(int i=2; i<int(temp2.length()); i++)
	{
		temp+=temp2[i];
	}
	for (int i=int(temp1.length()); i>-1*(int(temp.length())-int(temp1.length())); i--)
	{
		if(temp[j]=='1')
		{
			dec+=pow(2,i-1);
		}
		j+=1;
	}
	if(b<0)
	{
		dec=dec*-1;
	}
	return dec;
}

double oct_to_dec(double a)
{
	double b=a, c=a, dec=0;
	int d, j=0;
	if(a<0)
	{
		c=a*-1;
	}
	d=floor(c);
	c-=d;
	string temp1=to_string(d);
	string temp2=to_string(c);
	string temp=temp1;
	for(int i=2; i<int(temp2.length()); i++)
	{
		temp+=temp2[i];
	}
	for (int i=int(temp1.length()); i>-1*(int(temp.length())-int(temp1.length())); i--)
	{
		dec+=((int(temp[j])-48)*pow(8,i-1));
		j+=1;
	}
	if(b<0)
	{
		dec=dec*-1;
	}
	return dec;
}

double hex_to_dec(string a)
{
	double dec=0;
	string b="", c="";
	int x=int(a.length()), k=0;
	string value="0123456789ABCDEF";
	for(int i=0; i<int(a.length()); i++)
	{
		if(i<=x)
		{
			if(a[i]!='-' && a[i]!='.')
			{
				b+=a[i];
			}
			else if(a[i]=='.')
			{
				x=i;
			}
		}
		else if(i>x)
		{
			c+=a[i];
		}
	}
	string temp=b+c;
	for(int i=int(b.length()); i>-1*(int(c.length())); i--)
	{
		for(int j=0; j<16; j++)
		{
			if(int(toupper(temp[k]))==int(value[j]))
			{
				dec+=j*pow(16,i-1);
				k+=1;
				break;
			}
		}
	}
	if(a[0]=='-')
	{
		dec=dec*-1;
	}
	return dec;
}

bool check_bin(double a)
{
	string temp=to_string(a);
	for(int i=0; i<int(temp.length()); i++)
	{
		if(temp[i]!='1' && temp[i]!='0' && temp[i]!='-' && temp[i]!='.')
		{
			return false;
		}
	}
	return true;
}

bool check_oct(double a)
{
	string temp=to_string(a);
	for(int i=0; i<int(temp.length()); i++)
	{
		if((int(temp[i])<48 || int(temp[i])>55) && temp[i]!='-' && temp[i]!='.')
		{
			return false;
		}
	}
	return true;
}

bool check_hex(string a)
{
	string temp=a;
	int countpoint=0;
	for(int i=0; i<int(temp.length()); i++)
	{
		if(temp[i]=='.')
		{
			countpoint+=1;
			if(countpoint>1)
			{
				return false;
			}
		}
		if((temp[i]=='-' && i>0) || (temp[i]=='.' && (i==0 || i==int(a.length())-1 || (i==1 && temp[i-1]=='-'))))
		{
			return false;
		}
		if(!((int(temp[i])>=48 && int(temp[i])<=57) || (int(toupper(temp[i]))>=65 && int(toupper(temp[i]))<=70)) && temp[i]!='-' && temp[i]!='.')
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int menu;
	double dec, bin, oct;
	string hex;
	char back;
	do
	{
		system("cls");
		cout << "+===============================+\n";
		cout << "|              MENU             |\n";
		cout << "+===============================+\n\n";
		cout << " 1. Decimal to Binary\n";
		cout << " 2. Decimal to Octal\n";
		cout << " 3. Decimal to Hexadecimal\n";
		cout << " 4. Binary to Decimal\n";
		cout << " 5. Binary to Octal\n";
		cout << " 6. Binary to Hexadecimal\n";
		cout << " 7. Octal to Decimal\n";
		cout << " 8. Octal to Binary\n";
		cout << " 9. Octal to Hexadecimal\n";
		cout << "10. Hexadecimal to Decimal\n";
		cout << "11. Hexadecimal to Binary\n";
		cout << "12. Hexadecimal to Octal\n\n";
		cout << "Select : ";
		cin >> menu;
		cout << "\n";
		if(menu==1)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|       DECIMAL TO BINARY       |\n";
			cout << "+===============================+\n\n";
			cout << "Decimal\t: ";
			cin >> dec;
			cout << "Binary\t: " << dec_to_bin(dec);
		}
		else if(menu==2)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|        DECIMAL TO OCTAL       |\n";
			cout << "+===============================+\n\n";
			cout << "Decimal\t: ";
			cin >> dec;
			cout << "Octal\t: " << dec_to_oct(dec);
		}
		else if(menu==3)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|     DECIMAL TO HEXADECIMAL    |\n";
			cout << "+===============================+\n\n";
			cout << "Decimal\t\t: ";
			cin >> dec;
			cout << "Hexadecimal\t: " << dec_to_hex(dec);
		}
		else if(menu==4)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|       BINARY TO DECIMAL       |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Binary\t: ";
				cin >> bin;
				if(!check_bin(bin))
				{
					cout << "\nEvery bit must be in range [0,1]!\n\n";
				}
			}
			while(!check_bin(bin));
			cout << "Decimal\t: " << bin_to_dec(bin);
		}
		else if(menu==5)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|        BINARY TO OCTAL        |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Binary\t: ";
				cin >> bin;
				if(!check_bin(bin))
				{
					cout << "\nEvery bit must be in range [0,1]!\n\n";
				}
			}
			while(!check_bin(bin));
			cout << "Octal\t: " << dec_to_oct(bin_to_dec(bin));
		}
		else if(menu==6)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|     BINARY TO HEXADECIMAL     |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Binary\t\t: ";
				cin >> bin;
				if(!check_bin(bin))
				{
					cout << "\nEvery bit must be in range [0,1]!\n\n";
				}
			}
			while(!check_bin(bin));
			cout << "Hexadecimal\t: " << dec_to_hex(bin_to_dec(bin));
		}
		else if(menu==7)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|        OCTAL TO DECIMAL       |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Octal\t: ";
				cin >> oct;
				if(!check_oct(oct))
				{
					cout << "\nEvery bit must be in range [0,7]!\n\n";
				}
			}
			while(!check_oct(oct));
			cout << "Decimal\t: " << oct_to_dec(oct);
		}
		else if(menu==8)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|        OCTAL TO BINARY        |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Octal\t: ";
				cin >> oct;
				if(!check_oct(oct))
				{
					cout << "\nEvery bit must be in range [0,7]!\n\n";
				}
			}
			while(!check_oct(oct));
			cout << "Binary\t: " << dec_to_bin(oct_to_dec(oct));
		}
		else if(menu==9)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|      OCTAL TO HEXADECIMAL     |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Octal\t\t: ";
				cin >> oct;
				if(!check_oct(oct))
				{
					cout << "\nEvery bit must be in range [0,7]!\n\n";
				}
			}
			while(!check_oct(oct));
			cout << "Hexadecimal\t: " << dec_to_hex(oct_to_dec(oct));
		}
		else if(menu==10)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|     HEXADECIMAL TO DECIMAL    |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Hexadecimal\t: ";
				cin >> hex;
				if(!check_hex(hex))
				{
					cout << "\nInput error!\n\n";
				}
			}
			while(!check_hex(hex));
			cout << "Decimal\t\t: " << hex_to_dec(hex);
		}
		else if(menu==11)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|     HEXADECIMAL TO BINARY     |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Hexadecimal\t: ";
				cin >> hex;
				if(!check_hex(hex))
				{
					cout << "\nInput error!\n\n";
				}
			}
			while(!check_hex(hex));
			cout << "Binary\t\t: " << dec_to_bin(hex_to_dec(hex));
		}
		else if(menu==12)
		{
			system("cls");
			cout << "+===============================+\n";
			cout << "|      HEXADECIMAL TO OCTAL     |\n";
			cout << "+===============================+\n\n";
			do
			{
				cout << "Hexadecimal\t: ";
				cin >> hex;
				if(!check_hex(hex))
				{
					cout << "\nInput error!\n\n";
				}
			}
			while(!check_hex(hex));
			cout << "Octal\t\t: " << dec_to_oct(hex_to_dec(hex));
		}
		else 
		{
			cout << "Menu does not exist!";
		}
		cout << "\n\nBack to menu? (Y/N) : ";
		cin >> back;
		cout << "\n";
	}
	while(toupper(back)=='Y');
}
