#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
// Fonction pour calculer le cosinus de l'angle entre deux vecteurs
double cosineSimilarity(const vector<int>& v1, const vector<int>& v2) {
    // Calcul du produit scalaire
    double dotProduct = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        dotProduct += v1[i] * v2[i];
    }

    // Calcul des normes des vecteurs
    double normV1 = 0.0, normV2 = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        normV1 += v1[i] * v1[i];
        normV2 += v2[i] * v2[i];
    }

    // Calcul du cosinus de l'angle
    double similarity = dotProduct / (sqrt(normV1) * sqrt(normV2));

    return similarity;
}

// Fonction pour lire le contenu d'un fichier et le stocker dans un vecteur d'entiers
vector<int> readFile(const string& filename) {
    ifstream file(filename);
    vector<int> content;

    char c;
    while (file.get(c)) {
        content.push_back(static_cast<int>(c));
    }

    return content;
}


int main(int argc, char **argv){
    string line,line2,phrase;
    int cpt_phr=1,cpt_mot=1,cpt_sim=0,cpt_tt_mot=0;
    fstream file("fichier.txt",ios::out|ios::trunc);

    //Remplir fichier 1
    if(file.is_open()){
        file<<"nom entier: sarah oukaci"<<endl;
        file<<"niveau: M1 SSI"<<endl;
        file<<"age: 21 ans"<<endl;
        file.close();
        cout<<"fichier cree et donnees enregistrees"<<endl;
    }
    else{
        cout<<"Erreur"<<endl;
    }

    fstream file2("fichier2.txt",ios::out|ios::trunc);

    //Remplir fichier 2
    if(file2.is_open()){
        file2<<"nom entier: sarah oukaci"<<endl;
        file2<<"niveau: BAC scientifique"<<endl;
        file2<<"age: 21 ans"<<endl;
        file2.close();
        cout<<"fichier cree et donnees enregistrees"<<endl;
    }
    else{
        cout<<"Erreur"<<endl;
    }

    fstream Lecture_file("fichier.txt",ios::in);
    fstream Lecture_file2("fichier2.txt",ios::in);

    string name {""};
    //Lecture des fichiers au fure et à mesure (ligne par ligne)
    if(Lecture_file.is_open() && Lecture_file2.is_open()){
        while(getline(Lecture_file, line) && getline(Lecture_file2, line2)){
            cout<<"phrase "<<cpt_phr<<" fichier 1: ("<<line2<<")"<<endl;
            cout<<"phrase "<<cpt_phr<<" fichier 2: ("<<line<<")"<<endl;
            istringstream iss2(line2);
            string word2;
            istringstream iss(line);
            string word;
            //Lecture des lignes au fure et à mesure (mot par mot)
            while (iss2 >> word2 && iss >>word) {
                cout << "mot "<<cpt_mot <<" fichier 1: ("<< word2<<")" << endl;
                cout << "mot "<<cpt_mot<<" fichier 2: ("<<word<<")" << endl;
                cpt_mot+=1;
                //comparaison des mots (afficher 1 s'ils sont similaire sinon afficher 0)
                if(word == word2){
                    cout<<true<<endl;
                    cpt_sim+=1;
                }else{
                    cout<<false<<endl;
                }
            cpt_tt_mot+=1;
            }
            cpt_phr+=1;
            cpt_mot=1;
        }

        //affichage le nombres de mots similaires dans tt le text
        cout<<"nombre de mots similaire: "<<cpt_sim<<"/"<<cpt_tt_mot<<endl;
        cout << "\n Degree de similarite entre les fichiers methode1 : " << 90-cpt_sim*90/cpt_tt_mot <<"/90"<< endl;

        Lecture_file.close();
        Lecture_file2.close();


    string filename1 = "fichier.txt";
    string filename2 = "fichier2.txt";

    // Lire le contenu des fichiers dans des vecteurs d'entiers
    vector<int> content1 = readFile(filename1);
    vector<int> content2 = readFile(filename2);

    // Remplir les vecteurs avec des zéros pour égaliser les longueurs
    size_t maxLength = max(content1.size(), content2.size());
    content1.resize(maxLength, 0);
    content2.resize(maxLength, 0);

    // Calculer la similarité cosinus(en utilisant le produit scalaire)
    double similarity = cosineSimilarity(content1, content2)*90;


    // Afficher le degré de similarité de [0-90]
    cout << "\n Degree de similarite entre les fichiers methode2 : " << similarity <<"/90"<< endl;

    }
    else{
        cout<<"Erreur d\'ouverture du fichier"<<endl;
    }
}
