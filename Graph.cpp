#include <iostream>
#include "ccc_win.h"
#include <cmath>
#include <sstream>

using namespace std;

float L1=-10;
float L2= 10;
double pi = 3.141592654;
double e = 2.718281828 ;

void axis(void)
{
  cwin << Message ( Point ( -10 , -9.5 ), "Ehab AlBadawy");
	cwin << Line ( Point (10,0) , Point(-10,0));//X axis
	cwin << Line ( Point (0,10) , Point(0,-10));//Y axis
	
	for (int i = L1 ; i <= L2 ; i++ )
	{
		if ( i == 0 ) continue;
		
		cwin << Line ( Point (i,.1) , Point(i,-.1));//for X axis
		cwin << Line ( Point (.1,i) , Point(-.1,i));//for Y axis

		cwin << Message ( Point (i,0) , i ); //for X axis
		cwin << Message ( Point (0,i) , i ); //for Y axis

		for ( int n = L1  ; n <= L2 ; n++ )
		{
		cwin << Line ( Point (i,n) , Point(i, n + .08 )); 
		}
	}

}
void table (void)

{
	cwin << Message ( Point ( -10 , -9.5 ), "Ehab AlBadawy");
	cwin << Line ( Point ( -4.5 , 6 )  , Point ( 4.5 , 6 ) ) ;



	cwin << Line ( Point ( -4.5 , 5 )  , Point ( 4.5 , 5 ) ) ;
	cwin << Line ( Point ( -4.5 , 3 )  , Point ( 4.5 , 3 ) ) ;
	cwin << Line ( Point ( -4.5 , 1 )  , Point ( 4.5 , 1 ) ) ;
	cwin << Line ( Point ( -4.5 ,-1 )  , Point ( 4.5 ,-1 ) ) ;
	cwin << Line ( Point ( -4.5 ,-3 )  , Point ( 4.5 ,-3 ) ) ;
	cwin << Line ( Point ( -4.5 ,-5 )  , Point ( 4.5 ,-5 ) ) ;

	cwin << Line ( Point ( -4.5 , 6 )  , Point ( -4.5 , -5 ) ) ;
	cwin << Line ( Point ( -1.5 , 5 )  , Point ( -1.5 , -5 ) ) ;
	cwin << Line ( Point (  1.5 , 5 )  , Point (  1.5 , -3 ) ) ;
	cwin << Line ( Point (  4.5 , 6 )  , Point (  4.5 , -5 ) ) ;
	
	cwin << Message ( Point ( -3.4 , 4.2 ) , "sin");
	cwin << Message ( Point ( -3.6 , 2.2 ) , "sin^-1");
	cwin << Message ( Point ( -3.4 , 0.2 ) , "sinh");

	cwin << Message ( Point ( -.4 , 4.2 ) , "cos");
	cwin << Message ( Point ( -.6 , 2.2 ) , "cos^-1");
	cwin << Message ( Point ( -.4 , 0.2 ) , "cosh");

	cwin << Message ( Point ( 2.9 , 4.2 ) , "tan");
	cwin << Message ( Point ( 2.8 , 2.2 ) , "tan^-1");
	cwin << Message ( Point ( 2.9 , 0.2 ) , "tanh");

	cwin << Message ( Point ( -3.15 , -1.7 ) , "ln");
	cwin << Message ( Point ( -.4 , -1.7) , "log");
	cwin << Message ( Point ( 2.9 , -1.7) , "exp");
	
	
	cwin << Message ( Point ( -3.1 , -3.7 ) , "x");
	cwin << Message ( Point ( 1, -3.7) , "graph");

}
float stringToFloat(std::string str)
{
  std::string::size_type sz;

  float n = std::stof (str,&sz);

  return n;
}
string floatToString(float x)
{
	stringstream ss (stringstream::in | stringstream::out);

  ss << x ;

  string str = ss.str();

  return str;
}


