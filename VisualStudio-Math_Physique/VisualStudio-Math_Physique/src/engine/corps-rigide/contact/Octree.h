#ifndef __OCTREE_H__
#define __OCTREE_H__

#include "BoundingVolumeSphere.h"

/*
	J'ai un plateau de base, d'une dimension fixé		(tout ce qui en sort est considéré comme OOB et donc est une erreur et ne régis pas au même règle imposé)
	Un premier objet est intrdoduit dans le plateau, je récupère sa position et son rayon.
	Lorsq'un un autre objet est introduit
		Je découpe en 8 la zone
			Ces zones sont établis comme zone basse de mon arbre
            Elles otbiennent chacun la dimension coupé de leurs parent. 
            Un test s'effectue pour savoir où se place les objets du parents pour les enfants
                    Si j'atteint la profondeur max, j'établis les liens
                    Je regarde les feuille des branches les plus basse qui possèdent 2 objets ou plus
                    J'intègre dans une liste de duets d'objets les 2 objets contenu dans la zone
                        si il y a plusieurs objets, j'éffectue un lien avec chaque objet sauf lui même.


*/

// Une fois la variable de limitation de découpe atteinte, j'appelle BVS->PossibleCollision()




#include <iostream>
#include <vector>

const int MAX_DEPTH = 7;
const int MAX_CORPS_RIGIDE = 2;





struct Node {           
    //chaque noeuds possèdent une dimension et une liste pouvant contenir 1 ou 2 corps rigide
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
    Octree(int* initialDimension, int maxDepth) : maxDepth(maxDepth) { root = new Node(initialDimension); }   //Racine de taille et de profondeur défini
    ~Octree() { deleteTree(root); }

    bool CR_Into_Zone(Node, CorpsRigide);                   //Retourne true si l'objet est dans la zone et l'ajoute à la liste affilié à la zone

    bool test_CR_Into_Zone(Node, CorpsRigide);              //Fait le calcul si le corp rigide se trouve dans une zone où non        

    void set_CR_Into_Zone_Liste(Node, CorpsRigide);         //Ajoute à la liste de corps rigide 
   
    bool test_nb_CR(Node);                                  //vérifie si on a 1 objet ou moins dans liste_corps_rigide (false si on dépasse 1 objet)

    void generateNode(Node* parent, int depth);             //génère une branche
                                                                //check si on est pas a profondeur max
                                                                //créer 8 branches et donne la dimension à chacun
                                                                //test_CR_Into_Zone()  &&  set_CR_Into_Zone_Liste()
                                                                    
    CorpsRigide* getleaf(void);                             //Effectue la liste de tout les duets de CR en fouillant les feuilles


    
    
    void deleteTree(Node* node);                            // Coupe la branche lorsque le dernier corp rigide disparait
    
};





#endif



class TreeNode {
public:

    void Placement(CorpsRigide);       //lors d'un placement d'un corp rigide, ça va l'implémenter dans la liste des objet de la zone où il se place

    void generateChildren(int depth);

   
};

