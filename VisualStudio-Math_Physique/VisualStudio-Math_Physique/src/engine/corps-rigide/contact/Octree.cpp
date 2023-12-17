#include "Octree.h"

bool Octree::CR_Into_Zone(Node zone, CorpsRigide cr)	
// Si le corps rigide est dans la zone, alors il faut le mettre dans la liste de possession de la branche/zone
{	
	bool result;
	if( result = test_CR_Into_Zone(zone, cr) )
		{ set_CR_Into_Zone_Liste(zone, cr); }
	return result;
}

bool Octree::test_CR_Into_Zone(Node zone, CorpsRigide cr)
// Calcul de vérification du corps rigide dans la zone
{

    //TODO

	return false;
}

void Octree::set_CR_Into_Zone_Liste(Node zone, CorpsRigide cr)
// Place le corps rigide dans la liste de possession de la branche/zone et vérifie si on a dépassé le nombre de corps rigide de la zone
{
	zone.liste_Corp_Rigide.push_back(cr);
	if (test_nb_CR(zone, cr)) {
		


	}
}

bool Octree::test_nb_CR(Node zone)
// Regarde la taille du tableau et vérifie si on a dépassé 2
// False si on a 2 ou plusieurs élément
{
	return (zone.liste_Corp_Rigide.size() < 2);
}



void Octree::generateNode(Node* parent, int depth)
{

    if (depth >= maxDepth) {    // On execute la génération d'une branche, sauf si on est a la profondeur max
        return;
    }
    if (test_nb_CR(*parent)) {  // On execute la génération d'une branche, sauf si on a moins de 2 corps rigide dans la liste 
        return;                 // Si "false" c'est qu'on a dépassé 2 éléments, donc on génère des branches
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

void Octree::deleteTree(Node* node)
{
    if (node == nullptr) { return; }
    node->liste_Corp_Rigide.clear();
    delete node;
}

