typedef struct{
    char titulo[50];
    int anio;
    char nacionalidad[50];
    int idDirector;
    int idPelicula;
    int isEmpty;
}ePelicula;

typedef struct{
    char nombre[50];
    char fechaNacimiento[15];
    char paisOrigen[50];
    int idDirector;
    int isEmpty;
}eDirector;

int initArrayPelicula(ePelicula* pPelicula, int length);
int initArrayDirectores(eDirector* pDirector, int length);
char mostrarMenu( char textomenu[], char min, char max );
int obtenerEspacioLibrePelicula(ePelicula* pPelicula,int length);
int obtenerEspacioLibreDirector(eDirector* pDirector,int length);
int buscarPorId(ePelicula* pPelicula, int length, int idPelicula);
void pedirDatosPelicula(ePelicula* pPelicula, int length,eDirector* pDirector, int lengthDirector, char* titulo,int* anio, char* nacionalidad, int* idDirector, int* idPelicula, int pedirIdPelicula);
ePelicula cargarPelicula(char auxTitulo[],int auxAnio, char auxNacionalidad[], int auxIdDirector, int auxIdPelicula);
void agregarPelicula(ePelicula* pPelicula,int length, eDirector* pDirector, int lengthDirector);
int isEmptyPelicula(ePelicula* pPelicula, int length);
int isEmptyDirector(eDirector* pDirector, int length);;
void modificar(ePelicula* pPelicula,int length, eDirector* pDirector, int lengthDirector);
void borrar(ePelicula* pPelicula, int length);
int buscarPorIdDirector(eDirector* pDirector, int length, int idDirector);
int buscarPorNombre(eDirector* pDirector, int length, char auxNombre[]);
void pedirDatosDirector(eDirector* pDirector, int length, char* nombre,char* fechaNacimiento ,char* paisOrigen, int* idDirector);
void nuevoDirector(eDirector* pDirector,int length);
void eliminarDirector(eDirector* pDirector, int length);



