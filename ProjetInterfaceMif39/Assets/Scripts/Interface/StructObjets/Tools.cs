using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Structures_Simu
{
    public class Vect3
    {
        private float x, y, z;

        public Vect3(float new_x, float new_y, float new_z)
        {
            x = new_x;
            y = new_y;
            z = new_z;
        }

        ////////////
        // GETTER //
        ////////////

        public float getX()
        {
            return x;
        }

        public float getY()
        {
            return y;
        }

        public float getZ()
        {
            return z;
        }

        ////////////
        // SETTER //
        ////////////

        public void setX(float new_x)
        {
            x = new_x;
        }

        public void setY(float new_y)
        {
            y = new_y;
        }

        public void setZ(float new_z)
        {
            z = new_z;
        }

    }

    /*class MapEnumPointeur
    {
		public Dictionary<FONC_BOOL, bool(*)	            (Conscient* a)> mapFoncBool;
		public Dictionary<FONC_VOID, void(*)		        (Conscient* a)> mapFoncVoid;
		public Dictionary<FONC_VOID_ENTITY, void(*)	    	(Conscient* a, Entite * e)> mapFoncVoidEntity;
		public Dictionary<FONC_INT_ENTITY, int(*)		    (Conscient* a, Entite * e)> mapFoncIntEntity;
		public Dictionary<FONC_ENTITY_ENTITY, Entite*(*)	(Conscient* a, Entite * e)> mapFoncEntityEntity;
    }

    //FONC_BOOL
    bool fonction_true(Sentient_Entity* a);
    bool fonction_false(Sentient_Entity* a);

    //FONC_INT_ENTITY
    int fonction_int_1(Sentient_Entity* a, Entity* e);
    int fonction_int_2(Sentient_Entity* a, Entity* e);
    int fonction_int_3(Sentient_Entity* a, Entity* e);
    int fonction_int_4(Sentient_Entity* a, Entity* e);

    //FONC_VOID
    void idle(Sentient_Entity* agent);
    void dormir(Sentient_Entity* agent);
    void goto_haut(Sentient_Entity* agent);
    void goto_bas(Sentient_Entity* agent);
    void goto_gauche(Sentient_Entity* agent);
    void goto_droite(Sentient_Entity* agent);

    //FONC_VOID_ENTITY
    void go_to(Sentient_Entity* agent, Entity* e);

    //FONC_ENTITY_ENTITY
    Entity* getHallOf(Sentient_Entity* agent, Entity* e);
    Entity* getNearesOf(Sentient_Entity* agent, Entity* e);*/
}

enum FONC_VOID
{
    TOURNER,
    DORMIR,
    ALLER_EN_HAUT,
    ALLER_EN_BAS,
    ALLER_A_GAUCHE,
    ALLER_A_DROITE,
    FONC_V_NULL
};

enum FONC_VOID_ENTITY
{
   ALLER_A,
   FONC_V_E_NULL
};

enum FONC_ENTITY_ENTITY
{
    AVOIR_LA_MOITIE_DE,
    AVOIR_A_PEU_PRES,
    FONC_E_E_NULL
};

enum FONC_BOOL
{
    FONC_BOOL_TRUE,
    FONC_BOOL_FALSE,
    FONC_B_NULL
};

enum FONC_BOOl_ENTITY
{
    FONC_B_E_NULL
};

enum FONC_INT_ENTITY
{
    FONC_INT_1,
    FONC_INT_2,
    FONC_INT_3,
    FONC_INT_4,
    FONC_I_E_NULL
};


