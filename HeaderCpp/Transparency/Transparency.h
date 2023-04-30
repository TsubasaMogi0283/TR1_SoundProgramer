#pragma once

//0%
unsigned const int Transparency0 = 0xFFFFFF00;
//1%
unsigned const int Transparency1 = 0xFFFFFF03;
//2%
unsigned const int Transparency2 = 0xFFFFFF05;
//3%
unsigned const int Transparency3 = 0xFFFFFF08;
//4%
unsigned const int Transparency4 = 0xFFFFFF0A;
//5%
unsigned const int Transparency5 = 0xFFFFFF0D;
//10%
unsigned const int Transparency10 = 0xFFFFFF1A;
//15%
unsigned const int Transparency15 = 0xFFFFFF26;
//20%		   
unsigned const int Transparency20 = 0xFFFFFF33;
//25%		   
unsigned const int Transparency25 = 0xFFFFFF40;
//30%		    
unsigned const int Transparency30 = 0xFFFFFF4D;
//35%		    
unsigned const int Transparency35 = 0xFFFFFF59;
//40%		    
unsigned const int Transparency40 = 0xFFFFFF66;
//45%		    
unsigned const int Transparency45 = 0xFFFFFF73;
//50%		    
unsigned const int Transparency50 = 0xFFFFFF80;
//55%		    
unsigned const int Transparency55 = 0xFFFFFF8C;
//60%		    
unsigned const int Transparency60 = 0xFFFFFF99;
//65%		    
unsigned const int Transparency65 = 0xFFFFFFA6;
//70%		    
unsigned const int Transparency70 = 0xFFFFFFB3;
//75%		    
unsigned const int Transparency75 = 0xFFFFFFBF;
//80%		    
unsigned const int Transparency80 = 0xFFFFFFCC;
//85%		    
unsigned const int Transparency85 = 0xFFFFFFD9;
//90%		    
unsigned const int Transparency90 = 0xFFFFFFE6;
//95%		    
unsigned const int Transparency95 = 0xFFFFFFF2;
//100%		    
unsigned const int Transparency100 = 0xFFFFFFFF;


void Frash(unsigned int& textureTransparency);

void FrashFast(unsigned int& textureTransparency, int& nextConditionName, int nextSceneName);