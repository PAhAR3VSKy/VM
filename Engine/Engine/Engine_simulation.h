#pragma once
#include <math.h>
class Engine
{
private:
	int I;				//Момент инерции двигателя
	int* M;				//Кусочно-линейная зависимость крутящего момента
	int* V;				//Скорость вращения коленвала 
	int T;				//Температура перегрева
	int T_ambient;		//Температура окружающей среды
	double H_moment;	//Коэффициент зависимости скорости нагрева от крутящего момента
	double H_speed;		//Коэффициент зависимости скорости нагрева от скорости вращения коленвала
	double C;			//Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей	среды
public:
	Engine();
	~Engine();
	void set_ambient_T(int);
	int Heating_rate();
	int Newton(int, double*, double*, double);
};

Engine::Engine()
{
	I = 10;
	M = new int[6]{ 20, 75, 105, 75, 0 };
	V = new int[6]{ 0, 75, 150, 200, 250, 300 };
	T = 110;
	H_moment = 0.01;
	H_speed = 0.0001;
	C = 0.1;
}

Engine::~Engine()
{
	delete[] M;
	delete[] V;
}

void Engine::set_ambient_T(int ambient_temperature)
{
	this->T_ambient = ambient_temperature;
}

int Engine::Newton(int n, double* V, double* M, double x)
{
	double P;
}