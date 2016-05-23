using Structures_Simu;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

public enum ETAT{
    NORD,
    SUD,
    EST,
    OUEST,
    MANGER,
    COUPER_BOIS,
    PRENDRE,
    SAUTER,
    FRAPPER,
    CONSTRUIRE,
    A_FAIM,
    PAS_FAIM
};

namespace Structures_Simu
{
    public class Conscient
    {
        private Tangible tangible;
        private Dictionary<int, int> valeurs_caracteristiques;
        private ETAT etat;
        private Dictionary<Position, Entite> memorisation;
        // private Stack<pair<Comportement*, Noeud*>> comportement;

        public Conscient(Position new_pos, string s, TYPE t)
        {
            Tangible tang = new Tangible(s, t);
            tang.getEntite().setPos(new_pos.getX(), new_pos.getY());
            tang.getEntite().setId(tang.getEntite().getNbId());
            tang.getEntite().incremente_nb_id();
        }
      
        public int getVal(int id)
        {
            var myValue = valeurs_caracteristiques.FirstOrDefault(x => x.Value == id).Key;
            if (myValue != 1)
            {
                return -1;
            }
            return myValue;
        }

        public int setVal(int id, int v)
        {
            var myValue = valeurs_caracteristiques.FirstOrDefault(x => x.Value == id).Key;
            if (myValue != 1)
            {
                return -1;
            }
            valeurs_caracteristiques[id] = v;
            return myValue;
        }

        public void vision()
        {
            int vue = 10;
            for (int x = tangible.getEntite().getPos().getX() - vue / 2; x < tangible.getEntite().getPos().getX() + vue / 2; x++)
            {
                for (int y = tangible.getEntite().getPos().getY() - vue / 2; y < tangible.getEntite().getPos().getY() + vue / 2; y++)
                {
                    Position newPos = new Position(x, y);
                    if (tangible.getEntite().getPos().isInCircle(newPos, vue))
                    {
                        // memorisation[newPos] = map.getEntityAt(newPos);
                    }
                }
            }
        }

        //public void addToTrace(Comportement* c, Noeud* n) { }
        //public void removeTopTrace() { }
    }

    public class Non_conscient
    {
        private Tangible tangible;
        private Vect3 sizeIE;
        private int nb_id;
        private int orientation;
        private int point_de_structure;
        private Dictionary<int, int> valeurs_caracteristiques;

        public Non_conscient(Position new_pos, string n, TYPE t, int o, int x, int y, int z)
        {
            Tangible tang = new Tangible(n, t);
            tang.getEntite().setPos(new_pos.getX(), new_pos.getY());
            tang.getEntite().setId(tang.getEntite().getNbId());
            tang.getEntite().incremente_nb_id();
            orientation = o;
            Vect3 v = new Vect3(x, y, z);
            sizeIE = v;
        }

        public int getOrientation()
        {
            return orientation;

        }

        public void setOrientation(int _o)
        {
            orientation = _o;
        }

        public int getPointDeStructure()
        {
            return point_de_structure;
        }

        public void setPointDeStructure(int sp)
        {
            point_de_structure = sp;
        }

        public int getVal(int id)
        {
            var myValue = valeurs_caracteristiques.FirstOrDefault(x => x.Value == id).Key;
            if (myValue != 1)
            {
                return -1;
            }
            return myValue;
        }

        public int setVal(int id, int v)
        {
            var myValue = valeurs_caracteristiques.FirstOrDefault(x => x.Value == id).Key;
            if (myValue != 1)
            {
                return -1;
            }
            valeurs_caracteristiques[id] = v;
            return myValue;
        }

    };
}
