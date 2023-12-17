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

    bool CR_Into_Zone(Node, CorpsRigide); //Retourne true si l'objet est dans la zone et l'ajoute à la liste affilié à la zone
    bool test_CR_Into_Zone(Node, CorpsRigide);              //Fait le calcul si le corp rigide se trouve dans une zone où non        
    void set_CR_Into_Zone_Liste(Node, CorpsRigide);         //Ajoute à la liste de corps rigide 
    bool test_nb_CR(Node, CorpsRigide);                     //vérifie si on a 2 objet ou plus
    //generateNode()                                        //génère une branche
                                                                    //check si on est pas a profondeur max
                                                                    //créer 8 branches et donne la dimension à chacun
                                                                    //test_CR_Into_Zone()  &&  set_CR_Into_Zone_Liste()
    CorpsRigide* getleaf(void);                             //Effectue la liste de tout les duets de CR en fouillant les feuilles


    void generateNode(Node* parent, int depth) {

        if (depth >= maxDepth) {
            return;
        }

        //longeur du parent
        int dx = (parent->dimension[0] + parent->dimension[1]);    
        int dy = (parent->dimension[2] + parent->dimension[3]);  
        int dz = (parent->dimension[4] + parent->dimension[5]);  
        //millieu du parent
        int xm = dx / 2;
        int ym = dy / 2;
        int zm = dz / 2;

        /*  
            //dimension des 8 zones du parents sous forme  newdim{Xa,Xb,Ya,Yb,Za,Zb} 
        
            int dimA[6] = { xm - dx, xm     , ym - dy, ym     , zm - dz, zm      };
            int dimB[6] = { xm     , xm + dx, ym - dy, ym     , zm - dz, zm      };
            int dimC[6] = { xm - dx, xm     , ym - dy, ym     , zm     , zm + dz };
            int dimD[6] = { xm     , xm + dx, ym - dy, ym     , zm     , zm + dz };
            int dimE[6] = { xm - dx, xm     , ym     , ym + dy, zm - dz, zm      };
            int dimF[6] = { xm     , xm + dx, ym     , ym + dy, zm - dz, zm      };
            int dimG[6] = { xm - dx, xm     , ym     , ym + dy, zm     , zm + dz };
            int dimH[6] = { xm     , xm + dx, ym     , ym + dy, zm     , zm + dz };
        */

        
        int newdimension[8][6] = {  { xm - dx, xm     , ym - dy, ym     , zm - dz, zm      },   //dimension de la zone A
                                    { xm     , xm + dx, ym - dy, ym     , zm - dz, zm      },   //dimension de la zone B
                                    { xm - dx, xm     , ym - dy, ym     , zm     , zm + dz },   //dimension de la zone C
                                    { xm     , xm + dx, ym - dy, ym     , zm     , zm + dz },   //dimension de la zone D
                                    { xm - dx, xm     , ym     , ym + dy, zm - dz, zm      },   //dimension de la zone E
                                    { xm     , xm + dx, ym     , ym + dy, zm - dz, zm      },   //dimension de la zone F
                                    { xm - dx, xm     , ym     , ym + dy, zm     , zm + dz },   //dimension de la zone G
                                    { xm     , xm + dx, ym     , ym + dy, zm     , zm + dz } }; //dimension de la zone H

        for (int i = 0; i < 8; i++) {
            Node* newNode = new Node(newdimension[i]);
            generateNode(newNode, depth + 1);
           
        }
        
        
        
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 8; ++i) {
            deleteTree(node->data[i]);
        }

        delete node;
    }
};





#endif



class TreeNode {
public:

    void Placement(CorpsRigide);       //lors d'un placement d'un corp rigide, ça va l'implémenter dans la liste des objet de la zone où il se place

    void generateChildren(int depth);

   
};

