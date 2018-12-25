#include "Fileman.h"



Fileman::Fileman()
{
	s = "object";
	Fileman::imp_obj();
}

Fileman::Fileman(string a):s(a) {}

void Fileman::imp_obj(){
	//Fileman::imp_mtl();
	ifstream file;
	int i = 0, j = 0, k = 0;
	file.open(s+".obj");
	if (!file) {
		cout << "cannot open file" << endl;
		exit(1);
	}
	float max = 5;
	for (string line; getline(file, line); )
	{
		istringstream in(line);
		string type;
		in >> type;
		if (type=="blender"){}
		else if (type == "v")  
		{
			float x, y, z;
			in >> x >> y >> z;
			vertices[i++] = -x;
			if (fabs(x) > max) max = fabs(x);
			vertices[i++] = y;
			if (fabs(y) > fabs(max)) max = fabs(y);
			vertices[i++] = z;
			if (fabs(z) > fabs(max)) max = fabs(z);

			continue;
		}
		else if (type == "vn") {
			float x, y, z;
			in >> x >> y >> z;
			normals[j++] = x;
			normals[j++] = y;
			normals[j++] = z;
			continue;
		}
		else if (type == "f") {
			int x, a;
			char l;
			for (int i = 0; i < 3; i++) {
				in >> x >> l >> l >> a;
				indices[k++] = x - 1;
			}
			continue;
		}

	}
	nov = i;
	non = j;
	nof = k;
	for (int m = 0; m < nov; m) {
		vertices[m++] /= max;
		vertices[m++] /= max;
		vertices[m++] /= max;
	}
	file.close();
}

void Fileman::imp_mtl(){

	ifstream file;
	int i = 0;
	file.open(s + ".mtl");
	if (!file) {
		cout << "cannot open file" << endl;
		exit(1);
	}

	for (string line; getline(file, line); )
	{
		istringstream in(line);
		string type;
		in >> type;
		if (type == "newmtl") {
			string name;
			in >> name;
			mat[i].name = name;
		}
		else if (type == "Ns") {
			int a;
			in >> a;
			mat[i].Ns = a;
		}
		else if (type == "Ka") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ka[0] = x;
			mat[i].Ka[1] = y;
			mat[i].Ka[2] = z;
		}
		else if (type == "Kd") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Kd[0] = x;
			mat[i].Kd[1] = y;
			mat[i].Kd[2] = z;
		}
		else if (type == "Ks") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ks[0] = x;
			mat[i].Ks[1] = y;
			mat[i].Ks[2] = z;
		}
		else if (type == "Ke") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ke[0] = x;
			mat[i].Ke[1] = y;
			mat[i].Ke[2] = z;
		}
		else if (type == "d") {
			int a;
			in >> a;
			mat[i].d = a;
		}
		else if (type == "illum") {
			int a;
			in >> a;
			mat[i].illum = a;
			i++;
		}

	}
	/*
	for (int j = 0; j < i; j++) {
		cout << mat[j].name << endl;
		cout << mat[j].Ns << endl;
		for (int k = 0; k < 3; k++) {
			cout << mat[j].Ka[k] << "\t";
		}
		cout << endl;
		for (int k = 0; k < 3; k++) {
			cout << mat[j].Ks[k] << "\t";
		}
		cout << endl;
		for (int k = 0; k < 3; k++) {
			cout << mat[j].Kd[k] << "\t";
		}
		cout << endl;
		for (int k = 0; k < 3; k++) {
			cout << mat[j].Ke[k] << "\t";
		}
		cout << endl;
		cout << mat[j].d << endl;
		cout << mat[j].illum << endl;
		
	}
	*/
	file.close();
}


Fileman::~Fileman()
{
}
