#ifndef __OCTREE_H__
#define __OCTREE_H__

#include "BoundingVolumeSphere.h"

/*
	J'ai un plateau de base, d'une dimension fix�		(tout ce qui en sort est consid�r� comme OOB et donc est une erreur et ne r�gis pas au m�me r�gle impos�)
	Un premier objet est intrdoduit dans le plateau, je r�cup�re sa position et son rayon.
	Lorsq'un un autre objet est introduit
		Je d�coupe en 8 la zone
			Ces zones sont �tablis comme zone basse de mon arbre
            Elles otbiennent chacun la dimension coup� de leurs parent. 
            Un test s'effectue pour savoir o� se place les objets du parents pour les enfants
                    Si j'atteint la profondeur max, j'�tablis les liens
                    Je regarde les feuille des branches les plus basse qui poss�dent 2 objets ou plus
                    J'int�gre dans une liste de duets d'objets les 2 objets contenu dans la zone
                        si il y a plusieurs objets, j'�ffectue un lien avec chaque objet sauf lui m�me.


*/

// Une fois la variable de limitation de d�coupe atteinte, j'appelle BVS->PossibleCollision()




#include <iostream>
#include <vector>

const int MAX_DEPTH = 7;
const int MAX_CORPS_RIGIDE = 2;





struct Node {           
    //chaque noeuds poss�dent une dimension et une liste pouvant contenir 1 ou 2 corps rigide
    int dimension[6];
    std::vector<CorpsRigide> liste_Corp_Rigide;

    Node(int* dim) { for (int i = 0; i < 6; ++i) { dimension[i] = dim[i]; } }       //constructeur 
    ~Node() {}                                                                      //destructeur
};



class Octree {
private:
    Node* root;
    int maxDepth = MAX_DEPTH;
public:
    Octree(int* initialDimension, int maxDepth) : maxDepth(maxDepth) { root = new Node(initialDimension); }   //Racine de taille et de profondeur d�fini
    ~Octree() { deleteTree(root); }

    bool CR_Into_Zone(Node, CorpsRigide);                   //Retourne true si l'objet est dans la zone et l'ajoute � la liste affili� � la zone

    bool test_CR_Into_Zone(Node, CorpsRigide);              //Fait le calcul si le corp rigide se trouve dans une zone o� non        

    void set_CR_Into_Zone_Liste(Node, CorpsRigide);         //Ajoute � la liste de corps rigide 
   
    bool test_nb_CR(Node);                                  //v�rifie si on a 1 objet ou moins dans liste_corps_rigide (false si on d�passe 1 objet)

    void generateNode(Node* parent, int depth);             //g�n�re une branche
                                                                //check si on est pas a profondeur max
                                                                //cr�er 8 branches et donne la dimension � chacun
                                                                //test_CR_Into_Zone()  &&  set_CR_Into_Zone_Liste()
                                                                    
    CorpsRigide* getleaf(void);                             //Effectue la liste de tout les duets de CR en fouillant les feuilles


    
    
    void deleteTree(Node* node);                            // Coupe la branche lorsque le dernier corp rigide disparait
    
};





#endif



class TreeNode {
public:

    void Placement(CorpsRigide);       //lors d'un placement d'un corp rigide, �a va l'impl�menter dans la liste des objet de la zone o� il se place

    void generateChildren(int depth);

   
};

