#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "templateandclass.h"

using namespace std;



int main(){
	variable first;
	variable second;
	variable third;
	variable fourth;
	char results;
	char* arbit1 = NULL;
	char* arbit2 = NULL;
	char* arbitchar1 = NULL;
	char* arbitchar2 = NULL;
	char * result;
	int funcadddecide = 0;
	int funcsubdecide = 0;
	int funcmuldecide = 0;
	int funcdivdecide = 0;
	string let[80];
	int pine = 0;
	char* check;
	int checks = 0;
	unsigned int j = 0;
	string linebuffer;
	string lines[5];
	int i = 0;
	ifstream interpret("sample.txt"); //create a stream to file
	if (interpret.is_open()){ //opening the file
		//cout << "hello";
	}
	else{
		cout << "error opening file!"; //error if not opening the file
	}
	while (interpret && getline(interpret, linebuffer)){
		cout << linebuffer << "\n";
		char * writable = new char[linebuffer.size() + 1];
		std::copy(linebuffer.begin(), linebuffer.end(), writable);
		writable[linebuffer.size()] = '\0';
		char *p = strtok(writable, " ");
		if (strcmp(p, "let") == 0){
			checks++;
			p = strtok(NULL, " ");
			//cout<<p<<"\n";
			if (checks == 1){
				first.name = p;
			}
			if (checks == 2){
				second.name = p;
			}
			if (checks == 3){
				third.name = p;
			}
			if (checks == 4){
				fourth.name = p;
			}

			//char cha = *p;
			if (isdigit(*p)){
				cout << "syntax error...\n";
				break;
			}
			else{
				p = strtok(NULL, " ");
				//cout<<p<<"\n";
				if (strcmp(p, "=") != 0){
					cout << "syntax error...\n";
					break;
				}
				p = strtok(NULL, " ");

				if (checks == 1){
					first.value = p;
					cout << first.value << "\n";
				}
				if (checks == 2){
					second.value = p;
					cout << second.value << "\n";
				}
				if (checks == 3){
					third.value = p;
					cout << third.value << "\n";
				}
				if (checks == 3){
					fourth.value = p;
					cout << fourth.value << "\n";
				}
				p = strtok(NULL, " ");
				//cout<<p<<"\n";
				if (strcmp(p, ";") != 0){
					cout << "syntax error...\n";
					break;
				}
			}

			//while (p) {
			//printf ("Token: %s\n", p);
			//p = strtok(NULL, " ");

			//}
		}
		else if (strcmp(p, "print") == 0){
			p = strtok(NULL, " ");
			if (strcmp(p, first.name) == 0){
				cout << first.value << "\n";
			}
			if (strcmp(p, second.name) == 0){
				cout << second.value << "\n";
			}
			//if(strcmp(p, result) == 0){
			//cout<<result<<"\n";
			//}


		}
		else{
			result = p;  //store last result in this
			cout << p << "\n";
			p = strtok(NULL, " ");
			if (strcmp(p, "=") != 0){
				cout << "syntax error (No = sign here)\n";
				break;
			}
			p = strtok(NULL, " ");
			if (isdigit(*p)){

				arbit1 = p;
				cout << "arbit1:" << arbit1 << "\n";

			}
			else{
				arbitchar1 = p;
				cout << "arbitchar1:" << arbitchar1 << "\n";

			}
			p = strtok(NULL, " ");
			if (strcmp(p, "+") == 0){
				funcadddecide = 1;
				//cout << funcadddecide;
			}
			if (strcmp(p, "-") == 0){
				funcsubdecide = 2;
				cout << funcsubdecide;
			}
			if (strcmp(p, "*") == 0){
				funcmuldecide = 3;
				cout << funcmuldecide;
			}
			if (strcmp(p, "/") == 0){
				funcdivdecide = 4;
				cout << funcdivdecide;
			}
			p = strtok(NULL, " ");
			if (isdigit(*p)){

				arbit2 = p;
				cout << "arbit1:" << arbit2 << "\n";

			}
			else{
				arbitchar2 = p;
				cout << "arbitchar1:" << arbitchar2 << "\n";

			}
			p = strtok(NULL, " ");
			if (strcmp(p, ";") != 0 && p == NULL){
				cout << "Syntax Error...\n";
				cout << "No semicolon...\n";
				break;
			}

		}
		//cout<<first;
		//cout<<second;
		//while (p) {
		//printf ("Token: %s\n", p);
		//p = strtok(NULL, " ");
		//}


	}
	if (funcadddecide == 1){
		if (arbitchar1 != NULL && arbitchar2 != NULL){

			if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0 || strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
				cout << "hello";
				char a;
				char b;
				if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0){
					a = *first.value;
					b = *second.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *first.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0){
					a = *first.value;
					b = *first.value;
				}
				if (strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *second.value;
				}
				if (isdigit(a) && isdigit(b)){ // if x = 14 only taking 1 of 14 check this
					int ant = a - '0';
					int bent = b - '0';
					int res = addition(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					results = addition(a, b);
					cout << results;
				}
			}
		}
		if (arbitchar1 == NULL && arbitchar2 == NULL){
			char a = *arbit1;
			char b = *arbit2;
			int ant = a - '0';
			int bent = b - '0';
			int res = addition(ant, bent);
			cout << "Final Result:" << res << "\n";

			results = addition(a, b);
			// cout<<results;

		}
		if (arbitchar1 != NULL && arbit2 != NULL){
			if (strcmp(first.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *first.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = addition(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *first.value;
					char b = *arbit2;
					results = addition(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *second.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					cout << "hello";
					int bent = b - '0';
					int res = addition(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *second.value;
					char b = *arbit2;
					results = addition(a, b);
					cout << results;
				}

			}
		}
		if (arbit1 != NULL && arbitchar2 != NULL){
			if (strcmp(first.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *first.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = addition(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *first.value;
					results = addition(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *second.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = addition(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *second.value;
					results = addition(a, b);
					cout << results;
				}

			}


		}

	}
	if (funcsubdecide == 2){
		if (arbitchar1 != NULL && arbitchar2 != NULL){

			if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0 || strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
				cout << "hello";
				char a;
				char b;
				if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0){
					a = *first.value;
					b = *second.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *first.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0){
					a = *first.value;
					b = *first.value;
				}
				if (strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *second.value;
				}
				if (isdigit(a) && isdigit(b)){ // if x = 14 only taking 1 of 14 check this
					int ant = a - '0';
					int bent = b - '0';
					int res = subtraction(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					results = subtraction(a, b);
					cout << results;
				}
			}
		}
		if (arbitchar1 == NULL && arbitchar2 == NULL){
			char a = *arbit1;
			char b = *arbit2;
			int ant = a - '0';
			int bent = b - '0';
			int res = subtraction(ant, bent);
			cout << "Final Result:" << res << "\n";

			//results = addition(a, b);
			// cout<<results;

		}
		if (arbitchar1 != NULL && arbit2 != NULL){
			if (strcmp(first.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *first.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = subtraction(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *first.value;
					char b = *arbit2;
					results = subtraction(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *second.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					cout << "hello";
					int bent = b - '0';
					int res = subtraction(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *second.value;
					char b = *arbit2;
					results = subtraction(a, b);
					cout << results;
				}

			}
		}
		if (arbit1 != NULL && arbitchar2 != NULL){
			if (strcmp(first.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *first.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = subtraction(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *first.value;
					results = subtraction(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *second.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = subtraction(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *second.value;
					results = subtraction(a, b);
					cout << results;
				}

			}


		}

	}
	if (funcmuldecide == 3){
		if (arbitchar1 != NULL && arbitchar2 != NULL){

			if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0 || strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
				cout << "hello";
				char a;
				char b;
				if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0){
					a = *first.value;
					b = *second.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *first.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0){
					a = *first.value;
					b = *first.value;
				}
				if (strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *second.value;
				}
				if (isdigit(a) && isdigit(b)){ // if x = 14 only taking 1 of 14 check this
					int ant = a - '0';
					int bent = b - '0';
					int res = multiplication(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					results = multiplication(a, b);
					cout << results;
				}
			}
		}
		if (arbitchar1 == NULL && arbitchar2 == NULL){
			char a = *arbit1;
			char b = *arbit2;
			int ant = a - '0';
			int bent = b - '0';
			int res = multiplication(ant, bent);
			cout << "Final Result:" << res << "\n";

			//results = addition(a, b);
			// cout<<results;

		}
		if (arbitchar1 != NULL && arbit2 != NULL){
			if (strcmp(first.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *first.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = multiplication(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *first.value;
					char b = *arbit2;
					results = multiplication(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *second.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					cout << "hello";
					int bent = b - '0';
					int res = multiplication(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *second.value;
					char b = *arbit2;
					results = multiplication(a, b);
					cout << results;
				}

			}
		}
		if (arbit1 != NULL && arbitchar2 != NULL){
			if (strcmp(first.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *first.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = multiplication(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *first.value;
					results = multiplication(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *second.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = multiplication(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *second.value;
					results = multiplication(a, b);
					cout << results;
				}

			}


		}

	}
	if (funcdivdecide == 4){
		if (arbitchar1 != NULL && arbitchar2 != NULL){

			if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0 || strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0 || strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
				cout << "hello";
				char a;
				char b;
				if (strcmp(first.name, arbitchar1) == 0 && strcmp(second.name, arbitchar2) == 0){
					a = *first.value;
					b = *second.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *first.value;
				}
				if (strcmp(first.name, arbitchar2) == 0 && strcmp(first.name, arbitchar1) == 0){
					a = *first.value;
					b = *first.value;
				}
				if (strcmp(second.name, arbitchar2) == 0 && strcmp(second.name, arbitchar1) == 0){
					a = *second.value;
					b = *second.value;
				}
				if (isdigit(a) && isdigit(b)){ // if x = 14 only taking 1 of 14 check this
					int ant = a - '0';
					int bent = b - '0';
					int res = division(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					results = division(a, b);
					cout << results;
				}
			}
		}
		if (arbitchar1 == NULL && arbitchar2 == NULL){
			char a = *arbit1;
			char b = *arbit2;
			int ant = a - '0';
			int bent = b - '0';
			int res = division(ant, bent);
			cout << "Final Result:" << res << "\n";

			//results = addition(a, b);
			// cout<<results;

		}
		if (arbitchar1 != NULL && arbit2 != NULL){
			if (strcmp(first.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *first.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = division(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *first.value;
					char b = *arbit2;
					results = division(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar1) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *second.value;
				char b = *arbit2;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					cout << "hello";
					int bent = b - '0';
					int res = division(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *second.value;
					char b = *arbit2;
					results = division(a, b);
					cout << results;
				}

			}
		}
		if (arbit1 != NULL && arbitchar2 != NULL){
			if (strcmp(first.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *first.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = division(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *first.value;
					results = division(a, b);
					cout << results;
				}
			}
			if (strcmp(second.name, arbitchar2) == 0){// && strcmp(second.name, arbitchar2)==0){
				char a = *arbit1;
				char b = *second.value;
				if (isdigit(a) && isdigit(b)){
					int ant = a - '0';
					int bent = b - '0';
					int res = division(ant, bent);
					cout << "Final Result:" << res << "\n";
				}
				else{
					char a = *arbit1;
					char b = *second.value;
					results = division(a, b);
					cout << results;
				}

			}


		}

	}
	return 0;
}