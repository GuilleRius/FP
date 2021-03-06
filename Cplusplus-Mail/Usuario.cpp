#include "Usuario.h"

bool usuario::cargar (tUsuario & usuario, ifstream & archivo) {
	bool ok = false;
	//Comprobamos que el nombre a cargar no sea el centinela
	string txt;
	archivo >> txt;
	if(txt != CENTINELA_LISTA) {
		usuario.nombre = txt;
		archivo >> usuario.contraseņa;
		listaRegistros::cargar(usuario.listaRecibidos, archivo); 
		listaRegistros::cargar(usuario.listaEnviados, archivo);
		ok = true;
	}
	return ok;
}

void usuario::guardar(const tUsuario & usuario, ofstream & archivo){
	archivo << usuario.nombre << endl;
	archivo << usuario.contraseņa << endl;

	listaRegistros::guardar(usuario.listaRecibidos,archivo);
	listaRegistros::guardar(usuario.listaEnviados, archivo);
}

void inicializar (tUsuario & usuario, string id, string contraseņa) {
	
	usuario.nombre= id;
	
	usuario.contraseņa=contraseņa;//Validamos contraseņa
	listaRegistros::inicializar(usuario.listaRecibidos);
	listaRegistros::inicializar(usuario.listaEnviados);
}

bool validarContraseņa (const tUsuario & usuario, string contraseņa){
	bool okey;

	if(usuario.contraseņa==contraseņa)
		okey=true;
	else
		okey=false;

	return okey;
}