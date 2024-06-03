#include "Constants.h"

const long double Constants::presetConstants[42]
{	3.14159265359,		//00: (π)pi
	1.67262192595e-27,	//01: (mp)proton mass
	1.67492750056e-2,	//02: (mn)neutron mass 
	9.1093837139e-31,	//03: (me)electron mass
	1.883531627e-28,	//04: (mμ)muon mass 
	5.29177210544e-11,	//05: (a0)Bohr radius
	6.62607015e-34,		//06: (h)Planck constant 
	5.050783699e-27,	//07: (μN)nuclear magneton 
	9.2740100657e-24,	//08: (μB)Bohr magneton 
	1.0545718173 - 34,	//09: (ℏ)Planck constant, rationalized 
	7.29735257e-3,		//10: (α)fine-structure constant 
	2.817940327e-15,	//11: (re)classical electron radius 
	2.426310239e-12,	//12: (λC)Compton wavelength 
	2.675222005e+8,		//13: (γp)proton gyromagnetic ratio 
	1.321409856e-15,	//14: (λCp)proton Compton wavelength 
	1.319590907e-15,	//15: (λCn)neutron Compton wavelength 
	1.09737315e+7,		//16: (R∞)Rydberg constant 
	1.660538921e-27,	//17: (u)atomic mass unit 
	1.410606743e-26,	//18: (μp)proton magnetic moment 
	-9.2847643e-24,		//19: (μe)electron magnetic moment 
	-9.6623647e-27,		//20: (μn)neutron magnetic moment 
	-4.49044807e-26,	//21: (μμ)muon magnetic moment 
	9.648533213e+4,		//22: (F)Faraday constant 
	1.602176565e-19,	//23: (e)elementary charge 
	6.02214076e+23,		//24: (NA)Avogadro constant 
	1.3806488e-23,		//25: (k)Boltzmann constant 
	0.022710954,		//26: (Vm)molar volume of ideal gas(100kPa) 
	8.314462618,		//27: (R)molar gas constant 
	2.99792458e8,		//28: (C0)speed of light in vacuum 
	3.741771852e-16,	//29: (C1)first radiation constant
	1.438775e-2,		//30: (C2)second radiation constant 
	5.670374419e-8,		//31: (σ)Stefan-Boltzmann constant 
	8.854187817e-12,	//32: (ε0)electric constant 
	1.256637061e-6,		//33: (μ0)magnetic constant 
	2.067833848e-15,	//34: (Φ0)magnetic flux quantum 
	9.80665,			//35: (g)standard acceleration of gravity 
	7.748091729e-5,		//36: (G0)conductance quantum 
	376.730313412,		//37: (Z0)characteristic impedance of vacuum
	273.15,				//38: (t)Celsius temperature 
	6.67384e-11,		//39: (G)Newtonian constant of gravitation 
	101325,				//40: (atm)standard atmosphere
	2.718281828459		//41: (e)Euler's number
};

std::string Constants::outputConst(int code)
{
	//for the precision of small number
	std::ostringstream constant;
	constant << std::setprecision(100) << presetConstants[code];

	return constant.str();
}