#include "Cliente.h"
#include <iostream>
using namespace  std;

int main()
{

	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << "Ingrese Nit:";
	getline(cin, nit);
	cout << "Ingrese Nombres:";
	getline(cin, nombres);
	cout << "Ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;

	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

	c.crear();
	c.leer();
	c.modificar();
	c.eliminar();

	system("pause");
	return 0;

}
/*#include <mysql.h>
 #include <iostream>
#include <string>
using namespace std;
int q_estado;

void mostrar();
void menu();
void insertar();
void menu2();
void menu_principal();
void eliminar_marca();
void modificar_marca();
void insertar_producto();
void mostrar_producto();
void eliminar_producto();
void modificar_producto();

int main() {
	menu_principal();
}

void menu_principal() {
	int p;
	do {
		system("cls");
		cout << ("1. Tabla Marcas")<<endl;
		cout << ("2. Tabla Productos") <<endl ;
		cout << ("3. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> p;
		switch(p){
		case 1:system("cls"); menu();
			break;
		case 2: system("cls");menu2();
			break;
		}
	} while (p!=3);
}
void menu() {
	int a;
	do{
	system("cls");
	cout << ("1. Insertar Datos" ) << endl;
	cout << ("2. Mostrar Datos ")<<endl;
	cout << ("3. Eliminar datosa") << endl;
	cout << ("4. Modificar Datos") << endl;
	cout << ("5. Salir")<<endl;
	cout << ("Ingrese opcion: ");
	cin >> a;
switch(a){
case 1:system("cls");
	insertar();
	break;
case 2:system("cls");
	mostrar();
	break;

case 3:system("cls");
	eliminar_marca();
	break;

case 4: system("cls");
	modificar_marca();
	break;
}
} while (a != 5);
}

void menu2() {
	int a;
	do {
		system("cls");
		cout << ("1. Insertar Datos") << endl;
		cout << ("2. Mostrar Datos ") << endl;
		cout << ("3. Eliminar datosa") << endl;
		cout << ("4. Modificar Datos") << endl;
		cout << ("5. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> a;
		switch (a) {
		case 1:system("cls");
			insertar_producto();
			break;
		case 2:system("cls");
			mostrar_producto();
			break;
			
		case 3:system("cls");
			eliminar_producto();
			break;
			
		case 4: system("cls");
			modificar_producto();
			break;
		}
	} while (a != 5);
}

void insertar()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {
		string marca;
		cout << "Ingrese Marca:";
		cin >> marca;


		string insertar = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insertar.c_str();

		// executar el query
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {

			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar xxx" << endl;
		}
	}
	else {
		cout << " xxx Error en la Conexion xxxx" << endl;
	}
	system("pause");
}

void mostrar() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion exitosa\n";
		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " , " << fila[1] << endl;
			}
		}
		else {
			cout << "Error al consultar\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void eliminar_marca()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {
		string ID;
		cout << "Ingrese Marca:";
		cin >> ID;


		string eliminar = "delete from marcas where idmarca=(" + ID + ")";
		const char* i = eliminar.c_str();

		// executar el query
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {

			cout << "Eliminacion exitosa" << endl;
		}
		else {
			cout << " xxx Error al Ingresar xxx" << endl;
		}
	}
	else {
		cout << " xxx Error en la Conexion xxxx" << endl;
	}
	system("pause");

}
void modificar_marca() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {

		string idmarca, marca;
		char s;
	 cout << ("__________________________________________________________________________________")<<endl;
	 cout << ("|                   M O D I F I C A R                D A T O S                    |")<<endl;
	 cout << ("|_________________________________________________________________________________|")<<endl;

	cout << "Ingrese el id del registro que desea modificar: ";
		cin >> idmarca;
		string consulta = "select * from marcas where idmarca=" + idmarca + "";
		const char* m = consulta.c_str();
		q_estado = mysql_query(conectar, m);

		if (!q_estado) {

			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {

			 cout << "Id Marca: " << fila[0]<<endl;
		 cout << ("Marca: ") << fila[1] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "\ningrese el nuevo nombre de la marca: ";
					cin >> marca;
					string modificar = "update marcas set marca = '" + marca + "' where idmarca =" + idmarca + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
				else {
					cout << ("Bien hecho crack") << endl;
				}
			}
		}
		else {
			cout << "Error al modificar\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void insertar_producto() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {
		string fecha = "now()";
		string pro,idmarc,descripcion,pcosto,preventa,exis;
		cin.ignore();
		cout << "Ingrese producto:";
		getline(cin,pro);
		 
		cout << ("ingrese Id marca:");
		cin>> idmarc;

		cin.ignore();
		cout << "Ingrese descripcion: ";
		getline(cin, descripcion);

		cout << ("Ingrese precio costo: ");
		cin >> pcosto;

		cout << ("Ingrese precio venta: ");
		cin >> preventa;

		cout << ("Ingrese existencia: ");
		cin >> exis;

		string insertar = "insert into productos(producto,idmarca,descripcion,precio_costo, precio_venta,existencia,fecha_ingreso) values('" + pro + "',"+idmarc+",'"+descripcion+"',"+pcosto+","+preventa+","+exis+","+fecha+")";
		const char* i = insertar.c_str();

		// executar el query
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {

			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar xxx" << endl;
		}
	}
	else {
		cout << " xxx Error en la Conexion xxxx" << endl;
	}
	system("pause");

}
void mostrar_producto() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;

	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);

	if (conectar) {
		cout << "Conexion exitosa\n";
		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			 cout << ("_________________________________________________________________________________")<<endl;
			 cout <<("|                    D A T O S             G U A R D A D A S                      |")<<endl;
			cout << ("|_________________________________________________________________________________|")<<endl;
			 cout << "ID |" << "Producto |" << "ID Marca |" << "Descripcion |" << "Precio costo |" << "Precio venta |       " << "Fecha Ingreso       "<<endl;
			cout << ("----------------------------------------------------------------------------------------------------------------");
			cout << ("\n");
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " |" << fila[1] << "     |" << fila[2] << "   |" << fila[3] << "        |" << fila[4] << "        |" << fila[5] << "       |" << fila[7] << endl;
			}
		}
		else {
			cout << "No hay datos registrados\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	cout << ("\n\n\n\n");
	system("pause");
}
void eliminar_producto() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0); 
	if (conectar) {
		cout << "Conexion exitosa\n";
		string idproducto;
		cout << "Ingrese el id del producto que desea eliminar\n";
		cin >> idproducto;
		string eliminar = "delete from productos where idproductos =" + idproducto + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Eliminacion exitosa\n";
		}
		else {
			cout << "Error al eliminar\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void modificar_producto() {

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "lesly", "leslyquevedo0016", "crud", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion exitosa\n";
		string idproductos, producto, idmarca, descripcion, existencia, precio_costo, precio_venta;
		cout << "Ingrese el id del registro que desea modificar\n";
		cin >> idproductos;
		cout << "Ingrese el nuevo nombre del producto\n";
		cin >> producto;
		cout << "Ingrese el nuevo id de marca\n";
		cin >> idmarca;
		cout << "Ingrese la nueva descripcion\n";
		cin >> descripcion;
		cout << "Ingrese la nueva cantidad de existencias\n";
		cin >> existencia;
		cout << "Ingrese el nuevo precio de costo\n";
		cin >> precio_costo;
		cout << "Ingrese el nuevo precio de venta\n";
		cin >> precio_venta;
		string modificar = "update productos set producto = '" + producto + "',idmarca = '" + idmarca + "',descripcion = '" + descripcion + "',existencia = '" + existencia + "',precio_costo = '" + precio_costo + "',precio_venta = '" + precio_venta + "'  where idmarca =" + idproductos + "";
		const char* m = modificar.c_str();
		q_estado = mysql_query(conectar, m);
		if (!q_estado) {
			cout << "Modificacion exitosa\n";
		}
		else {
			cout << "Error al modificar\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	system("pause");
}*/
