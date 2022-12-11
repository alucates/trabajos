#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

class LightSaber{
public:
	string username;
    string colorLight;

    LightSaber(string user ,string color){
    	LightSaber::username = user;
    	LightSaber::colorLight = color;
    }
    LightSaber(){};

    string mostrarLight(){
    	return "Padwan: " + username + " Color LightSaber: " + colorLight;
    }
};




template<typename LightSaber> class VectorPEL{
private:
	LightSaber * v_, * space_, * last_;

public:
    VectorPEL(): v_{new LightSaber[0]}, space_{v_}, last_{v_} {}
    VectorPEL(VectorPEL<LightSaber> const& v): v_{new LightSaber[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()} {
        try{
            for(auto i = size_t{0}; i< v.size(); ++i){
                v_[i] = v[i];
            }
        }
        catch (...){
            delete[] v_;
            throw;
        }
    }
    ~VectorPEL() {delete[] v_;}

    auto capacity() const -> size_t {return last_ - v_;}
    auto size() const -> size_t {return space_ - v_;}
    auto empty() const -> bool {return v_ == last_;}
    int num(int x){
        	return x;
        }
     auto now(int x) -> LightSaber* {return v_ + x;}

    auto begin() -> LightSaber* {return v_;}
    auto begin() const -> LightSaber const* {return v_;}
    auto end() -> LightSaber* {return space_;}
    auto end() const -> LightSaber const* {return space_;}

    auto push_back(LightSaber const& valor){
        if(space_ ==  last_){
            size_t cp =  capacity(), new_cp = (cp == 0)? 2:2*cp;
            LightSaber* new_block = new LightSaber[new_cp];
            try {
                for (auto i = size_t{}; i < cp; ++i) {
                    new_block[i] = v_[i];
                }
                new_block[cp] = valor;
            }
            catch (...){
                delete[] new_block;
                throw;
            }
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else{
            *space_ = valor;
            ++space_;
        }
    }


};

void cinearlo(){
    cin.ignore();
    cin.clear();
	cin.sync();
}



string detectorLightS(){
int n1,n2,n3,n4,n5,n6;
int p1 = 0,p2 = 0,p3 = 0,p4 = 0,p5 = 0,p6 = 0;
cout<<"Describe tu estilo de Lucha"<< endl;
            cout << "1- Cruel\n" ; //red
		    cout << "2- Agresivo\n"  ; //purple
		    cout << "3- Acrobatico\n"  ; // green
		    cout << "4- Balanceado\n"  ; // blue
		    cout << "5- Pacifico\n"  ; // silver
		    cout << "6- Portector\n"; // Yellow
		    cin >> n1;
		    cinearlo();


cout << "Porque te convertirias en Jedi?"<<endl;
        cout << "1- Me encanta pelear\n" ; // red
	    cout << "2- Para enseñar al mundo de mis ideales\n"; // purple
	    cout << "3- Para comprender mi poder y mi destino\n"  ; // green
	    cout << "4- Para traer justicia al universo\n"  ; // azul
	    cout << "5- Para traer paz al universo\n"  ; // silver
	    cout << "6- Para proteger a mis seres queridos\n"; // yellow
	    cin >> n2;
		   cinearlo();

cout << "Cual seria tu  mayor debilidad a superar?" << endl;
        cout << "1- Muy confiado en mi mismo\n" ; // red
	    cout << "2- Demasiado Orgulloso\n"; // purple
	    cout << "3- Me preocuparia demasiado con las consecuencias del futuro\n"  ; // green
	    cout << "4- Sigo mi deber al 100%, no encuentro debilidades en mi\n"  ; // azul
	    cout << "5- Me preocupo demasiado con los demas\n"  ; // silver
	    cout << "6- Muy emocional\n"; // yellow
	    cin>>n3;
		   cinearlo();

cout << "Como te describirian los demas"<<endl;
        cout << "1- Idealista\n" ; // red
	    cout << "2- Lider\n"; // purple
	    cout << "3- Constructivo\n"  ; // green
	    cout << "4- Responsable\n"  ; // azul
	    cout << "5- Empatico\n"  ; // silver
	    cout << "6- Protectivo\n"; // yellow
	    cin>>n4;
		   cinearlo();

cout << "Que buscan en un amigo?"<<endl;
    cout << "1- Poder\n" ; // red
    cout << "2- Sabiduría\n"; // purple
    cout << "3- Racionalidad\n"  ; // green
    cout << "4- Compromiso\n"  ; // azul
    cout << "5- Lealtad\n"  ; // silver
    cout << "6- Kindness\n"; // yellow
    cin>>n5;
	cinearlo();

cout << "Cual de estas eligirias?"<<endl;
  cout << "1- Ser el lider e un planeta entero\n" ; // red
  cout << "2- Busque artefactos Jedi o Sith importantes\n"; // purple
  cout << "3- Enseñar a un Padwan\n"  ; // green
  cout << "4- Ir de incógnito para informar sobre el Imperio para la Rebelión\n"  ; // azul
  cout << "5- Busque artefactos Jedi o Sith importantes\n"  ; // silver
  cout << "6- Proteger aquellos que amas con tu vida\n"; // yellow 6
  cin>>n6;
  cinearlo();
  int listN[6] = {n1,n2,n3,n4,n5,n6};
  for (int i = 0; i < 6; ++i) {
      if(listN[i] == 1){
    	  p1++;
      }else if(listN[i] == 2){
         p2++;
      }else if(listN[i] == 3){
         p3++;
      }else if(listN[i] == 4){
         p4++;
      }else if(listN[i] == 5){
        p5++;
      }else if(listN[i] == 6){
         p6++;
      }
   }
  cout <<p6<<endl;
   if(p1>p2 && p1>p3 && p1>p4 && p1>p5 && p1>p6){
	  return "rojo";
  }else if(p2>p1 && p2>p3 && p2>p4 && p2>p5 && p2>p6){
	  return "morado";
  }else if(p3>p1 && p3>p2 && p3>p4 && p3>p5 && p3>p6){
	  return "verde";
  }else if(p4>p1 && p4>p2 && p4>p3 && p4>p5 && p4>p6){
	  return "azul";
  }else if(p5>p1 && p5>p2 && p5>p3 && p5>p4 && p5>p6){
	  return "plata";
  }else if(p6>p1 && p6>p2 && p6>p3 && p6>p4 && p6>p5){
	  return "amarillo";
  }else{
	  return "naranja";
  }
}

string descLightSaber(string &color){
	cout << "-- BREVE DESCRIPCIÓN --" << endl;
 if(color == "rojo"){
       return "Los sables de luz rojos a menudo se asocian con los Sith o los Jedi oscuros, y simbolizan la ira y la determinación.\n El Código Sith predica que la ira, el odio y la agresión son la forma de lograr\n los objetivos de uno, lo que probablemente explica por qué el rojo se convirtió\nen el color elegido por muchos Lores Sith";
 }else if(color == "morado"){
     return "Los sables de luz morados son menos comunes,\npero a menudo se ven como un signo de nobleza y sabiduria.\n En el universo de Star Wars, Mace Windu es el unico Jedi que empuno un sable de luz purpura y es considerado uno de los miembros mas sabios de la Orden.";
 }else if(color == "verde"){
	 return " Tal como el azul es uno de los más comunes\n Representa el crecimiento, la armonía y la naturaleza. ";
 }else if(color == "azul"){
     return "Tal como el verde es uno de los más comunes\n Significa justicia, verdad y serenidad.";
 }else if(color == "plata"){
     return"Los sables de luz plateados se ven como un signo de pureza y paz.\n En Star Wars: Episodio III - La venganza de los Sith, Obi-Wan Kenobi usa un sable de luz plateado\n cuando se enfrenta a su antiguo aprendiz, Darth Vader. Esto representa \nel final del tiempo de Kenobi como Jedi y el comienzo de su nuevo papel como protector de la paz.";
 }else if(color == "amarillo"){
      return "Los sables de luz amarillos también son relativamente raros, \npero representan el poder del sol y la esperanza para el futuro. \nEn Star Wars: The Clone Wars, Ahsoka Tano empuña un sable de luz amarillo\n para simbolizar su nuevo papel como líder y protectora.";
 }else if(color == "naranja"){
      return "Los sables de luz naranja están asociados con la ambición, la creatividad y el ingenio.\n En el universo de Star Wars, la Maestra Jedi Luminara Unduli es conocida por su sable de luz naranja,\n que usa con gran efecto en la batalla.";
 }else{
	 return "orden 66";
 }
}

int main() {
 VectorPEL<LightSaber> starWars;
 int caso;
 bool continuar = true;
 while(continuar){
	 cout << "----Introduce la opción que deseas realizar----\n"
	 				"1- Insertar datos del Padwan\n"
	 				"2- Ver datos de todos los Padwans\n"
	 				"3- Filtrar datos Padwans\n"
	 				"4- Salir del Programa\n";
	 cin.clear();
	 cin.sync();
       cin >> caso;
       int num = starWars.size();
	 switch(caso){
	 case 1:
	 {
		 string user;
		 cout << "Digite su nombre padwan: " << user << endl;
		 cin >> user;
		 cout << "QUIZ - ¿COLOR LIGHTSABER?" << endl;
		 string color = detectorLightS();
		 cout << "El color del light saber es: " << color << endl;
		 starWars.push_back(LightSaber{user,color});

	 }
	 break;
	 case 2:
	 {

     for (int i = 0;  i < num; ++i) {
    	 LightSaber nombre = *starWars.now(i);
    	 cout << "Padwan " << (i+1) << "º : " << nombre.username<<endl;
    	 cout << "Color Light Saber : " << nombre.colorLight <<endl;
    	 cout <<  descLightSaber(nombre.colorLight) << "\n " << endl;
	   }
	 }

	 break;
	 case 3:
	 {
	   string name;
	   cout << "Introduce el nombre del padwan"<<endl;
	   cin>>name;

	   for (int i = 0; i < num; ++i){
	       LightSaber nombre = *starWars.now(i);
         if(nombre.username == name){
        	 cout << "Padwan " << (i+1) << "º : " << nombre.username<<endl;
        	    	 cout << "Color Light Saber : " << nombre.colorLight <<endl;
        	    	 cout <<  descLightSaber(nombre.colorLight) << "\n " << endl;
         }else{
        	 cout << "El nombre de padwana no existen\n" << endl;
         }

	   }

	 }
     break;
	 case 4:
	 {
          continuar = false;
	 }
	 break;
	 default:
	 {
	 }
	 break;
	 }
 };
}
