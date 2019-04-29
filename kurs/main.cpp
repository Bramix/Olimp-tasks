#include <stdio.h> 
#include <iostream>
#include <vector>
#include <cmath>
#define n 3

using namespace std;

typedef struct {
	int degree; 
	double value;
} table;

typedef struct {
	double maxTime;
	double deltaTime;
	double degree;
	double r;
	double v;
	double alpha;
	vector <table> arr;
} date;
typedef struct {
	double temp;
	double visk;
	double F;
} answer;

void inputAll (date * elem);
double getTemperature(double  T, double apha, double time);
double getVisk (double temperature, table arr);
answer ** getAnswer (date d []);
void output (answer ** answer, date d []) ;
int main (void) {
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	date dates [n]; 
	inputAll (dates);
	answer ** res = getAnswer (dates);
	output (res, dates);
}
void inputAll (date * d) {
	for (int i = 0; i < n; i++) {
		cin >> (d + i) -> maxTime >> (d + i ) -> deltaTime >> (d + i ) -> degree;
		cin >> (d + i ) -> r >> (d + i) -> v >> (d + i) -> alpha;
		table t;
		while (t.degree != 100){
			cin >> t.degree >> t.value ;
			(d + i ) -> arr.push_back(t);
		}
		t.degree = 0;
	}
}
double getTemperature(double T, double alpha, double time){
	double res = T * exp (-alpha * time);
	return res;
}
double getVisk (double temperature, vector <table> arr ){
	int i = 0;
	double res;
	for (int i = 0 ;  i  < arr.size(); i++){
		
		if (temperature <= arr[i].degree) {
			res = arr[i - 1].value + (arr [i].value - arr[i - 1].value) / (arr[i].degree - arr[i - 1].degree) * (temperature - arr[i - 1].degree);
			break;	
		}
	}
	return res;
}
answer ** getAnswer (date d []) {
	int s;
	double temp, visk, F;
	answer ** res = new answer * [n];
	for (int i = 0; i < n ; i++){
		s = d[i].maxTime / d[i].deltaTime + 1;
		res [i] = new answer [s];
		int k = 0 ;
		for (int j  =  0; j <= d[i].maxTime ; j += d[i].deltaTime) {
			temp = getTemperature (d[i].degree, d[i].alpha, j);
			visk = getVisk (temp, d[i].arr);
			F = 6 * M_PI * visk * d[i].v * d[i].r ;
			res [i][k].visk = visk;
			res [i][k].temp = temp;
			res [i][k].F = F;
			k ++ ;
		}
	}
	return res;
}
void output (answer ** res, date d []) {
	for (int i = 0; i < n ; i++){
		printf ("The results of %dst list of dates: \n", i);
		int j = 0;
		for (double  k = 0; k <= d[i].maxTime; k += d[i].deltaTime){
			printf ("For time = %lf seconds,  temperature = %.3lf C ° , viscosity = %lf grams/(sec * sm), F = %lf \n", k , res[i][j].temp, res[i][j].visk, res[i][j].F);
			j ++;
		}
	}
}