int ccc_win_main()
{	while(1){
		cwin.clear();
	
	table();

	string fx = "F(x) = " ;
	string str_sin = " sin(x)";
	string str_sinh = " sinh(x)";
	string str_asin = " sin^-1(x)";
	string str_cos = " cos(x)";
	string str_cosh = " cosh(x)";
	string str_acos = " cos^-1(x)";
	string str_tan =  " tan(x)";
	string str_tanh = " tanh(x)";
	string str_atan = " tan^-1(x)";
	string str_log = " log(x)";
	string str_ln = " ln(x)";
	string str_exp = " exp(x)";
	string str_x = " x";

	

	Point p1 = cwin.get_mouse("");
	float xp1 = p1.get_x();
	float yp1 = p1.get_y();

		if(xp1 > -4.5 && xp1 < -1.5 && yp1 > -5 && yp1 < -3 )
		{
			//x


		float x1, y1, m, n;
	
		fx += str_x ;
		cwin << Message ( Point ( -4.3 , 5.7) , fx );
		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> ( x^m + x1 )^n + y1" );

		
		m = cwin.get_double("m = ");
		x1 = cwin.get_double("x1 = ");
		n = cwin.get_double("n = ");
		y1 = cwin.get_double("y1 = ");

		string str_m = floatToString(m);
		string str_x1 = floatToString(x1);
		string str_n = floatToString(n);
		string str_y1 = floatToString(y1);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = ( x^" + str_m + " + " + str_x1 + " )^" + str_n + " + " + str_y1);

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = ( x^" + str_m + " + " + str_x1 + " )^" + str_n + " + " + str_y1);
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			
			float yx = pow((pow(x,m)+x1),n) + y1 ;

			cwin << Line ( Point ( x , yx ) , Point( ( x + .09 ) , ( yx + .001 ) ));
	}
		}

		else if(xp1 > -4.5 && xp1 < -1.5 && yp1 > 3 && yp1 < 5)
		{
			//sin

		float k, m, n , L;
		fx += str_sin ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> sin^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = sin^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = sin^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			
			float ysin  = sin  (pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
	}


		}


		else if(xp1 > -4.5 && xp1 < -1.5 && yp1 > 1 && yp1 < 3 )
		{
		//sin-1
	
		
	
		float k, m, n , L;
		fx += str_asin ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> sin-1^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = sin-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = sin-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  = asin  (pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}


		}

	
		else if(xp1 > -4.5 && xp1 < -1.5 && yp1 > -1 && yp1 < 1 )
		{
			//sinh
	
		
		float k, m, n , L;
		fx += str_sinh ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> sinh^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = sinh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = sinh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  = sinh  (pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}

		}


		
		else if(xp1 > -1.5 && xp1 < 1.5 && yp1 > 3 && yp1 < 5 )
		{
			//cos
		
		float k, m, n , L;
		fx += str_cos ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> cos^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = cos^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = cos^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  = cos(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}


		}

		else if(xp1 > -1.5 && xp1 < 1.5 && yp1 > 1 && yp1 < 3 )
		{

			
			//cos-1
	
			float k, m, n , L;
		fx += str_acos ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> cos-1^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = cos-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = cos-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  = acos(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}


		}
		
		else if(xp1 > -1.5 && xp1 < 1.5 && yp1 > -1 && yp1 < 1 )
		{
			//cosh
		
					float k, m, n , L;
		fx += str_cosh ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> cosh^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = cosh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = cosh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  = cosh(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}


		}
		
			else if(xp1 > 1.5 && xp1 < 4.5 && yp1 > 3 && yp1 < 5 )
		{
			//tan
		
					float k, m, n , L;
		fx += str_tan ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> tan^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = tan^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = tan^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  =tan(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}


		}
		
		else if(xp1 > 1.5 && xp1 < 4.5 && yp1 > 1 && yp1 < 3 )
		{
			
			//tan-1
	
		
					float k, m, n , L;
		fx += str_atan ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> tan-1^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = tan-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = tan-1^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  =atan(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}

		}

		else if(xp1 > 1.5 && xp1 < 4.5 && yp1 > -1 && yp1 < 1 )
		{
			//tanh
		
		
					float k, m, n , L;
		fx += str_tanh ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> tanh^n( ( x^m + k )^L )" );

		
		n = cwin.get_double("n = ");
		m = cwin.get_double("m = ");
		k= cwin.get_double("k = ");
		L = cwin.get_double("L = ");

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
		string str_L = floatToString(L);
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = tanh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) , "F(x) = tanh^"+str_n+"( ( x^"+str_m+" + "+str_k+" )^"+str_L+" )");
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ysin  =tanh(pow((pow(x,m)+k),n));

			cwin << Line ( Point ( x , ysin ) , Point( ( x + .09 ) , ( ysin + .001 ) ));
		}

		}
		
			else if(xp1 > -4.5 && xp1 < -1.5 && yp1 > -3 && yp1 < -1 )
		{
			//ln
		
		float k, m, n , L;
		fx += str_ln ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> (ln( x^m - k ))^n" );

		
		m = cwin.get_double("m = ");
		k = cwin.get_double("k = ");
		n= cwin.get_double("n = ");
		

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
	
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = (ln( x^"+str_m+" - "+str_k+" ))^"+str_n );

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) ,"F(x) = (ln( x^"+str_m+" - "+str_k+" ))^"+str_n);
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float yln  =pow(log(pow(x,m)+k),n);

			cwin << Line ( Point ( x , yln ) , Point( ( x + .09 ) , ( yln + .001 ) ));
		}

		}

		else if(xp1 > -1.5 && xp1 < 1.5 && yp1 > -3 && yp1 < 1 )
		{
			//log
	
	float k, m, n , L;
		fx += str_log ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> (log( x^m - k ))^n" );

		
		m = cwin.get_double("m = ");
		k = cwin.get_double("k = ");
		n= cwin.get_double("n = ");
		

		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
	
	

		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = (log( x^"+str_m+" - "+str_k+" ))^"+str_n );

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )
				break;
			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) ,"F(x) = (log( x^"+str_m+" - "+str_k+" ))^"+str_n);
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float yln  =pow(log10(pow(x,m)+k),n);

			cwin << Line ( Point ( x , yln ) , Point( ( x + .09 ) , ( yln + .001 ) ));
		}
		}
	
		else if(xp1 > 1.5 && xp1 < 4.5 && yp1 > -3 && yp1 < -1 )
		{
			//exp
		
	float k, m, n , L;
		fx += str_ln ;
		
		cwin << Message ( Point ( -4.3 , 5.7),  fx );

		cwin << Message ( Point ( -9 ,8.5 ) , "Enter these values --> (exp( x^m - k ))^n" );
				
		m = cwin.get_double("m = ");
		k = cwin.get_double("k = ");
		n= cwin.get_double("n = ");
	
		string str_m = floatToString(m);
		string str_n = floatToString(n);
		string str_k = floatToString(k);
	
		cwin.clear();
		table();
		
		cwin << Message ( Point ( -4.3 , 5.7) , "F(x) = (exp( x^"+str_m+" - "+str_k+" ))^"+str_n );

	cwin << Message ( Point ( -9 ,8.5 ) , "if that is the function you are looking for, Click on graph" );

		while(1){

			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > -1.5 && xp1 < 4.5 && yp1 > -5 && yp1 < -3 )

				break;

			}

		cwin.clear();
		axis();
		cwin << Message ( Point ( -9.75 , 8.75) ,"F(x) = (exp( x^"+str_m+" - "+str_k+" ))^"+str_n);
		for ( float x = L1 ; x < L2 ; x = x + .0009 )
		{
			float ynexp  = pow ( e , pow((pow(x,m)+k),n) );

			cwin << Line ( Point ( x , ynexp ) , Point( ( x + .09 ) , ( ynexp + .001 ) ));
		}

		}
	cwin << Line ( Point (7.5 , -8 ) , Point ( 9.5,-8 ) );
	cwin << Line ( Point (7.5 , -8 ) , Point ( 7.5,-9 ) );
	cwin << Line ( Point (7.5 , -9 ) , Point ( 9.5,-9 ) );
	cwin << Line ( Point (9.5 , -9 ) , Point ( 9.5,-8 ) );
	cwin << Message ( Point ( 7.59 , -8.16 ) , "try again");
	
	while (1)
	{
			Point p1 = cwin.get_mouse("");
			float xp1 = p1.get_x();
			float yp1 = p1.get_y();
		
			if(xp1 > 7.5 && xp1 < 9.5 && yp1 > -9 && yp1 < -8 )

				break;
	}	
		}

return 0;	
}
