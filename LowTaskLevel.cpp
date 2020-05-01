#include"Stdafx.h"
using namespace std;
/*
 «Рейс»:
 марка автомобиля; номер автомобиля;пункт назначения;
 грузоподъемность (в тоннах); стоимость единицы груза;
 общая стоимость груза. Вывести данные про автомобили,
 грузоподъемность которых больше 2 тонн
*/
struct Reis;
void ShowReisData(Reis* BufferMas, int count_auto);
void FillMasReis(Reis* Mas, int count_auto = 3);
void ShowFileTxt(Reis* BufferMas, int count_auto, string FileName);
void WorkFunc(Reis* BufferMas, int count_auto);
struct Reis
{
    string markauto;
    string pynkt_naznachenia;
    int    num_auto;
    int    gryzopodimnost;
    int    cost_one_item;
    int    unit_cost;
};

void FillMasReis(Reis* Mas, int count_auto)
{
    string mas_pynkt[] = {"Киев", "Одесса", "Харьков"};
    string mas_markauto[] = { "Volvo", "Renault", "Daf" };
    for (size_t num_reis = 0; num_reis < count_auto; num_reis++)
    {
        Mas[num_reis].cost_one_item = 500 + rand() % 5000;
        Mas[num_reis].gryzopodimnost = 1 + rand() % 3;
        Mas[num_reis].markauto = mas_markauto[num_reis];
        Mas[num_reis].num_auto = 1000 + rand() % 5000;
        Mas[num_reis].pynkt_naznachenia = mas_pynkt[num_reis];
        Mas[num_reis].unit_cost = Mas[num_reis].cost_one_item* count_auto;
    }
}

void FillFileTxt(Reis* Mas,int count_auto, string FileName)//zapolnit fail
{
    ofstream f_out;
    f_out.open(FileName, ios::out);
    for (size_t i = 0; i < count_auto; i++)
    {
        f_out << Mas[i].cost_one_item << " ";
        f_out << Mas[i].gryzopodimnost << " ";
        f_out << Mas[i].markauto << " ";
        f_out << Mas[i].num_auto << " ";
        f_out << Mas[i].pynkt_naznachenia << " ";
        f_out << Mas[i].unit_cost << "\n";
    }
    f_out.close();
}

void ShowFileTxt(Reis* BufferMas, int count_auto, string FileName)
{
    ifstream f_in;
    f_in.open(FileName, ios::in);
    for (size_t i = 0; i < count_auto; i++)
    {
        string temp = "\n";
        f_in  >> BufferMas[i].cost_one_item ;
        f_in  >> BufferMas[i].gryzopodimnost ;
        f_in  >> BufferMas[i].markauto ;
        f_in  >> BufferMas[i].num_auto;
        f_in  >> BufferMas[i].pynkt_naznachenia ;
        f_in  >> BufferMas[i].unit_cost ;
    }
    f_in.close();
    ShowReisData(BufferMas, count_auto);
}

void WorkFunc(Reis* Mas, int count_auto)
{
    bool flag = false;
    cout << "\nДанные про автомобили,грузоподъемность которых больше 2 тонн: \n\t";
    for (size_t num_reis= 0; num_reis < count_auto; num_reis++)
    {
        if (Mas[num_reis].gryzopodimnost > 2)
        {
            flag = true;
            cout << Mas[num_reis].cost_one_item << " ";
            cout << Mas[num_reis].gryzopodimnost << " ";
            cout << Mas[num_reis].markauto << " ";
            cout << Mas[num_reis].num_auto << " ";
            cout << Mas[num_reis].pynkt_naznachenia << " ";
            cout << Mas[num_reis].unit_cost << "\n\t";
       }
    }
    (flag!=true) ? cout << "\nДанные о таких автомобилях отсутствуют!!!\n" : cout<<"";
}

void ShowReisData(Reis* Mas, int count_auto)
{
    for (size_t num_reis = 0; num_reis < count_auto; num_reis++)
    {
      cout << "\nИнформация о " << num_reis + 1 << " рейсе: \n\t";
                  cout<<     Mas[num_reis].markauto      <<" ";
                  cout << Mas[num_reis].num_auto << " ";
                  cout << Mas[num_reis].pynkt_naznachenia << " ";
                  cout << Mas[num_reis].gryzopodimnost << " ";
                  cout<< Mas[num_reis].cost_one_item     <<" ";
                  cout<< Mas[num_reis].unit_cost         <<"\n";
    }
}

void low()
{
	system("cls");
	std::cout << "\nLow tasl level: \n";
    Reis* masreis = new Reis[3];
    string filename = "ReisDataBase.txt";
    FillMasReis(masreis, 3);
    FillFileTxt(masreis, 3, filename);
    Reis* buffer = new Reis[3];
    cout << "\nДанные о рейсах:\n"
                  "\tмарка автомобиля;\n\tномер автомобиля;\n\tпункт назначения;\n\t"
                   "грузоподъемность(в тоннах);\n\tстоимость единицы груза;\n\t"
                    "общая стоимость груза.";
    ShowFileTxt(buffer, 3, filename);
    WorkFunc(buffer, 3);

    getchar();
}